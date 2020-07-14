#pragma once
#include <iostream>
using namespace std;

struct queue
{
	int* array;
	unsigned int capacity;
	int top;
};
typedef struct queue QUEUE;

QUEUE* createQueue(unsigned int capacity);
bool isFull(QUEUE* q);
bool isEmpty(QUEUE* q);
void enqueue(QUEUE* q, int item);
int dequeue(QUEUE* q);
int peek(QUEUE* q);
void empty(QUEUE* q);