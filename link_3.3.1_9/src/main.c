#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
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

node* swap(node* head, int x) {
	node* ptr = head;
	node* p = NULL;
	node* q = NULL;

	if (head->data == x) {
		p = head->next;
		head->next = p->next;
		p->next = head;
		head = p;
	}
	else {
		while (ptr != NULL && ptr->data != x) {
			p = ptr;
			ptr = ptr->next;
		}

		q = ptr->next;

		p->next = q;
		ptr->next = q->next;
		q->next = ptr;

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

	printf("please input a value:");
	scanf("%d", &x);

	head = swap(head, x);
	output(head);

	return 0;
}