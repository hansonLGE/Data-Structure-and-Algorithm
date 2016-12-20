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

void swap(dnode* head, int x) {
	dnode* p = head;

	while (p->data != x) {
		p = p->right;
	}

	dnode* q = p->right;
	dnode* r = p->left;

	p->right = q->right;
	q->right->left = p;

	q->right = p;
	p->left = q;

	r->right = q;
	q->left = r;
}

int main(int argc, char** argv) {
	dnode* head = NULL;
	int x = 0;

	create(&head);
	output(head);

	printf("please input the node data:");
	scanf("%d", &x);
	swap(head, x);
	output(head);

	return 0;
}