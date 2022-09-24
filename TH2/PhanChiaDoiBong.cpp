#include<stdio.h>
#define max_vertices 100
#define max_edges 500

typedef struct{
	int n, m; //n dinh m cung
	int A[max_vertices][max_edges];
	
}Graph;

	//khoi tao do thi
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
	//noi hai dinh do thi
void add_top(Graph* G, int x, int y){
	G->A[x][y]=1;
	G->A[y][x]=1;
}
	// danh cho do thi dinh dinh => kiem tra 2 dinh x y co ke nhau khong
int adjacent_top(Graph *G, int x, int y){
	return G->A[x][y] == 1;
}

int color[100], fail;
void dfs(Graph *G, int x, int c){
	if(color[x] == -1) {
		color[x] = c;
		int v;
		for(v = 1; v <= G->n; v++)
			if(adjacent_top(G,x,v))
				dfs(G,v,!c);
	}else{
		if(color[x] != c) fail = 0;
	}
	
}

void is_bigraph(Graph *G){
	int j;
	for(j = 1; j <= G->n; j++) color[j] = -1;
	fail = 1;
	dfs(G,1,0);
	if(fail){
		for(j = 1; j <= G->n; j++){
			if(color[j] == 0) printf("%d ",j);
		}
		printf("\n");
		for(j = 1; j <= G->n; j++){
			if(color[j] != 0) printf("%d ",j);
			
		}
	}
	else printf("IMPOSSIBLE");
}
int main(){
//	freopen("d:\\th.txt", "r", stdin); //Nop b�i nho bo d�ng n�y.
	Graph G;
	int n, m, u, v, e;
	scanf("%d %d", &n, &m); //Doc du lieu
	init_graph(&G, n, n);
	for (e = 1; e <= m; e++) {
		scanf("%d%d", &u, &v);
		add_top(&G, u, v);
	} 	
	is_bigraph(&G);
	return 0;
}
