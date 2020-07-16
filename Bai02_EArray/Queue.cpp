#include "Queue.h"

QUEUE* createQueue(unsigned int capacity) {
	QUEUE* queue = new QUEUE;
	queue->top = -1;
	queue->capacity = capacity;
	queue->array = new int[capacity];

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
	q->array[++q->top] = item;
}

int dequeue(QUEUE* q) {
	if (isEmpty(q)) {
		return INT_MAX;
	}
	int data = q->array[0];
	for (int i = 0; i < q->top - 1; i++) {
		q->array[i] = q->array[i + 1];
	}
	q->top--;
	return data;
}

int peek(QUEUE* q) {
	if (isEmpty(q)) {
		return INT_MAX;
	}
	return q->array[0];
}

void empty(QUEUE* q) {
	q->capacity = 0;
	q->top = -1;
	delete[] q->array;
}