#include "Helper.h"

#include <mpi.h>
#include <Windows.h>
#include <string.h>

const std::string CurrentDateTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	// Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
	// for more information about date/time format
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}

int GetProcessRank()
{
	int process_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &process_rank);

	return process_rank;
}

// TODO - make async
void WriteToFile(std::string& message) {

	HANDLE hOpen = OpenMutex(MUTEX_ALL_ACCESS, FALSE, TEXT("WriteFileMutex1"));

	WaitForSingleObject(hOpen, INFINITE);

	std::ofstream file;
	file.open("test.txt", std::ios::app);
	std::string str = CurrentDateTime() + ": " + std::to_string(GetProcessRank()) + " " + message + "\n----------------------\n";
	file << str;

	ReleaseMutex(hOpen);
	CloseHandle(hOpen);
}



void DoStuff()
{
	WriteToFile(std::string("I am doing STUFF"));
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
