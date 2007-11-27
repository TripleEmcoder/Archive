#pragma once

class SocketException
{
public:
	int error;
	char* msg;
	SocketException(int error, const char* msg);
	~SocketException();	
};

class Winsocket
{
	typedef DWORD (WINAPI *socket_handler) (SOCKET); 
private:
	SOCKET socket;
	socket_handler handler;
public:
	Winsocket(void);
	void init(int af, int type, int protocol);
	void bind(const char* address, int port);
	void listen(socket_handler handler);
	void close();
};
