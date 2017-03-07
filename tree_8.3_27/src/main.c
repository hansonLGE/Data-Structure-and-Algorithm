/*
There is a binary tree which is stored by link. Please write a function to get all ancestors of the node in which the data is equal to x.

�ڶ������в���ֵΪx�Ľ�㣬����ƴ�ӡֵΪx�Ľڵ�����������㷨��������ֵΪx�Ľ�㲻����1����
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
} stack;

void create_bit_tree(bnode** p) {
	char x = 0;

	printf("input a node data:");
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

void ancestor(bnode* root, char x) {
	int flag = 0;
	bnode* ptr = root;
	stack st;

	memset(&st, 0, sizeof(st));

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
					printf("the x's ancestor:");
					for (int i = 1; i < st.top; i++) {
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

	printf("create a tree(example: a b d g # # # e h # # i # # c # f # #):\n");
	create_bit_tree(&head);

	printf("input a node data:");
	scanf("%c", &x);
	while (getchar() != '\n');

	ancestor(head, x);
	printf("\n");

	return 0;
}