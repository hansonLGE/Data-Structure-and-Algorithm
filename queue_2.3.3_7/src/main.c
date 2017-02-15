/*
Please write the functions of a queue by two stacks, s1 and s2.

利用2个栈s1和s2,模拟队列操作：enqueue, dequeue, is_queue_empty
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100
#define M 2

typedef struct _stack{
	int s[MAXSIZE];
	int top;
} stack;

int is_empty(stack* st) {
	if (st->top == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void push(stack* st, int value) {
	if (st->top == MAXSIZE) {
		printf("the stack is full.\n");
	}
	else {
		st->top++;
		st->s[st->top] = value;
	}
}

int pop(stack* st) {
	int ret = 0;

	if (is_empty(st)) {
		printf("the stack is empty.\n");
	}
	else {
		ret = st->s[st->top];
		st->top--;
	}

	return ret;
}

void enqueue(stack* st, int x) {
	if (st->top == MAXSIZE) {
		printf("the queue is full.\n");
	}
	else {
		push(st, x);
	}
}

int dequeue(stack* st1, stack* st2) {
	int ret = 0;

	while (!is_empty(st1)) {
		push(st2, pop(st1));
	}

	ret = pop(st2);

	while (!is_empty(st2)) {
		push(st1, pop(st2));
	}

	return ret;
}

int is_queue_empty(stack* st){
	if (is_empty(st)){
		return 1;
	}
	else {
		return 0;
	}
}

int main(int argc, char** argv) {
	stack st1;
	stack st2;
	int val = 0;
	int x = 0;

	memset(&st1, 0, sizeof(st1));
	memset(&st2, 0, sizeof(st2));

	for (int i = 0; i < M; i++) {
		printf("enqueue a int element:");
		scanf("%d", &x);
		enqueue(&st1, x);
	}

	while (!is_queue_empty(&st1)) {
		val = dequeue(&st1, &st2);
		printf("dequeue a value is:%d\n", val);
	}

	return 0;
}