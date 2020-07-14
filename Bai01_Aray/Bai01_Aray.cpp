// Bai01_Aray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Stack.h"


int main()
{
	STACK* s = createStack(1000);

	push(s, 10);
	push(s, -5);
	push(s, 153);
	push(s, -13);
	push(s, 342);

	cout << "pop: " << pop(s) << endl;
	cout << "peek: " << peek(s) << endl;

	empty(s);

	return 0;
}