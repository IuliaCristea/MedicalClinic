#pragma once
#include <chrono>
#include "mpi.h"
#include "Helper.h"
#include <iostream>
#include <sstream>

namespace ClinicMPI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class PatientForm : public System::Windows::Forms::Form
	{
		public:
			PatientForm(void)
			{
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				//
			}
			PatientForm(int tabPage)
			{
				InitializeComponent();

				if (tabPage == 1)
				{
					patientFormTabs->SelectTab(1);
				}
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~PatientForm()
			{
				if (components)
				{
					delete components;
				}
			}
	private: System::Windows::Forms::TabControl^ patientFormTabs;
	protected:

	private: System::Windows::Forms::TabPage^ patientInsertTab;
	protected:

	protected:

	protected:

	private: System::Windows::Forms::TabPage^ patientGetTab;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ SimulatePatientsLabel;
	private: System::Windows::Forms::Button^ buttonSubmitPatient;
	private: System::Windows::Forms::TextBox^ textBoxPatientCNP;
	private: System::Windows::Forms::Label^ labelCNP;
	private: System::Windows::Forms::TextBox^ textBoxNumberOfPatients;
	private: System::Windows::Forms::Label^ numberOfPatientsLabel;
	private: System::Windows::Forms::TextBox^ textBoxPatientAddress;
	private: System::Windows::Forms::Label^ addressLabel;
	private: System::Windows::Forms::TextBox^ textBoxPatientName;
	private: System::Windows::Forms::Label^ labelName;
	private: System::Windows::Forms::Label^ titleLabel;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ getPatientsButton;
	private: System::Windows::Forms::RichTextBox^ getPatientsTextBox;


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
				System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PatientForm::typeid));
				this->patientFormTabs = (gcnew System::Windows::Forms::TabControl());
				this->patientInsertTab = (gcnew System::Windows::Forms::TabPage());
				this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				this->SimulatePatientsLabel = (gcnew System::Windows::Forms::Label());
				this->buttonSubmitPatient = (gcnew System::Windows::Forms::Button());
				this->textBoxPatientCNP = (gcnew System::Windows::Forms::TextBox());
				this->labelCNP = (gcnew System::Windows::Forms::Label());
				this->textBoxNumberOfPatients = (gcnew System::Windows::Forms::TextBox());
				this->numberOfPatientsLabel = (gcnew System::Windows::Forms::Label());
				this->textBoxPatientAddress = (gcnew System::Windows::Forms::TextBox());
				this->addressLabel = (gcnew System::Windows::Forms::Label());
				this->textBoxPatientName = (gcnew System::Windows::Forms::TextBox());
				this->labelName = (gcnew System::Windows::Forms::Label());
				this->titleLabel = (gcnew System::Windows::Forms::Label());
				this->patientGetTab = (gcnew System::Windows::Forms::TabPage());
				this->getPatientsTextBox = (gcnew System::Windows::Forms::RichTextBox());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->getPatientsButton = (gcnew System::Windows::Forms::Button());
				this->patientFormTabs->SuspendLayout();
				this->patientInsertTab->SuspendLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				this->patientGetTab->SuspendLayout();
				this->SuspendLayout();
				// 
				// patientFormTabs
				// 
				this->patientFormTabs->Controls->Add(this->patientInsertTab);
				this->patientFormTabs->Controls->Add(this->patientGetTab);
				this->patientFormTabs->Dock = System::Windows::Forms::DockStyle::Fill;
				this->patientFormTabs->Location = System::Drawing::Point(0, 0);
				this->patientFormTabs->Margin = System::Windows::Forms::Padding(0);
				this->patientFormTabs->Name = L"patientFormTabs";
				this->patientFormTabs->SelectedIndex = 0;
				this->patientFormTabs->Size = System::Drawing::Size(557, 574);
				this->patientFormTabs->TabIndex = 12;
				// 
				// patientInsertTab
				// 
				this->patientInsertTab->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(149)),
					static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(216)));
				this->patientInsertTab->Controls->Add(this->pictureBox1);
				this->patientInsertTab->Controls->Add(this->SimulatePatientsLabel);
				this->patientInsertTab->Controls->Add(this->buttonSubmitPatient);
				this->patientInsertTab->Controls->Add(this->textBoxPatientCNP);
				this->patientInsertTab->Controls->Add(this->labelCNP);
				this->patientInsertTab->Controls->Add(this->textBoxNumberOfPatients);
				this->patientInsertTab->Controls->Add(this->numberOfPatientsLabel);
				this->patientInsertTab->Controls->Add(this->textBoxPatientAddress);
				this->patientInsertTab->Controls->Add(this->addressLabel);
				this->patientInsertTab->Controls->Add(this->textBoxPatientName);
				this->patientInsertTab->Controls->Add(this->labelName);
				this->patientInsertTab->Controls->Add(this->titleLabel);
				this->patientInsertTab->Location = System::Drawing::Point(4, 25);
				this->patientInsertTab->Name = L"patientInsertTab";
				this->patientInsertTab->Padding = System::Windows::Forms::Padding(3);
				this->patientInsertTab->Size = System::Drawing::Size(549, 545);
				this->patientInsertTab->TabIndex = 0;
				this->patientInsertTab->Text = L"Insert";
				// 
				// pictureBox1
				// 
				this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
				this->pictureBox1->Location = System::Drawing::Point(382, 61);
				this->pictureBox1->Name = L"pictureBox1";
				this->pictureBox1->Size = System::Drawing::Size(106, 117);
				this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
				this->pictureBox1->TabIndex = 23;
				this->pictureBox1->TabStop = false;
				// 
				// SimulatePatientsLabel
				// 
				this->SimulatePatientsLabel->AutoSize = true;
				this->SimulatePatientsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				this->SimulatePatientsLabel->Location = System::Drawing::Point(150, 376);
				this->SimulatePatientsLabel->Name = L"SimulatePatientsLabel";
				this->SimulatePatientsLabel->Size = System::Drawing::Size(239, 20);
				this->SimulatePatientsLabel->TabIndex = 22;
				this->SimulatePatientsLabel->Text = L"Simulate importing patients";
				this->SimulatePatientsLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				// 
				// buttonSubmitPatient
				// 
				this->buttonSubmitPatient->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->buttonSubmitPatient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				this->buttonSubmitPatient->Location = System::Drawing::Point(388, 486);
				this->buttonSubmitPatient->Margin = System::Windows::Forms::Padding(4);
				this->buttonSubmitPatient->Name = L"buttonSubmitPatient";
				this->buttonSubmitPatient->Size = System::Drawing::Size(100, 28);
				this->buttonSubmitPatient->TabIndex = 21;
				this->buttonSubmitPatient->Text = L"Submit";
				this->buttonSubmitPatient->UseVisualStyleBackColor = true;
				this->buttonSubmitPatient->Click += gcnew System::EventHandler(this, &PatientForm::buttonSubmitPatient_Click);
				// 
				// textBoxPatientCNP
				// 
				this->textBoxPatientCNP->Location = System::Drawing::Point(231, 308);
				this->textBoxPatientCNP->Margin = System::Windows::Forms::Padding(4);
				this->textBoxPatientCNP->Name = L"textBoxPatientCNP";
				this->textBoxPatientCNP->Size = System::Drawing::Size(257, 22);
				this->textBoxPatientCNP->TabIndex = 20;
				// 
				// labelCNP
				// 
				this->labelCNP->AutoSize = true;
				this->labelCNP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->labelCNP->Location = System::Drawing::Point(55, 308);
				this->labelCNP->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				this->labelCNP->Name = L"labelCNP";
				this->labelCNP->Size = System::Drawing::Size(101, 20);
				this->labelCNP->TabIndex = 19;
				this->labelCNP->Text = L"Patient CNP";
				// 
				// textBoxNumberOfPatients
				// 
				this->textBoxNumberOfPatients->Location = System::Drawing::Point(231, 414);
				this->textBoxNumberOfPatients->Margin = System::Windows::Forms::Padding(4);
				this->textBoxNumberOfPatients->Name = L"textBoxNumberOfPatients";
				this->textBoxNumberOfPatients->Size = System::Drawing::Size(257, 22);
				this->textBoxNumberOfPatients->TabIndex = 18;
				// 
				// numberOfPatientsLabel
				// 
				this->numberOfPatientsLabel->AutoSize = true;
				this->numberOfPatientsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				this->numberOfPatientsLabel->Location = System::Drawing::Point(55, 414);
				this->numberOfPatientsLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				this->numberOfPatientsLabel->Name = L"numberOfPatientsLabel";
				this->numberOfPatientsLabel->Size = System::Drawing::Size(114, 20);
				this->numberOfPatientsLabel->TabIndex = 17;
				this->numberOfPatientsLabel->Text = L"Nr. of patients";
				// 
				// textBoxPatientAddress
				// 
				this->textBoxPatientAddress->Location = System::Drawing::Point(231, 267);
				this->textBoxPatientAddress->Margin = System::Windows::Forms::Padding(4);
				this->textBoxPatientAddress->Name = L"textBoxPatientAddress";
				this->textBoxPatientAddress->Size = System::Drawing::Size(257, 22);
				this->textBoxPatientAddress->TabIndex = 16;
				// 
				// addressLabel
				// 
				this->addressLabel->AutoSize = true;
				this->addressLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->addressLabel->Location = System::Drawing::Point(55, 267);
				this->addressLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				this->addressLabel->Name = L"addressLabel";
				this->addressLabel->Size = System::Drawing::Size(128, 20);
				this->addressLabel->TabIndex = 15;
				this->addressLabel->Text = L"Patient Address";
				// 
				// textBoxPatientName
				// 
				this->textBoxPatientName->Location = System::Drawing::Point(231, 223);
				this->textBoxPatientName->Margin = System::Windows::Forms::Padding(4);
				this->textBoxPatientName->Name = L"textBoxPatientName";
				this->textBoxPatientName->Size = System::Drawing::Size(257, 22);
				this->textBoxPatientName->TabIndex = 14;
				// 
				// labelName
				// 
				this->labelName->AutoSize = true;
				this->labelName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->labelName->Location = System::Drawing::Point(55, 223);
				this->labelName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				this->labelName->Name = L"labelName";
				this->labelName->Size = System::Drawing::Size(110, 20);
				this->labelName->TabIndex = 13;
				this->labelName->Text = L"Patient Name";
				// 
				// titleLabel
				// 
				this->titleLabel->AutoSize = true;
				this->titleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->titleLabel->Location = System::Drawing::Point(185, 16);
				this->titleLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				this->titleLabel->Name = L"titleLabel";
				this->titleLabel->Size = System::Drawing::Size(148, 25);
				this->titleLabel->TabIndex = 12;
				this->titleLabel->Text = L"Insert patients";
				// 
				// patientGetTab
				// 
				this->patientGetTab->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(149)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
					static_cast<System::Int32>(static_cast<System::Byte>(216)));
				this->patientGetTab->Controls->Add(this->getPatientsTextBox);
				this->patientGetTab->Controls->Add(this->label1);
				this->patientGetTab->Controls->Add(this->getPatientsButton);
				this->patientGetTab->Location = System::Drawing::Point(4, 25);
				this->patientGetTab->Name = L"patientGetTab";
				this->patientGetTab->Padding = System::Windows::Forms::Padding(3);
				this->patientGetTab->Size = System::Drawing::Size(549, 545);
				this->patientGetTab->TabIndex = 1;
				this->patientGetTab->Text = L"Get";
				// 
				// getPatientsTextBox
				// 
				this->getPatientsTextBox->Location = System::Drawing::Point(46, 173);
				this->getPatientsTextBox->Name = L"getPatientsTextBox";
				this->getPatientsTextBox->Size = System::Drawing::Size(464, 232);
				this->getPatientsTextBox->TabIndex = 2;
				this->getPatientsTextBox->Text = L"";
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label1->Location = System::Drawing::Point(195, 44);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(90, 25);
				this->label1->TabIndex = 1;
				this->label1->Text = L"Patients";
				// 
				// getPatientsButton
				// 
				this->getPatientsButton->Location = System::Drawing::Point(143, 107);
				this->getPatientsButton->Name = L"getPatientsButton";
				this->getPatientsButton->Size = System::Drawing::Size(198, 28);
				this->getPatientsButton->TabIndex = 0;
				this->getPatientsButton->Text = L"Get Patients";
				this->getPatientsButton->UseVisualStyleBackColor = true;
				this->getPatientsButton->Click += gcnew System::EventHandler(this, &PatientForm::getPatientsButton_Click);
				// 
				// PatientForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(149)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
					static_cast<System::Int32>(static_cast<System::Byte>(216)));
				this->ClientSize = System::Drawing::Size(557, 574);
				this->Controls->Add(this->patientFormTabs);
				this->Margin = System::Windows::Forms::Padding(4);
				this->Name = L"PatientForm";
				this->Text = L"PatientForm";
				this->patientFormTabs->ResumeLayout(false);
				this->patientInsertTab->ResumeLayout(false);
				this->patientInsertTab->PerformLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				this->patientGetTab->ResumeLayout(false);
				this->patientGetTab->PerformLayout();
				this->ResumeLayout(false);

			}
	#pragma endregion
		private: System::Void buttonSubmitPatient_Click(System::Object^ sender, System::EventArgs^ e) {

			int numprocs;
			MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
		
			String^ textboxName = textBoxPatientName->Text;
			int numberOfPatientsToSimulate = int::Parse(textBoxNumberOfPatients->Text);
			WriteToFile("numberOfPatientsToSimulate !!! ----------------------  " + string(to_string(numberOfPatientsToSimulate)));

			String^ textboxAddress = textBoxPatientAddress->Text;
			String^ textboxCNP = textBoxPatientCNP->Text;
					
			MPI_Status stats[100];
			MPI_Request reqs[100];
			int buf[10] = { }, done[10];
			int requestNumber = 0;
			int numberOfProcessesStarted = 0;
			
			int availableProcs = numprocs - 1;

			for(int processId = 1; processId <= numprocs - 1; processId++)
			{
				numberOfProcessesStarted++;
				
				int numberOfPatientsToSimulate_ForProcess = (numberOfPatientsToSimulate / (availableProcs)) + numberOfPatientsToSimulate % (availableProcs);
				int option = InsertMultiple;
				char name[1000], address[1000], cnp[1000];

				sprintf(name, "%s", textboxName);
				sprintf(address, "%s", textboxAddress);
				sprintf(cnp, "%s", textboxCNP);

				MPI_Isend(&option, 1, MPI_INT, processId, 0, MPI_COMM_WORLD, &reqs[++requestNumber]);

				MPI_Isend(name, sizeof(name), MPI_CHAR, processId, 1, MPI_COMM_WORLD, &reqs[++requestNumber]);
				MPI_Isend(&numberOfPatientsToSimulate_ForProcess, 1, MPI_INT, processId, 2, MPI_COMM_WORLD, &reqs[++requestNumber]);
				MPI_Isend(address, sizeof(address), MPI_CHAR, processId, 3, MPI_COMM_WORLD, &reqs[++requestNumber]);
				MPI_Isend(cnp, sizeof(cnp), MPI_CHAR, processId, 4, MPI_COMM_WORLD, &reqs[++requestNumber]);
				
				numberOfPatientsToSimulate -= numberOfPatientsToSimulate_ForProcess;
				availableProcs--;
			}
			
			MPI_Waitall(requestNumber, reqs, stats);
			
			int success = 0;
			// Get result from processes
			for(int i = 1; i <= numberOfProcessesStarted; i++)
			{
				int res = 0;
				MPI_Recv(&res, 1, MPI_INT, i, 4444, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

				if (res == 1)
					success++;
			}

			if (success == numprocs - 1)
			{
				MessageBox::Show("Successfully inserted patient");
			}
			else
			{
				MessageBox::Show("Failed to insert patient");
			}
		}
	private: System::Void getPatientsButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int number = 1;
		int option = GetMultiple;
		char result[10000] = "";
		MPI_Status stats[10];
		MPI_Request reqs[10];

		MPI_Isend(&option, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &reqs[0]);
		MPI_Isend(&number, 1, MPI_INT, 1, 1, MPI_COMM_WORLD, &reqs[1]);
		MPI_Waitall(2, reqs, stats);

		MPI_Recv(result, 10000, MPI_CHAR, 1, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

		int a_size = sizeof(result) / sizeof(char);
		String^ rez = gcnew String(convertToString(result, a_size).c_str());
		getPatientsTextBox->Text = rez;
	}

	   string convertToString(char* a, int size)
	   {
		   int i;
		   string s = "";
		   for (i = 0; i < size; i++) {
			   s = s + a[i];
		   }
		   return s;
	   }
};
}
