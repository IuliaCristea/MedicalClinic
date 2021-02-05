#pragma once
#include "PatientForm.h"
#include "JeSuisDoctorForm.h"
#include "AddDoctorForm1.h"
#include "IAmPatientForm.h"
#include "IAmDoctorForm.h"
namespace ClinicMPI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MenuForm
	/// </summary>
	public ref class MenuForm : public System::Windows::Forms::Form
	{
	public:
		MenuForm(void)
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
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonAddPatient;
	private: System::Windows::Forms::Label^ mainFormTitleLabel;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ buttonGetPatients;
	private: System::Windows::Forms::Button^ doctorButton;
	private: System::Windows::Forms::Button^ iAmPatientButton;
	private: System::Windows::Forms::Button^ button1;

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuForm::typeid));
			this->buttonAddPatient = (gcnew System::Windows::Forms::Button());
			this->mainFormTitleLabel = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->buttonGetPatients = (gcnew System::Windows::Forms::Button());
			this->doctorButton = (gcnew System::Windows::Forms::Button());
			this->iAmPatientButton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonAddPatient
			// 
			this->buttonAddPatient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->buttonAddPatient->Location = System::Drawing::Point(118, 204);
			this->buttonAddPatient->Name = L"buttonAddPatient";
			this->buttonAddPatient->Size = System::Drawing::Size(123, 25);
			this->buttonAddPatient->TabIndex = 0;
			this->buttonAddPatient->Text = L"Add patients";
			this->buttonAddPatient->UseVisualStyleBackColor = true;
			this->buttonAddPatient->Click += gcnew System::EventHandler(this, &MenuForm::buttonAddPatient_Click);
			// 
			// mainFormTitleLabel
			// 
			this->mainFormTitleLabel->AutoSize = true;
			this->mainFormTitleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mainFormTitleLabel->Location = System::Drawing::Point(89, 7);
			this->mainFormTitleLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->mainFormTitleLabel->Name = L"mainFormTitleLabel";
			this->mainFormTitleLabel->Size = System::Drawing::Size(215, 18);
			this->mainFormTitleLabel->TabIndex = 1;
			this->mainFormTitleLabel->Text = L"Medical information system";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(99, 53);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(164, 112);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// buttonGetPatients
			// 
			this->buttonGetPatients->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->buttonGetPatients->Location = System::Drawing::Point(118, 235);
			this->buttonGetPatients->Name = L"buttonGetPatients";
			this->buttonGetPatients->Size = System::Drawing::Size(123, 25);
			this->buttonGetPatients->TabIndex = 3;
			this->buttonGetPatients->Text = L"Get patients";
			this->buttonGetPatients->UseVisualStyleBackColor = true;
			this->buttonGetPatients->Click += gcnew System::EventHandler(this, &MenuForm::buttonGetPatients_Click);
			// 
			// doctorButton
			// 
			this->doctorButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->doctorButton->Location = System::Drawing::Point(118, 266);
			this->doctorButton->Name = L"doctorButton";
			this->doctorButton->Size = System::Drawing::Size(123, 25);
			this->doctorButton->TabIndex = 4;
			this->doctorButton->Text = L"I Am doctor";
			this->doctorButton->UseVisualStyleBackColor = true;
			this->doctorButton->Click += gcnew System::EventHandler(this, &MenuForm::doctorButton_Click);
			// 
			// iAmPatientButton
			// 
			this->iAmPatientButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->iAmPatientButton->Location = System::Drawing::Point(118, 297);
			this->iAmPatientButton->Name = L"iAmPatientButton";
			this->iAmPatientButton->Size = System::Drawing::Size(123, 25);
			this->iAmPatientButton->TabIndex = 5;
			this->iAmPatientButton->Text = L"I Am a patient";
			this->iAmPatientButton->UseVisualStyleBackColor = true;
			this->iAmPatientButton->Click += gcnew System::EventHandler(this, &MenuForm::iAmPatientButton_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(118, 173);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(123, 25);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Add doctor";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MenuForm::button1_Click);
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(149)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)));
			this->ClientSize = System::Drawing::Size(378, 342);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->iAmPatientButton);
			this->Controls->Add(this->doctorButton);
			this->Controls->Add(this->buttonGetPatients);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->mainFormTitleLabel);
			this->Controls->Add(this->buttonAddPatient);
			this->Name = L"MenuForm";
			this->Text = L"MenuForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void buttonAddPatient_Click(System::Object^ sender, System::EventArgs^ e) {
			ClinicMPI::PatientForm^ form = gcnew  ClinicMPI::PatientForm(0);
			form->Show();
		}	

		private: System::Void buttonGetPatients_Click(System::Object^ sender, System::EventArgs^ e) {
			ClinicMPI::PatientForm^ form = gcnew  ClinicMPI::PatientForm(1);
			form->Show();
		}

		private: System::Void doctorButton_Click(System::Object^ sender, System::EventArgs^ e) {

			IAmDoctorForm^ form = gcnew IAmDoctorForm;
			form->Show();
		}

		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			AddDoctorForm^ form = gcnew AddDoctorForm;
			form->Show();
		}

		private: System::Void iAmPatientButton_Click(System::Object^ sender, System::EventArgs^ e) {
			IAmPatientForm^ form = gcnew IAmPatientForm;
			form->Show();
		}
		};
}
