#pragma once
#include <tchar.h>
#include <iostream>
#include <Windows.h>
#include <WinInet.h>
#include "PersonalComputer.h"
#pragma comment(lib,"wsock32.lib")
#pragma comment(lib, "Wininet.lib")

class NetworkData : public PersonalComputer
{
private:
	WSADATA WSAData;
public:
	void showNetworkData();
	void writeNetworkDataIntoFile(ofstream & os);
};