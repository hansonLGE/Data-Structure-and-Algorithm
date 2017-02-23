/*
double circual link: the first node and second node would be swaped.

双向循环链表：交换第一个与第二个结点
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct _dnode{
	int data;
	struct _dnode* left;
	struct _dnode* right;
} dnode;

void create(dnode** head) {
	dnode *s, *p = NULL;
	int cycle = 1;
	int x = 0;

	while (cycle)
	{
		printf("input a node data:");
		scanf("%d", &x);

		if (x == 0) {
			cycle = 0;
		}
		else {
			s = (dnode*)malloc(sizeof(dnode));
			s->data = x;
			s->left = s->right = NULL;

			if (p == NULL) {
				s->left = s->right = s;
				*head = s;
				p = s;
			}
			else {
				p->right = s;
				s->left = p;
				s->right = *head;
				(*head)->left = s;
				p = s;
			}
		}
	}
}

void output(dnode* head) {
	dnode* ptr = head;

	printf("%d ", ptr->data);

	ptr = ptr->right;
	while (ptr != head){
		printf("%d ", ptr->data);
		ptr = ptr->right;
	}

	printf("\n");
}

dnode* swap(dnode* head) {
	dnode* p = head->right;
	dnode* q = head->left;

	head->right = p->right;
	p->right->left = head;

	p->right = head;
	head->left = p;

	q->right = p;
	p->left = q;

	head = p;

	return head;
}

int main(int argc, char** argv) {
	dnode* head = NULL;

	create(&head);
	output(head);

	printf("swap:\n");
	head = swap(head);
	output(head);

	return 0;
}