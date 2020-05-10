#pragma once
#include <iostream>
#include <Windows.h>
#include "PersonalComputer.h"

class DiskData : PersonalComputer
{
public:
	void showDiskData();
	void writeDiskDataIntoFile(ofstream &os);
};