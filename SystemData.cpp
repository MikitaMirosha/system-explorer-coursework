#include "SystemData.h"

void SystemData::showSystemData()
{
	system("cls");
	getSystemData();
	cout << "СИСТЕМА" << endl << endl;
	cout << "Имя компьютера: " << computerName << endl;
	cout << "Имя пользователя: " << userName << endl;
	cout << "Системная папка: " << systemFolder << endl;
	cout << "Папка Windows: " << windowsFolder << endl;
	cout << "Временная папка: " << tempFolder << endl;
	system("pause");
}

void SystemData::writeSystemDataIntoFile(ofstream &os)
{
	getSystemData();
	os << "-------------------------------------" << endl;
	os << "СИСТЕМА" << endl << endl;
	os << "Имя компьютера: " << computerName << endl;
	os << "Имя пользователя: " << userName << endl;
	os << "Системная папка: " << systemFolder << endl;
	os << "Папка Windows: " << windowsFolder << endl;
	os << "Временная папка: " << tempFolder << endl;
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