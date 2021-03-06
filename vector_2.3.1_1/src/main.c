/*
There is a non-decreasing vector. Please write a function of inserting a element that still keep the vector non-decreasing.

非递减有序序列，插入一个元素，仍然保持该序列非递减有序
*/
#include <stdio.h>
#include <stdlib.h>

#define M 32

static int insert(int* vector, int n, int value) {
	int i = 0, j = 0;

	if (value >= vector[n - 1]) {
		vector[n] = value;
	}
	else {
		while (value >= vector[i]) {
			i++;
		}

		for (j = n - 1; j >= i; j--) {
			vector[j + 1] = vector[j];
		}

		vector[i] = value;
	}

	n++;

	return n;
}

void output(int* vector, int n){
	for (int i = 0; i < n; i++){
		printf("%d\n", vector[i]);
	}
}

int main(int argc, char** argv){
	int vector[M] = {0};
	int n = 0;
	int m = 0;
	int data = 0;

	printf("please sequence size:");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("input a data:");
		scanf("%d", &vector[i]);
	}

	printf("please insert a data:");
	scanf("%d", &data);

	m = insert(vector, n, data);

	output(vector, m);
	printf("the new size is:%d\n", m);

	return 0;
}