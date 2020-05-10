#pragma once
#include <iostream>
#include <Windows.h>
#include "PersonalComputer.h"

class MemoryData : public PersonalComputer
{
private:
	MEMORYSTATUS memoryStatus;
public:
	int getRAMLoad();
	void setMemoryData();
	void showMemoryData();
	void writeMemoryDataIntoFile(ofstream& os);
};