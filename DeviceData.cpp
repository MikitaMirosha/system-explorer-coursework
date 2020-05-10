#include "DeviceData.h"

void DeviceData::setDeviceData()
{
	hDevInfo = SetupDiGetClassDevs(NULL, 0, 0, DIGCF_PRESENT | DIGCF_ALLCLASSES);
	spDevInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
}

void DeviceData::showDeviceDataList()
{
	system("cls");
	setDeviceData();

	if (hDevInfo == INVALID_HANDLE_VALUE)
	{
		cout << "Ошибка 06: список устройств не обнаружен.";
		return;
	}

	for (int i = 0; SetupDiEnumDeviceInfo(hDevInfo, i, &spDevInfoData); i++)
	{
		DWORD DataT;
		LPTSTR buffer = NULL;
		DWORD bufferSize = 0;

		while (!SetupDiGetDeviceRegistryProperty(hDevInfo, &spDevInfoData, SPDRP_DEVICEDESC, &DataT, (PBYTE)buffer, bufferSize, &bufferSize))
		{
			if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
		    {
				if (buffer) LocalFree(buffer);
					buffer = (char*)LocalAlloc(LPTR, bufferSize * 2);
			}
			else
			{
				break;
			}
		}

		if (buffer)
		{
			cout << i + 1 << ": " << buffer << endl;
			LocalFree(buffer);
		}
	}

	SetupDiDestroyDeviceInfoList(hDevInfo);
	system("pause");
}

void DeviceData::writeDeviceDataListIntoFile(ofstream &on)
{
	setDeviceData();

	if (hDevInfo == INVALID_HANDLE_VALUE)
	{
		on << "Ошибка 06: список устройств не обнаружен.";
		return;
	}

	for (int i = 0; SetupDiEnumDeviceInfo(hDevInfo, i, &spDevInfoData); i++)
	{
		DWORD DataT;
		LPTSTR buffer = NULL;
		DWORD bufferSize = 0;

		while (!SetupDiGetDeviceRegistryProperty(hDevInfo, &spDevInfoData, SPDRP_DEVICEDESC, &DataT, (PBYTE)buffer, bufferSize, &bufferSize))
		{
			if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
			{
				if (buffer) LocalFree(buffer);
				buffer = (char*)LocalAlloc(LPTR, bufferSize * 2);
			}
			else
			{
				break;
			}
		}
		if (buffer)
	    {
			on << i + 1 << ": " << buffer << endl;
			LocalFree(buffer);
		}
	}

	SetupDiDestroyDeviceInfoList(hDevInfo);
}