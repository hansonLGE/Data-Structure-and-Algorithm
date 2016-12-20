#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

int substring(char* s1, char* s2) {
	int len_s1 = strlen(s1);
	int len_s2 = strlen(s2);
	int i = 0;
	int j = 0;
	int flag = 0;

	while (i < len_s2) {
		if (flag == 0) {
			while (j < len_s1) {
				if (s2[i] == s1[j]) {
					flag = 1;
					j++;
					break;
				}

				j++;
			}
		}
		else {
			if (s2[i] == s1[j]) {
				j++;
				flag = 1;
			}
			else {
				i = -1;
				flag = 0;
			}
		}


		i++;
	}

	return flag;

}

int main(int argc, char** argv) {
	char vec_s1[MAXSIZE] = {"\0"};
	char vec_s2[MAXSIZE] = { '\0' };

	printf("input the first string s1:");
	scanf("%s", vec_s1);

	printf("input the first string s2:");
	scanf("%s", vec_s2);

	if (substring(vec_s1, vec_s2)) {
		printf("s2 is substring of s1\n");
	}
	else {
		printf("s2 is not substring of s1\n");
	}

	return 0;
}