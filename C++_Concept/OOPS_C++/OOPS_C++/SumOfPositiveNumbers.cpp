//#include <iostream>
//using namespace std;
//
//int main()
//{
//	signed int num;
//	static unsigned int l_SumOfPos = 0;
//	static signed int l_SumOfNeg = 0;
//	static unsigned int l_SumOfEven = 0;
//	static unsigned int l_SumOfOdd = 0;
//
//	while(1)
//	{
//		cout << "Enter a number to be added to your list, 0 to exit" << endl;
//		cin >> num;
//
//		if(num != 0)
//		{
//			if(num<0)
//			{
//				l_SumOfNeg = l_SumOfNeg + num;
//			} 
//			else 
//			{
//				l_SumOfPos = l_SumOfPos + num;
//
//				if(num%2 == 0)
//				{
//					l_SumOfEven = l_SumOfEven + num;
//				} 
//				else 
//				{
//					l_SumOfOdd = l_SumOfOdd + num;
//				}
//			}
//		} 
//		else 
//		{
//			break;
//		}
//	}
//
//	cout << "Sum of All Positive numbers: " << l_SumOfPos << endl;
//	cout << "Sum of All Negative numbers: " << l_SumOfNeg << endl;
//	cout << "Sum of All Even numbers: " << l_SumOfEven << endl;
//	cout << "Sum of All Odd numbers: " << l_SumOfOdd << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Base
//{
//public:
//	virtual void fun()=0;
//
//};
//
//class deri:public Base
//{
//public:
//	void fun()
//	{
//		cout<<"i am here";
//	}
//	//Base::fun();
//};
//
//int main()
//{
//	deri d;
//	//Base b;
//	d.fun();
//	return 0;
//}