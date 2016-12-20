#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 500

typedef struct _pack{
	int weight;
	int value;
} pack;

void zeroOnePack(int* dp, pack* pk, int n, int m, int path[][500]) {
	for (int i = 0; i < n; i++) {
		for (int j = m; j >= pk[i].weight; j--) {
			path[i+1][j] = 0;
			if (dp[j] < dp[j - pk[i].weight] + pk[i].value) {
				dp[j] = dp[j - pk[i].weight] + pk[i].value;
				path[i+1][j] = 1;
			}
		}
	}

	printf("the path:\n");
	for (int i = n, j = m; i >0&&j>0; i--) {
		if (path[i][j] == 1) {
			printf("%d:(%d, %d)\n", i, pk[i-1].weight, pk[i-1].value);
			j -= pk[i-1].weight;
		}
	}

	printf("\n");
}

int main(int argc, char** argv) {
	int m = 0;
	int n = 0;
	pack vec_pk[MAX];
	int dp[MAX];
	int path[MAX][MAX];

	printf("please input the size of packs:");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("input weight & value of the pack %d:", i+1);
		scanf("%d %d", &vec_pk[i].weight, &vec_pk[i].value);
	}

	printf("please input the total weight of a package:");
	scanf("%d", &m);

	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			path[i][j] = 0;
		}
	}

	zeroOnePack(dp, vec_pk, n, m, path);
	printf("the totle value is %d\n", dp[m]);

	return 0;
}