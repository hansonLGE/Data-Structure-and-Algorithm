#include <stdio.h>
#include <stdlib.h>

#define M 4
#define N 5

void trsmat(int a[][N], int b[][M]) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			b[j][i] = a[i][j];
		}
	}
}

void addmat(int c[][N], int a[][N], int b[][N]) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

void mulmat(int c[][1], int a[][N], int b[][1]) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < 1; j++) {
			c[i][j] = 0;
			for (int k = 0; k < N; k++) {
				c[i][j] = c[i][j] + a[i][k] * b[k][j];
			}
		}
	}
}

int main(int argc, char** argv) {
#if 0
	int mat_a[M][N];
	int mat_b[N][M];
	int k = 1;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			mat_a[i][j] = k++;
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", mat_a[i][j]);
		}

		printf("\n");
	}

	trsmat(mat_a, mat_b);

	printf("the transposed matrix is:\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", mat_b[i][j]);
		}

		printf("\n");
	}
#endif
#if 0
	int mat_a[M][N];
	int mat_b[M][N];
	int mat_c[M][N];
	int k = 1;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			mat_a[i][j] = k++;
		}
	}

	k = 1;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			mat_b[i][j] = k++;
		}
	}

	printf("the matrix a:\n");
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", mat_a[i][j]);
		}

		printf("\n");
	}

	printf("the matrix b:\n");
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", mat_b[i][j]);
		}

		printf("\n");
	}

	addmat(mat_c, mat_a, mat_b);

	printf("\nthe add matrix is:\n");
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", mat_c[i][j]);
		}

		printf("\n");
	}
#endif
	int mat_a[M][N];
	int mat_b[N][1];
	int mat_c[M][1];
	int k = 1;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			mat_a[i][j] = k++;
		}
	}

	k = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 1; j++) {
			mat_b[i][j] = k++;
		}
	}

	printf("the matrix a:\n");
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", mat_a[i][j]);
		}

		printf("\n");
	}

	printf("the matrix b:\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 1; j++) {
			printf("%d ", mat_b[i][j]);
		}

		printf("\n");
	}

	mulmat(mat_c, mat_a, mat_b);

	printf("\nthe mul matrix is:\n");
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < 1; j++) {
			printf("%d ", mat_c[i][j]);
		}

		printf("\n");
	}
	return 0;

}