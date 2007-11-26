// Host.Winsock.cpp : main project file.

#include "stdafx.h"
#include "WinsockConnection.h"
#define NETWORK_ERROR 1
#define NETWORK_OK 0

using namespace System;

void ReportError(int errorCode, const char *whichFunc) {
	printf("Call to %s returned error %d!", (char *)whichFunc, errorCode);
}

DWORD WINAPI EchoHandler(void* sd_) 
{
    WinsockConnection conn((SOCKET)sd_);
	conn.Process();
	return 0;
}

void AcceptConnections(SOCKET ListeningSocket)
{
    sockaddr_in sinRemote;
    int nAddrSize = sizeof(sinRemote);

    while (1) {
        SOCKET sd = accept(ListeningSocket, (sockaddr*)&sinRemote, &nAddrSize);
        if (sd != INVALID_SOCKET) {
			printf("Accepted connection from %s:%d.", inet_ntoa(sinRemote.sin_addr), ntohs(sinRemote.sin_port));
            
            DWORD nThreadID;
            CreateThread(0, 0, EchoHandler, (void*)sd, 0, &nThreadID);
        }
        else {
			ReportError(WSAGetLastError(), "AcceptConnections");
            return;
        }
    }
}

int main(array<System::String^>^ args)
{
	int nret;

	WORD sockVersion = MAKEWORD(1, 1);			
	WSADATA wsaData;
	
	WSAStartup(sockVersion, &wsaData);

	SOCKET listeningSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (listeningSocket == INVALID_SOCKET) {
		nret = WSAGetLastError();		// Get a more detailed error
		ReportError(nret, "socket()");		// Report the error with our custom function

		WSACleanup();				// Shutdown Winsock
		return NETWORK_ERROR;			// Return an error value
	}

	// Use a SOCKADDR_IN struct to fill in address information
	SOCKADDR_IN serverInfo;
	serverInfo.sin_family = AF_INET;
	serverInfo.sin_addr.s_addr = INADDR_ANY;
	serverInfo.sin_port = htons(119);

	// Bind the socket to our local server address
	nret = bind(listeningSocket, (LPSOCKADDR)&serverInfo, sizeof(struct sockaddr));

	if (nret == SOCKET_ERROR) {
		nret = WSAGetLastError();
		ReportError(nret, "bind()");

		WSACleanup();
		return NETWORK_ERROR;
	}


	// Make the socket listen
	nret = listen(listeningSocket, 10);		// Up to 10 connections may wait at any

	if (nret == SOCKET_ERROR) {
		nret = WSAGetLastError();
		ReportError(nret, "listen()");

		WSACleanup();
		return NETWORK_ERROR;
	}

	printf("Listening...\n");
	while (1)
	{
		AcceptConnections(listeningSocket);
		printf("Connection accepted\n");
	}

	closesocket(listeningSocket);


	// Shutdown Winsock
	WSACleanup();
	return NETWORK_OK;
}

