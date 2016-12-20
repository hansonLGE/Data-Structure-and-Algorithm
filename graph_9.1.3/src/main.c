#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXVEX 30

typedef struct _edgenode{
	int idx;
	int weight;
	char data;
	struct _edgenode* next;
}edgenode;

typedef struct _vexnode{
	char data;
	edgenode *link;
}vexnode;

typedef struct _queue{
	char data[MAXVEX];
	int front;
	int rear;
}queue;

int visited[MAXVEX] = {0};

void create_graph(vexnode* g, int n, int e) {
	int i = 0;
	int j = 0;
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

		j = 0;
		while (j < n && ch2 != g[j].data) {
			j++;
		}

		if (j >= n) {
			printf("failed to find the end node.\n");
			break;
		}

		p = g[i].link;

		q = (edgenode*)malloc(sizeof(edgenode));
		q->idx = j;
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
			printf("(%d %c %d)", p->idx, p->data, p->weight);

			p = p->next;
		}

		printf("\n");
	}
}

void dfs(vexnode* g, int n, char x) {
	int i = 0;
	edgenode* p = NULL;

	i = 0;
	while (i < n && g[i].data != x) {
		i++;
	}

	visited[i] = 1;
	printf("%c ", g[i].data);

	p = g[i].link;

	while(p != NULL) {
		if (visited[p->idx] == 0) {
			dfs(g, n, p->data);
		}
		p = p->next;
	}
}

void dfs_travel(vexnode* g, int n) {
	int i = 0;
	char ch = 0;

	while (1) {
		for (i = 0; i < n; i++) {
			visited[i] = 0;
		}

		printf("input a char for dfs:");
		scanf(" %c", &ch);
		printf("the dfs result is:");
		dfs(g, n, ch);
		printf("\n");
	}
}

void bfs(vexnode* g, int n, char x){
	queue qu;
	memset(&qu, 0, sizeof(qu));

	int i = 0;
	int j = 0;
	edgenode* p = NULL;
	char val = 0;

	i = 0;
	while (i < n && g[i].data != x) {
		i++;
	}

	visited[i] = 1;
	printf("%c ", g[i].data);

	qu.rear++;
	qu.data[qu.rear] = g[i].data;

	while (qu.front < qu.rear) {
		qu.front = (qu.front + 1) % MAXVEX;
		val = qu.data[qu.front];

		j = 0;
		while (j < n && g[j].data != val) {
			j++;
		}
		p = g[j].link;

		while (p != NULL) {
			if (visited[p->idx] == 0) {
				visited[p->idx] = 1;
				printf("%c ", p->data);

				qu.rear = (qu.rear+1) % MAXVEX;
				qu.data[qu.rear] = p->data;
			}

			p = p->next;
		}
	}
}

void bfs_travel(vexnode* g, int n) {
	int i = 0;
	char ch = 0;

	while (1) {
		for (i = 0; i < n; i++) {
			visited[i] = 0;
		}

		printf("input a char for bfs:");
		scanf(" %c", &ch);
		printf("the bfs result is:");
		bfs(g, n, ch);
		printf("\n");
	}
}

int main(int argc, char** argv) {
	int n = 0;
	int e = 0;
	int i = 0;
	vexnode adjlist[MAXVEX];
	memset(adjlist, 0, sizeof(adjlist));

	printf("input the count of nodes and edges:");
	scanf("%d %d", &n, &e);

	create_graph(adjlist, n, e);

	printf("travel the graph result is:\n");
	travgraph(adjlist, n);

//	dfs_travel(adjlist, n);
	bfs_travel(adjlist, n);

	return 0;
}
