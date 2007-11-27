// Host.Winsock.cpp : main project file.

#include "stdafx.h"
#include "Winsocket.h"
#include "WinsockConnection.h"

DWORD WINAPI winsock_connection_handler(SOCKET s)
{
	WinsockConnection connection(s);
	connection.Process();
	return 0;
}

int main(array<System::String^>^ args)
{
	WORD sockVersion = MAKEWORD(1, 1);			
	WSADATA wsaData;
	
	WSAStartup(sockVersion, &wsaData);

	Winsocket ls;

	try
	{
		ls.init(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		ls.bind("127.0.0.1", 119);
		ls.listen(winsock_connection_handler);
	}
	catch (SocketException& exc)
	{
		printf("Call to %s returned error %d!", exc.msg, exc.error);
	}
	finally
	{
		ls.close();
	}
	
	WSACleanup();

	return 0;
}

