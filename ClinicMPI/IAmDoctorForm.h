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
	/// Summary for IAmDoctorForm
	/// </summary>
	public ref class IAmDoctorForm : public System::Windows::Forms::Form
	{
	public:
		IAmDoctorForm(void)
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
		~IAmDoctorForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:

	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(53, 89);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(188, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"See appointments";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &IAmDoctorForm::button1_Click);
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->columnHeader1, this->columnHeader2 });
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(12, 118);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(272, 117);
			this->listView1->TabIndex = 2;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Patient";
			this->columnHeader1->Width = 114;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Date";
			this->columnHeader2->Width = 194;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Name";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(89, 40);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(152, 20);
			this->textBox1->TabIndex = 4;
			// 
			// IAmDoctorForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(149)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)));
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->button1);
			this->Name = L"IAmDoctorForm";
			this->Text = L"IAmDoctorForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion
	
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			int option = AppointmentByDoctor;
			int procId = GetNextProcId();
			MPI_Status status;
			char name[1000];

			sprintf(name, "%s", textBox1->Text);
			MPI_Send(&option, 1, MPI_INT, procId, 0, MPI_COMM_WORLD);

			WriteToFile(std::string("Am Gasit") + std::string(name));

			MPI_Send(name, sizeof(name), MPI_CHAR, procId, 1, MPI_COMM_WORLD);


			int cnt = 0;
			MPI_Recv(&cnt, 1, MPI_INT, procId, 2, MPI_COMM_WORLD, &status);

			for (int i = 0; i < cnt; i++)
			{

				char Pname[1000], date[1000];

				MPI_Recv(Pname, 1000, MPI_CHAR, procId, 3, MPI_COMM_WORLD, &status);
				WriteToFile(std::string("in i am doctor form ") + Pname);
				MPI_Recv(date, 1000, MPI_CHAR, procId, 4, MPI_COMM_WORLD, &status);


				ListViewItem^ a = listView1->Items->Add(gcnew String(Pname));
				a->SubItems->Add(gcnew String(date));

			}

		}
	};
}
