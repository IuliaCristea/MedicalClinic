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
			this->buttonAddPatient = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonAddPatient
			// 
			this->buttonAddPatient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->buttonAddPatient->Location = System::Drawing::Point(80, 107);
			this->buttonAddPatient->Name = L"buttonAddPatient";
			this->buttonAddPatient->Size = System::Drawing::Size(123, 25);
			this->buttonAddPatient->TabIndex = 0;
			this->buttonAddPatient->Text = L"Add patient";
			this->buttonAddPatient->UseVisualStyleBackColor = true;
			this->buttonAddPatient->Click += gcnew System::EventHandler(this, &MenuForm::buttonAddPatient_Click);
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->buttonAddPatient);
			this->Name = L"MenuForm";
			this->Text = L"MenuForm";
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void buttonAddPatient_Click(System::Object^ sender, System::EventArgs^ e) {
			ClinicMPI::PatientForm^ form = gcnew  ClinicMPI::PatientForm;
			form->Show();
		}	
	};
}
