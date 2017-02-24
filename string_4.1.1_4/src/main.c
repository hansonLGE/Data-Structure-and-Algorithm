/*
把串r1插入到串r中第i个字符开始的位置上。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

void insert(char* ptr_r, char* ptr_r1, int i) {
	int k = 0;
	int len_r = strlen(ptr_r);
	int len_r1 = strlen(ptr_r1);

	if (i == 0 || i >= len_r || len_r + len_r1 >= MAXSIZE) {
		printf("out of bounds.\n");
	}
	else {
		for (k = len_r - 1; k >= i-1; k--) {
			ptr_r[k + len_r1] = ptr_r[k];
		}

		for (k = 0; k < len_r1; k++) {
			ptr_r[i + k - 1] = ptr_r1[k];
		}

		len_r = len_r + len_r1;
		ptr_r[len_r] = '\0';
	}
}

int main(int argc, char** argv) {
	char r[MAXSIZE] = {'\0'};
	char r1[MAXSIZE] = { '\0' };
	int i = 0;

	printf("input the first string:");
	scanf("%s", r);

	printf("input the second string:");
	scanf("%s", r1);

	printf("please input the insert location in the first string:");
	scanf("%d", &i);

	insert(r, r1, i);

	printf("the value is:%s\n", r);

	return 0;
}