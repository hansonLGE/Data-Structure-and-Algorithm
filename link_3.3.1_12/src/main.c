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
