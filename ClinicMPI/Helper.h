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
	AddDoctor,
	AddAppointment,
	AllDoctors,
	AppointmentByDoctor
	//GetById
};

int GetProcessRank();
void DoStuff();
const std::string CurrentDateTime();
void WriteToFile(std::string&);
static int cnt = 0;
static int GetNextProcId()
{
	int rank, numprocs;
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	//sub mutex
	if (rank == 0)
	{
		cnt++;
		return cnt % numprocs;
	}

	return -1;
}
