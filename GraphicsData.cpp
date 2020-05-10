#include "GraphicsData.h"

void GraphicsData::showGraphicsData()
{
	system("cls");
	getGraphicsData();
	cout << "ВИДЕОКАРТА" << endl << endl;
	cout << "Видеокарта: " << displayDevice.DeviceString << endl;
	cout << "Объём видеопамяти: " << displayDevice.StateFlags / 1024 / 1024 << " МБ" << endl;
	cout << "Ветка реестра: " << displayDevice.DeviceKey << endl;
	getDesktopWin();
	cout << "Разрешение экрана: " << GetDeviceCaps(HDCScreen, HORZRES) << " x " << GetDeviceCaps(HDCScreen, VERTRES) << endl;
	cout << "Размер экрана: " << GetDeviceCaps(HDCScreen, HORZSIZE) << " мм х " << GetDeviceCaps(HDCScreen, VERTSIZE) << " мм" << endl;
	cout << "Размер диагонали: " << setprecision(3) << getDiagonal() << " дюймов" << endl;
	cout << "Цветовая палитра: " << GetDeviceCaps(HDCScreen, BITSPIXEL) << " бит" << endl;
	cout << "Частота обновления: " << GetDeviceCaps(HDCScreen, VREFRESH) << " Гц" << endl;

	system("pause");
}

void GraphicsData::writeGraphicsDataIntoFile(ofstream &os)
{
	os << "-------------------------------------" << endl;
	getGraphicsData();
	os << "ВИДЕОКАРТА" << endl << endl;
	os << "Видеокарта: " << displayDevice.DeviceString << endl;
	os << "Объём видеопамяти: " << displayDevice.StateFlags / 1024 / 1024 << " МБ" << endl;
	os << "Ветка реестра: " << displayDevice.DeviceKey << endl;
	getDesktopWin();
	os << "Разрешение экрана: " << GetDeviceCaps(HDCScreen, HORZRES) << " x " << GetDeviceCaps(HDCScreen, VERTRES) << endl;
	os << "Размер экрана: " << GetDeviceCaps(HDCScreen, HORZSIZE) << " мм х " << GetDeviceCaps(HDCScreen, VERTSIZE) << " мм" << endl;
	os << "Размер диагонали: " << setprecision(3) << getDiagonal() << " дюймов" << endl;
	os << "Цветовая палитра: " << GetDeviceCaps(HDCScreen, BITSPIXEL) << " бит" << endl;
	os << "Частота обновления: " << GetDeviceCaps(HDCScreen, VREFRESH) << " Гц" << endl;
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