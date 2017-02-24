/*
从串r中删除从第i个字符开始的，长度为j的一个字串。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

void del_substring(char* ptr_r, int i, int j) {
	int len = strlen(ptr_r);

	if (i + j - 1 > len) {
		printf("out of bouds\n");
	}
	else {
		for (int k = i + j - 1; k < len; k++) {
			ptr_r[k-j] = ptr_r[k];
		}

		len = len - j;
		ptr_r[len] = '\0';
	}
}

int main(int argc, char** argv) {
	char r[MAXSIZE] = { '\0' };
	int i = 0;
	int j = 0;

	printf("please input a string:");
	scanf("%s", &r);

	printf("input delete the location and lenth:");
	scanf("%d %d", &i, &j);
	del_substring(r, i, j);
	printf("the value is:%s\n", r);
}
