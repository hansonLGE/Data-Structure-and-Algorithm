/*
There is a signal link which is in ascending order. A pointer points to it's head, please write a function to insert a node to the link
and the link is still in ascending order.

有一个有序单链表（从小到大）。表头指针为head，编写一个函数向该链表中插入一个元素为x的结点，使插入后的链表依然有序。
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

node* insert_order(node* head, int x) {
	node *s, *p, *q;

	s = (node*)malloc(sizeof(node));
	s->data = x;
	s->next = NULL;

	if (head == NULL || x < head->data) {
		s->next = head;
		head = s;
	}
	else {
		p = head;
		while (p != NULL && x > p->data) {
			q = p;
			p = p->next;
		}

		s->next = p;
		q->next = s;
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

int main(int argc, char** argv) {
	node* head = NULL;
	int x = 0;

	create(&head);
	output(head);

	printf("insert a new value:");
	scanf("%d", &x);

	head = insert_order(head, x);
	output(head);

	return 0;
}