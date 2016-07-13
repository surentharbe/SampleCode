#include "MyWin32ClassTwo.h"

namespace MyWin32DLL
{
    MyWin32ClassTwo::MyWin32ClassTwo()
    {
        vartwo = 345;
    }

    void MyWin32ClassTwo::Setvar(int val)
    {
        vartwo = val;
    }
 
    int MyWin32ClassTwo::Getvar()
    {
        return vartwo;
    }
}  