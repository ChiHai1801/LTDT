#include <stdio.h>
#include<conio.h>
#define MAXV 100
typedef struct{
	int n;
	int A[MAXV][MAXV];
}Graph;
void init_graph(Graph* G, int n){
	int i, j;
	G->n=n;
	for (i=1; i<=n; i++){
		for (j=1; j<=n; j++)
			G->A[i][j]=0;
	}
}
void add_edge(Graph* G, int x, int y){
	G->A[x][y]=1;
	G->A[y][x]=1;
}
int adjacent(Graph* G, int x, int y){
	return G->A[x][y]!=0;
}
int degree(Graph* G, int x){
	int y, deg=0;
	for(y=1; y<=G->n; y++)
		if(G->A[x][y]>0)
			deg++;
	return deg;
}

// Khai bao List
#define MAX_E 100
typedef int elementtype;
typedef struct{
	elementtype data[MAX_E];
	int size;
}List;
void makenull(List* L){
	L->size=0;
}
void push_back(List* L, elementtype x){
	L->data[L->size]=x;
	L->size++;
}
elementtype element_at(List* L, int i){
	return L->data[i-1];
}
int count(List* L){
	return L->size;
}
/*Tim dinh ke */
List neighbors(Graph* G, int x){
	int y;
	List l;
	makenull(&l);
	for(y=1; y<=G->n; y++)
		if(adjacent(G, x, y))
			push_back(&l ,y);
	return l;
}

#define MAX_VERTICES 100
typedef struct {
	int n;
	int A[MAX_VERTICES][MAX_VERTICES];
} Graph;

	int rank[MAX_VERTICES];
void ranking(Graph* G) {
	int d[MAX_VERTICES];
	int x, u;
	for (u = 1; u <= G->n; u++)
		d[u] = 0;
	for (x = 1; x <= G->n; x++)
		for (u = 1; u <= G->n; u++)
			if (G->A[x][u] != 0)
				d[u]++;
				List S1, S2;
				make_null_list(&S1);
		for (u = 1; u <= G->n; u++)
			if (d[u] == 0)
				push_back(&S1, u);
				int k = 1, i;
		while (S1.size > 0) {
			make_null_list(&S2);
			for (i = 1; i <= S1.size; i++) {
				int u = element_at(&S1, i);
				rank[u] = k;
				int v;
			for (v = 1; v <= G->n; v++)
				if (G->A[u][v] != 0) {
					d[v]--;
				if (d[v] == 0)
					push_back(&S2, v);
				}
			}
		copy_list(&S1, &S2);
			k++;
		}
}

//int d[MAX_VERTICES]
int main() {
	Graph G;
	int n, u, x, v, j;

	FILE* file 
	freopen("DuAnXayNha.txt", "r", stdin);
	scanf("%d", &n);
	init_graph(&G, n+2);
	for (u = 1; u <= n; u++) {
		scanf("%d", &d[u]); 
	do {
		fscanf("%d", &v);
		if (v > 0) add_edge(&G, v, u);
	} while (v > 0);
} 

	for (u = 1; u <= n; u++) {
	int deg_neg = 0;
	for (x = 1; x <= n; x++)
		if (G.A[x][u] > 0)
	deg_neg++;
		if (deg_neg == 0)
			add_edge(&G, n+1, u); 
}

	for (u = 1; u <= n; u++) {
	int deg_pos = 0;
	for (v = 1; v <= n; v++)
		if (G.A[u][v] > 0)
			deg_pos++;
		if (deg_pos == 0)
			add_edge(&G, u, n+2);
	}
	
	topo_sort(&G, &L)

	int t[MAX_VERTICES];
		t[n+1] = 0;
	for (j = 2; j <= L.size; j++) {
		int u = element_at(&L, j);
		t[u] = +oo;
	for (x = 1; x <= G.n; x++)
		if (G.A[x][u] > 0)
			t[u] = min(t[u], t[x] + d[x]);
	}

	T[n+2] = t[n+2];
	for (j = L.size - 1; j >= 1; j--) {
		int u = element_at(&L, j);
		t[u] = -1;
	for (v = 1; v <= G.n; v++)
		if (G.A[u][v] > 0)
			T[u] = max(T[u], T[v] - d[u]);
}

	return 0;
	
}
