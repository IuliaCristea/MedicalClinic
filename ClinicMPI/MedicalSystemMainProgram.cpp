// MedicalSystemMainProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "mpi.h"
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include "MainProcess.h"
#include "Helper.h"
#include "PatientWorker.h"
#include "PatientForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main()
{

	HANDLE  ghMutex = CreateMutex(
		NULL,
		FALSE,
		TEXT("DBMutexName"));

	if (ghMutex == NULL)
	{
		std::cout << "failed to create DBMutex, end process";
		return 1;
	}

	MPI_Init(NULL, NULL);

	int rank, numprocs;
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	/*if (numprocs != 6)
	{
		std::cout << "Wrong number of procs";

		CloseHandle(ghMutex);
		return 1;
	}*/

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	switch (rank)
	{
	case Main:
	{
		MainProcess proc;
		proc.Run();
		//std::cout << "MAIN";

		/*Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		Application::Run(gcnew Program::PatientForm());*/
		break;
	}
	case PatientW:
	{
		PatientWorker worker;
		worker.Run();
		break;
	}
	case DoctorW:
	{
		break;
	}
	case AppointmentW:
	{
		break;
	}
	case ClinicW:
	{
		break;
	}
	case EvaluationW:
	{
		break;
	}
	default:
		std::cout << "fail";
	}

	MPI_Finalize();
	CloseHandle(ghMutex);
}
