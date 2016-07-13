#include "Client.h"

// Constructor //
WSockClient::WSockClient(int RequestVersion)
{
	hSocket = INVALID_SOCKET;

	if(WSAStartup(MAKEWORD(RequestVersion, 0), &wsaData) == 0)
	{
		if(LOBYTE(wsaData.wVersion < RequestVersion))
		{
			throw "Requested version not available.";
		}
	}
	else
		throw "Startup failed.";
}

// Destructor //
WSockClient::~WSockClient()
{
	if(WSACleanup() != 0)
		throw "Cleanup failed.";
	if(hSocket != INVALID_SOCKET)
		closesocket(hSocket);
}

void WSockClient::SetClientSockAddr(sockaddr_in *sockAddr, int PortNumber, char *IP)
{
    sockAddr->sin_addr.S_un.S_addr = inet_addr(IP);
	sockAddr->sin_family = AF_INET;						// Use TCP/IP protocol
	sockAddr->sin_port = htons(PortNumber);
}

bool WSockClient::ConnectServer(int PortNumber, char *IP)
{
	SetClientSockAddr(&sockAddr, PortNumber, IP);		// Settings

	if((hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
		throw "Could not create socket.";
	cout << "Attempting to connect to " << inet_ntoa(sockAddr.sin_addr) << endl;
	if(connect(hSocket, (sockaddr*)(&sockAddr), sizeof(sockAddr)) != 0)		// Connect to the server
		throw "Could not connect";

	return true;
}

void WSockClient::StartChat()
{
	while(true)
	{
		char *SendText = new char[128];

		cout << "Client: ";
		cin.getline(SendText, 127, '\n');

		if(strcmp(SendText, "exit") == 0)
			return;

		if(send(hSocket, SendText, strlen(SendText), 0) == SOCKET_ERROR)
			throw "Server probably down. ";

		delete[] SendText;
	}
}