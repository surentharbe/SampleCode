// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//void getDir(const char* d, vector<string> & f)
//{
//	FILE* pipe =  NULL;
//	string pCmd = "dir /B /S " + string(d);
//	//string pCmd = "dir " + string(d);
//	char buf[256];
//
//	if( NULL == (pipe = _popen(pCmd.c_str(),"rt")))
//	{
//		cout<<"Shit"<<endl;
//		return;
//	}
//
//	while (!feof(pipe))
//	{
//		if(fgets(buf,256,pipe) != NULL)
//		{
//			f.push_back(string(buf));
//		}
//
//	}
//	_pclose(pipe);
//}
//
//int main(int argc, char* argv[])
//{
//	vector<string> files;
//	getDir("D:\\Tamil_Movies", files);
//	vector<string>::const_iterator it = files.begin();
//	cout<<"Printing Dir"<<endl;
//
//	while( it != files.end())
//	{
//		cout<<*it<<endl;
//		it++;
//	}
//	//system("PAUSE");
//	return 0;	
//}