/*
Abstruct Vs Interface:
Interfaces can have no state or implementation
A class that implements an interface must provide an implementation of all the method of that interface
Abstract classes may contain state (data members) and/or implementation (methods)
Abstract classes can be inherited without implementing the abstract methods (though such a derived class is abstract itself)
Interfaces may be multiple-inherited, abstract classes may not (this is probably the key concrete reason for interfaces to exist separately from abtract classes - they permit an implementation of multiple inheritance that removes many of the problems of general MI).
If you anticipate creating multiple versions of your component, create an abstract class. Abstract classes provide a simple and easy way to version your components. By updating the base class, all inheriting classes are automatically updated with the change. Interfaces, on the other hand, cannot be changed once created. If a new version of an interface is required, you must create a whole new interface.
If the functionality you are creating will be useful across a wide range of disparate objects, use an interface. Abstract classes should be used primarily for objects that are closely related, whereas interfaces are best suited for providing common functionality to unrelated classes.

Usage:
The purpose of an abstract class is to define a common protocol for a set of concrete subclasses
code reuse and proper partitioning across classes. 
It allows strict run time polymorphism.
Abstract classes allow for compile time protocol enforcement.
It makes more sense to define a function once in a parent class rather than defining over and over again in multiple subclasses
*/

//#include <iostream> 
//using namespace std;
// 
//// Base class
//class Shape 
//{
//public:
//	//Constructor
//	Shape() 
//	{ 
//		cout<<"In Shape Constructor"<<endl;
//	}
//	~Shape()
//	{
//		cout<<"In Shape Destructor"<<endl;
//	}
//
//   // pure virtual function providing interface framework.
//   virtual int getArea() = 0;
//
//   //Member Function
//   void setWidth(int w)
//   {
//      width = w;
//   }
//   void setHeight(int h)
//   {
//      height = h;
//   }
//
//protected:
//	//Member Variable
//   int width;
//   int height;
//};
// 
//// Derived classes
//class Rectangle: public Shape
//{
//public:
//	//Constructor
//	Rectangle() 
//	{ 
//		cout<<"In Rectangle Constructor"<<endl;
//	}
//	~Rectangle()
//	{
//		cout<<"In Rectangle Destructor"<<endl;
//	}
//
//	int getArea()
//   { 
//      return (width * height); 
//   }
//};
// 
//int main(void)
//{
//	Rectangle *Rect = new Rectangle(); 
//	Rect->setWidth(5);
//	Rect->setHeight(7);
//	cout << "Total Rectangle area: " << Rect->getArea() << endl;
//	delete Rect;
//	return 0;
//}