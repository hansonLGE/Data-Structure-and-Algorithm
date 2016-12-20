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
	bnode *s;

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
	else {
		if (p->left == NULL && p->right == NULL) {
			if (q->left == p) {
				q->left = NULL;
			}
			else if (q->right == p) {
				q->right = NULL;
			}

			free(p);
		}
		else if (p->left != NULL && p->right == NULL) {
			if (q->left == p) {
				q->left = p->left;
			}
			else if (q->right == p) {
				q->right = p->left;
			}

			free(p);
		}
		else if (p->left == NULL && p->right != NULL) {
			if (q->left == p) {
				q->left = p->right;
			}
			else if (q->right == p) {
				q->right = p->right;
			}

			free(p);
		}
		else {
			s = p->left;
			while (s->right != NULL) {
				q = s;
				s = s->right;
			}

			p->data = s->data;
			if (q != p) {
				q->right = s->left;
			}
			else {
				q->left = s->left;
			}

			free(s);
		}

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

	printf("create a BST(example 62,88,58,47,35,73,51,99,37,93):\n");
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