// Host.Winsock.cpp : main project file.

#include "stdafx.h"
#include "Winsocket.h"
#include "WinsockConnection.h"

using namespace System;
using namespace Nntp;
using namespace Nntp::Storage;
using namespace Nntp::Storage::Database;

DWORD WINAPI ProcessConnection(SOCKET s)
{
	WinsockConnection^ connection = gcnew WinsockConnection(s);
	INntpRepository^ repository = gcnew DatabaseRepository();
	NntpSession^ session = gcnew NntpSession(connection, repository);
	
	connection->Process();
	
	delete session;
	delete repository;
	delete connection;
	
	Console::WriteLine("Connection closed.");

	return 0;
}

int main(array<System::String^>^ args)
{
	WSADATA wsaData;
	
	WSAStartup(MAKEWORD(1, 1), &wsaData);

	Winsocket ls;

	try
	{
		ls.init(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		ls.bind("0.0.0.0", 119);
		ls.listen(ProcessConnection);
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

