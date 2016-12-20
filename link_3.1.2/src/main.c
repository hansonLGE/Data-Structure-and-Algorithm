#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _dnode {
	int data;
	struct _dnode *left, *right;
} dnode;

dnode* create() {
	dnode *head, *s, *p = NULL;
	int cycle = 1;
	int x = 0;

	while (cycle) {
		printf("input a value:");
		scanf("%d", &x);
		if (x == 0) {
			cycle = 0;
		}
		else {
			s = (dnode*)malloc(sizeof(dnode));
			s->data = x;
			s->left = NULL;
			s->right = NULL;

			if (p == NULL) {
				head = s;
				p = s;
			}
			else {
				p->right = s;
				s->left = p;
				p = s;
			}
		}
	}

	//cycle double link
	//p->right = head;
	//head->left = p;
	return head;
}

void find(dnode* ptr, int x) {
	dnode* p = ptr;

	while (p != NULL && p->data != x) {
		p = p->right;
	}

	if (p == NULL) {
		printf("failed to find the value.\n");
	}
	else {
		printf("success to find the value\n");
	}
}

void find1(dnode* ptr, int x) {
	dnode* p = ptr;

	if (p->data == x) {
		printf("(cycle)success to find the value\n");
	}
	else {
		p = ptr->right;
		while (p != ptr && p->data != x) {
			p = p->right;
		}

		if (p != ptr) {
			printf("(cycle)success to find the value\n");
		}
		else {
			printf("(cycle)failed to find the value\n");
		}
	}
}

dnode* insert(dnode* ptr, int i, int x){
	dnode* p = ptr;
	int j = 0;

	dnode* s = (dnode*)malloc(sizeof(dnode));
	s->data = x;
	s->left = NULL;
	s->right = NULL;

	if (i == 0) {
		s->right = ptr;
		ptr->left = s;
		ptr = s;
	}
	else {
		j = 1;
		while (p != NULL && j < i) {
			p = p->right;
			j++;
		}

		if (p != NULL) {
			if (p->right == NULL) {
				p->right = s;
				s->left = p;
			}
			else {
				s->right = p->right;
				p->right->left = s;
				p->right = s;
				s->left = p;
			}
		}
		else {
			printf("failed to find the insert location\n");
		}
	}

	return ptr;
}

dnode* delete(dnode* ptr, int x) {
	dnode* p = ptr;

	if (ptr->data == x) {
		ptr = ptr->right;
		ptr->left = NULL;
		p->right = NULL;
		free(p);
	}
	else {
		p = ptr->right;
		while (p != NULL && p->data != x) {
			p = p->right;
		}

		if (p != NULL) {
			if (p->right == NULL) {
				p->left->right = NULL;
				p->left = NULL;
				free(p);
			}
			else {
				p->left->right = p->right;
				p->right->left = p->left;
				free(p);
			}
		}
		else {
			printf("failed to find the value.\n");
		}
	}

	return ptr;
}

void output(dnode* ptr) {
	dnode* p = ptr;

	while (p)
	{
		printf("%d ", p->data);
		p = p->right;
	}

	printf("\n");
}

int main(int argc, char** argv){
	dnode *ptr;
	int x = 0;
	int loc = 0;

#if 1
	printf("create a single double link\n");
	ptr = create();

	output(ptr);
	/*printf("please inoput the find value:");
	scanf("%d", &x);
	find(ptr, x);
	printf("input insert location and value:");
	scanf("%d %d", &loc, &x);
	ptr = insert(ptr, loc, x);*/

	printf("delete the value:");
	scanf("%d", &x);
	ptr = delete(ptr, x);
	output(ptr);
#else
	printf("create a cycle double link\n");
	ptr = create();

	printf("please inoput the find value:");
	scanf("%d", &x);
	find1(ptr, x);

#endif

	return 0;
}