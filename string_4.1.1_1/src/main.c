/*
There are two strings called s1 and s2. Please write a function to combine s1 with s2.

将2个字符串s1和s2，合并为一个字符串。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct _orderstring {
	char vec[MAXSIZE];
	int len;
} orderstring;

void concat(orderstring* ptr_r1, orderstring* ptr_r2, orderstring* ptr_r) {
	int i = 0;

	if (ptr_r1->len + ptr_r2->len > MAXSIZE) {
		printf("the new string has not enough size.\n");
	}
	else {
		for (i = 0; i < ptr_r1->len; i++) {
			ptr_r->vec[i] = ptr_r1->vec[i];
		}

		for (i = 0; i < ptr_r2->len; i++) {
			ptr_r->vec[ptr_r1->len + i] = ptr_r2->vec[i];
		}

		ptr_r->vec[ptr_r1->len + i] = '\0';
		ptr_r->len = ptr_r1->len + ptr_r2->len;
	}
}

int main(int argc, char** argv) {
	orderstring r1, r2, r;
	memset(&r1, 0, sizeof(orderstring));
	memset(&r2, 0, sizeof(orderstring));

	printf("please input the first string:");
	scanf("%s", r1.vec);
	r1.len = strlen(r1.vec);

	printf("please input the second string:");
	scanf("%s", r2.vec);
	r2.len = strlen(r2.vec);

	concat(&r1, &r2, &r);
	printf("concat string is:%s\n", r.vec);

	return 0;
}