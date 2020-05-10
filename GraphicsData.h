#pragma once
#include <iomanip>
#include <iostream>
#include <windows.h>
#include "PersonalComputer.h"

class GraphicsData : public PersonalComputer
{
private:
	HDC HDCScreen;
	DISPLAY_DEVICE displayDevice;
public:
	float getDiagonal();
	void getDesktopWin();
	void getGraphicsData();
	void showGraphicsData();
	void writeGraphicsDataIntoFile(ofstream & os);
};