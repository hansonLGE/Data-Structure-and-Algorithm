/*
Binary Sort Tree: create、search、delete.

二叉排序树：建立、查找、删除。
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct _bnode{
	int data;
	struct _bnode *left, *right;
} bnode;

bnode* search(bnode* ptr, int x) {
	if (ptr == NULL) {
		return NULL;
	}
	else {
		if (x == ptr->data) {
			return ptr;
		}
		else if (x < ptr->data) {
			return search(ptr->left, x);
		}
		else {
			return search(ptr->right, x);
		}
	}
}

void delnode(bnode* head, int x) {
	bnode *p = head, *q = NULL;
	bnode *r;

	while (p != NULL && p->data != x) {
		if (x < p->data) {
			q = p;
			p = p->left;
		}
		else if(x > p->data){
			q = p;
			p = p->right;
		}
	}

	if (p == NULL) {
		printf("failed to find the node.\n");
	}
	else if(p->left == NULL){
		if (q == NULL) {
			head = p->right;
		}
		else if (q->left == p) {
			q->left = p->right;
		}
		else {
			q->right = p->right;
		}

		free(p);
		p = NULL;
	}
	else {
		r = p->left;
		while (r->right != NULL) {
			r = r->right;
		}

		r->right = p->right;

		if (q == NULL) {
			head = p->left;
		}
		else if (q->left == p) {
			q->left = p->left;
		}
		else {
			q->right = p->left;
		}

		free(p);
		p = NULL;
	}
}

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
int main(int argc, char** argv) {
	bnode* head = NULL;
	bnode* ptr = NULL;
	int x = 0;

	printf("create a BST(example 62,88,58,47,35,73,51,99,37,93,-1):\n");
	create(&head);
	in_order(head);

	printf("\ninput a search data:");
	scanf("%d", &x);
	ptr = search(head, x);
	printf("\nthe location node is %d\n", ptr);

	printf("\ninput a delete data:");
	scanf("%d", &x);
	delnode(head, x);
	in_order(head);

	return 0;
}