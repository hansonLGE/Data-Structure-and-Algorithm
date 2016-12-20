#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int bin_search(int* vec, int x, int low, int high) {
	int mid = 0;

	if (low > high) {
		return low;
	}
	else {
		mid = (low + high)/2;
		if (x == vec[mid]) {
			return mid;
		}
		else if (x > vec[mid]) {
			return bin_search(vec, x, mid + 1, high);
		}
		else {
			return bin_search(vec, x, low, mid - 1);
		}
	}
}

void bin_sort(int* vec, int n) {
	int tmp = 0;
	int j = 0;
	int low = 0;
	int high = 0;
	int idx = 0;

	for (int i = 1; i < n; i++) {
		tmp = vec[i];

		low = 0;
		high = i - 1;
		idx = bin_search(vec, tmp, low, high);

		for (j = i - 1; j >= idx; j--) {
			vec[j + 1] = vec[j];
		}

		vec[idx] = tmp;
	}
}

void insert_sort(int* vec, int n) {
	int tmp = 0;
	int j = 0;

	for (int i = 1; i < n; i++) {
		tmp = vec[i];

		j = i - 1;
		while (j>=0 && vec[j] > tmp) {
			vec[j + 1] = vec[j];
			j--;
		}

		vec[j + 1] = tmp;
	}
}

void bubble_sort(int* vec, int n) {
	int tmp = 0;

	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j <n-1-i; j++) {
			if (vec[j] > vec[j + 1]) {
				tmp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = tmp;
			}
		}
	}
}

void quick_sort(int* vec, int left, int right) {
	int i = left;
	int j = right;
	int tmp = 0;

	if (left < right) {
		tmp = vec[left];

		while (i < j) {
			while (i<j && vec[j] >= tmp) {
				j--;
			}
			if (i < j) {
				vec[i] = vec[j];
				i++;
			}

			while (i < j && vec[i] <= tmp) {
				i++;
			}
			if (i < j) {
				vec[j] = vec[i];
				j--;
			}
		}

		vec[i] = tmp;
		quick_sort(vec, left, i - 1);
		quick_sort(vec, i + 1, right);
	}
}

void choose_sort(int* vec, int n) {
	int k = 0;

	for (int i = 0; i < n - 1; i++) {
		k = i;

		for (int j = i + 1; j < n; j++) {
			if (vec[j] < vec[k]) {
				k = j;
			}
		}

		if (k != i) {
			int tmp = vec[i];
			vec[i] = vec[k];
			vec[k] = tmp;
		}
	}
}

void sift(int* vec, int idx) {
	int i = idx;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int tmp = 0;
	int j = 0;

	while ((vec[left] != 0 && vec[left] > vec[i]) || (vec[right] != 0 && vec[right] > vec[i])) {
		if (vec[left] > vec[right]) {
			j = left;
		}
		else {
			j = right;
		}

		tmp = vec[i];
		vec[i] = vec[j];
		vec[j] = tmp;

		i = j;
		left = 2 * i + 1;
		right = 2 * i + 2;
	}
}

void heap_sort(int* vec, int n) {
	int i = 0;
	int m = n - 1;
	int tmp = 0;

	for (i = n/2 -1; i >= 0; i--) {
		sift(vec, i);
	}

	while (vec[0] != 0) {
		printf("%d ", vec[0]);
		vec[0] = vec[m];
		vec[m] = 0;
		m--;

		sift(vec, 0);
	}
	printf("\n");
}

void output(int* vec, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", vec[i]);
	}

	printf("\n");
}

int main(int argc, char** argv) {
	int n = 0;
	int vec[MAX] = { 0 };

	printf("please input the size of a recoed:");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("input a int data:");
		scanf("%d", &vec[i]);
	}

	//insert_sort(vec, n);
	//bin_sort(vec, n);
	//bubble_sort(vec, n);
	//quick_sort(vec, 0, n - 1);
	//choose_sort(vec, n);
	//output(vec, n);
	heap_sort(vec, n);

	return 0;
}