/*
Dynamic_Cast:
	Used for conversion of polymorphic types. base to derived conversion is not allowed with dynamic_cast unless the base class is polymorphic (Virtual).
	Conversion from base class to derived class (UpCasting).
	This cast type uses information available at compile time to perform the required type conversion. 
	The dynamic_cast can only be used with pointers and references to objects
	It always be successful if we use it to cast a class to one of its base classes.	
	If a class is polymorphic then dynamic_cast will perform a special check during execution. 
	This check ensures that the expression is a valid and complete object of the requested class.
*/

//#include <iostream>
//using namespace std;
//
//class Base 
//{
//public:
//	virtual void doThings()
//	{
//		cout<<"Inside Base doThings"<<endl;
//	}
//};
//
//class Derived: public Base 
//{
//public:
//    void doThings() 
//	{ 
//		cout<<"Inside Derived doThing"<<endl;
//	} 
//};
//
//int main()
//{
//	//Derived *d = new Base();				// This is not possible. for this we need to use dynamic cast
//		
//	//Base *b = new Base();
//	//Derived *d = dynamic_cast<Derived*>(b);
//	//d->doThings();							// It will give Null Pointer
//	
//	//Derived to base (Upcasting)
//	Base * b1 = new Derived;
//    Base * b2 = new Base;
//    Derived * d1;
//    d1 = dynamic_cast<Derived*>(b1); 
//	d1->doThings();
//
//	//Base to Derived (DownCasting)
//	Derived d2;
//	Base* b3 = (Base*) &d2;	
//	Derived& d3 = dynamic_cast<Derived&>(*b3);
//	d3.doThings();
//
//	return 0;
//}