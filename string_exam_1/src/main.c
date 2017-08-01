/*
Given a string which is make up by some world, please write s function to revert the words. For example, "hello world"-->"world hello"
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100

typedef struct _stack{
	char s[N];
	int top;
} stack;

int is_full(stack* st){
	if (st->top == N) {
		return 1;
	}

	return 0;
}

int is_empty(stack* st) {
	if (st->top == 0) {
		return 1;
	}

	return 0;
}

void push(stack* st, char x) {
	if (!is_full(st)) {
		st->top++;
		st->s[st->top] = x;
	}
}

char top(stack* st) {
	if (!is_empty(st)) {
		return st->s[st->top];
	}

	return 0;
}

void pop(stack* st) {
	if (!is_empty(st)) {
		st->top--;
	}
}

int main(int argc, char** argv) {
	char str[N] = { '\0' };
	printf("input a string which is make up by some world:");
	scanf("%[^\n]", str);

	stack st;
	memset(&st, 0, sizeof(stack));
	int n = strlen(str);

	for (int i = n - 1; i >= 0; i--) {
		if (str[i] != ' ') {
			push(&st, str[i]);
		}
		else {
			while (!is_empty(&st)) {
				printf("%c", top(&st));
				pop(&st);
			}
			printf(" ");
		}
	}

	while (!is_empty(&st)) {
		printf("%c", top(&st));
		pop(&st);
	}
	return 0;
}