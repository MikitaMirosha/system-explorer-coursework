#include "MemoryData.h"

unsigned long MB = 1024 * 1024;

void MemoryData::showMemoryData()
{
	system("cls");
	setMemoryData();
	cout << "ОПЕРАТИВНАЯ ПАМЯТЬ" << endl << endl;
	cout << "Физическая память" << endl;
	cout << "Загрузка: " << memoryStatus.dwMemoryLoad << "%" << endl;
	cout << "Свободно: " << memoryStatus.dwAvailPhys / MB << " МБ" << endl;
	cout << "Всего: " << memoryStatus.dwTotalPhys / MB << " МБ" << endl << endl;
	cout << "Виртуальная память" << endl;
	cout << "Свободно: " << memoryStatus.dwAvailPageFile / MB << " МБ" << endl;
	cout << "Всего: " << memoryStatus.dwTotalPageFile / MB << " МБ" << endl;
	system("pause");
}

void MemoryData::writeMemoryDataIntoFile(ofstream &os)
{
	setMemoryData();
	os << "-------------------------------------" << endl;
	os << "ОПЕРАТИВНАЯ ПАМЯТЬ" << endl << endl;
	os << "Физическая память" << endl;
	os << "Загрузка: " << memoryStatus.dwMemoryLoad << "%" << endl;
	os << "Свободно: " << memoryStatus.dwAvailPhys / MB << " МБ" << endl;
	os << "Всего: " << memoryStatus.dwTotalPhys / MB << " МБ" << endl << endl;
	os << "Виртуальная память" << endl;
	os << "Свободно: " << memoryStatus.dwAvailPageFile / MB << " МБ" << endl << endl;
	os << "Всего: " << memoryStatus.dwTotalPageFile / MB << " МБ" << endl;
}

void MemoryData::setMemoryData()
{
	GlobalMemoryStatus(&memoryStatus);
}

int MemoryData::getRAMLoad()
{
	return memoryStatus.dwMemoryLoad;
}