///* 
//Virtual Destructor:
//	Destructor is generally used to deallocate memory and do some other cleanup for a class object and it’s class members whenever an object is destroyed.
//	Destructors are distinguished by the tilde, the ‘~’ that appears in front of the destructor name. 
//	In order to define a virtual destructor, all you have to do is simply add the keyword “virtual” before the tilde symbol.
//	One important design paradigm of class design is that if a class has one or more virtual functions, then that class should also have a virtual destructor.
//	When we have Virtual destructor inside the base class, then first Derived class's destructor is called and then Base class's destructor is called, which is the desired behaviour.
//	Destructors in the Base class can be Virtual. 
//	Whenever Upcasting is done, Destructors of the Base class must be made virtual for proper destrucstion of the object when the program exits.
//NOTE : Constructors are never Virtual, only Destructors can be Virtual.
//Usage:
//	Deleting a derived class object using a pointer to a base class that has a non-virtual destructor results in undefined behavior.
//Pure Virtual Destructors:
//	Pure Virtual Destructors are legal in C++. Also, pure virtual Destructors must be defined, which is against the pure virtual behaviour.
//	The only difference between Virtual and Pure Virtual Destructor is, that pure virtual destructor will make its Base class Abstract, hence you cannot create object of that class.
//	There is no requirement of implementing pure virtual destructors in the derived classes.
//
//
//*/
//#include <iostream>
//using namespace std;
//
//class Base
//{
//public:
//	Base()
//	{ 
//		cout<<"Constructing Base"<<endl;
//	}
//
//	virtual ~Base()
//	{ 
//		cout<<"Destroying Base"<<endl;
//	}
//};
//
//class Derive: public Base
//{
//public:
//	Derive()
//	{ 
//		cout<<"Constructing Derive"<<endl;
//	}
//
//	~Derive()
//	{ 
//		cout<<"Destroying Derive"<<endl;
//	}
//};
//
//void main()
//{
//	Base *bPtr = new Derive();
//	delete bPtr; // Constructing Base Constructing Derive Destroying Derive Destroying Base if we use virtual destructure
//}