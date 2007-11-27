#include "stdafx.h"
#include "Winsocket.h"

Winsocket::Winsocket(void)
{
	this->socket = INVALID_SOCKET;
}

void Winsocket::init(int af, int type, int protocol)
{
	this->socket = ::socket(af, type, protocol);

	if (this->socket == INVALID_SOCKET) 
	{
		throw SocketException(WSAGetLastError(), "init()");
	}
}

void Winsocket::close()
{
	if (socket != INVALID_SOCKET)
		closesocket(this->socket);
}
	
void Winsocket::bind(const char* address, int port)
{
	SOCKADDR_IN serverInfo;
	serverInfo.sin_family = AF_INET;
	serverInfo.sin_addr.s_addr = inet_addr(address);
	serverInfo.sin_port = htons(port);

	if (::bind(socket, (LPSOCKADDR)&serverInfo, sizeof(struct sockaddr)) == SOCKET_ERROR) 
	{
		throw SocketException(WSAGetLastError(), "bind()");
	}
}
	
void Winsocket::listen(socket_handler handler)
{
	if (::listen(socket, 10) == SOCKET_ERROR) 
	{
		throw SocketException(WSAGetLastError(), "listen()");
	}

	sockaddr_in sinRemote;
    int nAddrSize = sizeof(sinRemote);

	this->handler = handler;

	printf("Listening...\n");
    while (1) 
	{
        SOCKET sd = accept(socket, (sockaddr*)&sinRemote, &nAddrSize);
        if (sd != INVALID_SOCKET) 
		{
			printf("Accepted connection from %s:%d.\n", inet_ntoa(sinRemote.sin_addr), ntohs(sinRemote.sin_port));

            DWORD nThreadID;
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)handler, (void*)sd, 0, &nThreadID);
        }
    }
}

SocketException::SocketException(int error, const char *msg)
{
	this->error = error;
	this->msg = new char[sizeof(msg)];
	strcpy_s(this->msg, sizeof(msg), msg);
}

SocketException::~SocketException()
{
	delete[] this->msg;
}
