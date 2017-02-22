/*
There is a cyciral single link which has not both head pointer and head node and only has a point pointting certain node P.
Please write a function to delete the prior node of P.

假设在长度大于1的循环单链表中，即无头结点，也无头指针，只有某个结点的指针，编写一个函数删除该结点的前驱结点。
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

	p->next = *head;
}

void output(node* head) {
	node* ptr = head;
	printf("%d ", ptr->data);

	ptr = head->next;
	while (ptr != head) {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}

	printf("\n");
}

void  del(node* head, int x) {
	node* ptr = head;
	node* p = NULL;
	node* q = NULL;

	while (ptr->data != x) {
		ptr = ptr->next;
	}

	p = ptr;
	while (p->next != ptr) {
		p = p->next;
	}

	q = p;
	while (q->next != p) {
		q = q->next;
	}

	q->next = ptr;
	free(p);
}

int main(int argc, char** argv) {
	node* head = NULL;
	int x = 0;

	create(&head);
	output(head);

	printf("please input the node data:");
	scanf("%d", &x);
	del(head, x);
	output(head);

	return 0;
}