#include "Server.h"

WSockServer::WSockServer(int RequestVersion)
{
	hSocket = INVALID_SOCKET;
	ClientSocket = INVALID_SOCKET;

	if(WSAStartup(MAKEWORD(RequestVersion, 0), &wsaData) == 0)		// Check required version
	{
		if(LOBYTE(wsaData.wVersion < RequestVersion))
		{
			throw "Requested version not available.";
		}
	}
	else
		throw "Startup failed.";
}

WSockServer::~WSockServer()
{
	if(WSACleanup() != 0)
		throw "Cleanup failed.";
	if(hSocket != INVALID_SOCKET)
		closesocket(hSocket);
	if(ClientSocket != INVALID_SOCKET)
		closesocket(hSocket);
}


void WSockServer::SetServerSockAddr(sockaddr_in *sockAddr, int PortNumber)
{
	sockAddr->sin_family = AF_INET;
	sockAddr->sin_port = htons(PortNumber);
	sockAddr->sin_addr.S_un.S_addr = INADDR_ANY;			// Listen on all available ip's
}


bool WSockServer::RunServer(int PortNumber)
{	
	if((hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)		// Create socket
		throw "Could not create socket.";
	SetServerSockAddr(&sockAddr, PortNumber);										// Fill sockAddr
	if(bind(hSocket, (sockaddr*)(&sockAddr), sizeof(sockAddr)) != 0)
		throw "Could not bind socket.";
	if(listen(hSocket, SOMAXCONN) != 0)
		throw "Could not put the socket in listening mode.";

	int cnf = 0;
	TCHAR buffer[256] = TEXT("");
	DWORD dwSize = sizeof(buffer);
	TCHAR szDescription[8][32] = {TEXT("NetBIOS"), 
		TEXT("DNS hostname"), 
		TEXT("DNS domain"), 
		TEXT("DNS fully-qualified"), 
		TEXT("Physical NetBIOS"), 
		TEXT("Physical DNS hostname"), 
		TEXT("Physical DNS domain"), 
		TEXT("Physical DNS fully-qualified")};
	for (cnf = 0; cnf < ComputerNameMax; cnf++)
	{
		if (!GetComputerNameEx((COMPUTER_NAME_FORMAT)cnf, buffer, &dwSize))
		{
			printf(TEXT("GetComputerNameEx failed (%d)\n"), GetLastError());
			//return;
		}
		else printf(TEXT("%s: %s\n"), szDescription[cnf], buffer);
		dwSize = _countof(buffer);
		ZeroMemory(buffer, dwSize);
	}

	cout << "Server settings: " << endl;
	cout << "IP: " << inet_ntoa(sockAddr.sin_addr) << endl;
	cout << "PORT: " << ntohs(sockAddr.sin_port) << endl << endl;

	int SizeAddr = sizeof(ClientAddr);

	cout << "Waiting for clients... ";
	ClientSocket = accept(hSocket, (sockaddr*)(&ClientAddr), &SizeAddr);
	cout << "client found!" << endl;
	return true;
}

void WSockServer::StartChat()
{
	while(true)
	{
		int BytesRec = recv(ClientSocket, Buffer, sizeof(Buffer), 0);

		if(BytesRec == 0)
		{
			cout << "The client closed the connection. " << endl;
		}
		else if(BytesRec == SOCKET_ERROR)
		{
			throw "The client seems to be offline.";
		}
		else
		{
			Buffer[BytesRec] = 0;
			cout << "Client: " << Buffer << endl;
		}
	}
}




