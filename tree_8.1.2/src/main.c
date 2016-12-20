#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _bnode {
	int data;
	int ltag, rtag;
	struct _bnode *left, *right;
} bnode;

static bnode* pre = NULL;

bnode* create_bit_tree() {
	int x = 0;
	bnode* ptr;

	printf("input a data(-1 means NULL for child):");
	scanf("%d", &x);
	if (x == -1) {
		ptr = NULL;
	}
	else {
		ptr = (bnode*)malloc(sizeof(bnode));
		memset(ptr, 0, sizeof(bnode));

		ptr->data = x;
		ptr->left = create_bit_tree();
		ptr->right = create_bit_tree();
	}

	return ptr;
}

void pre_order(bnode* ptr) {
	if (ptr != NULL) {
		printf("%d ", ptr->data);
		pre_order(ptr->left);
		pre_order(ptr->right);
	}
}

void in_order(bnode* ptr) {
	if (ptr != NULL) {
		in_order(ptr->left);
		printf("%d ", ptr->data);
		in_order(ptr->right);
	}
}

void post_order(bnode* ptr) {
	if (ptr != NULL) {
		post_order(ptr->left);
		post_order(ptr->right);
		printf("%d ", ptr->data);
	}
}

void in_thread(bnode* p) {
	if (p != NULL) {
		in_thread(p->left);

		if (p->left == NULL) {
			p->ltag = 1;
			p->left = pre;
		}
		else {
			p->ltag = 0;
		}

		if (pre != NULL && pre->right == NULL) {
			pre->rtag = 1;
			pre->right = p;
		}
		else {
			p->rtag = 0;
		}

		pre = p;

		in_thread(p->right);
	}
}

int depth(bnode* ptr) {
	int dep1 = 0;
	int dep2 = 0;

	if (ptr == NULL) {
		return 0;
	}
	else {
		dep1 = depth(ptr->left);
		dep2 = depth(ptr->right);
		if (dep1 < dep2) {
			return dep2 + 1;
		}
		else {
			return dep1 + 1;
		}
	}
}

int main(int argc, char** argv) {
	bnode* head = NULL;

	printf("create a tree(example: 1 2 -1 3 -1 -1 4 -1 5 -1 -1):\n");
	head = create_bit_tree();

	printf("output the tree by pre_order:");
	pre_order(head);
	printf("\noutput the tree by in_order:");
	in_order(head);
	printf("\noutput the tree by post_order:");
	post_order(head);

	printf("\nthread the tree by in_order.\n");
	in_thread(head);

	//printf("the depth of the tree is %d\n", depth(head));

	return 0;
}