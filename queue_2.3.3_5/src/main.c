#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct _queue {
	int qe[MAXSIZE];
	int front;
	int count;
} queue;

void makenull(queue* qu){
	qu->front = 1;
	qu->count = 0;
}

int isEmpty(queue* qu) {
	if (qu->count == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int pop(queue* qu) {
	int ret = 0;

	if (qu->count == 0) {
		printf("the queue is empty.\n");
	}
	else {
		ret = qu->qe[qu->front];
		qu->front = (qu->front + 1) % MAXSIZE;
	}

	return ret;
}

void enqueue(queue* qu, int x) {
	int place = 0;
	if (qu->count == MAXSIZE) {
		printf("the queue is full.\n");
	}
	else {
		place = (qu->front + qu->count) % MAXSIZE;
		qu->qe[place] = x;
		qu->count++;
	}
}

int dequeue(queue* qu) {
	int ret = 0;

	if (qu->count == 0) {
		printf("the queue is empty.\n");
	}
	else {
		ret = qu->qe[qu->front];
		qu->front = (qu->front + 1) % MAXSIZE;
		qu->count--;
	}

	return ret;
}

int main(int argc, char** argv) {
	queue qu;
	memset(&qu, 0, sizeof(qu));

	enqueue(&qu, 34);
	enqueue(&qu, 89);

	printf("pop value is:%d\n", pop(&qu));
	printf("dequeue value is:%d\n", dequeue(&qu));

	return 0;
}