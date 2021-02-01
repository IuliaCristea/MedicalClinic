#include "PatientWorker.h"


void PatientWorker::Run()
{
	while (true)
	{
		MPI_Status status;
		int option; //1 - insert, 2 - get
		MPI_Recv(&option, 1, MPI_INT, Main, 0, MPI_COMM_WORLD,
			MPI_STATUS_IGNORE);
		bool done = 0;
		if (option == 1)
		{
			char name[1000], address[1000], cnp[1000];
			int gender;

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

			//	cout << cnp;
			done = Insert(name, std::to_string(gender), address, cnp);

			MPI_Send(&done, 1, MPI_INT, Main, 4444, MPI_COMM_WORLD);
			// nu trebuie sa trimiti inapoi?

		}
	}
}

bool PatientWorker::Insert(string name, string gender, string address, string cnp)
{
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);

	conn = mysql_real_connect(conn, "localhost", "root", "resforever123!", "medicalclinic", 3306, NULL, 0);

	if (conn) {

		char buffer[1000];
		sprintf_s(buffer, "insert into patient (name, gender, address, cnp) values ('%s', '%s', '%s', '%s')", name.c_str(), gender.c_str(), address.c_str(), cnp.c_str());
		int qstate;
		qstate = mysql_query(conn, buffer);
		if (!qstate)
		{
			return true;

		}
		else
		{
			//cout << "Query failed: " << mysql_error(conn) << endl;
			return false;
		}

	}
	else
	{
		return false;
	}
}