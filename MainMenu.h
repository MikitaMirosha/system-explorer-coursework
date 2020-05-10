#pragma once
#include "File.h"
#include <conio.h>
#include <iostream>
#include "CPUData.h"
#include "DiskData.h"
#include "MemoryData.h"
#include "DeviceData.h"
#include "SystemData.h"
#include "ProcessData.h"
#include "NetworkData.h"
#include "LoadStatus.h"
#include "GraphicsData.h"

class MainMenu
{
public:
	void showMainMenu();
	void selectCommand(CPUData &);
};