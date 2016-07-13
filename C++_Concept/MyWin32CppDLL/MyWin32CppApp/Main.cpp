#include<iostream>
using namespace std;
 
#include "MyWin32ClassOne.h" 
#include "MyWin32ClassTwo.h" 
using namespace MyWin32DLL;
 
int main()
{
    cout<<"Hello C++ Win32 DLL"<<endl;
 
    MyWin32ClassOne sc1;
    cout<<"default value of variable from dll : "<<sc1.Getvar()<<endl;
    sc1.Setvar(101);
    cout<<"value of variable from dll : "<<sc1.Getvar()<<endl;
 
    MyWin32ClassTwo sc2;
    cout<<"default value of variable from dll : "<<sc2.Getvar()<<endl;
    sc2.Setvar(200);
    cout<<"value of variable from dll : "<<sc2.Getvar()<<endl;
 
    cin.get();//pause console to see the message

    return 0;
}