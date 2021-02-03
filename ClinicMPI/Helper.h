#pragma once
#include <ctime>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

enum ProcessRanks
{
	Main,
	PatientW,
	DoctorW,
	AppointmentW,
	ClinicW,
	EvaluationW
};

int GetProcessRank();
void DoStuff();
const std::string CurrentDateTime();
void WriteToFile(std::string&);
