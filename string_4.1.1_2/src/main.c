#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

void substring(char* p_r1, char* p_r, int i, int j) {
	for (int k = 0; k < j; k++) {
		p_r[k] = p_r1[i + k - 1];
	}

	p_r[j] = '\0';
}

int main(int argc, char** argv) {
	char r1[MAXSIZE] = {'\0'};
	char r[MAXSIZE] = {'\0'};
	int i = 0;
	int j = 0;

	printf("please input the string value:");
	scanf("%s", r1);

	printf("input the location %d and count %d for substring:");
	scanf("%d %d", &i, &j);
	substring(r1, r, i, j);

	printf("substring is:%s\n", r);

	return 0;
}