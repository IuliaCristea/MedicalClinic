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
	/// Summary for IAmPatientForm
	/// </summary>
	public ref class IAmPatientForm : public System::Windows::Forms::Form
	{

	private: int procId = -1;
	public:
		IAmPatientForm(void)
		{
			InitializeComponent();
			int option = AllDoctors;
			procId = GetNextProcId();
			MPI_Status status;
			MPI_Send(&option, 1, MPI_INT, procId, 0, MPI_COMM_WORLD);

			int cnt = 0;
			MPI_Recv(&cnt, 1, MPI_INT, procId, 1, MPI_COMM_WORLD, &status);

			for (int i = 0; i < cnt; i++)
			{

				char name[1000], spec[1000];
				int docId = -1;
				
				MPI_Recv(&docId, 1, MPI_INT, procId, 2, MPI_COMM_WORLD, &status);
				MPI_Recv(name, 1000, MPI_CHAR, procId, 3, MPI_COMM_WORLD, &status);
				MPI_Recv(spec, 1000, MPI_CHAR, procId, 4, MPI_COMM_WORLD, &status);
				

				ListViewItem^ a = listView1->Items->Add(System::Convert::ToString(docId));
				a->SubItems->Add(gcnew String(name));
				a->SubItems->Add(gcnew String(spec));

			}

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~IAmPatientForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^ listView1;
	protected:
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader3;

	protected:




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
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnHeader3, this->columnHeader1,
					this->columnHeader2
			});
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(15, 29);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(260, 120);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"DocId";
			this->columnHeader3->Width = 48;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Doctor Name";
			this->columnHeader1->Width = 105;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Speciality";
			this->columnHeader2->Width = 84;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(64, 211);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(141, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Make appointment";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &IAmPatientForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(92, 155);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(180, 20);
			this->textBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 158);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Patient Id";
			this->label1->Click += gcnew System::EventHandler(this, &IAmPatientForm::label1_Click);
			// 
			// IAmPatientForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(149)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)));
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listView1);
			this->Name = L"IAmPatientForm";
			this->Text = L"IAmPatientForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		char docIdstr[1000], patientIdstr[1000];


		int option = AddAppointment;
		procId = GetNextProcId();
		MPI_Status status;
		MPI_Request req1, req2;

		MPI_Send(&option, 1, MPI_INT, procId, 0, MPI_COMM_WORLD);

		sprintf(docIdstr, "%s", listView1->SelectedItems[0]->Text);
		sprintf(patientIdstr, "%s", textBox1->Text);

	/*	
		WriteToFile(string(docIdstr));
		WriteToFile(string(patientIdstr));*/


		int docId = std::stoi(docIdstr);
		int patientId = std::stoi(patientIdstr);

		
		MPI_Isend(&docId, 1, MPI_INT, procId, 1, MPI_COMM_WORLD, &req1);
		MPI_Isend(&patientId, 1, MPI_INT, procId, 2, MPI_COMM_WORLD, &req2);

		MPI_Wait(&req1, &status);
		MPI_Wait(&req2, &status);
	
		int res = 0;
		MPI_Recv(&res, 1, MPI_INT, procId, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

		if (res == 1)
		{
			MessageBox::Show("Successfully created  Appointment");
		}
		else
		{
			MessageBox::Show("Failed to create Appointment");


		}


	}
};
}
