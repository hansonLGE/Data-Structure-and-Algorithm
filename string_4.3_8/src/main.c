/*
There are two strings named s and t. Please write a function to get lagest common substring for them.

采用顺序结构存储，编写一个函数，求串s和串t的一个最长公共子串。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

void maxcomstr(char* str_s, char* str_t, int* idx, int* length) {
	int len_s = strlen(str_s);
	int len_t = strlen(str_t);
	int i = 0;
	int j = 0;
	int k = 0;

	for (i = 0; i < len_s; i++) {
		j = 0;
		while (j < len_t) {
			if (str_s[i] == str_t[j]) {
				k = 0;
				while (str_s[i + k] == str_t[j + k]) {
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
	char vec_s[MAXSIZE] = { '\0' };
	char vec_t[MAXSIZE] = { '\0' };
	int index = 0;
	int length = 0;

	printf("please input the first string:");
	scanf("%s", vec_s);

	printf("please input the second string:");
	scanf("%s", vec_t);

	maxcomstr(vec_s, vec_t, &index, &length);

	printf("the max sub string length:%d and the index is:%d\n", length, index);
	printf("the max sub string is:");

	for (int i = 0; i < length; i++) {
		printf("%c", vec_s[i + index]);
	}
	printf("\n");

	return 0;
}