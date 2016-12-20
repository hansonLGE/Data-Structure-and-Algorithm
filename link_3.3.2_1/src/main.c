#include <stdio.h>
#include <stdlib.h>

typedef struct _dnode{
	int key;
	struct _dnode* left;
	struct _dnode* right;
} dnode;


void create(dnode** head) {
	dnode *s, *p = NULL;
	int cycle = 1;
	int x = 0;

	while (cycle)
	{
		printf("input a node key:");
		scanf("%d", &x);

		if (x == 0) {
			cycle = 0;
		}
		else {
			s = (dnode*)malloc(sizeof(dnode));
			s->key = x;
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

	printf("%d ", ptr->key);

	ptr = ptr->right;
	while (ptr != head) {
		printf("%d ", ptr->key);
		ptr = ptr->right;
	}

	printf("\n");
}

void delnode(dnode* head, int x) {
	dnode* ptr = head;

	while (ptr->key != x) {
		ptr = ptr->right;
	}

	dnode* p = ptr->left;
	dnode* q = ptr->right;

	p->right = q;
	q->left = p;

	free(ptr);
}

int main(int argc, char** argv) {
	dnode* head = NULL;
	int x = 0;

	create(&head);
	output(head);

	printf("please input a delte node key:");
	scanf("%d", &x);

	delnode(head, x);
	output(head);

	return 0;
}