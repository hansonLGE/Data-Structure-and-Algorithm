#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100 

void trans(char* r, char ch1, char ch2) {
	int len = strlen(r);

	for (int i = 0; i < len; i++) {
		if (r[i] == ch1) {
			r[i] = ch2;
		}
	}
}

int main(int argc, int argv) {
	char vec[MAXSIZE] = {'\0'};
	char ch1 = 0;
	char ch2 = 0;

	printf("please input a string:");
	scanf("%s\n", vec);

	//printf("input a character in the string and a instead character for it:");
	ch1 = getchar();
	//while ((ch1 = getchar()) != '\n')
		printf("ch1:%c\n", ch1);

	ch2 = getchar();
	printf("ch2:%c\n", ch2);
	//printf("ch1:%c---ch2:%c\n", ch1, ch2);
	//trans(vec, ch1, ch2);
	//printf("the trans value is %s\n", vec);
	return 0;
}