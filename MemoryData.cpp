#include "MemoryData.h"

unsigned long MB = 1024 * 1024;

void MemoryData::showMemoryData()
{
	system("cls");
	setMemoryData();
	cout << "����������� ������" << endl << endl;
	cout << "���������� ������" << endl;
	cout << "��������: " << memoryStatus.dwMemoryLoad << "%" << endl;
	cout << "��������: " << memoryStatus.dwAvailPhys / MB << " ��" << endl;
	cout << "�����: " << memoryStatus.dwTotalPhys / MB << " ��" << endl << endl;
	cout << "����������� ������" << endl;
	cout << "��������: " << memoryStatus.dwAvailPageFile / MB << " ��" << endl;
	cout << "�����: " << memoryStatus.dwTotalPageFile / MB << " ��" << endl;
	system("pause");
}

void MemoryData::writeMemoryDataIntoFile(ofstream &os)
{
	setMemoryData();
	os << "-------------------------------------" << endl;
	os << "����������� ������" << endl << endl;
	os << "���������� ������" << endl;
	os << "��������: " << memoryStatus.dwMemoryLoad << "%" << endl;
	os << "��������: " << memoryStatus.dwAvailPhys / MB << " ��" << endl;
	os << "�����: " << memoryStatus.dwTotalPhys / MB << " ��" << endl << endl;
	os << "����������� ������" << endl;
	os << "��������: " << memoryStatus.dwAvailPageFile / MB << " ��" << endl << endl;
	os << "�����: " << memoryStatus.dwTotalPageFile / MB << " ��" << endl;
}

void MemoryData::setMemoryData()
{
	GlobalMemoryStatus(&memoryStatus);
}

int MemoryData::getRAMLoad()
{
	return memoryStatus.dwMemoryLoad;
}