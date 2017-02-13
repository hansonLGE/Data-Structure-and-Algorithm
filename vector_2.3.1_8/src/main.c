/*
There are two vectors that A has m elements while B has n elements, All the elements are in an ascending order. 
Please write a function to merge them to vector C in which elements are also in an ascending order.

有两个向量A（有m个元素）和B（有n个元素），其元素均以从小到大升序排序，编写一个函数将他们合并成一个向量C，要求C的元素也是从小到大升序排序。
*/
#include <stdio.h>
#include <stdlib.h>

#define M1 16
#define M2 32

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
	int vector_a[M1] = { 0 };
	int vector_b[M1] = { 0 };
	int vector_c[M2] = { 0 };
	int m = 0, n = 0;

	printf("please input vector_a size:");
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		printf("input a int element:");
		scanf("%d", &vector_a[i]);
	}

	printf("please input vector_b size:");
	scanf("%d", &n);
	for (int j = 0; j < n; j++){
		printf("input a int element:");
		scanf("%d", &vector_b[j]);
	}

	int num = link(vector_a, m, vector_b, n, vector_c);

	printf("\n vector_c:\n");
	for (int i = 0; i < num; i++) {
		printf("%d\n", vector_c[i]);
	}

	return 0;
}