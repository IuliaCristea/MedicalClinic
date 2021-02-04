#pragma once
#include "helper.h"

using namespace std;
class PatientWorker
{

public:
	void Run();
	bool Insert(string name, int& numberOfPatientsToAdd, string address, string cnp);//, int &numberOfPatientsToAdd);
	string GetPatients(int& numberOfPatientsToGet, string name, string id);
	tuple<int, string, string, string, string> GetByID(int id);
};

