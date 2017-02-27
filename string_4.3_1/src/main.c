/*
Please write a function to replace all ch1 with ch2.

将串r种所有值为ch1的字符替换为ch2。
*/
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
	scanf("%s", vec);

	printf("input a character in the string:");
	//ch1 = getchar();
	//while ((ch1 = getchar()) != '\n')
	scanf(" %c", &ch1);

	printf("input a instead character:");
	//ch2 = getchar();
	scanf(" %c", &ch2);

	trans(vec, ch1, ch2);
	printf("the trans value is %s\n", vec);
	return 0;
}