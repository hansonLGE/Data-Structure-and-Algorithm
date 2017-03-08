/*
Please write a algorithm to get successor of a node in the threaded binary tree by inorder, and then the tree would be traveled 
by non-recursive inorder.

编写出中序线索二叉树中任意结点的后继算法，并以此写出中序非递归遍历算法。
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct _bnode{
	char data;
	struct _bnode *left, *right;
	int ltag, rtag;
}bnode;

static bnode* pre = NULL;

void in_thread(bnode* ptr) {
	if (ptr != NULL) {
		in_thread(ptr->left);

		if (ptr->left == NULL) {
			ptr->ltag = 1;
			ptr->left = pre;
		}
		else {
			ptr->ltag = 0;
		}

		if (pre != NULL && pre->right == NULL) {
			pre->rtag = 1;
			pre->right = ptr;
		}
		else {
			if (pre != NULL) {
				pre->rtag = 0;
			}
		}

		pre = ptr;

		in_thread(ptr->right);
	}
}

bnode* succ(bnode* p) {
	bnode* q;

	if (p->rtag == 1) {
		return p->right;
	}
	else {
		q = p->right;
		while (q->ltag == 0) {
			q = q->left;
		}

		return q;
	}
}

void thinorder(bnode* root) {
	bnode* ptr = root;
	while (ptr != NULL) {
		printf("%c ", ptr->data);
		ptr = succ(ptr);
	}
}

void create_bit_tree(bnode** ptr){
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

int main(int argc, char** argv) {
	bnode* root = NULL;

	printf("create a tree(example: a b d g # # # e h # # i # # c # f # #):\n");
	create_bit_tree(&root);

	printf("in thread.\n");
	in_thread(root);

	thinorder(root);
	printf("\n");

	return 0;

}