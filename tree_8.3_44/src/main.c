/*
create a BST based on a vector.
*/
#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct _bnode{
	int data;
	struct _bnode *left, *right;
}bnode;

 
void insert(bnode** p, bnode* s) {
	if (*p == NULL){
		*p = s;
	}
	else {
		if (s->data == (*p)->data) {
			return;
		}
		else if (s->data < (*p)->data) {
			insert(&((*p)->left), s);
		}
		else {
			insert(&((*p)->right), s);
		}
	}
}

void create(bnode** root, int* arr, int n) {
	int i = 0;
	bnode* s = NULL;

	for (i = 0; i < n; i++) {
		s = (bnode*)malloc(sizeof(bnode));
		s->data = arr[i];
		s->left = NULL;
		s->right = NULL;

		insert(root, s);
	}
}

void in_order(bnode* p) {
	if (p != NULL) {
		in_order(p->left);
		printf("%d ", p->data);
		in_order(p->right);
	}
}

int main(int argc, char** argv) {
	int vec[N] = { 0 };
	int n = 0;
	bnode* root = NULL;

	printf("input a vector size:");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("input a int data:");
		scanf("%d", &vec[i]);
	}

	printf("\n");
	printf("create a BST:\n");
	create(&root, vec, n);

	printf("output the BST by in order:\n");
	in_order(root);
	printf("\n");

	return 0;
}