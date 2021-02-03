#include <fstream>
#include "PatientWorker.h"
#include "Helper.h"
//#include <future>



void PatientWorker::Run()
{
	while (true)
	{
		int option; //1 - insert, 2 - get
		MPI_Recv(&option, 1, MPI_INT, Main, 0, MPI_COMM_WORLD,
			MPI_STATUS_IGNORE);
		
		bool done = 0;
		if (option == 1)
		{
			char name[1000], address[1000], cnp[1000];
			int gender, numberOfPatientsToAdd;

			MPI_Recv(name, 1000, MPI_CHAR, Main, 1, MPI_COMM_WORLD,
				MPI_STATUS_IGNORE);

			//cout << name;

			MPI_Recv(&gender, 1, MPI_INT, Main, 2, MPI_COMM_WORLD,
				MPI_STATUS_IGNORE);

			MPI_Recv(address, 1000, MPI_CHAR, Main, 3, MPI_COMM_WORLD,
				MPI_STATUS_IGNORE);

			//	cout << address;

			MPI_Recv(cnp, 1000, MPI_CHAR, Main, 4, MPI_COMM_WORLD,
				MPI_STATUS_IGNORE);


			MPI_Recv(&numberOfPatientsToAdd, 1, MPI_INT, Main, 5, MPI_COMM_WORLD,
				MPI_STATUS_IGNORE);

			//	cout << cnp;
			//std::thread new_thread(DoStuff);
			//new_thread.join();
			// spawn new thread that calls foo()
			for (int i = 1; i <= numberOfPatientsToAdd; i++)
			{
				DoStuff;
			}

			done = Insert(name, std::to_string(gender), address, cnp, numberOfPatientsToAdd);
			//WriteToFile(string("The DB RESULT IS: " + to_string(done)));

			MPI_Send(&done, 1, MPI_INT, Main, 4444, MPI_COMM_WORLD);
			//			MPI_Isend(&done, 1, MPI_INT, Main, 4444, MPI_COMM_WORLD,&adsa);

			// nu trebuie sa trimiti inapoi?

		}
	}
}

bool PatientWorker::Insert(string name, string gender, string address, string cnp, int &numberOfPatientsToAdd)
{
	srand((int)time(0));
	cnp = cnp + to_string(rand() % 1000);
	
	HANDLE hOpen = OpenMutex(MUTEX_ALL_ACCESS,FALSE,TEXT("FDBMutexName1"));
	if (hOpen == NULL)
	{
		WriteToFile("OpenMutex error!!: %d " + std::to_string(GetLastError()));
		return false;
	}	
	else
		WriteToFile(string("OpenMutex successfully"));
	
	WaitForSingleObject(hOpen, INFINITE);
	bool isSuccessful = false;
	
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);

	conn = mysql_real_connect(conn, "localhost", "root", "44880", "medicalclinic", 3306, NULL, 0);


	if (conn) {

		char buffer[1000];
		int qstate;


		for(int i = 1; i <= numberOfPatientsToAdd; i++)
		{			
			sprintf_s(buffer, "insert into patient (name, gender, address, cnp) values ('%s', '%s', '%s', '%s')", 
				name.c_str() + to_string(i), gender.c_str() + to_string(i), address.c_str() + to_string(i), cnp.c_str() + to_string(i) + "_" + to_string(GetProcessRank()));
			qstate = mysql_query(conn, buffer);
			
			//WriteToFile(string("qstate: " + to_string(qstate) + " --  i= " + to_string(i)));

			if (!qstate)
			{
				isSuccessful = true;
			}
			else
			{
				isSuccessful = false;
				break;
			}
		}
	}

	WriteToFile(string("Before release mutex!"));
	ReleaseMutex(hOpen);
	CloseHandle(hOpen);
	
	return isSuccessful;
}