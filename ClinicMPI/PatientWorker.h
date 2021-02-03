#pragma once
#include <string.h>
#include <iostream>
#include <tuple>
#include <iostream>
#include <string>
#include <tuple>
#include <mysql.h>
#include "mpi.h"
#include "helper.h"

using namespace std;
class PatientWorker
{

public:
	void Run();
	bool Insert(string name, string gender, string address, string cnp, int &numberOfPatientsToAdd);
	tuple<int, string, string, string, string> GetByID(int id);
};

