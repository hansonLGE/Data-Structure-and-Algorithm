#include <stdio.h>
#include <stdlib.h>

#define MAX 80

int proc1(int a[][MAX], int m, int n) {
	int sum = 0;
	int i = 0;
	int j = 0;

	for (i = 0; i < n; i++) {
		sum = sum + a[0][i];
	}

	for (i = 0; i < n; i++) {
		sum = sum + a[m-1][i];
	}

	for (i = 0; i < m; i++) {
		sum = sum + a[i][0];
	}

	for (i = 0; i < m; i++) {
		sum = sum + a[i][n-1];
	}

	sum = sum - a[0][0] - a[0][n-1]-a[m-1][n-1]-a[m-1][0];

	return sum;
}

int proc2(int a[][MAX], int m, int n) {
	int sum = 0;
	int i = 0;
	int j = 0;

	for (i = 0; i < m; i = i + 2) {
		for (j = 0; j < n; j = j + 2) {
			sum = sum + a[i][j];
		}
	}

	return sum;
}

void proc3(int a[][MAX], int m, int n){
	int sum = 0;
	int sum2 = 0;
	if (m != n) {
		printf("m is not equal n.\n");
	}
	else {
		for (int i = 0; i < n; i++) {
			sum = sum + a[i][i];
			sum2 = sum2 + a[n - i - 1][i];
		}
	}

	printf("sum:%d, sum2:%d\n", sum, sum2);
}

int main(int argc, char** argv) {
	int m, n, i, j;
	int mat[MAX][MAX] = { {0} };

	printf("m:");
	scanf("%d", &m);

	printf("n:");
	scanf("%d", &n);

	printf("input the matrix value:\n");
	int k = 1;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("the value of question 1 is:%d\n\n", proc1(mat, m,n));
	printf("the value of question 2 is:%d\n\n", proc2(mat, m, n));
	printf("the value of question 3 is:\n");
	proc3(mat, m, n);
	return 0;

}