/*
Please write a function to get the gcd of two integers.

求两个正整数m和n的最大公约数gcd.
*/
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

	printf("please input two integers:\n");
	printf("x = ");
	scanf("%d", &x);
	printf("y = ");
	scanf("%d", &y);

	printf("The greatest common divisor is:%d\n", gcd(x, y));
	return 0;
}