#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct vector {
	int array[MAXSIZE];
	int top1;
	int top2;
} vector;

void push(vector* vec, int value, int i) {
	if (vec->top1 + 1 == vec->top2) {
		printf("the vector is full.\n");
	}
	else {
		if (i == 1) {
			vec->top1++;
			vec->array[vec->top1] = value;
		}
		else {
			vec->top2--;
			vec->array[vec->top2] = value;

		}
	}
}

int pop(vector* vec, int i) {
	int ret = 0;

	if (i == 1) {
		if (vec->top1 == 0) {
			printf("the stack1 is empty.\n");
		}
		else {
			ret = vec->array[vec->top1];
			vec->top1--;
		}
	}
	else {
		if (vec->top2 == MAXSIZE + 1) {
			printf("the stack2 is empty.\n");
		}
		else {
			ret = vec->array[vec->top2];
			vec->top2++;
		}
	}

	return ret;
}

void setnull(vector* vec, int i) {
	if (i == 1) {
		vec->top1 = 0;
	}
	else {
		vec->top2 = MAXSIZE + 1;
	}
}

int main(int argc, char** argv) {
	vector array;
	memset(&array, 0, sizeof(array));

	push(&array, 5, 1);
	int value = pop(&array, 1);

	printf("pop value:%d\n", value);

	setnull(&array, 1);
}