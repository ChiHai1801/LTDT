#include<stdio.h> 
#define max_vertices 100 
#define max_edges 500 
typedef struct{ 
	int n, m; //n dinh m cung 
	int A[max_vertices][max_edges]; 
}Graph;

void init_graph(Graph *G, int n, int m){ 
	int i, j; 
	G->n = n; 
	G->m = m; 
	for(i = 1; i <= n; i++){ 
		for(j = 1; j <= m; j++){ 
			G->A[i][j] = 0; 
		} 
	} 
}
 
void add_edge (Graph* G, int e, int x, int y){ 
	G->A[x][e]=1; 
	G->A[y][e]=1; 
} 
int degree(Graph G, int x){ 
	int e, deg = 0; 
	for(e = 1; e <= G.m; e++){ 
		if(G.A[x][e] == 1) deg++; 
	} 
	return deg; 
} 
void max_degree(Graph G){ 
	int max_degree, temp; 
	int i, top = 0, n = G.n; 
	for(i = 1; i <= n; i++){ 
		temp = degree(G,i); 
		if(max_degree < temp){ 
			max_degree = temp; 
			top = i; 
		} 
	} 
	printf("%d %d",top,max_degree); 
}
 
int main(){ 
	Graph G; 
	int n, m, u, v, e; 
	scanf("%d %d", &n, &m); //Doc du lieu 
	init_graph(&G, n, m); 
	for (e = 1; e <= m; e++) { 
		scanf("%d%d", &u, &v); 
		add_edge(&G, e, u, v); 
	} 
	max_degree(G); 
	return 0; 
} 
