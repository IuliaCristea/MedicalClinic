#include <fstream>
#include "PatientWorker.h"
#include <sstream>
#include "Helper.h"
#include<tuple>
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
			case AddDoctor:
			{

				char name[1000], speciality[1000];

				MPI_Recv(name, 1000, MPI_CHAR, Main, 1, MPI_COMM_WORLD,
					MPI_STATUS_IGNORE);

				MPI_Recv(speciality, 1000, MPI_CHAR, Main, 2, MPI_COMM_WORLD,
					MPI_STATUS_IGNORE);

				int res = 0;
				if (InsertDoctor(name, speciality))
				{
					res = 1;
				}

				MPI_Send(&res, 1, MPI_INT, Main, 3, MPI_COMM_WORLD);

				break;
			}
			case AllDoctors:
			{
				GetAllDoctors();
				break;
			}
			case AddAppointment:
			{

				int docId, patId;

				MPI_Recv(&docId, 1, MPI_INT, Main, 1, MPI_COMM_WORLD,
					MPI_STATUS_IGNORE);


				MPI_Recv(&patId, 1, MPI_INT, Main, 2, MPI_COMM_WORLD,
					MPI_STATUS_IGNORE);


				int res = 0;
				if (InsertAppointment(docId, patId))
				{
					res = 1;
				}

				MPI_Send(&res, 1, MPI_INT, Main, 3, MPI_COMM_WORLD);

				break;
			}
			case AppointmentByDoctor:
			{
				char name[1000];

				MPI_Recv(name, 1000, MPI_CHAR, Main, 1, MPI_COMM_WORLD,
					MPI_STATUS_IGNORE);
				WriteToFile(string("Name : ") + string(name));
				GetAppointmentsByDoctorName(name);
				break;
			}
			default:
			{
				WriteToFile(string("Something Went Wrong = Default Case "));
				break;
			}
		}
	}
}


string PatientWorker::GetAppointmentsByDoctorName(string name)
{
	bool isSuccessful = false;
	int qstate, max5Counter = 0;
	string resultFromGet;
	stringstream resultStringStream;
	string result;

	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);

	conn = mysql_real_connect(conn, "localhost", "root", "resforever123!", "medicalclinic", 3306, NULL, 0);
	WriteToFile(string("conn----------- " + to_string(conn == NULL)));


	HANDLE hOpen = OpenMutex(MUTEX_ALL_ACCESS, FALSE, TEXT("FDBMutexName2"));
	if (hOpen == NULL)
	{
		WriteToFile("OpenMutex error!!: %d " + std::to_string(GetLastError()));
		return false;
	}
	else
	{
		WriteToFile(string("OpenMutex successfully"));
	}

	WaitForSingleObject(hOpen, INFINITE);
	WriteToFile(string("MUTEX AQUIRED"));

	tuple<string, string> results[1000];
	int rowNum = 0;

	if (conn) {

		char buffer[1000];
		int qstate;

		WriteToFile(string("Execute get appointment by doctor name"));
		sprintf_s(buffer, "select a.date, p.name from appointment a join doctor d on (a.doctorid = d.doctorid) join patient p on (p.patientid = a.patientid)  where d.name like '%s'", name.c_str());
		WriteToFile(string(buffer));
		qstate = mysql_query(conn, buffer);

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

			results[rowNum] = make_tuple(row[0], row[1]); //date, name
			WriteToFile(string("row result is: ") + row[0] + " " + row[1]);

			rowNum++;
		}
		result = resultStringStream.str();

		// Clear String Stream
		resultStringStream.clear();
		resultStringStream.str(std::string());

		WriteToFile(string("result is: " + to_string(rowNum)));

		// Clear Results
		if (res != NULL)
			mysql_free_result(res);
	}


	WriteToFile(string("Release mutex!"));
	ReleaseMutex(hOpen);
	WriteToFile(string("Close Handle"));
	CloseHandle(hOpen);

	MPI_Send(&rowNum, 1, MPI_INT, Main, 2, MPI_COMM_WORLD);

	for (int i = 0; i < rowNum; i++)
	{
		WriteToFile(string("we are sending: ") + (get<1>(results[i])).c_str() + " " + (get<0>(results[i])).c_str());

		MPI_Send((get<1>(results[i])).c_str(), (get<1>(results[i])).length() + 1, MPI_CHAR, Main, 3, MPI_COMM_WORLD); //name
		MPI_Send((get<0>(results[i])).c_str(), (get<0>(results[i])).length() + 1, MPI_CHAR, Main, 4, MPI_COMM_WORLD); //date
	}

	return result;
}

bool PatientWorker::InsertAppointment(int doctorid, int patientid)
{
	bool isSuccessful = false;
	char date[50] = "2021-02-05";
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);

	conn = mysql_real_connect(conn, "localhost", "root", "resforever123!", "medicalclinic", 3306, NULL, 0);
	WriteToFile(string("conn----------- " + to_string(conn == NULL)));


	HANDLE hOpen = OpenMutex(MUTEX_ALL_ACCESS, FALSE, TEXT("FDBMutexName2"));
	if (hOpen == NULL)
	{
		WriteToFile("OpenMutex error!!: %d " + std::to_string(GetLastError()));
		return false;
	}
	else
	{
		WriteToFile(string("OpenMutex successfully"));
	}

	WaitForSingleObject(hOpen, INFINITE);
	WriteToFile(string("MUTEX AQUIRED"));

	if (conn) {

		char buffer[1000];
		char dateTxt[1000] = "STR_TO_DATE('2021-02-05', '%Y-%m-%d')";
		int qstate;

		WriteToFile(string("Execute INSERT appointment"));
		sprintf_s(buffer, "insert into appointment (doctorid, patientid, date) values ('%d', '%d', %s)",
			doctorid, patientid, dateTxt);
		qstate = mysql_query(conn, buffer);

		if (!qstate)
		{
			isSuccessful = true;
		}
	
	}

	WriteToFile(string("Release mutex!"));
	ReleaseMutex(hOpen);
	WriteToFile(string("Close Handle"));
	CloseHandle(hOpen);

	return isSuccessful;
}


string PatientWorker::GetAllDoctors(){

	bool isSuccessful = false;
	int qstate, max5Counter = 0;
	string resultFromGet;
	stringstream resultStringStream;
	string result;

	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);
	int rowNum = 0;
	conn = mysql_real_connect(conn, "localhost", "root", "resforever123!", "medicalclinic", 3306, NULL, 0);
	WriteToFile(string("conn----------- " + to_string(conn == NULL)));

	tuple<int, string, string> results[1000];

	HANDLE hOpen = OpenMutex(MUTEX_ALL_ACCESS, FALSE, TEXT("FDBMutexName2"));
	if (hOpen == NULL)
	{
		WriteToFile("OpenMutex error!!: %d " + std::to_string(GetLastError()));
		return false;
	}
	else
	{
		WriteToFile(string("OpenMutex successfully"));
	}

	WaitForSingleObject(hOpen, INFINITE);
	WriteToFile(string("MUTEX AQUIRED"));

	if (conn) {

		char buffer[1000];
		int qstate;

		WriteToFile(string("Execute get all doctors"));
		sprintf_s(buffer, "select doctorid, name, specialty from doctor");
		qstate = mysql_query(conn, buffer);

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
			results[rowNum] = make_tuple(std::stoi(row[0]), row[1], row[2]);
			rowNum++;
		}

		// Clear Results
		if (res != NULL)
			mysql_free_result(res);
	}


	WriteToFile(string("Release mutex!"));
	ReleaseMutex(hOpen);
	WriteToFile(string("Close Handle"));
	CloseHandle(hOpen);

	MPI_Send(&rowNum, 1, MPI_INT, Main, 1, MPI_COMM_WORLD);

	for (int i = 0; i < rowNum; i++)
	{

		MPI_Send(&(get<0>(results[i])), 1, MPI_INT, Main, 2, MPI_COMM_WORLD);
		MPI_Send((get<1>(results[i])).c_str(), (get<1>(results[i])).length() + 1, MPI_CHAR, Main, 3, MPI_COMM_WORLD);
		MPI_Send((get<2>(results[i])).c_str(), (get<2>(results[i])).length() + 1, MPI_CHAR, Main, 4, MPI_COMM_WORLD);

	}


	return result;
}


bool PatientWorker::InsertDoctor(string name, string specialty)
{
	// randomize clinic id
	int clinicID = 3;
	string gender = "male";

	bool isSuccessful = false;

	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);

	conn = mysql_real_connect(conn, "localhost", "root", "resforever123!", "medicalclinic", 3306, NULL, 0);
	WriteToFile(string("conn----------- " + to_string(conn == NULL)));


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

		WriteToFile(string("Execute INSERT doctor"));

		sprintf_s(buffer, "insert into doctor (name, gender, specialty, clinicid) values ('%s', '%s', '%s', '%d')",
			name.c_str(), "male", specialty.c_str(), clinicID);

		qstate = mysql_query(conn, buffer);

		if (!qstate)
		{
			isSuccessful = true;
		}
	}

	WriteToFile(string("Release mutex!"));
	ReleaseMutex(hOpen);
	WriteToFile(string("Close Handle"));
	CloseHandle(hOpen);

	return isSuccessful;
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