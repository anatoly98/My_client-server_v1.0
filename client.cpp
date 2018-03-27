
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment(lib,"ws2_32.lib")

#include <WinSock2.h>

#include <iostream>

#include <string>

using namespace std;

int main()

{

	

	WSAData wsaData; // структура для иницилизации сокетов

	WORD version = MAKEWORD(2, 1); // версия сокетов

	if (WSAStartup(version, &wsaData) != 0) // Функция WSAStartup инициализирует WinSock.  Если инициализация состоялась, то вернется нулевое значение. 

	{

		cout << "Winsock startup failed"<<endl;
		system("pause");
		return 1;

	}



	SOCKADDR_IN addr;  // структура, чтобы указать адрес локальной или удаленной конечной точки, к которому осуществляется подключение сокета. 

	int sizeofaddr = sizeof(addr); // размер структуры для передачи в функцию 

	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP-адрес этой точки

	addr.sin_port = htons(1111); //Port = 1111

	addr.sin_family = AF_INET; // Семейство адресов 




	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL); // инициализация сокета для передачи данных

	if (connect(Connection, (SOCKADDR*)&addr, sizeofaddr) != 0) // инициализирует соединение со стороны указаннного сокета

	{

		cout << "Failed to Connect"<<endl;
		system("pause");
		return 1;

	}

	cout << "Connected!" << endl;

    char b[] = "test message";

    send(Connection, b, 30, NULL); // функция для передачи

    system("pause");

    closesocket(Connection); //закрывает одну из сторон соединения

	WSACleanup(); // завершает использование данного DLL и прерывает обращение к функциям WinSock

	return 0;

}