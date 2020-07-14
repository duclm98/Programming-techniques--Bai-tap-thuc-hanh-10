#pragma once
#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};
typedef struct node NODE;

struct list 
{
	NODE* head;
	NODE* tail;
};
typedef struct list LIST;

struct stack
{
	LIST* array;
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