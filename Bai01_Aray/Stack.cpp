#include "Stack.h"

STACK* createStack(unsigned int capacity) {
	STACK* stack = new STACK;
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = new int[capacity];

	return stack;
}

bool isFull(STACK* s) {
	return (s->top >= (int)s->capacity - 1);
}

bool isEmpty(STACK* s) {
	return s->top == -1;
}

void push(STACK* s, int item) {
	if (isFull(s)) {
		cout << "Stack da day!" << endl;
		return;
	}
	s->array[++s->top] = item;
}

int pop(STACK* s) {
	if (isEmpty(s)) {
		return INT_MAX;
	}
	return s->array[s->top--];
}

int peek(STACK* s) {
	if (isEmpty(s)) {
		return INT_MAX;
	}
	return s->array[s->top];
}

void empty(STACK* s) {
	s->capacity = 0;
	s->top = -1;
	delete[] s->array;
}