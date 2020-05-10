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
		cout << "Ошибка 07: не удается записать информацию в файл." << endl;
		system("pause");
		return;
	}

	system("cls");
	systemTime.getSystemTime();
	os << asctime (systemTime.systemTime) << endl;

	systemData.writeSystemDataIntoFile(os);
	cout << "Данные системы записаны успешно" << endl;

	cpuData.writeCPUDataIntoFile(os);
	cout << "Данные процессора записаны успешно" << endl;

	diskData.writeDiskDataIntoFile(os);
	cout << "Данные дисков записаны успешно" << endl;

	memoryData.writeMemoryDataIntoFile(os);
	cout << "Данные памяти записаны успешно" << endl;

	networkData.writeNetworkDataIntoFile(os);
	cout << "Данные сети записаны успешно" << endl;

	graphicsData.writeGraphicsDataIntoFile(os);
	cout << "Данные видеокарты записаны успешно" << endl;
	os.close();

	os.open("processdata.txt", ios_base::out | ios_base::trunc);
	if (!os.is_open())
	{
		cout << "Ошибка 07: не удается записать информацию в файл." << endl;
		system("pause");
		return;
	}

	os << asctime(systemTime.systemTime) << endl;
	processData.writeProcessDataListIntoFile(os);
	cout << "Данные процессов записаны успешно" << endl;
	os.close();

	os.open("devicedata.txt", ios_base::out | ios_base::trunc);
	if (!os.is_open())
	{
		cout << "Ошибка 07: не удается записать информацию в файл." << endl;
		system("pause");
		return;
	}

	os << asctime(systemTime.systemTime) << endl;
	deviceData.writeDeviceDataListIntoFile(os);
	cout << "Данные устройств записаны успешно" << endl;
	os.close();

	system("pause");
}