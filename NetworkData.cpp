#include "NetworkData.h"

void NetworkData::showNetworkData()
{
	system("cls");
	cout << "����" << endl << endl;
	if (!WSAStartup(!NULL, &WSAData))
	{
		char localHost[100];
		if (!gethostname(localHost, sizeof(localHost)))
		{
			HOSTENT* hEnt;
			cout << "��������� ����: " << localHost << endl;
			hEnt = gethostbyname((char*)&localHost);
			if (hEnt != NULL)
			{
				cout << "��� �����: " << hEnt->h_name << endl;
				int adapter = 0;
				while (hEnt->h_addr_list[adapter])
				{
					sockaddr_in sockAddr;
					memcpy(&sockAddr.sin_addr, hEnt->h_addr_list[adapter], hEnt->h_length);
					cout << "�����: " << inet_ntoa(sockAddr.sin_addr) << endl;
					adapter++;
				}
				BOOL check = FALSE;
				check = InternetCheckConnection("http://google.com/", 1, 0);
				if (check == TRUE) 
					cout << "���������� ���������� � ���������" << endl;
				else 
					cout << "���������� �� ���������� � ���������" << endl;
			}
		}
	}
	system("pause");
}

void NetworkData::writeNetworkDataIntoFile(ofstream &os)
{
	os << "-------------------------------------" << endl;
	os << "����" << endl << endl;
	if (!WSAStartup(!NULL, &WSAData))
	{
		char localHost[100];
		if (!gethostname(localHost, sizeof(localHost)))
		{
			HOSTENT* hEnt;
			os << "��������� ����: " << localHost << endl;
			hEnt = gethostbyname((char*)&localHost);
			if (hEnt != NULL)
			{
				os << "��� �����: " << hEnt->h_name << endl;
				int adapter = 0;
				while (hEnt->h_addr_list[adapter])
				{
					sockaddr_in sockAddr;
					memcpy(&sockAddr.sin_addr, hEnt->h_addr_list[adapter], hEnt->h_length);
					os << "�����: " << inet_ntoa(sockAddr.sin_addr) << endl;
					adapter++;
			    }
				BOOL check = FALSE;
				check = InternetCheckConnection("http://google.com/", 1, 0);
				if (check == TRUE) 
					os << "���������� ���������� � ���������" << endl;
				else 
					os << "���������� �� ���������� � ���������" << endl;
			}
		}
	}
}