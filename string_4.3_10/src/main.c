/*
Please write a function to get the count of a sub string in a string. The count woould be 0 if the sub string does not exist.

����˳��ṹ�洢����дһ����������һ���Ӵ���һ���ַ����г��ֵĴ�����������Ӵ���������Ϊ0��
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

int str_count(char* substr, char* str) {
	int count = 0;
	int len_sub = strlen(substr);
	int len = strlen(str);
	int i = 0;
	int j = 0;
	int k = 0;

	while (j < len) {
		if (substr[i] == str[j]) {
			k = 0;
			while (k < len_sub && substr[k] == str[j + k]) {
				k++;
			}

			if (k == len_sub) {
				count++;
			}

			j += k;
		}
		else {
			j++;
		}
	}

	return count;
}

int main(int argc, char** argv) {
	char vec_str[MAXSIZE] = {'\0'};
	char vec_sub[MAXSIZE] = {'\0'};

	printf("input a string:");
	scanf("%s", vec_str);

	printf("input a sub string:");
	scanf("%s", vec_sub);

	printf("the count is %d\n", str_count(vec_sub, vec_str));

	return 0;
}