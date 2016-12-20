#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXVEX 100

typedef struct _node{
	int num;
	char data;
}node;

typedef struct _graph{
	node vexs[MAXVEX];
	int edges[MAXVEX][MAXVEX];
} graph;

void creat_graph(graph* p_adj, int n, int e) {
	int i = 0;
	int j = 0;
	int k = 0;
	int w = 0;
	char ch1 = 0;
	char ch2 = 0;

	for (i = 0; i < n; i++) {
		printf("the %d node's data:", i);
		scanf(" %c", &(p_adj->vexs[i].data));
		p_adj->vexs[i].num = i;
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			p_adj->edges[i][j] = 0;
		}
	}

	for (k = 0; k < e; k++) {
		printf("the %d edge =>\n", k);
		printf("start:");
		scanf(" %c", &ch1);
		printf("end:");
		scanf(" %c", &ch2);
		printf("the weight:");
		scanf("%d", &w);

		i = 0;
		while (i < n && ch1 != p_adj->vexs[i].data) {
			i++;
		}

		if (i >= n) {
			printf("failed to find the start node.\n");
			break;
		}

		j = 0;
		while (j < n && ch2 != p_adj->vexs[j].data) {
			j++;
		}

		if (j >= n) {
			printf("failed to find the end node.\n");
			break;
		}

		p_adj->edges[i][j] = w;
	}

}

void prim(graph* p_adj, int n, char x) {
	int lowcost[MAXVEX] = { 0 };
	int closest[MAXVEX] = {0};
	int i = 0;
	int j = 0;
	int k = 0;
	int min = 0;
	int t = 0;

	while (t < n && x != p_adj->vexs[t].data) {
		t++;
	}

	for (i = 0; i < n; i++) {
		lowcost[i] = p_adj->edges[t][i];
	}

	closest[t] = -1;

	for (i = 0; i < n; i++) {
		if (t == i) {
			continue;
		}
		else {
			k = 0;
			min = 32767;

			for (j = 0; j < n; j++) {
				if (closest[j] != -1 && lowcost[j] < min) {
					min = lowcost[j];
					k = j;
				}
			}

			if (k) {
				printf("(%d, %d) %d\n", closest[k], k, lowcost[k]);
				closest[k] = -1;

				for (j = 0; j < n; j++) {
					if (closest[j] != -1 && p_adj->edges[k][j] < lowcost[j]) {
						lowcost[j] = p_adj->edges[k][j];
						closest[j] = k;
					}
				}
			}
		}
	}

}

int main(int argc, char** argv) {
	graph m_graph;
	memset(&m_graph, 0, sizeof(graph));

	int n = 0;
	int e = 0;
	printf("input the count of nodes(n) and edges(e):");
	scanf("%d %d", &n, &e);

	creat_graph(&m_graph, n, e);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", m_graph.edges[i][j]);
		}
	}
	printf("\n");

	char ch = 0;
	scanf(" %c", &ch);

	prim(&m_graph, n, ch);


	return 0;
}