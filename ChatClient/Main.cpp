#include <iostream>
#include "Client.h"
using namespace std;

#define REQ_WINSOCK_VER	2
#define PORT			4444

int main(int argc, char *argv[])
{
	char StrIP[30];								// StrIP will hold the ip if the
												// user don't give an argument.
	try
	{
		WSockClient MyClient(REQ_WINSOCK_VER);	// Winsock startup.
		cout << "Search server... " << endl;
		
		if(argc >= 2)							// If user give an argument (IP ADDRESS)
		{
			cout << argv[1] << endl;
			if(!MyClient.ConnectServer(PORT, argv[1]))
			{
				cout << "ChatClient was unable to connect. " << endl;
			}
		}
		else
		{
			cout << "IP ADRESS: ";
			cin.getline(StrIP, 29, '\n');
			if(!MyClient.ConnectServer(PORT, StrIP))
			{
				cout << "ChatClient was unable to connect. " << endl;
			}
		}
		cout << "You are connected to the server. " << endl << endl;
		cout << "Type 'exit' to disconnect. " << endl;
		MyClient.StartChat();
	}
	catch(char *ErrMsg) { cout << "\nError: " << ErrMsg << endl; }
	return 0;
}