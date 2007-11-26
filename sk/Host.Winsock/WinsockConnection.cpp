#include "StdAfx.h"
#include "WinsockConnection.h"

using namespace System;
using namespace System::Text;

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

void WinsockConnection::SendLine(String^ format, ...cli::array<Object^,1>^ values)
{
	String^ output = String::Format(format, values);
	pin_ptr<unsigned char> _output = &Encoding::UTF8->GetBytes(output)[0];
	//gg_send_message(session, GG_CLASS_MSG, login, _output);
}

