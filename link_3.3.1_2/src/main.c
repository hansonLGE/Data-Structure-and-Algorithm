/*
已知一个单链表，编写一个函数复制该单链表。

There is a signal link, please write a function to copy it.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node{
	int data;
	struct _node* next;
} node;

node* create() {
	node *head = NULL, *s, *p = NULL;
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

void copy(node* head1, node** head2) {
	node *p = head1, *q = NULL, *s;

	while (p != NULL) {
		s = (node*)malloc(sizeof(node));
		s->data = p->data;
		s->next = NULL;

		if (q == NULL) {
			*head2 = s;
			q = s;
		}
		else {
			q->next = s;
			q = s;
		}

		p = p->next;
	}
}

int main(int argc, char** argv) {
	node* head1 = create();
	node* head2 = NULL;

	printf("original link:\n");
	output(head1);

	copy(head1, &head2);

	printf("copy link:\n");
	output(head2);
}