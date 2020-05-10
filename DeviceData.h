#pragma once
#include "List.h"
#include <iostream>
#include <Windows.h>
#include <SetupAPI.h>
#pragma comment(lib,"SetupAPI.lib")

using namespace std;

class DeviceData : List
{
private:
	HDEVINFO hDevInfo;
	SP_DEVINFO_DATA spDevInfoData;
public:
	void setDeviceData();
	void showDeviceDataList();
	void writeDeviceDataListIntoFile(ofstream& os);
};