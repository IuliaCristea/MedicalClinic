#include <fstream>
#include "PatientWorker.h"
#include <sstream>
#include "Helper.h"
//#include <future>



void PatientWorker::Run()
{
	while (true)
	{
		int option; //1 - insert, 2 - get
		MPI_Recv(&option, 1, MPI_INT, Main, 0, MPI_COMM_WORLD,
			MPI_STATUS_IGNORE);

		string result = "";
		bool done = 0;
		
		switch (option) {
			case InsertMultiple: 
			{
				WriteToFile(string("Insert Multiple Case "));

				char name[1000], address[1000], cnp[1000];
				int numberOfPatientsToAdd;

				MPI_Recv(name, 1000, MPI_CHAR, Main, 1, MPI_COMM_WORLD,
					MPI_STATUS_IGNORE);

				MPI_Recv(&numberOfPatientsToAdd, 1, MPI_INT, Main, 2, MPI_COMM_WORLD,
					MPI_STATUS_IGNORE);

				MPI_Recv(address, 1000, MPI_CHAR, Main, 3, MPI_COMM_WORLD,
					MPI_STATUS_IGNORE);

				MPI_Recv(cnp, 1000, MPI_CHAR, Main, 4, MPI_COMM_WORLD,
					MPI_STATUS_IGNORE);

				/*MPI_Recv(&numberOfPatientsToAdd, 1, MPI_INT, Main, 5, MPI_COMM_WORLD,MPI_STATUS_IGNORE);*/

				for (int i = 1; i <= numberOfPatientsToAdd; i++)
				{
					DoStuff();
				}

				done = Insert(name, numberOfPatientsToAdd, address, cnp);//, numberOfPatientsToAdd);
				//WriteToFile(string("The DB RESULT IS: " + to_string(done)));

				MPI_Send(&done, 1, MPI_INT, Main, 4444, MPI_COMM_WORLD);
				//			MPI_Isend(&done, 1, MPI_INT, Main, 4444, MPI_COMM_WORLD,&adsa);
			}
			case GetMultiple:
			{
				WriteToFile(string("GET MULTIPLE Case "));

				int numberOfPatientsToGet = 0;
				char name[100], id[100];
				MPI_Recv(&numberOfPatientsToGet, 1, MPI_INT, Main, 1, MPI_COMM_WORLD,
					MPI_STATUS_IGNORE);

				MPI_Recv(name, 100, MPI_CHAR, Main, 2, MPI_COMM_WORLD,
					MPI_STATUS_IGNORE);
					
				MPI_Recv(id, 100, MPI_CHAR, Main, 3, MPI_COMM_WORLD,
					MPI_STATUS_IGNORE);

				result = GetPatients(numberOfPatientsToGet, name, id);
					
				MPI_Send(result.c_str(), result.length() + 1,MPI_CHAR, Main, 4, MPI_COMM_WORLD);
				break;
			}
			/*case GetById:
			{
				WriteToFile(string("GetById Case "));
				break;
			}*/
			default:
			{
				WriteToFile(string("Something Went Wrong = Default Case "));
				break;
			}
		}
	}
}

string PatientWorker::GetPatients(int& numberOfPatientsToGet, string name, string id)//, int &numberOfPatientsToAdd)
{

	WriteToFile(string("connnumberOfPatientsToGet " + to_string(numberOfPatientsToGet) + "name " + name + "id " + id));

	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);
	string result;
	
	conn = mysql_real_connect(conn, "localhost", "root", "resforever123!", "medicalclinic", 3306, NULL, 0);
	WriteToFile(string("conn----------- " + to_string(conn == NULL)));

	HANDLE hOpen = OpenMutex(MUTEX_ALL_ACCESS, FALSE, TEXT("FDBMutexName2"));
	if (hOpen == NULL)
	{
		WriteToFile("OpenMutex error!!: %d " + std::to_string(GetLastError()));
		return "";
	}
	else
		WriteToFile(string("OpenMutex successfully"));

	WaitForSingleObject(hOpen, INFINITE);
	WriteToFile(string("MUTEX AQUIRED"));

	if (conn) {

		char query[1000];
		int qstate, max5Counter = 0;
		string resultFromGet;
		stringstream resultStringStream;
		WriteToFile(string("numberOfPatientsToGet " + to_string(numberOfPatientsToGet)));
		WriteToFile(string("Execute GET-------------------"));

		if((id.length() <= 0 && (name.length() <= 0))) {
			sprintf_s(query, "SELECT * FROM patient ORDER BY name asc limit %d", numberOfPatientsToGet);
		}
		else if (id.length() <= 0)
		{
			sprintf_s(query, "SELECT * FROM patient WHERE name LIKE '%%%s%%' ORDER BY name asc limit %d", name, numberOfPatientsToGet);
		}
		else if (name.length() <= 0)
		{
			sprintf_s(query, "SELECT * FROM patient WHERE patientid LIKE '%%%s%%' ORDER BY name asc limit %d", id, numberOfPatientsToGet);
		}
		else
		{
			sprintf_s(query, "SELECT * FROM patient WHERE patientid LIKE '%%%s%%' OR name LIKE '%%%s%%' ORDER BY name asc limit %d", id, name, numberOfPatientsToGet);
		}

		/*resultStringStream << query;
		WriteToFile(resultStringStream.str());*/
		qstate = mysql_query(conn, query);

		// If failed, return empty string
		if (qstate)
		{
			WriteToFile(string("exited QSTATE"));
			return "";			
		}
		res = mysql_store_result(conn);

		// Get the number of the columns
		int num_fields = mysql_num_fields(res);

		WriteToFile(string("num_fields  " + to_string(num_fields)));

		// Fetch all rows from the result
		while ((row = mysql_fetch_row(res)))
		{
			// Print all columns
			for (int i = 0; i < num_fields; i++)
			{
				max5Counter++;
				if (max5Counter == 6)
				{
					resultStringStream << std::endl;
					max5Counter = 1;
				}
				// Make sure row[i] is valid!
				if (row[i] != NULL)
				{				
					resultStringStream << row[i] << '\t';
				}
				else
				{
					resultStringStream << "NULL" << '\t';
				}
			}
		}
		result = resultStringStream.str();

		// Clear String Stream
		resultStringStream.clear();
		resultStringStream.str(std::string());
		
		WriteToFile(string("result is: " +result));
		
		// Clear Results
		if (res != NULL)
			mysql_free_result(res);
	}

	WriteToFile(string("Release mutex!"));
	ReleaseMutex(hOpen);
	WriteToFile(string("Close Handle"));
	CloseHandle(hOpen);

	return result;
}

bool PatientWorker::Insert(string name, int& numberOfPatientsToAdd, string address, string cnp)//, int &numberOfPatientsToAdd)
{
	// randomize cnp
	srand((int)time(0));
	cnp = cnp + to_string(rand() % 1000);

	bool isSuccessful = false;
	char genderNumberChar = cnp.at(0);
	string gender;
	if (genderNumberChar == '1' || genderNumberChar == '5')
	{
		gender = "Masculin";
	}
	else
	{
		gender = "Feminin";
	}		
	
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);

	conn = mysql_real_connect(conn, "localhost", "root", "resforever123!", "medicalclinic", 3306, NULL, 0);
	WriteToFile(string("conn----------- " + to_string(conn== NULL)));


	HANDLE hOpen = OpenMutex(MUTEX_ALL_ACCESS, FALSE, TEXT("FDBMutexName2"));
	if (hOpen == NULL)
	{
		WriteToFile("OpenMutex error!!: %d " + std::to_string(GetLastError()));
		return false;
	}
	else
		WriteToFile(string("OpenMutex successfully"));

	WaitForSingleObject(hOpen, INFINITE);

	WriteToFile(string("MUTEX AQUIRED"));


	if (conn) {

		char buffer[1000];
		int qstate;

		WriteToFile(string("numberOfPatientsToAdd----------- " + to_string(numberOfPatientsToAdd)));
		for(int i = 1; i <= numberOfPatientsToAdd; i++)
		{			
			WriteToFile(string("Execute INSERT"));
			sprintf_s(buffer, "insert into patient (name, gender, address, cnp) values ('%s', '%s', '%s', '%s')", 
				name.c_str() + string("_") + to_string(i), gender.c_str(), address.c_str() + string("_") + to_string(i), cnp.c_str() + string("_") + to_string(i) + "_" + to_string(GetProcessRank()));
			qstate = mysql_query(conn, buffer);
			
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

	WriteToFile(string("Release mutex!"));
	ReleaseMutex(hOpen);
	WriteToFile(string("Close Handle"));
	CloseHandle(hOpen);
	
	return isSuccessful;
}