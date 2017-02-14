/*
验证表达式是否正确。

Please write a function to check a expression whether it is correct or not.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct stack {
	char s[MAXSIZE];
	int top;
} stack;

void push(stack* st, char c){
	if (st->top == MAXSIZE) {
		printf("the stack is full.\n");
	}
	else {
		st->top++;
		st->s[st->top] = c;
	}
}

char pop(stack* st) {
	char ret = 0;

	if (st->top == 0) {
		printf("the stack is empty.\n");
	}
	else {
		ret = st->s[st->top];
		st->top--;
	}

	return ret;
}

int correct(stack* st, char* array) {
	int tag = 1;
	int i = 0;
	while (array[i] != '\0' && tag == 1) {
		if (array[i] == '(' || array[i] == '[' || array[i] == '{') {
			push(st, array[i]);
		}
		else {
			if (array[i] == ')') {
				if (pop(st) != '(') {
					tag = 0;
					break;
				}
			}
			else if (array[i] == ']') {
				if (pop(st) != '[') {
					tag = 0;
					break;
				}
			}
			else if (array[i] == '}') {
				if (pop(st) != '{') {
					tag = 0;
					break;
				}
			}
		}

		i++;
	}

	if (st->top > 0) {
		tag = 0;
	}

	return tag;
}

int main(int argc, char** argv) {
	char exp[MAXSIZE] = {'\0'};
	stack st;
	memset(&st, 0, sizeof(st));

	printf("please input a expression:");
	scanf("%s", exp);

	if (correct(&st, exp)) {
		printf("the exp is correct.\n");
	}
	else {
		printf("the exp is wrong.\n");
	}

	return 0;
}