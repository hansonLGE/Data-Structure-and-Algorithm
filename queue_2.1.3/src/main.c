/*
Circular Queue: eng,deq
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct queue {
	int qu[MAXSIZE];
	int front;
	int rear;
} queue;

int is_empty(queue* qu) {
	if (qu->front == qu->rear) {
		return 1;
	}

	return 0;
}

void enq(queue* qu, int value){
	if ((qu->rear + 1) % MAXSIZE == qu->front) {
		printf("the queue is enough.\n");
	}
	else {
		qu->rear = (qu->rear + 1) % MAXSIZE;
		qu->qu[qu->rear] = value;
	}
}
void deq(queue* qu, int* ptr_data){
	if (is_empty(qu)) {
		printf("the queue is empty.\n");
	}
	else {
		qu->front = (qu->front + 1) % MAXSIZE;
		*ptr_data = qu->qu[qu->front];
	}
}

int main(int argc, char** argv){
	int data;
	int ret;
	queue qu;
	memset(&qu, 0, sizeof(qu));

	printf("create a circular queue(size is 5).\n");
	for (int i = 0; i < 5; i++) {
		printf("enqueue a int data:");
		scanf("%d", &data);
		enq(&qu, data);
	}

	deq(&qu, &ret);
	printf("out the first data is :%d\n", ret);

	return 0;
}