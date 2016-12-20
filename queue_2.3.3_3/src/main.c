#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXSIZE 100
typedef struct queue {
	int qu[MAXSIZE];
	int front;
	int rear;
} queue;

void enqueue(queue* qu, int value) {
	if ((qu->rear + 1) % MAXSIZE == qu->front) {
		printf("the queue is full.\n");
	}
	else {
		qu->rear = (qu->rear + 1) % MAXSIZE;
		qu->qu[qu->rear] = value;
	}
}

int dequeue(queue* qu) {
	int ret = 0;

	if (qu->front == qu->rear) {
		printf("the queue is empty.\n");
	}
	else {
		qu->front = (qu->front + 1) % MAXSIZE;
		ret = qu->qu[qu->front];
	}

	return ret;
}

int main(int argc, char** argv) {
	queue qe;
	memset(&qe, 0, sizeof(qe));

	enqueue(&qe, 11);
	int value = dequeue(&qe);

	printf("de queue a value:%d\n", value);

	return 0;
}