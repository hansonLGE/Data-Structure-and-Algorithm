/*
Çó×Ö´®µÄÎ»ÖÃ¡£
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

int position(char* ptr_r1, char* ptr_r2) {
	int ret = 0;
	int len_r1 = strlen(ptr_r1);
	int len_r2 = strlen(ptr_r2);

	int i = 0;
	int j = 0;
	int k = 0;
	int flag = 0;

	for (i = 0; i < len_r2; i++) {
		for (j = i + k; j < len_r1; j++) {
			if (ptr_r2[i] == ptr_r1[j]) {
				if (flag == 0) {
					ret = j + 1;
					flag = 1;
				}

				break;
			}
			else {
				k++;

				if (flag == 1) {
					flag = 0;
					ret = 0;
					i = -1;
					break;
				}
			}
		}
	}
	
	return ret;
}

int main(int argc, char** argv){
	char r1[MAXSIZE] = {'\0'};
	char r2[MAXSIZE] = { '\0' };

	printf("input the first string r1:");
	scanf("%s", r1);

	printf("input the second string r2:");
	scanf("%s", r2);

	printf("the location of r2 in r1 is:%d\n ", position(r1, r2));

	return 0;
}