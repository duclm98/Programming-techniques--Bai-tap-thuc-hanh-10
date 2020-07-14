#include "Queue.h"

LIST* createList() {
	LIST* l = new LIST;
	l->head = NULL;
	l->tail = NULL;

	return l;
}

QUEUE* createQueue(unsigned int capacity) {
	QUEUE* queue = new QUEUE;
	queue->top = -1;
	queue->capacity = capacity;
	queue->array = createList();

	return queue;
}

bool isFull(QUEUE* q) {
	return (q->top >= (int)q->capacity - 1);
}

bool isEmpty(QUEUE* q) {
	return q->top == -1;
}

void enqueue(QUEUE* q, int item) {
	if (isFull(q)) {
		cout << "Queue da day!" << endl;
		return;
	}
	q->top++;
	NODE* node = new NODE;
	node->data = item;
	node->next = NULL;
	q->array->tail->next = node;
	q->array->tail = node;
}

int dequeue(QUEUE* q) {
	if (isEmpty(q)) {
		return INT_MAX;
	}
	NODE* node = q->array->tail;
	int data = node->data;
	NODE* p = q->array->head;
	while (p->next != q->array->tail)
	{
		p = p->next;
	}
	p->next = NULL;
	delete node;

	return data;
}

int peek(QUEUE* q) {
	if (isEmpty(q)) {
		return INT_MAX;
	}
	return q->array->tail->data;
}

void empty(QUEUE* q) {
	q->capacity = 0;
	q->top = -1;
	NODE* node = q->array->head;
	while (node) {
		NODE* tmp = node;
		node = node->next;
		q->array->head = node;
		delete tmp;
	}
}