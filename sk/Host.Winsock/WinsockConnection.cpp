#include "stdafx.h"
#include "WinsockConnection.h"

using namespace System;

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
}

void WinsockConnection::SendLine(String^ format, ...cli::array<Object^,1>^ values)
{
	String^ output = String::Format(format, values);

	Console::ForegroundColor = ConsoleColor::Green;
	Console::WriteLine(output);

	pin_ptr<unsigned char> _output = &Text::Encoding::UTF8->GetBytes(output)[0];
	send(socket, (const char*) _output, sizeof((const char*) _output), 0);
}
void WinsockConnection::Process()
{
	char buffer[255];
	
	while (!closing)
	{
		int rec = recv(socket, buffer, sizeof(buffer), 0);
		buffer[rec] = 0;
		String^ line = gcnew String((char*)buffer);

		if (rec == 0)
			break;

		Console::ForegroundColor = ConsoleColor::Red;
		Console::WriteLine(line);

		LineReceived(this, gcnew Nntp::LineEventArgs(line));
    }

	closesocket(socket);
}
