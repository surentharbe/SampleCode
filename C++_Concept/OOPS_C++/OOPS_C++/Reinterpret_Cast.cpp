/*
Reinterpret_Cast:
	This operator is used to convert any pointer to any other pointer type. It also can be used to convert any integral type to any pointer type and vice versa.
	Because of the unrelated or ‘random’ type conversion can be done using reinterpret_cast, it can be easily unsafe if used improperly and it is non portable.
	It should only be used when absolutely necessary.
	It cannot be used for const-ness and volatile-ness conversion.
	Can be used to convert for example, int* to char*, or classA to classB, which both class are unrelated classes, between two unrelated pointers, pointers to members or pointers to functions.
	For null pointer, it converts a null pointer value to the null pointer value of the destination type. 
	The reinterpret_cast is used for casts that are not safe:
		1. Between integers and pointers
		2. Between pointers and pointers
		3. Between function-pointers and function-pointers
	Eg:
	char *ptr_my = reinterpret_cast<char *>(0xb0000);

	char *ptr_my = 0;
	int *ptr_my_second = reinterpret_cast<int *>(ptr_my);
*/

//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//
//unsigned int* Test(int *q)
//{
// //convert int pointer to unsigned int pointer
// unsigned int* code = reinterpret_cast<unsigned int*>(q);
// //return the converted type data, a pointer...
// return code;
//}
//
//int main(void)
//{
// //array name is a pointer...
// int a[10];
// cout<<"int pointer unsigned int pointer"<<endl;
// for(int i = 0;i<=10;i++)
// cout<<(a+i)<<" converted to "<<Test(a+i)<<endl;
// return 0;
//}