#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100
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
		enqueue(st2, pop(st1));
	}

	ret = pop(st2);

	while (!is_empty(st2)) {
		enqueue(st1, pop(st2));
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

	memset(&st1, 0, sizeof(st1));
	memset(&st2, 0, sizeof(st2));

	enqueue(&st1, 23);
	enqueue(&st1, 43);

	val = dequeue(&st1, &st2);
	printf("dequeue a value is:%d\n", val);

	val = dequeue(&st1, &st2);
	printf("dequeue a value is:%d\n", val);

	return 0;
}