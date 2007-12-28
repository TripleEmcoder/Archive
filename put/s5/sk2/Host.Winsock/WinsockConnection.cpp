#include "stdafx.h"
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
}

void WinsockConnection::SendLine(String^ format, ...cli::array<Object^,1>^ values)
{
	String^ output = String::Format(format, values);

	Console::ForegroundColor = ConsoleColor::Green;
	Console::WriteLine(output);

	if (output->Length > 0)
	{
		pin_ptr<unsigned char> _output = &Encoding::UTF8->GetBytes(output)[0];
		send(socket, (const char*)_output, output->Length, 0);
	}

	send(socket, "\r\n", 2, 0);
}
void WinsockConnection::Process()
{
	array<String^>^ separators = {"\r\n"};

	char buffer[1024];
	StringBuilder input;

	while (!closing)
	{
		int length = recv(socket, buffer, sizeof(buffer), 0);
		
		if (length == 0)
			break;

		cli::array<unsigned char>^ _buffer = gcnew cli::array<unsigned char>(length);
		
		for (int i = 0; i < length; ++i)
			_buffer[i] = buffer[i];
		
		String^ __buffer = Encoding::UTF8->GetString(_buffer);

		input.Append(__buffer);

		if (__buffer->Contains("\r\n"))
		{
			String^ _input = input.ToString();

			array<String^>^ lines = _input->Split(separators, StringSplitOptions::None);
			
			for (int i = 0; i < lines->Length-1; ++i)
			{
				input.Remove(0, lines[i]->Length+2);

				Console::ForegroundColor = ConsoleColor::Blue;
				Console::WriteLine(lines[i]);

				LineReceived(this, gcnew Nntp::LineEventArgs(lines[i]));
			}			
		}	
	}

	closesocket(socket);

	Console::ForegroundColor = ConsoleColor::Gray;
}
