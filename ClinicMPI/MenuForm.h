#pragma once
#include "PatientForm.h"
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonAddPatient
			// 
			this->buttonAddPatient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->buttonAddPatient->Location = System::Drawing::Point(158, 251);
			this->buttonAddPatient->Margin = System::Windows::Forms::Padding(4);
			this->buttonAddPatient->Name = L"buttonAddPatient";
			this->buttonAddPatient->Size = System::Drawing::Size(164, 31);
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
			this->mainFormTitleLabel->Location = System::Drawing::Point(119, 9);
			this->mainFormTitleLabel->Name = L"mainFormTitleLabel";
			this->mainFormTitleLabel->Size = System::Drawing::Size(262, 24);
			this->mainFormTitleLabel->TabIndex = 1;
			this->mainFormTitleLabel->Text = L"Medical information system";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(132, 65);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(218, 138);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// buttonGetPatients
			// 
			this->buttonGetPatients->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->buttonGetPatients->Location = System::Drawing::Point(158, 311);
			this->buttonGetPatients->Margin = System::Windows::Forms::Padding(4);
			this->buttonGetPatients->Name = L"buttonGetPatients";
			this->buttonGetPatients->Size = System::Drawing::Size(164, 31);
			this->buttonGetPatients->TabIndex = 3;
			this->buttonGetPatients->Text = L"Get patients";
			this->buttonGetPatients->UseVisualStyleBackColor = true;
			this->buttonGetPatients->Click += gcnew System::EventHandler(this, &MenuForm::buttonGetPatients_Click);
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(149)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)));
			this->ClientSize = System::Drawing::Size(504, 421);
			this->Controls->Add(this->buttonGetPatients);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->mainFormTitleLabel);
			this->Controls->Add(this->buttonAddPatient);
			this->Margin = System::Windows::Forms::Padding(4);
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
};
}
