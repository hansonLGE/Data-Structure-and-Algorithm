#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct _bnode {
	int data;
	struct _bnode *left, *right;
} bnode;

void insert(bnode** ptr, bnode* s) {
	if (*ptr == NULL) {
		*ptr = s;
	}
	else {
		if (s->data == (*ptr)->data) {
			return;
		}
		else if (s->data < (*ptr)->data) {
			insert(&((*ptr)->left), s);
		}
		else {
			insert(&((*ptr)->right), s);
		}
	}
}

void create(bnode** head) {
	int flag = 1;
	int x = 0;
	bnode* s = NULL;

	while (flag) {
		printf("input a node data:");
		scanf("%d", &x);

		if (x == -1) {
			flag = 0;
		}
		else {
			s = (bnode*)malloc(sizeof(bnode));
			s->data = x;
			s->left = s->right = NULL;

			insert(head, s);
		}
	}

	return;
}

void in_order(bnode* ptr) {
	if (ptr != NULL) {
		in_order(ptr->left);
		printf("%d ", ptr->data);
		in_order(ptr->right);
	}
}

void dest_order(bnode* ptr) {
	if (ptr != NULL) {
		dest_order(ptr->right);
		printf("%d ", ptr->data);
		dest_order(ptr->left);
	}
}

int main(int argc, char** argv) {
	bnode* head = NULL;
	bnode* ptr = NULL;

	printf("create a BST(example 62,88,58,47,35,73,51,99,37,93):\n");
	create(&head);
	in_order(head);

	printf("\n");
	dest_order(head);
	printf("\n");

	return 0;
}