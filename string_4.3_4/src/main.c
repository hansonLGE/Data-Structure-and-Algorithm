#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

char* delij(char* s, int i, int j) {
	int len = strlen(s);

	if (i + j < len) {
		for (int k = i + j - 1; k < len; k++) {
			s[k - j] = s[k];
		}

		len = len - j;

		s[len] = '\0';
	}
	else {
		printf("failed\n");
	}

	return s;
}

int main(int argc, char** argv) {
	char vec[MAXSIZE] = {'\0'};
	int i = 0;
	int j = 0;

	printf("please input a string:");
	scanf("%s", vec);

	printf("input the start location and delete count:");
	scanf("%d %d", &i, &j);

	printf("the value is:%s\n", delij(vec, i, j));

	return 0;

}