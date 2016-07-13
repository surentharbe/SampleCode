#ifndef CLIENT_H__
#define CLIENT_H__

#include <windows.h>
#include <iostream>
using namespace std;

class WSockClient
{
public:
	WSockClient(int RequestVersion);
	~WSockClient();
	bool ConnectServer(int PortNumber, char *IP);			// Connect to the server
	void StartChat();										// Start the communication
private:
	WSADATA wsaData;
	SOCKET hSocket;
	sockaddr_in sockAddr;
	void SetClientSockAddr(sockaddr_in *sockAddr, int PortNumber, char *IP);			// Fill the sockAddr structure
};


#endif