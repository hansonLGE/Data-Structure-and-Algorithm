/*
有数组A[4][4]，编写一个函数计算两条对角线元素的乘积。
*/
#include <stdio.h>
#include <stdlib.h>

#define M 4

int main(int argc, char** argv) {
	int mat[M][M];
	int s = 1;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			printf("input a int data:");
			scanf("%d", &mat[i][j]);
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	int k = 0;
	for (k = 0; k < M; k++) {
		s = s * mat[k][k];
	}

	for (k = 0; k < M; k++) {
		s = s * mat[M-k-1][k];
	}

	printf("the value is:%d\n", s);
	return 0;
}