/*
Const_cast:
	The only way to cast away the const properties of an object is to use const_cast.
	Allows any pointer to be converted into any other pointer type. Also allows any integral type to be converted into any pointer type and vice versa..

	Eg:
		int a;
		const char *ptr_my = "Hello";
		a  = const_cast<int *>(ptr_my);
*/