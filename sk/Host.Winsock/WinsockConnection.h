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
	void Process();
	//void SendLine(System::String^, 
};