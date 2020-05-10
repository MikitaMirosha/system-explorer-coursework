#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <ctime>

class SystemTime
{
public:
	tm *systemTime;
	void getSystemTime();
	char hours[10] = { 0 };
	char minutes[10] = { 0 };
	char seconds[10] = { 0 };
};