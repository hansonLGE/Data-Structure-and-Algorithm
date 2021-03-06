/*
Saddlepoint

如果矩阵A中存在这样的一个元素A[i][j]满足条件：A[i][j]是第i行中值最小的元素，且又是第j列中值最大的元素，则称之为矩阵的一个马鞍点。
编写一个函数计算m*n的矩阵A的所有马鞍点。
*/
#include <stdio.h>
#include <stdlib.h>

#define M 100
#define N 100

void minmax(int a[][N], int m, int n) {
	int min = 0;
	int max = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	int r = 0;

	for (i = 0; i < m; i++) {
		min = a[i][0];
		r = 0;
		for (j = 0; j < n; j++) {
			if (min > a[i][j]) {
				min = a[i][j];
				r = j;
			}
		}

		max = a[0][r];
		for (k = 0; k < m; k++) {
			if (max < a[k][r]) {
				max = a[k][r];
			}
		}

		if (max == min) {
			printf("the Saddlepoint(%d, %d, %d)\n", i, r, a[i][r]);
		}
	}
}

int main(int argc, char** argv) {
	int mat[M][N] = { {0} };
	int m = 0;
	int n = 0;

	printf("m:");
	scanf("%d", &m);
	printf("n:");
	scanf("%d", &n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

	minmax(mat, m, n);

	return 0;

}