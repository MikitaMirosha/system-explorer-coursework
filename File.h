#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "CPUData.h"
#include "DiskData.h"
#include "MemoryData.h"
#include "SystemData.h"
#include "DeviceData.h"
#include "SystemTime.h"
#include "NetworkData.h"
#include "ProcessData.h"
#include "GraphicsData.h"

class File
{
private:
	ofstream os;
public:
	void saveDataIntoFile(CPUData &cpuData);
};