/*
Please write a function to create a graph based on adjacent list.

采用邻接表构建图。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXVEX 30

typedef struct _edgenode{
	int weight;
	char data;
	struct _edgenode* next;
}edgenode;

typedef struct _vexnode{
	char data;
	edgenode *link;
}vexnode;

void create_graph(vexnode* g, int n, int e) {
	int i = 0;
	int k = 0;
	int w = 0;
	char ch1 = 0;
	char ch2 = 0;
	edgenode *p = NULL, *q = NULL;

	for (i = 0; i < n; i++) {
		printf("input %d node's data:", i);
		scanf(" %c", &g[i].data);
		g[i].link = NULL;
	}

	for (k = 0; k < e; k++) {
		printf("\nthe %d edge =>\n", k);
		printf("start:");
		scanf(" %c", &ch1);
		printf("end:");
		scanf(" %c", &ch2);
		printf("the weight:");
		scanf("%d", &w);

		i = 0;
		while (i < n && ch1 != g[i].data) {
			i++;
		}

		if (i >= n) {
			printf("failed to find the start node.\n");
			break;
		}

		p = g[i].link;

		q = (edgenode*)malloc(sizeof(edgenode));
		q->data = ch2;
		q->weight = w;

		q->next = p;
		g[i].link = q;
	}
}

void travgraph(vexnode* g, int n) {
	int i = 0;
	edgenode* p = NULL;

	for (i = 0; i < n; i++) {
		printf("[%d, %c]", i, g[i].data);
		p = g[i].link;
		while (p != NULL) {
			printf("(%c %d)", p->data, p->weight);

			p = p->next;
		}

		printf("\n");
	}
}

int main(int argc, char** argv) {
	int n = 0;
	int e = 0;
	vexnode adjlist[MAXVEX];
	memset(adjlist, 0, sizeof(adjlist));

	printf("input the count of nodes and edges:");
	scanf("%d %d", &n, &e);

	create_graph(adjlist, n, e);

	printf("travel the graph result is:\n");
	travgraph(adjlist, n);
	return 0;
}
