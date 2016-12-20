#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int data;
	struct _node* next;
} node;

void create(node** head){
	node *s, *p = NULL;
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

node * sum(node* heada, node* headb) {
	node* headc = NULL;
	node* p = heada;
	node* q = headb;
	node* r = headc;
	node* s = NULL;

	while (p != NULL) {
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

		s = (node*)malloc(sizeof(node));
		s->data = q->data;
		s->next = NULL;

		r->next = s;
		r = s;

		p = p->next;
		q = q->next;
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
	node* headc = NULL;

	printf("create the set A:\n");
	create(&heada);
	output(heada);

	printf("create the set B:\n");
	create(&headb);
	output(headb);

	printf("merge result is:\n");
	headc = sum(heada, headb);
	output(headc);

	return 0;
}