/*
已知两个单链表A和B，其头指针分别为heada和headb，编写一个函数在单链表A中删除自第i个元素起的公len个元素，然后将他们插入一到单链表B的第位置之前。
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node* next;
} node;

void create(node** head) {
	node *s, *p = NULL;
	int cycle = 1;
	int x = 0;

	while (cycle) {
		printf("input a node data:");
		scanf("%d", &x);

		if (x == 0) {
			cycle = 0;
		}
		else {
			s = (node*)malloc(sizeof(node));
			s->data = x;
			s->next = NULL;

			if (p == NULL) {
				*head = s;
				p = s;
			}
			else {
				p->next = s;
				p = s;
			}
		}
	}
}

void output(node* head) {
	node* ptr = head;

	while (ptr != NULL) {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}

	printf("\n");
}

node* del(node* head, int i, int len) {
	node* p = head;
	node* ptr = head;
	node* q = head;
	int k = 1;

	if (i == 1) {
		while (k < len) {
			p = p->next;
			k++;
		}

		head = p->next;
		p->next = NULL;

		ptr = head;
	}
	else {
		k = 1;
		while (k < i - 1) {
			q = q->next;
			k++;
		}

		ptr = q->next;
		p = ptr;
		k = 1;
		while (k < len) {
			p = p->next;
			k++;
		}

		q->next = p->next;
		p->next = NULL;

	}

	return ptr;
}

node* insert(node* head1, node* head2, int j) {
	int k = 1;
	node *p = head1, *q = head2;

	while (p->next != NULL) {
		p = p->next;
	}

	if (j == 1) {
		p->next = head2;
		head2 = head1;
	}
	else {
		while (k < j - 1) {
			q = q->next;
			k++;
		}

		p->next = q->next;
		q->next = head1;
	}

	return head2;
}

int main(int argc, char** argv) {
	node* heada = NULL;
	node* headb = NULL;
	node* del_link = NULL;
	int i = 0;
	int len = 0;

	printf("create the first link:\n");
	create(&heada);
	output(heada);

	printf("create the second link:\n");
	create(&headb);
	output(headb);

	printf("please input the delete location and len:");
	scanf("%d %d", &i, &len);

	del_link = del(heada, i, len);
	output(del_link);
	printf("please input the insert location:");
	scanf("%d", &i);

	headb = insert(del_link, headb, i);
	output(headb);

	return 0;
}