#pragma once
#include <iostream>
using namespace std;

struct stack
{
	int* array;
	unsigned int capacity;
	int top;
};
typedef struct stack STACK;

STACK* createStack(unsigned int capacity);
bool isFull(STACK* s);
bool isEmpty(STACK* s);
void push(STACK* s, int item);
int pop(STACK* s);
int peek(STACK* s);
void empty(STACK* s);