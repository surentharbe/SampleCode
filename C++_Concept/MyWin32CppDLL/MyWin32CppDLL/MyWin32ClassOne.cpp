#include "MyWin32ClassOne.h"

namespace MyWin32DLL
{
    MyWin32ClassOne::MyWin32ClassOne()
    {
        varone = 123;
    }
 
    void MyWin32ClassOne::Setvar(int val)
    {
        varone = val;
    }
 
    int MyWin32ClassOne::Getvar()
    {
        return varone;
    }
} 