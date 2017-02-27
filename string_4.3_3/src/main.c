/*
please write a function that deletes all elements in which the value is equal to ch. Note：we need to pay attention to the efficiency.

对于顺序结构存储的串，编写一个函数删除其值等于ch的所有字符，要求具有较高效率。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

char* delall(char* x, char ch) {
	int k = 0;
	int i = 0;
	int len = strlen(x);
	
	while (i < len) {
		if (x[i] == ch) {
			k++;
		}
		else {
			x[i - k] = x[i];
		}

		i++;
	}

	len = len - k;

	x[len] = '\0';

	return x;
}

int main(int argc, char** argv) {
	char vec[MAXSIZE] = {'\0'};
	char* str = "hfjdkshfkj";
	char ch = 0;

	strcpy(vec, str);
	//printf("please input s atring:");
	//scanf("%s", vec);
	printf("string:%s\n", str);
	printf("input a delete character:");
	ch = getchar();

	printf("the value is: %s\n", delall(vec, ch));

	return 0;
}