#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct stack {
	int s[MAXSIZE];
	int top;
} stack;

int is_empty(stack* st) {
	if (st->top < 0) {
		return 1;
	}

	return 0;
}

void push(stack* st, int value) {
	if (st->top == MAXSIZE - 1) {
		printf("the stack size is enough.\n");
	}
	else {
		st->top++;
		st->s[st->top] = value;
	}
}

void pop(stack* st, int* ptr_data) {

	if (is_empty(st)) {
		printf("the stack is null.\n");
	}
	else {
		*ptr_data = st->s[st->top];
		st->top--;
	}
}

void top(stack* st, int* ptr_data){
	if (is_empty(st)) {
		printf("the stack is null.\n");
	}
	else {
		*ptr_data = st->s[st->top];
	}
}

int main(int argc, char** argv) {
	stack st;
	int value;
	int ret;
		
	memset(&st, 0, sizeof(st));
	st.top = -1;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &value);
		push(&st, value);
	}

	pop(&st, &ret);
	printf("pop a data:%d\n", ret);

	top(&st, &ret);
	printf("top a data:%d\n", ret);

	return 0;
}