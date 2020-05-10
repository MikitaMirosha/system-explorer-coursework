#include "NetworkData.h"

void NetworkData::showNetworkData()
{
	system("cls");
	cout << "СЕТЬ" << endl << endl;
	if (!WSAStartup(!NULL, &WSAData))
	{
		char localHost[100];
		if (!gethostname(localHost, sizeof(localHost)))
		{
			HOSTENT* hEnt;
			cout << "Локальный хост: " << localHost << endl;
			hEnt = gethostbyname((char*)&localHost);
			if (hEnt != NULL)
			{
				cout << "Имя хоста: " << hEnt->h_name << endl;
				int adapter = 0;
				while (hEnt->h_addr_list[adapter])
				{
					sockaddr_in sockAddr;
					memcpy(&sockAddr.sin_addr, hEnt->h_addr_list[adapter], hEnt->h_length);
					cout << "Адрес: " << inet_ntoa(sockAddr.sin_addr) << endl;
					adapter++;
				}
				BOOL check = FALSE;
				check = InternetCheckConnection("http://google.com/", 1, 0);
				if (check == TRUE) 
					cout << "Устройство подключено к интернету" << endl;
				else 
					cout << "Устройство не подключено к интернету" << endl;
			}
		}
	}
	system("pause");
}

void NetworkData::writeNetworkDataIntoFile(ofstream &os)
{
	os << "-------------------------------------" << endl;
	os << "СЕТЬ" << endl << endl;
	if (!WSAStartup(!NULL, &WSAData))
	{
		char localHost[100];
		if (!gethostname(localHost, sizeof(localHost)))
		{
			HOSTENT* hEnt;
			os << "Локальный хост: " << localHost << endl;
			hEnt = gethostbyname((char*)&localHost);
			if (hEnt != NULL)
			{
				os << "Имя хоста: " << hEnt->h_name << endl;
				int adapter = 0;
				while (hEnt->h_addr_list[adapter])
				{
					sockaddr_in sockAddr;
					memcpy(&sockAddr.sin_addr, hEnt->h_addr_list[adapter], hEnt->h_length);
					os << "Адрес: " << inet_ntoa(sockAddr.sin_addr) << endl;
					adapter++;
			    }
				BOOL check = FALSE;
				check = InternetCheckConnection("http://google.com/", 1, 0);
				if (check == TRUE) 
					os << "Устройство подключено к интернету" << endl;
				else 
					os << "Устройство не подключено к интернету" << endl;
			}
		}
	}
}