// main.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "RationalNumber.h"

int main()
{
	RationalNumber a(3,5);
	RationalNumber b(2,7);
	cout << a << endl;
	cout << b << endl;
	cout << a + b << endl;
	cout << a - b << endl;
	cout << ++a << endl;
	cout << a * b << endl;
	return 0;
}

