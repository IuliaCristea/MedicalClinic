#pragma once
#include "helper.h"

using namespace std;
class PatientWorker
{

public:
	void Run();
	bool Insert(string name, int& numberOfPatientsToAdd, string address, string cnp);//, int &numberOfPatientsToAdd);
	string GetPatients(int& numberOfPatientsToGet, string name, string id);
	bool PatientWorker::InsertDoctor(string name, string specialty);
	string PatientWorker::GetAllDoctors();
	bool PatientWorker::InsertAppointment(int doctorid, int patientid);
	string PatientWorker::GetAppointmentsByDoctorName(string name);
};

