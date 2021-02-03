#pragma once
#include<iostream>
#include "mpi.h"
#include "Helper.h"
#include <windows.h>
#include <stdio.h>
#include <conio.h>

class MainProcess
{
	public:
		void Run();

	private:
		void DisplayMenuText();
		void HandleReadPatient();
};

