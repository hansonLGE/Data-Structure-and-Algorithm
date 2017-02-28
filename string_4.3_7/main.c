/*
Please write a function to get the index and length of the sub string that is the longest repeated substring.

采用顺序结构存储串，编写一个函数求串s中出现的第一个最长重复子串的下标和长度。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

void maxsubstr(char* str, int* idx, int* length) {
	int len = strlen(str);
	int i = 0;
	int j = 0;
	int k = 0;

	for (i = 0; i < len; i++) {
		j = i + 1;
		while (j < len) {
			if (str[i] == str[j]) {
				k = 0;
				while (i + k != j && str[i + k] == str[j + k]) {
					k++;
				}

				if (k > *length) {
					*idx = i;
					*length = k;
				}

				j += k;
			}
			else {
				j++;
			}
		}
	}
}

int main(int argc, char** argv) {
	char vec[MAXSIZE] = {'\0'};
	int index = 0;
	int length = 0;

	printf("please input a string:");
	scanf("%s", vec);

	maxsubstr(vec, &index, &length);

	printf("the max sub string length:%d and the index is:%d\n", length, index);
	printf("the max sub string is:");

	for (int i = 0; i < length; i++) {
		printf("%c", vec[i + index]);
	}
	printf("\n");

	return 0;
}