#include "GraphicsData.h"

void GraphicsData::showGraphicsData()
{
	system("cls");
	getGraphicsData();
	cout << "����������" << endl << endl;
	cout << "����������: " << displayDevice.DeviceString << endl;
	cout << "����� �����������: " << displayDevice.StateFlags / 1024 / 1024 << " ��" << endl;
	cout << "����� �������: " << displayDevice.DeviceKey << endl;
	getDesktopWin();
	cout << "���������� ������: " << GetDeviceCaps(HDCScreen, HORZRES) << " x " << GetDeviceCaps(HDCScreen, VERTRES) << endl;
	cout << "������ ������: " << GetDeviceCaps(HDCScreen, HORZSIZE) << " �� � " << GetDeviceCaps(HDCScreen, VERTSIZE) << " ��" << endl;
	cout << "������ ���������: " << setprecision(3) << getDiagonal() << " ������" << endl;
	cout << "�������� �������: " << GetDeviceCaps(HDCScreen, BITSPIXEL) << " ���" << endl;
	cout << "������� ����������: " << GetDeviceCaps(HDCScreen, VREFRESH) << " ��" << endl;

	system("pause");
}

void GraphicsData::writeGraphicsDataIntoFile(ofstream &os)
{
	os << "-------------------------------------" << endl;
	getGraphicsData();
	os << "����������" << endl << endl;
	os << "����������: " << displayDevice.DeviceString << endl;
	os << "����� �����������: " << displayDevice.StateFlags / 1024 / 1024 << " ��" << endl;
	os << "����� �������: " << displayDevice.DeviceKey << endl;
	getDesktopWin();
	os << "���������� ������: " << GetDeviceCaps(HDCScreen, HORZRES) << " x " << GetDeviceCaps(HDCScreen, VERTRES) << endl;
	os << "������ ������: " << GetDeviceCaps(HDCScreen, HORZSIZE) << " �� � " << GetDeviceCaps(HDCScreen, VERTSIZE) << " ��" << endl;
	os << "������ ���������: " << setprecision(3) << getDiagonal() << " ������" << endl;
	os << "�������� �������: " << GetDeviceCaps(HDCScreen, BITSPIXEL) << " ���" << endl;
	os << "������� ����������: " << GetDeviceCaps(HDCScreen, VREFRESH) << " ��" << endl;
}

void GraphicsData::getGraphicsData()
{
	displayDevice.cb = sizeof(displayDevice);
	EnumDisplayDevices(NULL, 0, &displayDevice, 0);
}

float GraphicsData::getDiagonal()
{
	return (float)((sqrt(pow(GetDeviceCaps(HDCScreen, HORZSIZE), 2) + pow(GetDeviceCaps(HDCScreen, VERTSIZE), 2))) / 25.4);
}

void GraphicsData::getDesktopWin()
{
	HDCScreen = GetWindowDC(GetDesktopWindow());
}