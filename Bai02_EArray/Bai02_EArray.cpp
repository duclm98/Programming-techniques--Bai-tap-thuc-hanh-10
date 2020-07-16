// Bai02_EArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Queue.h"

int main()
{
	QUEUE* q = createQueue(1000);

	enqueue(q, 10);
	enqueue(q, -5);
	enqueue(q, 153);
	enqueue(q, -13);
	enqueue(q, 342);

	cout << "dequeue: " << dequeue(q) << endl;
	cout << "peek: " << peek(q) << endl;

	empty(q);

	return 0;
}