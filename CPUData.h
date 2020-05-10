#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include "PersonalComputer.h"

#define DELAY 700

class CPUData : public PersonalComputer
{
private:
	string processorName;
	string producerName;
	SYSTEM_INFO systemInfo;
	int numberOfCores;
	int sourceFrequency; 
	int L2;
	int L3;
public:
	int getCPULoad();
	void getCPUData();
	void showCPUData();
	ULONGLONG ft2ull(FILETIME& ft);
	void writeCPUDataIntoFile(ofstream &os);
};