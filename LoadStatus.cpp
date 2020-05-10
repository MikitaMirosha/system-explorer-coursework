#include "CPUData.h"
#include "SystemTime.h"
#include "MemoryData.h"
#include "LoadStatus.h"

void LoadStatus::showLoadStatus()
{
	int cpuUsage;
	CPUData cpuData;
	SystemTime systemTime;
	MemoryData memoryData;

	while (true)
	{	
		systemTime.getSystemTime();
		strftime(systemTime.hours, sizeof(systemTime.hours) / sizeof(systemTime.hours[0]), "%H", systemTime.systemTime);
		strftime(systemTime.minutes, sizeof(systemTime.minutes) / sizeof(systemTime.minutes[0]), "%M", systemTime.systemTime);
		strftime(systemTime.seconds, sizeof(systemTime.seconds) / sizeof(systemTime.seconds[0]), "%S", systemTime.systemTime);
		cpuUsage = cpuData.getCPULoad();

		system("cls");
		cout << "Время: "<< systemTime.hours << ":" << systemTime.minutes << ":" << systemTime.seconds << endl;
		cout << "Загрузка ЦП: " << cpuUsage << "%" << endl;
		memoryData.setMemoryData();
		cout << "Загрузка ОЗУ: " << memoryData.getRAMLoad() << "%" << endl << endl;
		cout << "Esc для выхода";

		if (_kbhit())
		{
			char checkEsc = _getche();
			if (checkEsc == 27) return;
		}
	}
	system("pause");
}