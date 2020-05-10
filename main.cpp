#include <iostream>
#include "MainMenu.h"

using namespace std;

int main()
{
	system("Color 70");
	setlocale(LC_ALL, "Russian");
	CPUData cpuData;
	MainMenu mainMenu;
	cpuData.getCPUData();
	while (true)
	{
		mainMenu.showMainMenu();
		mainMenu.selectCommand(cpuData);
		rewind(stdin);
		system("cls");
	}
}