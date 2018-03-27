
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment(lib,"ws2_32.lib")

#include <WinSock2.h>

#include <iostream>

#include <string>

using namespace std;

int main()

{

	

	WSAData wsaData; // ��������� ��� ������������ �������

	WORD version = MAKEWORD(2, 1); // ������ �������

	if (WSAStartup(version, &wsaData) != 0) // ������� WSAStartup �������������� WinSock.  ���� ������������� ����������, �� �������� ������� ��������. 

	{

		cout << "Winsock startup failed"<<endl;
		system("pause");
		return 1;

	}



	SOCKADDR_IN addr;  // ���������, ����� ������� ����� ��������� ��� ��������� �������� �����, � �������� �������������� ����������� ������. 

	int sizeofaddr = sizeof(addr); // ������ ��������� ��� �������� � ������� 

	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP-����� ���� �����

	addr.sin_port = htons(1111); //Port = 1111

	addr.sin_family = AF_INET; // ��������� ������� 




	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL); // ������������� ������ ��� �������� ������

	if (connect(Connection, (SOCKADDR*)&addr, sizeofaddr) != 0) // �������������� ���������� �� ������� ����������� ������

	{

		cout << "Failed to Connect"<<endl;
		system("pause");
		return 1;

	}

	cout << "Connected!" << endl;

    char b[] = "test message";

    send(Connection, b, 30, NULL); // ������� ��� ��������

    system("pause");

    closesocket(Connection); //��������� ���� �� ������ ����������

	WSACleanup(); // ��������� ������������� ������� DLL � ��������� ��������� � �������� WinSock

	return 0;

}