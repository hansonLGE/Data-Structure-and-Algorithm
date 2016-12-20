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

	printf("input a interger data:");
	scanf("%d", &x);

	reverse(x);
	printf("\n");

	return 0;
}