#pragma once

ref class WinsockConnection : Nntp::ILineConnection
{
private:
	SOCKET socket;
	bool closing;
public:
	WinsockConnection(SOCKET);
	virtual ~WinsockConnection();
	virtual void Close(void);
	virtual void SendLine(System::String^ format, ...cli::array<System::Object^,1>^ values);
	virtual event System::EventHandler<Nntp::LineEventArgs^>^ LineReceived;
	void Process();
};