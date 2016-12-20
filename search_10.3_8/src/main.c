#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

int binsearch(int* array, int low, int high, int x) {
	int mid = 0;

	if (low > high) {
		return low;
	}
	else {
		mid = (low + high) / 2;
		if (x == array[mid]) {
			return mid;
		}
		else if (x > array[mid]) {
			return binsearch(array, mid + 1, high, x);
		}
		else {
			return binsearch(array, low, mid - 1, x);
		}
	}
}

void bininsert(int* array, int* n, int x) {
	int idx = binsearch(array, 0, *n - 1, x);

	printf("before %d insert the new data.\n", idx);

	for (int i = *n - 1; i >= idx; i--) {
		array[i + 1] = array[i];
	}

	array[idx] = x;
	(*n)++;
}

int main(int argc, char** argv) {
	int vec[MAXSIZE] = {0};
	int n = 0;
	int x = 0;

	printf("create a ordered sequence:\n");
	printf("input the size:");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("input a int data:");
		scanf("%d", &vec[i]);
	}

	while (1) {
		printf("input the insert data(int):");
		scanf("%d", &x);
		bininsert(vec, &n, x);

		for (int i = 0; i < n; i++) {
			printf("%d ", vec[i]);
		}
		printf("\n");
	}

	return 0;
}