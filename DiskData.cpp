#include "DiskData.h"

void DiskData::showDiskData()
{
	system("cls");
	int diskCounter = 0;
	int size = GetLogicalDriveStrings(NULL, 0);
	TCHAR* logicalDrives = new TCHAR[size];
	GetLogicalDriveStrings(size, logicalDrives);

	cout << "�����" << endl << endl;
	while (*logicalDrives)
	{
		TCHAR diskName[80];
		lstrcpy(diskName, logicalDrives);
		UINT uDriveType = GetDriveType(diskName);

		diskCounter = diskCounter + 1; 
		cout << "���� " << diskName << " - "; 

		switch (GetDriveType(diskName))
		{
			case DRIVE_UNKNOWN: cout << "����������� ����" << endl; break;
			case DRIVE_NO_ROOT_DIR: cout << "�� ����������" << endl; break;
			case DRIVE_REMOVABLE: cout << "������� ����" << endl; break;
			case DRIVE_FIXED: cout << "������������� ����" << endl; break;
			case DRIVE_REMOTE: cout << "network-����" << endl; break;
			case DRIVE_CDROM: cout << "CD-ROM" << endl; break;
			case DRIVE_RAMDISK: cout << "RAM-����" << endl; break;
		}

		__int64 freeSpace = 0, totalSpace = 0;
		GetDiskFreeSpaceEx(diskName, NULL, (PULARGE_INTEGER)&totalSpace, (PULARGE_INTEGER)&freeSpace); // ����������� ������  
		cout << "����� �����: " << totalSpace / (1024 * 1024) << " ��" << endl;
		cout << "��������: " << freeSpace / (1024 * 1024) << " ��" << endl;
		cout << "������: " << (totalSpace - freeSpace) / (1024 * 1024) << " ��" << endl;

		char fileSystemName[30];
		BOOL getVolumeInformationFlag = GetVolumeInformationA((LPCTSTR)diskName, NULL, 100, NULL, NULL, NULL, fileSystemName, 100);
		if (getVolumeInformationFlag != 0)
		{
			cout << "�������� �������: " << fileSystemName << endl << endl;
		}
		else
		{
			cout << "�������� ������� �� ����������" << endl << endl;
		}

		while (*logicalDrives) logicalDrives++;
		logicalDrives++;
	}

	system("pause");
}

void DiskData::writeDiskDataIntoFile(ofstream &os)
{
	int diskCounter = 0;
    int size = GetLogicalDriveStrings(NULL, 0);
	TCHAR* logicalDrives = new TCHAR[size];
	GetLogicalDriveStrings(size, logicalDrives);

	os << "-------------------------------------" << endl;
	os << "�����" << endl << endl;
	while (*logicalDrives)
	{
		TCHAR diskName[80];
		lstrcpy(diskName, logicalDrives);
		UINT uDriveType = GetDriveType(diskName);

		diskCounter = diskCounter + 1; 
		os << "���� " << diskName << " - "; 

		switch (GetDriveType(diskName))
		{
			case DRIVE_UNKNOWN: os << "����������� ����" << endl; break;
			case DRIVE_NO_ROOT_DIR: os << "�� ����������" << endl; break;
			case DRIVE_REMOVABLE: os << "������� ����" << endl; break;
			case DRIVE_FIXED: os << "������������� ����" << endl; break;
			case DRIVE_REMOTE: os << "network-����" << endl; break;
			case DRIVE_CDROM: os << "CD-ROM" << endl; break;
			case DRIVE_RAMDISK: os << "RAM-����" << endl; break;
		}

		__int64 freeSpace = 0, totalSpace = 0;
		GetDiskFreeSpaceEx(diskName, NULL, (PULARGE_INTEGER)&totalSpace, (PULARGE_INTEGER)&freeSpace); // ����������� �����    
		os << "����� �����: " << totalSpace / (1024 * 1024) << " ��" << endl;
		os << "��������: " << freeSpace / (1024 * 1024) << " ��" << endl;
		os << "������: " << (totalSpace - freeSpace) / (1024 * 1024) << " ��" << endl;

		char fileSystemName[30];
		BOOL getVolumeInformationFlag = GetVolumeInformationA((LPCTSTR)diskName, NULL, 100, NULL, NULL, NULL, fileSystemName, 100);
		if (getVolumeInformationFlag != 0)
		{
			os << "�������� �������: " << fileSystemName << endl << endl;
		}
		else
		{
			os << "�������� ������� �� ����������" << endl << endl;
		}

		while (*logicalDrives) logicalDrives++;
		logicalDrives++;
	}
}