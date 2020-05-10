#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <windows.h>
#include "PersonalComputer.h"
#define BUFFER 1000

class SystemData : public PersonalComputer
{
private:
	char userName[BUFFER];
	char computerName[BUFFER];
	char tempFolder[BUFFER];
	char systemFolder[BUFFER];
	char windowsFolder[BUFFER];
public:
	void getSystemData();
	void showSystemData();
	void writeSystemDataIntoFile(ofstream& os);
};