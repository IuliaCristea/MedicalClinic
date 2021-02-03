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
	HANDLE  ghMutex, ghMutex2;

	MPI_Init(NULL, NULL);

	int rank, numprocs;
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

		if (rank == 0)
		{			
			ghMutex = NULL;
			ghMutex = CreateMutex(
				NULL,
				FALSE,
				TEXT("FDBMutexName2"));


			if (ghMutex == NULL)
			{
				std::ofstream file;
				file.open("test.txt", std::ios::app);
				std::string str = CurrentDateTime() + ": Mutex Creation Failed- DB" + "\n----------------------\n";
				file << str;

				return 1;
			}
			else
			{
				std::ofstream file;
				file.open("test.txt", std::ios::app);
				std::string str = CurrentDateTime() + ":Mutex Successfully Created- DB" + "\n----------------------\n";
				file << str;
			}


	
			ghMutex2 = CreateMutex(
				NULL,
				FALSE,
				TEXT("WriteFileMutex1"));

			if (ghMutex2 == NULL)
			{
				std::ofstream file;
				file.open("test.txt", std::ios::app);
				std::string str = CurrentDateTime() + ": Mutex Creation failed - WriteFileMutex" + "\n----------------------\n";
				file << str;

				return 1;
			}
			else
			{
				std::ofstream file;
				file.open("test.txt", std::ios::app);
				std::string str = CurrentDateTime() + ":Mutex Successfuly Created- WriteFileMutex" + "\n----------------------\n";
				file << str;
			}






			MainProcess proc;
			proc.Run();
			//std::cout << "MAIN";

			/*Application::EnableVisualStyles();
			Application::SetCompatibleTextRenderingDefault(false);
			Application::Run(gcnew Program::PatientForm());*/
		}
		else
		{
	
			PatientWorker worker;
			worker.Run();
		}
	

	MPI_Finalize();
	if (ghMutex != NULL)
	{
		CloseHandle(ghMutex);
	}
	if (ghMutex2 != NULL)
	{
		CloseHandle(ghMutex);
	}
}
