/*
Please write functions to travel the binary tree by non-recursive, such as preorder、inorder and postorder.

非递归遍历二叉树（前序，中序，后续）
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct _bnode{
	char data;
	struct _bnode *left, *right;
} bnode;

typedef struct _stack{
	bnode* p_node[MAXSIZE];
	int top;
} stack;

typedef struct _stack2{
	bnode* p_node[MAXSIZE];
	int tag[MAXSIZE];
	int top;
} stack2;

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

void preorder(bnode* root) {
	bnode* ptr = NULL;
	stack st;
	memset(&st, 0, sizeof(st));

	if (root != NULL) {
		st.top++;
		st.p_node[st.top] = root;

		while (st.top > 0) {
			ptr = st.p_node[st.top];
			st.top--;
			printf("%c ", ptr->data);

			if (ptr->right != NULL) {
				st.top++;
				st.p_node[st.top] = ptr->right;
			}
			if (ptr->left != NULL) {
				st.top++;
				st.p_node[st.top] = ptr->left;
			}
		}

		printf("\n");
	}
	
}

void inorder(bnode* root) {
	bnode* ptr = root;
	stack st;
	memset(&st, 0, sizeof(st));
	int flag = 0;

	while (ptr != NULL || flag) {
		while (ptr != NULL) {
			st.top++;
			st.p_node[st.top] = ptr;
			ptr = ptr->left;
		}

		if (st.top > 0){
			flag = 1;
			ptr = st.p_node[st.top];
			st.top--;
			printf("%c ", ptr->data);

			ptr = ptr->right;
		}
		else {
			flag = 0;
		}
	}

	printf("\n");
}

void postorder(bnode* root) {
	bnode* ptr = root;
	stack2 st;
	memset(&st, 0, sizeof(st));
	int flag = 0;

	while (ptr != NULL || flag) {
		while (ptr != NULL) {
			st.top++;
			st.p_node[st.top] = ptr;
			st.tag[st.top] = 0;
			ptr = ptr->left;
		}

		if (st.top > 0){
			flag = 1;

			if (st.tag[st.top] == 1) {
				printf("%c ", st.p_node[st.top]->data);
				st.top--;
			}
			else {
				ptr = st.p_node[st.top];
				if (st.top > 0) {
					ptr = ptr->right;
					st.tag[st.top] = 1;
				}
			}
		}
		else {
			flag = 0;
		}
	}

	printf("\n");
}

int main(int argc, char** argv) {
	bnode* head = NULL;

	printf("create a tree(example: a b c # # # d e # f # # g # #):\n");
	create_bit_tree(&head);

	printf("the output by pre_order:\n");
	preorder(head);

	printf("the output by in_order:\n");
	inorder(head);

	printf("the output by post_order:\n");
	postorder(head);
	return 0;
};