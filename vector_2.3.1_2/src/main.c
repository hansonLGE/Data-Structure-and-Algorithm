#include <stdio.h>
#include <stdlib.h>

static int delete(int* vector, int n) {
	int i = 0;
	while (i < n - 1){
		if (vector[i] != vector[i + 1]) {
			i++;
		}
		else {
			for (int j = i; j < n - 1; j++) {
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
	int vector[16] = { 0 };
	int n;
	printf("please input data size:");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &vector[i]);
	}

	int m = delete(vector, n);

	output(vector, m);

	return 0;
}