#define _WINSOCK_DEPRECATED_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS 

#pragma comment (lib, "ws2_32.lib") 
#include <WinSock2.h> 
#include <iostream> 
#include <string> 
//#include <ws2tcpipt> 

using namespace std;

int main()
{
	WSAData wsaData;  // ��������� ��� ������������ �������
	WORD version = MAKEWORD(2, 1); // ������ �������
	int result = WSAStartup(version, &wsaData);// ������� WSAStartup �������������� WinSock.  ���� ������������� ����������, �� �������� ������� ��������. 
	if (result != 0)
	{
		return 1;
	}
	
        SOCKADDR_IN addr; // ���������, ����� ������� ����� ��������� ��� ��������� �������� �����, � �������� �������������� ����������� ������. 

	int addrlen = sizeof(addr); // ������ ��������� ��� �������� � ������� 
	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP-����� 
	addr.sin_port = htons(1111); // Port 
	addr.sin_family = AF_INET; // ��������� ������� 

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL); // ������������� ������ ��� ��������� ����� 
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr)); // ��������� ����� � ���������� �������. 
	listen(sListen, SOMAXCONN); // �������������� ������������� ����� � �������� �������� ����������. 

	SOCKET newConnection; // ������������� ������ ��� �������� ������ 
	newConnection = accept(sListen, (SOCKADDR*)&addr, &addrlen); // ������������ ��� �������� ������� �� ������������ ���������� �� ���������� �����. 

	if (newConnection == 0) // ���� ����������� �������� 

	{

		cout << "Failed to accept the client's connection." << endl;

	}

	else // ���� ������ ������������ 

	{



		cout << "Client Connected!" << endl;

		char buffer[30];

		recv(newConnection, buffer, sizeof(buffer), NULL); // ������� ��� ��������� ������ � ������������� ������ 

		cout << buffer <<endl;												   // ����� ����� ����������� ������ �� buffer 


	}

	closesocket(sListen); //��������� ���� �� ������ ����������

	closesocket(newConnection); //��������� ���� �� ������ ����������

	WSACleanup();// ��������� ������������� ������� DLL � ��������� ��������� � �������� WinSock


	system("pause");

	return 0;

}