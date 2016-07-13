namespace MyWin32DLL
{
    class MyWin32ClassOne
    {
    private:
        int varone;
    public:
        __declspec(dllexport) MyWin32ClassOne();//constructor
        __declspec(dllexport) void Setvar(int val);
        __declspec(dllexport) int Getvar();
    };
} 