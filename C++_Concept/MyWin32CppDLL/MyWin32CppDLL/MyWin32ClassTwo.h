namespace MyWin32DLL
{
    class MyWin32ClassTwo
    {
    private:
        int vartwo;
    public:
        __declspec(dllexport) MyWin32ClassTwo();//constructor
        __declspec(dllexport) void Setvar(int val);
        __declspec(dllexport) int Getvar();
    };
} 