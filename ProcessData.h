#pragma once
#include "List.h"
#include <iostream>
#include <windows.h>
#include <TlHelp32.h>

using namespace std;

class ProcessData : List
{
public:
	void showProcessDataList();
	void writeProcessDataListIntoFile(ofstream & os);
};