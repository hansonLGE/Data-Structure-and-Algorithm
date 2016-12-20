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
		printf("inoput a node data:");
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

	printf("separte the link.\n");
	disa(heada, &headb);
	output(heada);
	output(headb);

	return 0;
}