/*
Please write a function to reverse a integer. For example, 582 would be reversed to 285.

��дһ��������������������������磬582���Ϊ285��
*/
#include <stdio.h>
#include <stdlib.h>

void reverse(int n) {
	printf("%d", n % 10);

	if (n / 10 != 0) {
		reverse(n / 10);
	}
}

int main(int argc, char** argv) {
	int x = 0;

	printf("input a integer:");
	scanf("%d", &x);

	reverse(x);
	printf("\n");

	return 0;
}