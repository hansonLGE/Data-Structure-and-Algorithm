/*
basic operation for vector, such as insert and delete.
*/
#include <stdio.h>
#include <stdlib.h>

#define N 5

void create(int* vector, int n) {
	for (int i = 0; i < n; i++) {
		printf("input a int data:");
		scanf("%d", &vector[i]);
	}
}

void insert(int* vector, int i, int value) {
	if (i <= 0 || i > N) {
		printf("%s\n", "the insert location is wrong.");
	}
	else {
		for (int j = N - 1; j >= i - 1; j--) {
			vector[j + 1] = vector[j];
		}

		vector[i - 1] = value;

	}
}

void delete(int* vector, int i) {
	if (i <= 0 || i > N) {
		printf("%s\n", "the delete location is wrong.");
	}
	else {
		for (int j = i-1; j < N; j++) {
			vector[j] = vector[j+1];
		}
	}
}

void find(int* vector, int value) {
	int i = 0;
	while (i < N && vector[i] != value) {
		i++;
	}

	if (i < N) {
		printf("success to find it!\n");
	}
	else {
		printf("failed to find it!\n");
	}
}

void output(int* vector, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d\n", vector[i]);
	}
}

int main(int argc, char** argv) {
	int array[N + 1];
	int x = 0;

	printf("create a vector.\n");
	create(array, N);
	//insert(array, 3, 10);
	//output(array, N+1);

	//delete(array, 2);
	//output(array, N - 1);

	printf("find a data.\n");
	printf("input a int data:");
	scanf("%d", &x);
	find(array, x);

	return 0;
}