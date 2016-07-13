//#include <iostream>
//using namespace std;
//
//class Animal // base class
//{
//public:
//	int weight;
//	virtual int getWeight() 
//	{
//		weight = 100;
//		return weight;
//	}
//};
//
//class Tiger: public Animal 
//{
//public:
//	int weight;
//
//	int getWeight() 
//	{
//		weight = 200;
//		return weight;
//	}
//};
//
//int main()
//{	
//	Tiger t1;
//
//	/* below, an Animal object pointer is set to point 	to an object of the derived Tiger class  */
//	Animal *a1 = &t1; 
//
//	/*  below, how does this know to call the definition of getWeight in the Tiger class, and not the definition provided in the Animal class  */
//	cout<<a1 -> getWeight()<<endl; //100 if not use virtual otherwise 200
//	return 0;
//}			