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

	if (q->array->head == NULL && q->array->tail == NULL) {
		q->array->head = q->array->tail = node;
		node->next = node->prev = NULL;
		return;
	}

	node->next = q->array->head;
	node->prev = NULL;

	q->array->head->prev = node;
	q->array->head = node;
}

int dequeue(QUEUE* q) {
	if (isEmpty(q)) {
		return INT_MAX;
	}
	NODE* node = q->array->tail;
	int data = node->data;
	NODE* p = q->array->tail->prev;
	p->next = NULL;
	q->array->tail = p;

	delete node;

	q->top--;

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