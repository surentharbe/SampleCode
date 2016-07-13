/*
Virtual Function:
	Virtual function / method is simply a function whose behavior can be overriden within a subclass (or in C++ terms a derived class) 
	by redefining how the function works (using the same signature).

Usage:
	Redefining and Overriding
	Rectifing the diamond problem
	Polymorphism also achived in virtual function.
	The resolving of the function call is done at run-time.
*/

//#include <iostream>
//using namespace std;
//
//class Base 
//{
//public:
//    Base() 
//	{ 
//		cout<<"In Base Constructor"<<endl;
//	}
//	virtual ~Base()
//	{
//		cout<<"In Base Destructor"<<endl;
//	}
//
//	virtual void doThings()
//	{
//		cout<<"Inside Base doThings"<<endl;
//	}
//};
//
//class Derived: public Base 
//{
//public:
//	Derived() 
//	{ 
//		cout<<"In Derived Constructor"<<endl;
//	}
//	~Derived()
//	{
//		cout<<"In Derived Destructor"<<endl;
//	}
//    void doThings() 
//	{ 
//		cout<<"Inside Derived doThing"<<endl;
//	} 
//};
//
//int main() 
//{
//    Base *b1 = new Base();				
//	b1->doThings();				// In PublicAbstruct Constructor, Inside PublicAbstruct doThings
//	delete b1;
//
//	Base *b2 = new Derived();            
//	b2->doThings();				// In PublicAbstruct Constructor, Inside B doThings (Virtual, In PublicAbstruct Constructor, Inside B doThings)
//
//	//Derived d = new Base()	// Not possible. for this we are using the dynamic cast
//
//	delete b2;
//    return 0;
//}