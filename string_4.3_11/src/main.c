#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

int strcmp(char*a , char* b) {
	int len_a = strlen(a);
	int len_b = strlen(b);
	int min_len = 0;
	int i = 0;

	if (len_a < len_b) {
		min_len = len_a;
	}
	else {
		min_len = len_b;
	}

	while (i < min_len) {
		if (a[i] == b[i]) {
			i++;
		}
		else if (a[i] > b[i]){
			return 1;
		}
		else if (a[i] < b[i]) {
			return -1;
		}
	}

	if (len_a < len_b) {
		return -1;
	}
	else if (len_a == len_b) {
		return 0;
	}
	else {
		return 1;
	}
}

int main(int argc, char** argv) {
	char vec_s[MAXSIZE] = { '\0' };
	char vec_t[MAXSIZE] = { '\0' };
	int ret = 0;

	printf("input the first string s:");
	scanf("%s", vec_s);

	printf("input the second string t:");
	scanf("%s", vec_t);

	ret = strcmp(vec_s, vec_t);
	if (ret < 0) {
		printf("s<t\n");
	}
	else if (ret == 0) {
		printf("s=t\n");
	}
	else {
		printf("s>t\n");
	}

	return 0;
}