#include "File.h"

void File::saveDataIntoFile(CPUData &cpuData)
{
	DiskData diskData;
	MemoryData memoryData;
	SystemData systemData;
	SystemTime systemTime;
	DeviceData deviceData;
	NetworkData networkData;
	ProcessData processData;
	GraphicsData graphicsData;

	os.open("systemdata.txt", ios_base::out | ios_base::trunc);
	if (!os.is_open())
	{
		cout << "������ 07: �� ������� �������� ���������� � ����." << endl;
		system("pause");
		return;
	}

	system("cls");
	systemTime.getSystemTime();
	os << asctime (systemTime.systemTime) << endl;

	systemData.writeSystemDataIntoFile(os);
	cout << "������ ������� �������� �������" << endl;

	cpuData.writeCPUDataIntoFile(os);
	cout << "������ ���������� �������� �������" << endl;

	diskData.writeDiskDataIntoFile(os);
	cout << "������ ������ �������� �������" << endl;

	memoryData.writeMemoryDataIntoFile(os);
	cout << "������ ������ �������� �������" << endl;

	networkData.writeNetworkDataIntoFile(os);
	cout << "������ ���� �������� �������" << endl;

	graphicsData.writeGraphicsDataIntoFile(os);
	cout << "������ ���������� �������� �������" << endl;
	os.close();

	os.open("processdata.txt", ios_base::out | ios_base::trunc);
	if (!os.is_open())
	{
		cout << "������ 07: �� ������� �������� ���������� � ����." << endl;
		system("pause");
		return;
	}

	os << asctime(systemTime.systemTime) << endl;
	processData.writeProcessDataListIntoFile(os);
	cout << "������ ��������� �������� �������" << endl;
	os.close();

	os.open("devicedata.txt", ios_base::out | ios_base::trunc);
	if (!os.is_open())
	{
		cout << "������ 07: �� ������� �������� ���������� � ����." << endl;
		system("pause");
		return;
	}

	os << asctime(systemTime.systemTime) << endl;
	deviceData.writeDeviceDataListIntoFile(os);
	cout << "������ ��������� �������� �������" << endl;
	os.close();

	system("pause");
}