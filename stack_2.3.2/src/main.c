/*
There are two stacks(s1 & s2)that both share a vector called c[1, m]. In initial state, the bottom of stack pointer in s1 points to c[1] and
the bottom of stack pointer in s2 points to c[m]. Please write the functions push(i, x)��pop(i) and setnull(i), i=1,2. 
Note: push(i, x) is going to push a data x into s1 or s2. pop(i) is going to pop a data from s1 or s2. setnull(i) is going to empty s1 or s2.
      s1 and s2 will be fulled only if there is no enough room to be placed. 

������ջs1��s2����洢�ռ�c[1, m]������s1��ջ����c[1]����s2��ջ����c[m]�����ֱ��дs1��s2�Ľ�ջpush(i, x)����ջpop(i)������ջ��setnull(i)������
����i=1��2��ע����������ռ�c[1, m]ռ��ʱ�Ų����������
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct _vector {
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