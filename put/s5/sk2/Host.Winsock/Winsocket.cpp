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
	server_info.sin_family = AF_INET;
	server_info.sin_addr.s_addr = inet_addr(address);
	server_info.sin_port = htons(port);

	if (::bind(socket, (LPSOCKADDR)&server_info, sizeof(struct sockaddr)) == SOCKET_ERROR) 
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

	SOCKADDR_IN remote_info;
    int info_size = sizeof(remote_info);

	this->handler = handler;

	printf("Listening for connections on %s:%d.\n", inet_ntoa(server_info.sin_addr), ntohs(server_info.sin_port));
    while (1) 
	{
        SOCKET sd = accept(socket, (sockaddr*)&remote_info, &info_size);
        if (sd != INVALID_SOCKET) 
		{
			printf("Serving connection from %s:%d.\n", inet_ntoa(remote_info.sin_addr), ntohs(remote_info.sin_port));

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
