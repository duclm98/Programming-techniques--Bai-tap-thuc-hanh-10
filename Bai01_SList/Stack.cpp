#include "Stack.h"

LIST* createList() {
	LIST* l = new LIST;
	l->head = NULL;
	l->tail = NULL;

	return l;
}

STACK* createStack(unsigned int capacity) {
	STACK* stack = new STACK;
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = createList();

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
	s->top++;
	NODE* node = new NODE;
	node->data = item;
	node->next = s->array->head;
	s->array->head = node;
}

int pop(STACK* s) {
	if (isEmpty(s)) {
		return INT_MAX;
	}
	NODE* node = s->array->head;
	int data = node->data;
	s->array->head = s->array->head->next;
	delete node;

	return data;
}

int peek(STACK* s) {
	if (isEmpty(s)) {
		return INT_MAX;
	}
	return s->array->head->data;
}

void empty(STACK* s) {
	s->capacity = 0;
	s->top = -1;
	NODE* node = s->array->head;
	while (node) {
		NODE* tmp = node;
		node = node->next;
		s->array->head = node;
		delete tmp;
	}
}