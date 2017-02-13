/*
please write a function that deletes some elements which range from min to max. Note：we need to pay attention to the efficiency.

编写一个函数，删除多个元素，其值在（min, max）之间，要求高效率。
*/
#include <stdio.h>
#include <stdlib.h>

#define M 32

int delete(int* vector, int n, int min, int max){
	int i = 0, k = 0;

	while (i < n){
		if (vector[i] >= min && vector[i] <= max) {
			k++;
		}
		else {
			vector[i - k] = vector[i];
		}

		i++;
	}

	return n - k;
}

void output(int* vector, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d\n", vector[i]);
	}
}

int main(int argc, char** argv){
	int vector[M] = { 0 };
	int n = 0;
	int min = 0;
	int max = 0;

	printf("please input vector size:");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("input a int element:");
		scanf("%d", &vector[i]);
	}

	printf("please input the interval(min, max):");
	scanf("%d %d", &min, &max);

	int m = delete(vector, n, min, max);

	output(vector, m);
	return 0;
}