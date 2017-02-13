/*
Please write a function that a vector A is divided into two parts. The one part has elements which are more than 0, while elements in another part are less than 0.

编写一个函数将一个向量A（有n个元素且任何元素均不为0）分拆成二个向量，使A中大于0的元素存放在B中，小于0的元素存放在C中。
*/
#include <stdio.h>
#include <stdlib.h>

static void ret(int* vector, int n, int* vec_a, int* vec_b){
	int* p = vec_a;
	int* q = vec_b;

	for (int i = 0; i < n; i++) {
		if (vector[i] > 0){
			*q = vector[i];
			q++;
		}
		else if (vector[i] < 0){
			*p = vector[i];
			p++;
		}
	}
}

void output(int* vector) {
	int i = 0;
	while (vector[i] != 0) {
		printf("%d\n", vector[i]);

		i++;
	}
}

int main(int argc, char** argv){
	int vector[16] = { 0 };
	int vec_a[8] = { 0 };
	int vec_b[8] = { 0 };

	int n = 0;
	printf("please input vector size:");
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		printf("input a int element:");
		scanf("%d", &vector[i]);
	}

	ret(vector, n, vec_a, vec_b);

	printf("vector A:\n");
	output(vec_a);

	printf("vector B:\n");
	output(vec_b);

	return 0;

}