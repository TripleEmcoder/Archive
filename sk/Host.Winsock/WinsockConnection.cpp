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

	output += "\r\n";

	pin_ptr<unsigned char> _output = &Encoding::UTF8->GetBytes(output)[0];
	send(socket, (const char*)_output, output->Length, 0);
}
void WinsockConnection::Process()
{
	array<String^>^ separators = {"\r\n"};
	
	char _buffer[255];
	StringBuilder input;
	
	while (!closing)
	{
		int rec = recv(socket, _buffer, sizeof(_buffer), 0);
		if (rec == 0)
			break;

		_buffer[rec] = 0;
		String^ buffer = gcnew String((char*)_buffer);

		input.Append(buffer);

		if (buffer->Contains("\n"))
		{
			String^ s = input.ToString();
			array<String^>^ lines = s->Split(separators, StringSplitOptions::None);
			for (int i = 0; i < lines->Length-1; ++i)
			{
				String^ line = lines[i];
				input.Remove(0, line->Length+2);

				//if (line->Length > 0)
				//{
					Console::ForegroundColor = ConsoleColor::Red;
					Console::WriteLine(line);
					LineReceived(this, gcnew Nntp::LineEventArgs(line));
				//}
			}			
		}	
    }

	closesocket(socket);
	Console::ForegroundColor = ConsoleColor::Gray;
	Console::WriteLine("Connection closed.");
}
