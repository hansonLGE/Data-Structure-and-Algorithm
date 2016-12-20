#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n) {
	int tmp = 0;

	if (m < n) {
		tmp = m;
		m = n;
		n = tmp;
	}

	if (n == 0) {
		return m;
	}
	else {
		return gcd(n, m%n);
	}
}

int main(int argc, char** argv) {
	int x = 0;
	int y = 0;

	printf("please input two interger data:\n");
	printf("x = ");
	scanf("%d", &x);
	printf("y = ");
	scanf("%d", &y);

	printf("The greatest common divisor is:%d\n", gcd(x, y));
	return 0;
}