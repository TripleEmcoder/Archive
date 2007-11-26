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
    SOCKET socket = (SOCKET)sd_;
	WinsockConnection conn(socket);
	conn.Process();
	return 0;
	
    /*int nRetval = 0;
    SOCKET socket = (SOCKET)sd_;
		
	if (!EchoIncomingPackets(sd)) {
        cerr << endl << WSAGetLastErrorMessage(
                "Echo incoming packets failed") << endl;
        nRetval = 3;
    }

    cout << "Shutting connection down..." << flush;
    if (ShutdownConnection(sd)) {
        cout << "Connection is down." << endl;
    }
    else {
        cerr << endl << WSAGetLastErrorMessage(
                "Connection shutdown failed") << endl;
        nRetval = 3;
    }
	
	return nRetval;*/
}

void AcceptConnections(SOCKET ListeningSocket)
{
    sockaddr_in sinRemote;
    int nAddrSize = sizeof(sinRemote);

    while (1) {
        SOCKET sd = accept(ListeningSocket, (sockaddr*)&sinRemote,
                &nAddrSize);
        if (sd != INVALID_SOCKET) {
			printf("Accepted connection from %s:%d.",inet_ntoa(sinRemote.sin_addr),ntohs(sinRemote.sin_port));
            
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
	//Console::WriteLine(L"Hello World");
	WORD sockVersion;
	WSADATA wsaData;
	int nret;

	sockVersion = MAKEWORD(1, 1);			// We'd like Winsock version 1.1

	// We begin by initializing Winsock
	WSAStartup(sockVersion, &wsaData);


	// Next, create the listening socket
	SOCKET listeningSocket;

	listeningSocket = socket(AF_INET,		// Go over TCP/IP
			         SOCK_STREAM,   	// This is a stream-oriented socket
				 IPPROTO_TCP);		// Use TCP rather than UDP

	if (listeningSocket == INVALID_SOCKET) {
		nret = WSAGetLastError();		// Get a more detailed error
		ReportError(nret, "socket()");		// Report the error with our custom function

		WSACleanup();				// Shutdown Winsock
		return NETWORK_ERROR;			// Return an error value
	}


	// Use a SOCKADDR_IN struct to fill in address information
	SOCKADDR_IN serverInfo;

	serverInfo.sin_family = AF_INET;
	serverInfo.sin_addr.s_addr = INADDR_ANY;	// Since this socket is listening for connections,
							// any local address will do
	serverInfo.sin_port = htons(8888);		// Convert integer 8888 to network-byte order
							// and insert into the port field


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
							// one time to be accept()'ed

	if (nret == SOCKET_ERROR) {
		nret = WSAGetLastError();
		ReportError(nret, "listen()");

		WSACleanup();
		return NETWORK_ERROR;
	}


	// Wait for a client
	//SOCKET theClient;

	//theClient = accept(listeningSocket,
	//		   NULL,			// Address of a sockaddr structure (see explanation below)
	//		   NULL);			// Address of a variable containing size of sockaddr struct

	printf("Listening...\n");
	while (1)
	{
		AcceptConnections(listeningSocket);
		printf("Connection accepted\n");
	}

	//if (theClient == INVALID_SOCKET) {
	//	nret = WSAGetLastError();
	//	ReportError(nret, "accept()");

	//	WSACleanup();
	//	return NETWORK_ERROR;
	//}


	// Send and receive from the client, and finally,
	///closesocket(theClient);
	closesocket(listeningSocket);


	// Shutdown Winsock
	WSACleanup();
	return NETWORK_OK;
}

