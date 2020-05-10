#include "MainMenu.h"

void MainMenu::showMainMenu()
{
	cout << "______________________" << endl;
	cout << "1. �������" << endl;
	cout << "______________________" << endl;
	cout << "2. ���������" << endl;
	cout << "______________________" << endl;
	cout << "3. ������" << endl;
	cout << "______________________" << endl;
	cout << "4. ����" << endl;
	cout << "______________________" << endl;
	cout << "5. �����" << endl;
	cout << "______________________" << endl;
	cout << "6. ����������" << endl;
	cout << "______________________" << endl;
	cout << "7. ������ ���������" << endl;
	cout << "______________________" << endl;
	cout << "8. ������ ���������" << endl;
	cout << "______________________" << endl;
	cout << "9. ��������� �������" << endl;
	cout << "______________________" << endl;
	cout << "0. ��������� � ����" << endl;
	cout << "______________________" << endl;
	cout << "Esc - �����" << endl;
	cout << "______________________" << endl;
}

void MainMenu::selectCommand(CPUData &cpuData)
{
	switch (_getch())
	{
	case '1':
	{
		SystemData systemData;
		systemData.showSystemData();
		break;
	}
	case '2':
	{
		cpuData.showCPUData();
		break;
	}
	case '3':
	{
		MemoryData memoryData;
		memoryData.showMemoryData();
		break;
	}
	case '4':
	{
		NetworkData networkData;
		networkData.showNetworkData();
		break;
	}
	case '5':
	{
		DiskData diskData;
		diskData.showDiskData();
		break;
	}
	case '6': 
	{
		GraphicsData graphicsData;
		graphicsData.showGraphicsData();
		break;
	}
	case '7': 
	{
		ProcessData processData;
		processData.showProcessDataList();
		break;
	}
	case '8': 
	{
		DeviceData deviceData;
		deviceData.showDeviceDataList();
		break;
	}
	case '9': 
	{
		LoadStatus systemStatus;
		systemStatus.showLoadStatus();
		break;
	}
	case '0': 
	{
		File file;
		file.saveDataIntoFile(cpuData);
		break;
	}
	case 27:
	{
		exit(EXIT_SUCCESS);
		break;
	}
	}
}