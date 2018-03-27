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
	WSAData wsaData;  // структура дл€ иницилизации сокетов
	WORD version = MAKEWORD(2, 1); // верси€ сокетов
	int result = WSAStartup(version, &wsaData);// ‘ункци€ WSAStartup инициализирует WinSock.  ≈сли инициализаци€ состо€лась, то вернетс€ нулевое значение. 
	if (result != 0)
	{
		return 1;
	}
	
        SOCKADDR_IN addr; // структура, чтобы указать адрес локальной или удаленной конечной точки, к которому осуществл€етс€ подключение сокета. 

	int addrlen = sizeof(addr); // размер структуры дл€ передачи в функцию 
	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP-адрес 
	addr.sin_port = htons(1111); // Port 
	addr.sin_family = AF_INET; // —емейство адресов 

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL); // инициализаци€ сокета дл€ установки св€зи 
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr)); // —в€зывает сокет с конкретным адресом. 
	listen(sListen, SOMAXCONN); // ѕодготавливает прив€зываемый сокет к прин€тию вход€щих соединений. 

	SOCKET newConnection; // инициализаци€ сокета дл€ передачи данных 
	newConnection = accept(sListen, (SOCKADDR*)&addr, &addrlen); // »спользуетс€ дл€ прин€ти€ запроса на установление соединени€ от удаленного хоста. 

	if (newConnection == 0) // если подключение неудачно 

	{

		cout << "Failed to accept the client's connection." << endl;

	}

	else // если удачно подключениие 

	{



		cout << "Client Connected!" << endl;

		char buffer[30];

		recv(newConnection, buffer, sizeof(buffer), NULL); // функци€ дл€ получени€ данных с подключенного сокета 

		cout << buffer <<endl;												   // здесь нужно распечатать данные из buffer 


	}

	closesocket(sListen); //закрывает одну из сторон соединени€

	closesocket(newConnection); //закрывает одну из сторон соединени€

	WSACleanup();// завершает использование данного DLL и прерывает обращение к функци€м WinSock


	system("pause");

	return 0;

}