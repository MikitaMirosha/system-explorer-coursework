#include "SystemData.h"

void SystemData::showSystemData()
{
	system("cls");
	getSystemData();
	cout << "�������" << endl << endl;
	cout << "��� ����������: " << computerName << endl;
	cout << "��� ������������: " << userName << endl;
	cout << "��������� �����: " << systemFolder << endl;
	cout << "����� Windows: " << windowsFolder << endl;
	cout << "��������� �����: " << tempFolder << endl;
	system("pause");
}

void SystemData::writeSystemDataIntoFile(ofstream &os)
{
	getSystemData();
	os << "-------------------------------------" << endl;
	os << "�������" << endl << endl;
	os << "��� ����������: " << computerName << endl;
	os << "��� ������������: " << userName << endl;
	os << "��������� �����: " << systemFolder << endl;
	os << "����� Windows: " << windowsFolder << endl;
	os << "��������� �����: " << tempFolder << endl;
}

void SystemData::getSystemData()
{
	char temp[BUFFER];
	DWORD buffer = BUFFER;

	if (GetComputerNameA(temp, &buffer))
		strcpy(computerName, temp);
	if (GetUserNameA(temp, &buffer))
		strcpy(userName, temp);
	if (GetSystemDirectoryA(temp, MAX_PATH + 1))
		strcpy(systemFolder, temp);
	if (GetWindowsDirectoryA(temp, MAX_PATH + 1))
		strcpy(windowsFolder, temp);
	if (GetTempPathA(MAX_PATH + 1, temp))
		strcpy(tempFolder, temp);
}