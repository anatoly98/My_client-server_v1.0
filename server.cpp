//This is srever//

#define _WINSOCK_DEPRECATED_NO_WARNINGS 

#define _CRT_SECURE_NO_WARNINGS 



#pragma comment (lib, "ws2_32.lib") 

#include <WinSock2.h> 

#include <iostream> 

#include <string> 

#include "message_class.h"

//#include <ws2tcpipt> 



using namespace std;



int main()

{

	WSAData wsaData;  // структура для иницилизации сокетов

	WORD version = MAKEWORD(2, 1); // версия сокетов

	int result = WSAStartup(version, &wsaData);// Функция WSAStartup инициализирует WinSock.  Если инициализация состоялась, то вернется нулевое значение. 

	if (result != 0)

	{

		return 1;

	}



	SOCKADDR_IN addr; // структура, чтобы указать адрес локальной или удаленной конечной точки, к которому осуществляется подключение сокета. 



	int addrlen = sizeof(addr); // размер структуры для передачи в функцию 

	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP-адрес 

	addr.sin_port = htons(1111); // Port 

	addr.sin_family = AF_INET; // Семейство адресов 



	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL); // инициализация сокета для установки связи 

	bind(sListen, (SOCKADDR*)&addr, sizeof(addr)); // Связывает сокет с конкретным адресом. 

	listen(sListen, SOMAXCONN); // Подготавливает привязываемый сокет к принятию входящих соединений. 



	SOCKET newConnection; // инициализация сокета для передачи данных 

	newConnection = accept(sListen, (SOCKADDR*)&addr, &addrlen); // Используется для принятия запроса на установление соединения от удаленного хоста. 



	if (newConnection == 0) // если подключение неудачно 



	{



		cout << "Failed to accept the client's connection." << endl;



	}



	else // если удачно подключениие 



	{






		cout << "Client Connected!" << endl;


		message MSG;

		//char buffer[30];



		recv(newConnection, (char*)&MSG, sizeof(message), NULL); // функция для получения данных с подключенного сокета 

		cout << MSG.getMSG()<<endl;

		//cout << buffer << endl;												   // здесь нужно распечатать данные из buffer 





	}



	closesocket(sListen); //закрывает одну из сторон соединения



	closesocket(newConnection); //закрывает одну из сторон соединения



	WSACleanup();// завершает использование данного DLL и прерывает обращение к функциям WinSock





	system("pause");



	return 0;



}
