//#include <iostream>
//using namespace std;
//
//class Animal
//{
//public:
//	int age;
//	Animal()
//	{
//		age = 10;
//		cout << "animal constructor"<<endl;
//	}
//
//};
//
//class Tiger :virtual public Animal
//{
//public:
//	Tiger()
//	{
//		cout <<"constructor of tiger"<<endl;
//	}
//};
//
//class Lion :virtual public Animal
//{
//public:
//	Lion()
//	{
//		cout <<"constructor of Lion"<<endl;
//	}
//};
//
//class Liger : public Tiger , public Lion
//{
//public:
//	Liger()
//	{
//		cout <<"constructor of Liger"<<endl;
//	}
//	void showAge()
//	{
//		cout <<age<<endl;
//	}
//};
//
//int main()
//{
//	Liger l;
//	l.showAge();
//	return 0;
//}