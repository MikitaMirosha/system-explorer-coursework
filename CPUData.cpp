#include "CPUData.h"
#include <comdef.h>
#include <Wbemidl.h> 
#pragma comment(lib, "wbemuuid.lib")
#define _WIN32_DCOM 

void CPUData::showCPUData()
{
	system("cls");
	cout << "ПРОЦЕССОР" << endl << endl;
	cout << "Название: " << processorName << endl;
	cout << "Производитель: " << producerName << endl;
	cout << "Исходная частота: " << sourceFrequency << " МГц" << endl;

	if (systemInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
		cout << "Архитектура процессора: х64" << endl;
	if (systemInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL)
		cout << "Архитектура процессора: x32" << endl;

	cout << "Количество ядер: " << numberOfCores << endl;
	cout << "Количество логических процессоров: " << systemInfo.dwNumberOfProcessors << endl;
	cout << "Кэш L2: " << L2 << " Кб" << endl;
	cout << "Кэш L3: " << L3 << " Кб" << endl;
	cout << "Загруженность процессора: " << getCPULoad() << "%" << endl;

	system("pause");
}

void CPUData::writeCPUDataIntoFile(ofstream& os)
{
	os << "-------------------------------------" << endl;
	os << "ПРОЦЕССОР" << endl << endl;
	os << "Название: " << processorName << endl;
	os << "Производитель: " << producerName << endl;
	os << "Исходная частота: " << sourceFrequency << " МГц" << endl;

	if (systemInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
		os << "Архитектура процессора: х64" << endl;
	if (systemInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL)
		os << "Архитектура процессора: x32" << endl;

	os << "Количество ядер: " << numberOfCores << endl;
	os << "Количество логических процессоров: " << systemInfo.dwNumberOfProcessors << endl;
	os << "Кэш L2: " << L2 << " Кб" << endl;
	os << "Кэш L3: " << L3 << " Кб" << endl;
	os << "Загруженность процессора: " << getCPULoad() << "%" << endl;
}

// BSTR is a string data type that is used by COM
string convertBSTRtoStr(BSTR src) 
{
	_bstr_t wrapped_bstr = _bstr_t(src);
	int str_length = wrapped_bstr.length();
	char* char_array = new char[str_length];
	strcpy_s(char_array, str_length + 1, wrapped_bstr);
	return char_array;
}

void CPUData::getCPUData()
{
	GetSystemInfo(&systemInfo);

	// Инициализация COM-библиотеки (Component Object Model)
	HRESULT hResult;
	hResult = CoInitializeEx(0, COINIT_MULTITHREADED);
	if (FAILED(hResult))
	{
		cout << "Ошибка 01: COM-библиотека не инициализирована." << endl;
		return;
	}

	// Установка общих уровней безопасности COM-библиотеки
	hResult = CoInitializeSecurity(NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL);
	if (FAILED(hResult))
	{
		cout << "Ошибка 02: общие уровни безопасности не установлены." << endl;
		CoUninitialize();
		return;
	}

	// Получение исходного локатора в WMI (Windows Management Instrumentation)
	IWbemLocator *pLocator = NULL;
	// Создание одного объекта в локальной системе
	hResult = CoCreateInstance(CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER, IID_IWbemLocator, (LPVOID *)&pLocator);
	if (FAILED(hResult))
	{
		cout << "Ошибка 03: IWbemLocator не создан." << endl;
		CoUninitialize();
		return;
	}

	// Подключение к WMI (Windows Management Instrumentation)
	IWbemServices *pWbemServices = NULL;
	// Подключение к ветке root\cimv2
	hResult = pLocator->ConnectServer(_bstr_t(L"ROOT\\CIMV2"), NULL, NULL, 0, NULL, 0, 0, &pWbemServices);
	if (FAILED(hResult))
	{
		cout << "Ошибка 04: нет подключения к WMI" << hex << hResult << endl;
		pLocator->Release();
		CoUninitialize();
		return;
	}

	// Использование указателя на IWbemServices для запроса к WMI 
	IEnumWbemClassObject* pEnum = NULL;
	hResult = pWbemServices->ExecQuery(bstr_t("WQL"), bstr_t("SELECT * FROM Win32_Processor"), WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, NULL, &pEnum);
	if (FAILED(hResult))
	{
		cout << "Ошибка 05: запрос к WMI не выполнен." << hex << hResult << endl;
		pWbemServices->Release();
	    pLocator->Release();
	    CoUninitialize();
	    return;
	}

	// Получение данных
	IWbemClassObject *pWbemClassObject;
	ULONG uReturn = 0;

	while (pEnum)
	{
		HRESULT hResult = pEnum->Next(WBEM_INFINITE, 1, &pWbemClassObject, &uReturn);
		if (0 == uReturn)
			break;

		VARIANT pVariant;
		hResult = pWbemClassObject->Get(L"Name", 0, &pVariant, 0, 0);
		processorName = convertBSTRtoStr(pVariant.bstrVal);

		hResult = pWbemClassObject->Get(L"Manufacturer", 0, &pVariant, 0, 0);
		producerName = convertBSTRtoStr(pVariant.bstrVal);

		hResult = pWbemClassObject->Get(L"MaxClockSpeed", 0, &pVariant, 0, 0);
		sourceFrequency = pVariant.uintVal;

		hResult = pWbemClassObject->Get(L"NumberOfCores", 0, &pVariant, 0, 0);
		numberOfCores = pVariant.uintVal;

		hResult = pWbemClassObject->Get(L"L2CacheSize", 0, &pVariant, 0, 0);
		L2 = pVariant.uintVal;

		hResult = pWbemClassObject->Get(L"L3CacheSize", 0, &pVariant, 0, 0);
		L3 = pVariant.uintVal;

		pWbemClassObject->Release();
	}
}

ULONGLONG CPUData::ft2ull(FILETIME& ft)
{
	ULARGE_INTEGER u;
	u.HighPart = ft.dwHighDateTime;
	u.LowPart = ft.dwLowDateTime;
	return u.QuadPart;
}

int CPUData::getCPULoad()
{
	FILETIME lpIdleTimePrev, lpKernelTimePrev, lpUserTimePrev;
	GetSystemTimes(&lpIdleTimePrev, &lpKernelTimePrev, &lpUserTimePrev);
	Sleep(DELAY);
	FILETIME lpIdleTime, lpKernelTime, lpUserTime;
	GetSystemTimes(&lpIdleTime, &lpKernelTime, &lpUserTime);

	ULONGLONG system = (ft2ull(lpUserTime) - ft2ull(lpUserTimePrev)) + (ft2ull(lpKernelTime) - ft2ull(lpKernelTimePrev));
	int CPUUsage = int((system - ft2ull(lpIdleTime) + ft2ull(lpIdleTimePrev)) * 100.0 / system);

	return CPUUsage;
}
