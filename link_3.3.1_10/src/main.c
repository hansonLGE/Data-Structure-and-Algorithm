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

	p->next = *head;
}

node* link(node* head1, node* head2) {
	node *p = head1, *q = head2;

	while (p->next != head1) {
		p = p->next;
	}

	while (q->next != head2) {
		q = q->next;
	}

	q->next = head1;
	p->next = head2;

	return head2;
}
void output(node* head) {
	node* ptr = head;

	printf("%d ", ptr->data);

	ptr = ptr->next;

	while (ptr != head) {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}

	printf("\n");
}

int main(int argc, char** argv) {
	node* head1 = NULL;
	node* head2 = NULL;

	printf("create the first cycle link:\n");
	create(&head1);
	output(head1);

	printf("create the second cycle link:\n");
	create(&head2);
	output(head2);

	printf("the first cycle link is added to the tail of the second cycle link:\n");
	head2 = link(head1, head2);
	output(head2);

	return 0;
}