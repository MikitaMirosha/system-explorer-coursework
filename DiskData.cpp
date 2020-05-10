#include "DiskData.h"

void DiskData::showDiskData()
{
	system("cls");
	int diskCounter = 0;
	int size = GetLogicalDriveStrings(NULL, 0);
	TCHAR* logicalDrives = new TCHAR[size];
	GetLogicalDriveStrings(size, logicalDrives);

	cout << "ДИСКИ" << endl << endl;
	while (*logicalDrives)
	{
		TCHAR diskName[80];
		lstrcpy(diskName, logicalDrives);
		UINT uDriveType = GetDriveType(diskName);

		diskCounter = diskCounter + 1; 
		cout << "Диск " << diskName << " - "; 

		switch (GetDriveType(diskName))
		{
			case DRIVE_UNKNOWN: cout << "неизвестный диск" << endl; break;
			case DRIVE_NO_ROOT_DIR: cout << "не существует" << endl; break;
			case DRIVE_REMOVABLE: cout << "съёмный диск" << endl; break;
			case DRIVE_FIXED: cout << "фиксированный диск" << endl; break;
			case DRIVE_REMOTE: cout << "network-диск" << endl; break;
			case DRIVE_CDROM: cout << "CD-ROM" << endl; break;
			case DRIVE_RAMDISK: cout << "RAM-диск" << endl; break;
		}

		__int64 freeSpace = 0, totalSpace = 0;
		GetDiskFreeSpaceEx(diskName, NULL, (PULARGE_INTEGER)&totalSpace, (PULARGE_INTEGER)&freeSpace); // определение объема  
		cout << "Объем диска: " << totalSpace / (1024 * 1024) << " МБ" << endl;
		cout << "Свободно: " << freeSpace / (1024 * 1024) << " МБ" << endl;
		cout << "Занято: " << (totalSpace - freeSpace) / (1024 * 1024) << " МБ" << endl;

		char fileSystemName[30];
		BOOL getVolumeInformationFlag = GetVolumeInformationA((LPCTSTR)diskName, NULL, 100, NULL, NULL, NULL, fileSystemName, 100);
		if (getVolumeInformationFlag != 0)
		{
			cout << "Файловая система: " << fileSystemName << endl << endl;
		}
		else
		{
			cout << "Файловая система не определена" << endl << endl;
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
	os << "ДИСКИ" << endl << endl;
	while (*logicalDrives)
	{
		TCHAR diskName[80];
		lstrcpy(diskName, logicalDrives);
		UINT uDriveType = GetDriveType(diskName);

		diskCounter = diskCounter + 1; 
		os << "Диск " << diskName << " - "; 

		switch (GetDriveType(diskName))
		{
			case DRIVE_UNKNOWN: os << "неизвестный диск" << endl; break;
			case DRIVE_NO_ROOT_DIR: os << "не существует" << endl; break;
			case DRIVE_REMOVABLE: os << "съёмный диск" << endl; break;
			case DRIVE_FIXED: os << "фиксированный диск" << endl; break;
			case DRIVE_REMOTE: os << "network-диск" << endl; break;
			case DRIVE_CDROM: os << "CD-ROM" << endl; break;
			case DRIVE_RAMDISK: os << "RAM-диск" << endl; break;
		}

		__int64 freeSpace = 0, totalSpace = 0;
		GetDiskFreeSpaceEx(diskName, NULL, (PULARGE_INTEGER)&totalSpace, (PULARGE_INTEGER)&freeSpace); // определение объем    
		os << "Объем диска: " << totalSpace / (1024 * 1024) << " МБ" << endl;
		os << "Свободно: " << freeSpace / (1024 * 1024) << " МБ" << endl;
		os << "Занято: " << (totalSpace - freeSpace) / (1024 * 1024) << " МБ" << endl;

		char fileSystemName[30];
		BOOL getVolumeInformationFlag = GetVolumeInformationA((LPCTSTR)diskName, NULL, 100, NULL, NULL, NULL, fileSystemName, 100);
		if (getVolumeInformationFlag != 0)
		{
			os << "Файловая система: " << fileSystemName << endl << endl;
		}
		else
		{
			os << "Файловая система не определена" << endl << endl;
		}

		while (*logicalDrives) logicalDrives++;
		logicalDrives++;
	}
}