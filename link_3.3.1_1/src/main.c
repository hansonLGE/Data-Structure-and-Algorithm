/*
There is a signal link whose data value may be equal. A head pointer can be used, and please write a function to count the number of nodes 
whose data value is equal to x.

��һ����������ͬ����������ֵ������ͬ������ͷָ��Ϊhead����дһ����������������Ϊx�Ľ�������
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
	int data;
	struct _node* next;
} node;

//����������, 0��ʾ����
node* create() {
	int cycle = 1;
	node *head = NULL, *s, *p = NULL;
	int x = 0;

	while (cycle) {
		printf("input a int data:");
		scanf("%d", &x);
		if (x == 0) {
			cycle = 0;
		}
		else {
			s = (node*)malloc(sizeof(node));
			s->data = x;
			s->next = NULL;

			if (p == NULL) {
				head = s;
				p = s;
			}
			else {
				p->next = s;
				p = s;
			}
		}
	}

	return head;
}

void output(node* head) {
	node* ptr = head;
	while (ptr != NULL) {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}

	printf("\n");
}

int count(node* head, int value) {
	int cnt = 0;
	node* ptr = head;

	while (ptr != NULL) {
		if (ptr->data == value) {
			cnt++;
		}

		ptr = ptr->next;
	}

	return cnt;
}

int main(int argc, char** argv) {
	int x = 0;
	node* ptr = create();
	output(ptr);

	printf("input the count value:");
	scanf("%d", &x);

	printf("output the count:%d\n", count(ptr, x));

	return 0;;
}