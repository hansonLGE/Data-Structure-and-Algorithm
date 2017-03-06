/*
There is a binary tree which is stored by link. Please write a function to get the path between root and p that points a certain node.

假设二叉树采用链接存储结构进行存储，root指向根结点，p所指结点为任意结点，编写一个函数求出从根结点到p所指结点之间路径。
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
	int tag[MAXSIZE];
	int top;
}stack;

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

void path(bnode* root,char x) {
	stack st;
	memset(&st, 0, sizeof(st));
	bnode* ptr = root;
	int flag = 0;

	while (ptr != NULL || flag) {
		while (ptr != NULL) {
			st.top++;
			st.p_node[st.top] = ptr;
			st.tag[st.top] = 0;
			ptr = ptr->left;
		}

		if (st.top > 0) {
			flag = 1;

			if (st.tag[st.top] == 1) {
				if (st.p_node[st.top]->data == x) {
					printf("path:");

					for (int i = 1; i <= st.top; i++) {
						printf("%c ", st.p_node[i]->data);
					}

					break;
				}

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
	
}

int main(int argc, char** argv) {
	bnode* head = NULL;
	char x = 0;

	printf("create a tree(example: a b c # # # d e # f # # g # #):\n");
	create_bit_tree(&head);

	printf("input a search node data:");
	scanf("%c", &x);

	path(head, x);
	printf("\n");

	return 0;
}