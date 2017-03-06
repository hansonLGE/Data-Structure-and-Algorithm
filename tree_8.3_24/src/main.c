/*
Please write a function to get the layer of a node.

二叉树指定结点的层数。
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct _bnode{
	char data;
	struct _bnode *left, *right;
}bnode;

void create_bit_tree(bnode** p){
	char x = 0;

	printf("input a character(# means NULL for child):");
	scanf("%c", &x);
	while (getchar() != '\n');
	if (x == '#') {
		*p = NULL;
	}
	else {
		*p = (bnode*)malloc(sizeof(bnode));
		(*p)->data = x;
		create_bit_tree(&((*p)->left));
		create_bit_tree(&((*p)->right));
	}
}

void level(bnode* p, char x, int* h, int lev) {
	if (p == NULL) {
		*h = 0;
	}
	else if (p->data == x) {
		*h = lev;
	}
	else {
		level(p->left, x, h, lev+1);
		if (*h == 0) {
			level(p->right, x, h, lev + 1);
		}
	}
}

int main(int argc, char** argv) {
	bnode* head = NULL;
	char x = 0;
	int h = -1;
	int lev = 1;

	printf("create a tree(example: a b c # # # d e # f # # g # #):\n");
	create_bit_tree(&head);

	while (1) {
		printf("input a node value:");
		scanf("%c", &x);
		while (getchar() != '\n');

		level(head, x, &h, lev);
		printf("the level is %d\n", h);
	}

	return 0;
};