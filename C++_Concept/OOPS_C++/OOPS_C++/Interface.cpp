/*
Interface:
	Interface are nothing but a pure abstract class in C++. 
	Ideally this interface class should contain only pure virtual public methods and static const data. 
	There is no concept of interface in C++,
	You can simulate the behavior using an Abstract class.
	Abstract class is a class which has atleast one pure virtual function, 
	One cannot create any instances of an abstract class but You could create pointers and references to it. 
	Also each class inheriting from the abstract class must implement the pure virtual functions in order that it's instances can be created.
Usage:
	Runtime Polymorphism
*/

//#include <iostream>
//using namespace std;
//
//class Interface
//{
//public:
//    Interface()
//	{
//		cout<<"Inside Interface Constructor"<<endl;
//	}
//    virtual ~Interface()
//	{
//		cout<<"Inside Interface Dustructor"<<endl;
//	}
//    virtual void method1()=0;
//    virtual void method2()=0;
//};
//
//class Base : public Interface
//{
//private:
//    int myMember;
//
//public:
//    Base()
//	{
//		cout<<"Inside Base Constructor"<<endl;
//	}
//    ~Base()
//	{
//		cout<<"Inside Base Dustructor"<<endl;
//	}
//
//    void method1()
//	{
//		cout<<"Inside Method1"<<endl;
//	}
//    void method2()
//	{
//		cout<<"Inside Method2"<<endl;
//	}
//};
//
//int main(void)
//{
//    Interface *f = new Base();
//    f->method1();
//    f->method2();
//    delete f;
//    return 0;
//}