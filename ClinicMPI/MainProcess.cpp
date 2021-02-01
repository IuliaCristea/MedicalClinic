#include "MainProcess.h"
#include "MenuForm.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

void MainProcess::Run()
{
	//Aici dai start la Aplicatia mare, acum dam doar la form-ul asta
	/*Program::PatientForm^ form = gcnew  Program::PatientForm;
	form->Show();*/

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew ClinicMPI::MenuForm());
}
