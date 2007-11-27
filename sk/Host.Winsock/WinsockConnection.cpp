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
	send(socket, (const char*)_output->, output->Length, 0);
}
void WinsockConnection::Process()
{
	char buffer[255];
	
	while (!closing)
	{
		int total = 0;
		int rec = 0;
		do
		{
			rec = recv(socket, buffer + total, sizeof(buffer) - total, 0);
			total += rec;
		} while (rec > 0 && buffer[total-1] != '\n' && buffer[total-1] != '\r');
		
		while (buffer[total-1] == '\n' || buffer[total-1] == '\r')
			total--;
		buffer[total] = 0;
		
		String^ line = gcnew String((char*)buffer);

		if (rec == 0)
			break;

		Console::ForegroundColor = ConsoleColor::Red;
		Console::WriteLine(line);

		LineReceived(this, gcnew Nntp::LineEventArgs(line));
    }

	Console::WriteLine("Connection  closed.");

	closesocket(socket);
}
