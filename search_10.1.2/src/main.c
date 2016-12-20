#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

int binsearch(int* vec, int key, int low, int high) {
	int mid = 0;

	if (low > high) {
		return -1;
	}
	else {
		mid = (low + high) / 2;

		if (key < vec[mid]) {
			return binsearch(vec, key, low, mid - 1);
		}
		else if (key > vec[mid]) {
			return binsearch(vec, key, low + 1, high);
		}
		else {
			return mid;
		}
	}
}

int main(int argc, char** argv) {
	int vec[MAXSIZE] = {0};
	int n = 0;
	int key = 0;
	int ret = 0;

	printf("please input data size:");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("input a int data:");
		scanf("%d", &vec[i]);
	}

	while (1) {
		printf("input a search key:");
		scanf("%d", &key);
		ret = binsearch(vec, key, 0, n - 1);
		if (ret == -1) {
			printf("failed to find.\n");
		}
		else {
			printf("the location is:%d.\n", ret);
		}
	}

}