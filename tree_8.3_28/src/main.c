#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100
typedef struct _bnode{
	char data;
	struct _bnode *left, *right;
}bnode;

typedef struct _queue{
	bnode* vec[MAXSIZE];
	int front;
	int rear;
}queue;

void create_bit_tree(bnode** ptr) {
	char ch = 0;

	printf("input a char:");
	scanf("%c", &ch);

	while (getchar() != '\n');

	if (ch == '#') {
		*ptr = NULL;
	}
	else {
		*ptr = (bnode*)malloc(sizeof(bnode));
		(*ptr)->data = ch;

		create_bit_tree(&((*ptr)->left));
		create_bit_tree(&((*ptr)->right));
	}
}

void translevel(bnode* root) {
	bnode* ptr = NULL;
	queue qu;
	memset(&qu, 0, sizeof(qu));

	if (root != NULL) {
		qu.vec[qu.rear] = root;
		qu.rear++;

		while (qu.front < qu.rear) {
			ptr = qu.vec[qu.front];
			qu.front++;

			printf("%c ", ptr->data);

			if (ptr->left != NULL) {
				qu.vec[qu.rear] = ptr->left;
				qu.rear++;
			}

			if (ptr->right != NULL) {
				qu.vec[qu.rear] = ptr->right;
				qu.rear++;
			}
		}
	}

}
int main(int argc, char** argv) {
	bnode* root = NULL;

	printf("create a tree(example: a b d g # # # e h # # i # # c # f # #):\n");
	create_bit_tree(&root);

	printf("output the tree by level:\n");
	translevel(root);
	printf("\n");

	return 0;
}