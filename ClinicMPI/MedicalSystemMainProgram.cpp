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
	
	HANDLE  ghMutex = NULL;
	ghMutex = CreateMutex(
		NULL,
		FALSE,
		TEXT("FDBMutexName1"));

	MPI_Init(NULL, NULL);

	if (ghMutex == NULL)
	{
		WriteToFile(string("failed to create DBMutex, end process"));
		return 1;
	}
	else
	{
		WriteToFile(string("ok create DBMutex"));
	}
	
	int rank, numprocs;
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	/*if (numprocs != 6)
	{
		std::cout << "Wrong number of procs";

		CloseHandle(ghMutex);
		return 1;
	}*/

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

		if (rank == 0)
		{			
			MainProcess proc;
			proc.Run();
			//std::cout << "MAIN";

			/*Application::EnableVisualStyles();
			Application::SetCompatibleTextRenderingDefault(false);
			Application::Run(gcnew Program::PatientForm());*/
		}
		else
		{
			WriteToFile(string("Before start patient worker"));
			
			PatientWorker worker;
			worker.Run();
		}
	

	MPI_Finalize();
	if (ghMutex != NULL)
	{
		CloseHandle(ghMutex);
	}
}
