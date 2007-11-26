#include "StdAfx.h"
#include "WinsockConnection.h"

WinsockConnection::WinsockConnection(SOCKET socket)
{
	this->socket = socket;
	this->closing = false;
}

WinsockConnection::~WinsockConnection()
{
	
}

void WinsockConnection::Close()
{
	this->closing = true;
	//closesocket(socket);
}


