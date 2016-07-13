/*#include<iostream>
using namespace std;

class Base
{
    int a; 
    public:
        Base()
        {
            a = 1;
        }
        virtual void method()
        {
            cout << a;
        }
};
 
class Child: public Base
{
    int b;
    public: 
        Child()
        {
            b = 2; 
        }
        void method()
        { 
            cout << b;
        }
};
 
int main()
{
    Base *pBase; 
    Child oChild;
    pBase = &oChild;
    pBase->method(); 
    return 0;
}*/