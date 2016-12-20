#include <stdio.h>
#include <stdlib.h>

static int link(int* vector_a, int m, int* vector_b, int n, int* vector_c){
	int i = 0, j = 0, k = 0;
	int l = 0;

	while (i < m && j < n){
		if (vector_a[i] < vector_b[j]){
			vector_c[k] = vector_a[i];
			i++;
			k++;
		}
		else if (vector_a[i] > vector_b[j]){
			vector_c[k] = vector_b[j];
			j++;
			k++;
		}
		else {
			vector_c[k] = vector_a[i];
			i++;
			j++;
			k++;
		}
	}

	if (i == m) {
		for (l = j; j < n; j++) {
			vector_c[k] = vector_b[j];
			k++;
		}
	}

	if (j == n) {
		for (l = i; i < m; i++){
			vector_c[k] = vector_a[i];
			k++;
		}
	}

	return k;
}

int main(int argc, char** arhv){
	int vector_a[16] = { 0 };
	int vector_b[16] = { 0 };
	int vector_c[32] = { 0 };

	int m = 0, n = 0;

	printf("please input vector_a data size:");
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		scanf("%d", &vector_a[i]);
	}

	printf("please input vector_b data size:");
	scanf("%d", &n);
	for (int j = 0; j < n; j++){
		scanf("%d", &vector_b[j]);
	}

	int num = link(vector_a, m, vector_b, n, vector_c);

	printf("\n vector_c:\n");
	for (int i = 0; i < num; i++) {
		printf("%d\n", vector_c[i]);
	}

	return 0;
}