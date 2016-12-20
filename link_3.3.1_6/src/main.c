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

node* _union (node* ha, node* hb) {
	node *hc, *p = ha, *q = hb, *s, *r = NULL;

	while (p != NULL && q != NULL) {
		if (p->data < q->data) {
			s = (node*)malloc(sizeof(node));
			s->data = p->data;
			s->next = NULL;

			if (r == NULL) {
				hc = s;
				r = s;
			}
			else {
				r->next = s;
				r = s;
			}

			p = p->next;
		}
		else if (p->data > q->data) {
			s = (node*)malloc(sizeof(node));
			s->data = q->data;
			s->next = NULL;

			if (r == NULL) {
				hc = s;
				r = s;
			}
			else {
				r->next = s;
				r = s;
			}

			q = q->next;
		}
		else {
			s = (node*)malloc(sizeof(node));
			s->data = q->data;
			s->next = NULL;

			if (r == NULL) {
				hc = s;
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

	if (p == NULL) {
		while (q != NULL) {
			s = (node*)malloc(sizeof(node));
			s->data = q->data;
			s->next = NULL;

			r->next = s;
			r = s;

			q = q->next;
		}
	}

	if (q == NULL) {
		while (p != NULL) {
			s = (node*)malloc(sizeof(node));
			s->data = p->data;
			s->next = NULL;

			r->next = s;
			r = s;

			p = p->next;
		}
	}

	return hc;
}

int main(int argc, char** argv) {
	node* ha = NULL;
	node* hb = NULL;
	node* hc = NULL;

	printf("please create the first line.\n");
	create(&ha);
	output(ha);

	printf("please create the second line.\n");
	create(&hb);
	output(hb);

	hc = _union(ha, hb);
	printf("the union result:\n");
	output(hc);

	return 0;
}
