/*
There is a single link in which all elements are in ascending order. Please write a function to delete the same elements to keep one nodes in
the link.

有一个单链表，其结点的元素值以非递减有序排序，编写一个函数删除该链表中多余的元素值相同的结点。
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int data;
	struct _node* next;
} node;

void create(node** head){
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

void del(node* head) {
	node* p = head;
	node* q = NULL;

	while (p->next != NULL) {
		q = p->next;

		if (p->data != q->data) {
			p = p->next;
		}
		else {
			p->next = q->next;

			free(q);
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

int main(int argc, char** argv) {
	node* head = NULL;

	create(&head);
	output(head);

	printf("delete result is:\n");
	del(head);
	output(head);

	return 0;
}