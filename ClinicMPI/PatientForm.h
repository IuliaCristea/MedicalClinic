#pragma once
#include "mpi.h"
#include "Helper.h"
#include <iostream>

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
	private: System::Windows::Forms::Label^ titleLabel;
	private: System::Windows::Forms::Label^ labelName;
	private: System::Windows::Forms::TextBox^ textBoxPatientName;
	private: System::Windows::Forms::Label^ addressLabel;
	private: System::Windows::Forms::TextBox^ textBoxPatientAddress;

	private: System::Windows::Forms::Label^ genderLabel;
	private: System::Windows::Forms::TextBox^ textBoxPatientGender;

	private: System::Windows::Forms::Label^ labelCNP;
	private: System::Windows::Forms::TextBox^ textBoxPatientCNP;
	private: System::Windows::Forms::Button^ buttonSubmitPatient;
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
			this->titleLabel = (gcnew System::Windows::Forms::Label());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->textBoxPatientName = (gcnew System::Windows::Forms::TextBox());
			this->addressLabel = (gcnew System::Windows::Forms::Label());
			this->textBoxPatientAddress = (gcnew System::Windows::Forms::TextBox());
			this->genderLabel = (gcnew System::Windows::Forms::Label());
			this->textBoxPatientGender = (gcnew System::Windows::Forms::TextBox());
			this->labelCNP = (gcnew System::Windows::Forms::Label());
			this->textBoxPatientCNP = (gcnew System::Windows::Forms::TextBox());
			this->buttonSubmitPatient = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// titleLabel
			// 
			this->titleLabel->AutoSize = true;
			this->titleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->titleLabel->Location = System::Drawing::Point(138, 33);
			this->titleLabel->Name = L"titleLabel";
			this->titleLabel->Size = System::Drawing::Size(120, 20);
			this->titleLabel->TabIndex = 0;
			this->titleLabel->Text = L"Insert a patient:";
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelName->Location = System::Drawing::Point(56, 91);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(89, 16);
			this->labelName->TabIndex = 1;
			this->labelName->Text = L"Patient Name";
			// 
			// textBoxPatientName
			// 
			this->textBoxPatientName->Location = System::Drawing::Point(188, 91);
			this->textBoxPatientName->Name = L"textBoxPatientName";
			this->textBoxPatientName->Size = System::Drawing::Size(194, 20);
			this->textBoxPatientName->TabIndex = 2;
			// 
			// addressLabel
			// 
			this->addressLabel->AutoSize = true;
			this->addressLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addressLabel->Location = System::Drawing::Point(56, 131);
			this->addressLabel->Name = L"addressLabel";
			this->addressLabel->Size = System::Drawing::Size(103, 16);
			this->addressLabel->TabIndex = 3;
			this->addressLabel->Text = L"Patient Address";
			// 
			// textBoxPatientAddress
			// 
			this->textBoxPatientAddress->Location = System::Drawing::Point(188, 131);
			this->textBoxPatientAddress->Name = L"textBoxPatientAddress";
			this->textBoxPatientAddress->Size = System::Drawing::Size(194, 20);
			this->textBoxPatientAddress->TabIndex = 4;
			// 
			// genderLabel
			// 
			this->genderLabel->AutoSize = true;
			this->genderLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->genderLabel->Location = System::Drawing::Point(56, 171);
			this->genderLabel->Name = L"genderLabel";
			this->genderLabel->Size = System::Drawing::Size(97, 16);
			this->genderLabel->TabIndex = 5;
			this->genderLabel->Text = L"Patient Gender";
			// 
			// textBoxPatientGender
			// 
			this->textBoxPatientGender->Location = System::Drawing::Point(188, 171);
			this->textBoxPatientGender->Name = L"textBoxPatientGender";
			this->textBoxPatientGender->Size = System::Drawing::Size(194, 20);
			this->textBoxPatientGender->TabIndex = 6;
			// 
			// labelCNP
			// 
			this->labelCNP->AutoSize = true;
			this->labelCNP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelCNP->Location = System::Drawing::Point(59, 209);
			this->labelCNP->Name = L"labelCNP";
			this->labelCNP->Size = System::Drawing::Size(80, 16);
			this->labelCNP->TabIndex = 7;
			this->labelCNP->Text = L"Patient CNP";
			// 
			// textBoxPatientCNP
			// 
			this->textBoxPatientCNP->Location = System::Drawing::Point(188, 209);
			this->textBoxPatientCNP->Name = L"textBoxPatientCNP";
			this->textBoxPatientCNP->Size = System::Drawing::Size(194, 20);
			this->textBoxPatientCNP->TabIndex = 8;
			// 
			// buttonSubmitPatient
			// 
			this->buttonSubmitPatient->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->buttonSubmitPatient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->buttonSubmitPatient->Location = System::Drawing::Point(288, 298);
			this->buttonSubmitPatient->Name = L"buttonSubmitPatient";
			this->buttonSubmitPatient->Size = System::Drawing::Size(75, 23);
			this->buttonSubmitPatient->TabIndex = 9;
			this->buttonSubmitPatient->Text = L"Submit";
			this->buttonSubmitPatient->UseVisualStyleBackColor = true;
			this->buttonSubmitPatient->Click += gcnew System::EventHandler(this, &PatientForm::buttonSubmitPatient_Click);
			// 
			// PatientForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(418, 354);
			this->Controls->Add(this->buttonSubmitPatient);
			this->Controls->Add(this->textBoxPatientCNP);
			this->Controls->Add(this->labelCNP);
			this->Controls->Add(this->textBoxPatientGender);
			this->Controls->Add(this->genderLabel);
			this->Controls->Add(this->textBoxPatientAddress);
			this->Controls->Add(this->addressLabel);
			this->Controls->Add(this->textBoxPatientName);
			this->Controls->Add(this->labelName);
			this->Controls->Add(this->titleLabel);
			this->Name = L"PatientForm";
			this->Text = L"PatientForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonSubmitPatient_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ textboxName = textBoxPatientName->Text;
		//int gender = stoi(msclr::interop::marshal_as<std::string>(textBoxPatientGender->Text));
		int textboxGender = int::Parse(textBoxPatientGender->Text);
		String^ textboxAddress = textBoxPatientAddress->Text;
		String^ textboxCNP = textBoxPatientCNP->Text;

		MPI_Status status;

		MPI_Request rOption, rName, rGender, rAddress, rCnp;

		int option = 1;
		bool done = false;
		char name[1000], address[1000], cnp[1000];

		sprintf(name, "%s", textboxName);
		sprintf(address, "%s", textboxAddress);
		sprintf(cnp, "%s", textboxCNP);

		MPI_Isend(&option, 1, MPI_INT, PatientW, 0, MPI_COMM_WORLD, &rOption);


		MPI_Isend(name, sizeof(name), MPI_CHAR, PatientW, 1, MPI_COMM_WORLD, &rName);
		MPI_Isend(&textboxGender, 1, MPI_INT, PatientW, 2, MPI_COMM_WORLD, &rGender);
		MPI_Isend(address, sizeof(address), MPI_CHAR, PatientW, 3, MPI_COMM_WORLD, &rAddress);
		MPI_Isend(cnp, sizeof(cnp), MPI_CHAR, PatientW, 4, MPI_COMM_WORLD, &rCnp);

		MPI_Wait(&rOption, &status);
		MPI_Wait(&rName, &status);
		MPI_Wait(&rGender, &status);
		MPI_Wait(&rAddress, &status);
		MPI_Wait(&rCnp, &status);


		MPI_Recv(&done, 1, MPI_INT, PatientW, 4444, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

		if (done == 1)
		{
			MessageBox::Show("Successfully inserted patient");
			this->Close();
		}
		else
		{
			MessageBox::Show("Failed to insert patient");
		}


	}
};
}
