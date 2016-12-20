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

void output(node* head) {
	node* ptr = head;

	while (ptr != NULL) {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}

	printf("\n");
}

node* merge_link(node* heada, node* headb) {
	node* p = NULL;
	node* q = NULL;
	node* headc = NULL;
	node* r = NULL;

	if (heada->data <= headb->data) {
		headc = heada;
		p = heada;
		q = headb;
	}
	else {
		headc = headb;
		p = headb;
		q = heada;
	}

	while (p != NULL && q != NULL) {
		if (p->data <= q->data) {
			r = p;
			p = p->next;
		}
		else {
			r->next = q;
			r = q;
			q = r->next;
			r->next= p;
		}
	}

	if (p == NULL) {
		r->next = q;
	}

	if (q == NULL) {
		r->next = p;
	}

	return headc;
}

int main(int argc, char** argv) {
	node* heada = NULL;
	node* headb = NULL;
	node* headc = NULL;

	printf("create the link A:\n");
	create(&heada);
	output(heada);

	printf("create the link B:\n");
	create(&headb);
	output(headb);

	printf("merge link is:\n");
	headc = merge_link(heada, headb);
	output(headc);

	return 0;
}