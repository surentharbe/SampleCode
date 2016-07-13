/*
Static_Cast:
	Used for conversion of nonpolymorphic types.
	Conversion from derived class to base class (DownCasting).
	Standard conversion. For instance: from short to int or from int to float.
	This cast type uses information available at compile time to perform the required type conversion. 
*/

//#include <iostream>
//using namespace std;
//
//class Base 
//{
//public:
//	void doThings()
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
//	Base *b1 = new Derived();
//	b1->doThings();							//Inside Base. It should give the output as Inside Derived. because Base object is pointing to derived class.
//	
//	//Instead of above code we can use below code for nonpolymorphic types
//	Base *b = new Base();
//	Derived *d = static_cast<Derived*>(b);
//	d->doThings();							//Inside Derived
//
//	return 0;
//}