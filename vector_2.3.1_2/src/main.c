/*
There is a non-decreasing vector. Please write a function of deleting same element to keep one.

已知一个向量中的元素按元素值非递减有序排序，编写一个函数删除向量中多余的值相同的元素。
*/
#include <stdio.h>
#include <stdlib.h>

#define M 16

static int delete(int* vector, int n) {
	int i = 0;
	while (i < n){
		if (vector[i] != vector[i + 1]) {
			i++;
		}
		else {
			for (int j = i; j < n; j++) {
				vector[j] = vector[j + 1];
			}

			n--;
		}
	}

	return n;
}

void output(int* vector, int n){
	for (int i = 0; i < n; i++){
		printf("%d\n", vector[i]);
	}
}

int main(int argc, char** argv) {
	int vector[M] = { 0 };
	int n;
	printf("please input vector size:");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("input a data:");
		scanf("%d", &vector[i]);
	}

	int m = delete(vector, n);

	output(vector, m);

	return 0;
}