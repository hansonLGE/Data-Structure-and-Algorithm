/*
stack operation,such as push, pop and top.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct _stack {
	int st[MAX];
	int top;
}stack;

void push(stack* s, int x) {
	if (s->top == MAX) {
		printf("the stack is full.\n");
	}
	else {
		s->top++;
		s->st[s->top] = x;
	}
}

void pop(stack* s) {
	if (s->top == 0) {
		printf("the stack is empty.\n");
	}
	else {
		s->top--;
	}
}

void top(stack* s, int* x) {
	if (s->top == 0) {
		printf("the stack is empty.\n");
	}
	else {
		*x = s->st[s->top];
	}
}

int main(int argc, char** argv) {
	int size = 0;
	int x = 0;
	stack s;
	memset(&s, 0, sizeof(s));

	printf("create a stack, please input size of the stack:");
	scanf("%d", &size);

	for (int i = 0; i < size; i++) {
		printf("push a data:");
		scanf("%d", &x);

		push(&s, x);
	}

	top(&s, &x);
	printf("top data is:%d\n", x);
	return 0;
}