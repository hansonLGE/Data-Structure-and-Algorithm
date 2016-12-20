#include <stdio.h>
#include <stdlib.h>

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
	int vector[32] = { 0 };

	int n = 0;

	printf("please input data size:");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &vector[i]);

	}

	int m = delete(vector, n, 6, 15);

	output(vector, m);
	return 0;
}