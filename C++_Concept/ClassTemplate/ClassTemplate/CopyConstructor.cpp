#include<iostream>
using namespace std;

class Employee
{
public:
	Employee()
	{
		cout<<"Constructor"<<endl;
	}
	Employee(Employee &obj)
	{
		cout<<"Copy Constructor"<<endl;
	}
	void operator=(Employee &obj)
	{
		cout<<"Assignment operator"<<endl;		
	}
};

int main()
{
	Employee obj;
	//Employee obj1(obj);
	//Employee obj2 = obj;
	Employee obj3;
	obj3 = obj;
}