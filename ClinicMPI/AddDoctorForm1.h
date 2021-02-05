#pragma once
#include "Helper.h"

namespace ClinicMPI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddDoctorForm
	/// </summary>
	public ref class AddDoctorForm : public System::Windows::Forms::Form
	{
	public:
		AddDoctorForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddDoctorForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(234, 131);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Submit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddDoctorForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(88, 54);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(175, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 57);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Doctor Name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 88);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Speciality";
			this->label2->Click += gcnew System::EventHandler(this, &AddDoctorForm::label2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(88, 85);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(175, 20);
			this->textBox2->TabIndex = 4;
			// 
			// AddDoctorForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(149)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)));
			this->ClientSize = System::Drawing::Size(321, 166);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"AddDoctorForm";
			this->Text = L"AddDoctorForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {


	char name[1000], speciality[199];
	sprintf(name, "%s", textBox1->Text);
	sprintf(speciality, "%s", textBox2->Text);
	
	int option = AddDoctor;
	MPI_Request req1, req2, req3;
	MPI_Status status;
	int requestNumber = 0;

	int procId = GetNextProcId();
	

	MPI_Isend(&option, 1, MPI_INT, procId, 0, MPI_COMM_WORLD, &req1);
	MPI_Isend(name, sizeof(name), MPI_CHAR, procId, 1, MPI_COMM_WORLD, &req2);
	MPI_Isend(speciality, sizeof(speciality), MPI_CHAR, procId, 2, MPI_COMM_WORLD, &req3);

	MPI_Wait(&req1, &status);
	MPI_Wait(&req2, &status);
	MPI_Wait(&req3, &status);

	int res = 0;
	MPI_Recv(&res, 1, MPI_INT, procId, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

	if (res == 1)
	{
		MessageBox::Show("Successfully inserted Doctor");
	}
	else
	{
		MessageBox::Show("Failed to insert Doctor");

	}
}
};
}
