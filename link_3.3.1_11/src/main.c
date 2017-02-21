/*
Please write a function to split the link A into two signal links named A and B. The nodes in link A are located by odd number 
in original sequence while the nodes in link B are located by even number.

编写一个函数将一个头结点指针为a的单链表A分解成两个单链表A和B，其头结点指针分别为a和b，使得A链表中含有原链表A中序号为奇数的元素，而B中含有
原链表A中序号为偶数的元素，且保持原来的相对顺序。
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node* next;
} node;

void create(node** head) {
	node *s, *p = NULL;
	int cycle = 1;
	int x = 0;

	while (cycle)
	{
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
				*head = s;
				p = s;
			}
			else {
				p->next = s;
				p = s;
			}
		}
	}
}

void disa(node* heada, node** headb) {
	node *p, *q, *r;

	p = heada;
	*headb = heada->next;
	q = *headb;
	

	while (q != NULL && q->next != NULL) {
		r = q->next;

		p->next = r;
		q->next = r->next;
		p = r;
		q = r->next;
	}

	p->next = NULL;
}

void output(node* head){
	node* ptr = head;

	while (ptr != NULL) {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}

	printf("\n");
}

int main(int argc, char** argv) {
	node* heada = NULL;
	node* headb = NULL;

	create(&heada);
	output(heada);

	printf("split the link.\n");
	disa(heada, &headb);
	output(heada);
	output(headb);

	return 0;
}