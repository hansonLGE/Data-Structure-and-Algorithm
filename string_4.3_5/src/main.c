/*
There are two strings named s1 and s2. Please write a functon to replace the substring in s1 with s2. Note: the substring is got by the 
elements between location i and j, and the i and j can not be included.

采用顺序结构存储字符串s1，编写一个函数将s1中第i位置到第j位置之间的子串（不包括i和j的位置）替换为另一个字符串s2。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

char* stuff(char* s1, int i, int j, char* s2) {
	int length = j - i - 1;
	int len_s2 = strlen(s2);
	int len_s1 = strlen(s1);
	int diff_len = 0;
	int k = 0;

	if (length < len_s2) {
		diff_len = len_s2 - length;
		for (k = len_s1 - 1; k >= j - 1; k--) {
			s1[k + diff_len] = s1[k];
		}

		len_s1 = len_s1 + diff_len;
	}
	else if(length > len_s2){
		diff_len = length - len_s2;
		for (k = j - 1; k < len_s1; k++) {
			s1[k - diff_len] = s1[k];
		}

		len_s1 = len_s1 - diff_len;
	}

	for (k = 0; k < len_s2; k++, i++) {
		s1[i] = s2[k];
	}

	s1[len_s1] = '\0';
	return s1;
}

int main(int argc, char** argv) {
	char vec_s1[MAXSIZE] = { '\0' };
	char vec_s2[MAXSIZE] = {'\0'};
	int i = 0;
	int j = 0;

	printf("please input string s1:");
	scanf("%s", vec_s1);

	printf("please input string s2:");
	scanf("%s", vec_s2);

	printf("input the instead location(the start and the end):");
	scanf("%d %d", &i, &j);

	printf("the result is:%s\n", stuff(vec_s1, i, j, vec_s2));

	return 0;
}