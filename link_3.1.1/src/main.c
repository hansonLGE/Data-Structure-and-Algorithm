/*
signal link operation

1 输入一系列整数，以0标志结束，将这些整数作为data域建立一个单链表(单链表或循环单链表) ；
2 在已经建立好的单链表(单链表或循环单链表)中查找元素；
3 计算已经建立好的单链表(单链表或循环单链表)；
4 在已经建立好的单链表(单链表或循环单链表)中插入元素；
5 在已经建立好的单链表(单链表或循环单链表)中删除元素。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
	int data;
	struct _node* next;
} node;

node* create() {
	node *head, *s, *p = NULL;
	int x = 0;
	int cycle = 1;

	while (cycle) {
		printf("input a node data:");
		scanf("%d", &x);

		if (x == 0) {
			cycle = 0;
		}
		else {
			s = (node*)malloc(sizeof(node));
			s->data = x;
			s->next = NULL;

			if (p == NULL) {
				head = s;
				p = s;
			}
			else {
				p->next = s;
				p = s;
			}
		}
	}

	//p->next = head; //循环单link
	return head;
}

/*
单链表查找
*/
void find(node* ptr, int x) {
	node* p = ptr;

	while (p != NULL && p->data != x) {
		p = p->next;
	}

	if (p){
		printf("success to find the node.\n");
	}
	else {
		printf("failed to find a node.\n");
	}
}

/*
循环单链表查找
*/
void find1(node* ptr, int x) {
	node* p = ptr;

	if (p->data == x) {
		printf("(cycle)success to find the node.\n");
	}
	else {
		p = p->next;
		while (p != ptr && p->data != x) {
			p = p->next;
		}

		if (p != ptr){
			printf("(cycle)success to find the node.\n");
		}
		else {
			printf("(cycle)failed to find a node.\n");
		}
	}

}

/*
单链表长度
*/
int length(node* ptr) {
	node* p = ptr;
	int cnt = 0;

	while (p != NULL) {
		cnt++;
		p = p->next;
	}

	return cnt;
}

/*
循环单链表长度
*/
int length1(node* ptr) {
	node* p = ptr;
	int cnt = 0;

	if (p == ptr) {
		cnt++;
	}

	p = p->next;

	while (p != ptr) {
		cnt++;
		p = p->next;
	}

	return cnt;
}

/*
插入元素
*/
node* insert(node* ptr, int i, int x) {
	int j = 0;
	node* p = NULL;
	node* s = (node*)malloc(sizeof(node));
	s->data = x;
	s->next = NULL;

	if (i == 0) {
		s->next = ptr;
		ptr = s;
	}
	else {
		p = ptr;
		j = 1;

		while (p != NULL && j < i) {
			p = p->next;
			j++;
		}

		if (p != NULL) {
			s->next = p->next;
			p->next = s;
		}
		else {
			printf("failed to find the location.\n");
		}
	}

	return ptr;
}

/*
删除元素
*/
node* delete (node* ptr, int x) {
	node* p = ptr;
	node* q = NULL;

	if (p->data == x) {
		ptr = ptr->next;
		free(p);
	}
	else {
		p = ptr->next;
		while (p != NULL && p->data != x) {
			q = p;
			p = p->next;
		}

		if (p != NULL) {
			q->next = p->next;
			free(p);
		}
		else {
			printf("failed to find the node.\n");
		}
	}

	return ptr;
}

void output(node* ptr) {
	while (ptr) {
		printf("%d ", ptr->data);

		ptr = ptr->next;
	}

	printf("\n");
}

int main(int argc, char** argv) {
	int x = 0;
	int loc = 0;
#if 1
	printf("create a single link.\n");
	node* ptr = create();

	output(ptr);
	printf("len is %d\n", length(ptr));
	/*printf("find the node's data is :");
	scanf("%d", &x);
	find(ptr, x);*/

	/*printf("please input insert location and value:");
	scanf("%d %d", &loc, &x);
	ptr = insert(ptr, loc, x);*/

	printf("please delete value:");
	scanf("%d", &x);
	ptr = delete(ptr, x);
	output(ptr);
#else
	printf("create a cycle link.\n");
	node* ptr = create();
	printf("len is %d\n", length1(ptr));
	/*printf("find the node's data is :");
	scanf("%d", &x);
	find1(ptr, x);*/
#endif
	return 0;
}