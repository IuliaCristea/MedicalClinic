#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <chrono>
#include <thread>
#include <string.h>
#include <string>
#include <tuple>
#include <mysql.h>
#include "mpi.h"

enum ProcessRanks
{
	Main,
	PatientW,
	DoctorW,
	AppointmentW,
	ClinicW,
	EvaluationW
};

enum PatientOptions
{
	InsertMultiple,
	GetMultiple,
	//GetById
};

int GetProcessRank();
void DoStuff();
const std::string CurrentDateTime();
void WriteToFile(std::string&);
