#include "SystemTime.h"

void SystemTime::getSystemTime()
{
	time_t tm;
	time(&tm);
	systemTime = localtime(&tm);
}