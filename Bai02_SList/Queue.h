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

struct queue
{
	LIST* array;
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