#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

int same(char* x, char* y) {
	int i = 0;
	int tag = 1;
	int len_x = strlen(x);
	int len_y = strlen(y);

	if (len_x != len_y) {
		return 0;
	}
	else {
		while (i < len_x &&tag) {
			if (x[i] != y[i]) {
				tag = 0;
				break;
			}

			i++;
		}
	}

	return tag;
}

int main(int argvc, char** argv) {
	char vec_x[MAXSIZE] = {'\0'};
	char vec_y[MAXSIZE] = { '\0' };

	printf("please input first string:");
	scanf("%s", vec_x);

	printf("please input second string:");
	scanf("%s", vec_y);

	if (same(vec_x, vec_y)) {
		printf("the two string is same\n");
	}
	else {
		printf("the two string is not same.\n");
	}

	return 0;
}