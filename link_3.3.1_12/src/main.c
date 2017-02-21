/*
There are two single links named A and B in which all elements are in ascending order. Please write a function to get the intersection
between A and B, the intersection is called link C in which elements are still in ascending order.

已知两个单链表A与B分别表示两个集合，其元素递增排序。编写一个函数求出A和B的交集C，要求C同样以元素值递增的单链表形式存储。
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int data;
	struct _node* next;
} node;

void create(node** head) {
	node* s, *p = NULL;
	int cycle = 1;
	int x = 0;

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

node* inter(node* heada, node* headb) 
{
	node* headc = NULL;
	node*p = heada;
	node*q = headb;
	node *s, *r = headc;

	while(p != NULL && q != NULL) {
		if (p->data < q->data) {
			p = p->next;
		}
		else if(p->data > q->data){
			q = q->next;
		}
		else {
			s = (node*)malloc(sizeof(node));
			s->data = p->data;
			s->next = NULL;

			if (r == NULL) {
				headc = s;
				r = s;
			}
			else {
				r->next = s;
				r = s;
			}

			p = p->next;
			q = q->next;
		}
	}

	return headc;
}

void output(node* head) {
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

	printf("create the set A:\n");
	create(&heada);
	output(heada);

	printf("create the set B:\n");
	create(&headb);
	output(headb);

	node* headc = inter(heada, headb);
	printf("the intersection is:\n");
	output(headc);

	return 0;
}
