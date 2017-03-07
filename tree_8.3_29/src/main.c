/*
Please write a function to get the count of all nodes leaf nodes and one child nodes.

分别计算二叉树的结点个数、叶子结点数、单孩子结点数。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _bnode{
	char data;
	struct _bnode *left, *right;
}bnode;

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

void nodes(bnode* ptr,  int* count) {
	if (ptr != NULL) {
		(*count)++;

		nodes(ptr->left, count);
		nodes(ptr->right, count);
	}
}

int leafs(bnode* ptr) {
	int num1;
	int num2;

	if (ptr == NULL) {
		return 0;
	}
	else if(ptr->left == NULL && ptr->right == NULL){
		return 1;
	}
	else {
		num1 = leafs(ptr->left);
		num2 = leafs(ptr->right);
		return num1 + num2;
	}
}

int onechild(bnode* ptr) {
	int num1;
	int num2;

	if (ptr == NULL) {
		return 0;
	}
	else if (ptr->left == NULL && ptr->right != NULL) {
		return 1;
	}
	else if (ptr->left != NULL && ptr->right == NULL) {
		return 1;
	}
	else {
		num1 = onechild(ptr->left);
		num2 = onechild(ptr->right);

		return num1 + num2;
	}
}
int main(int argc, char** argv) {
	bnode* root = NULL;
	int n = 0;
	int m = 0;
	int k = 0;

	printf("create a tree(example: a b d g # # # e h # # i # # c # f # #):\n");
	create_bit_tree(&root);

	nodes(root, &n);
	printf("all the count of nodes is:%d\n", n);

	m = leafs(root);
	printf("the count of leaf nodes is:%d\n", m);

	k = onechild(root);
	printf("the count of one child nodes is:%d\n", k);

	printf("the count of two child nodes is:%d\n", n - m - k);

	return 0;
}