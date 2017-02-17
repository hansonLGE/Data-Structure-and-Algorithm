/*
There is a signal link which has one node at least and a pointer pointing to head. Please write a function to invert the link.

有一个单链表L（至少有一个结点），其头节点指针为head，编写一个函数将L逆置。
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node* next;
} node;

/*
创建一个单链表
*/
void create(node** head){
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

	p->next = *head;//cycle link

}

void output(node* head) {
	node* ptr = head;

	while (ptr != NULL) {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}

	printf("\n");
}

void invert(node** head) {
	node *p = *head;
	node *q = p->next;
	node *r = NULL;

	while (q != NULL) {
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}

	(*head)->next = NULL;
	*head = p;
}

//cycle link
void invert_cycle(node** head) {
	node *p = *head;
	node *q = p->next;
	node *r = NULL;

	while (q != *head) {
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}

	(*head)->next = p;
	*head = p;
}


int main(int argc, char** argv) {
	node* head = NULL;

	create(&head);
	//output(head);

	//invert(&head);
	invert_cycle(&head);
	printf("invert link:\n");
	output(head);
	return 0;
}