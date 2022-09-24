#include<stdio.h>
struct edge{
	int u, v;
	int w;
};
struct vertice{
	int dist, pre, mark;
};
typedef struct{
	struct edge edges[200];
	struct vertice vertices[200];
	int n , m; //n dinh m cung

}Graph;
void init_graph(Graph *G, int n){
	G->n = n;
	G->m = 0;
}
void add_edge(Graph *G, int u, int v, int w){
	G->m++;
	G->edges[G->m].u = u;
	G->edges[G->m].v = v;
	G->edges[G->m].w = w;
}
void show(Graph G){
	int i;
	for(i = 1; i <= G.m; i++){
		printf("%d. cung (%d, %d) co w = %d\n",i,G.edges[i].u,G.edges[i].v,G.edges[i].w);
	}
}

void bellmanford(Graph *G, int root){
	int v, i, e, temp, u;
	for(v = 1; v <= G->n; v++){
		G->vertices[v].dist = 555;
		G->vertices[v].pre = 0;
	}
	G->vertices[root].dist = 0;
	G->vertices[root].pre = -1;
	for(i = 1; i <= G->n - 1; i++){
		for(e = 1; e <= G->m; e++){
			u = G->edges[e].u;
			v = G->edges[e].v;
			temp = G->vertices[u].dist + G->edges[e].w;
			if(temp < G->vertices[v].dist){
				G->vertices[v].dist = temp;
				G->vertices[v].pre = u;
			}
		}
	}
	for(e = 1; e <= G->m; e++){
		u = G->edges[e].u;
		v = G->edges[e].v;
		temp = G->vertices[u].dist + G->edges[e].w;
		if(temp < G->vertices[v].dist){
			printf("negative cycle");
			return;
		}		
	}
	printf("ok");

	
	
}

void path(Graph G){
	int i;
	for(i = 1; i <= G.n; i++){
		printf("dinh %d co (%d, %d)\n",i,G.vertices[i].dist,G.vertices[i].pre);
	}
}

int find_weight(Graph G, int u, int v){
	int e;
	for(e = 1; e <= G.m; e++){
		if(G.edges[e].u == u && G.edges[e].v == v) return G.edges[e].w;
	}
	return 0;
}
int lenght(Graph G){
	int len = 0, n = G.n, temp;
	while(1 != n){
		temp = G.vertices[n].pre;
		len += find_weight(G,temp,n);
		n = temp;
	}
	return len;
}
int main(){
//	freopen("d:\\LYTHUYETDOTHI\\filetest.txt", "r", stdin); //Nop b�i nho bo d�ng n�y.
	Graph G;
	int n, m, u, v, e, w;
	scanf("%d %d", &n, &m); //Doc du lieu n dinh m cung
	init_graph(&G, n);
	for(e = 1; e <= m; e++){
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	bellmanford(&G,1);
//	printf("%d ",lenght(G));
//	path(G);
	//show(G);
}


=========================================================

#include<stdio.h>
struct edge{
	int u, v;
	int w;
};
struct vertice{
	int dist, pre, mark;
};
typedef struct{
	struct edge edges[200];
	struct vertice vertices[200];
	int n , m; //n dinh m cung

}Graph;
void init_graph(Graph *G, int n){
	G->n = n;
	G->m = 0;
}
void add_edge(Graph *G, int u, int v, int w){
	G->m++;
	G->edges[G->m].u = u;
	G->edges[G->m].v = v;
	G->edges[G->m].w = w;
}
void show(Graph G){
	int i;
	for(i = 1; i <= G.m; i++){
		printf("%d. cung (%d, %d) co w = %d\n",i,G.edges[i].u,G.edges[i].v,G.edges[i].w);
	}
}

void bellmanford(Graph *G, int root){
	int v, i, e, temp, u;
	for(v = 1; v <= G->n; v++){
		G->vertices[v].dist = 555;
		G->vertices[v].pre = 0;
	}
	G->vertices[root].dist = 0;
	G->vertices[root].pre = -1;
	for(i = 1; i <= G->n - 1; i++){
		for(e = 1; e <= G->m; e++){
			u = G->edges[e].u;
			v = G->edges[e].v;
			temp = G->vertices[u].dist + G->edges[e].w;
			if(temp < G->vertices[v].dist){
				G->vertices[v].dist = temp;
				G->vertices[v].pre = u;
			}
		}
	}
//	for(e = 1; e <= G->m; e++){
	//	u = G->edges[e].u;
	//	v = G->edges[e].v;
	//	temp = G->vertices[u].dist + G->edges[e].w;
	//	if(temp < G->vertices[v].dist){
		//	printf("negative cycle");
	//		return;
	//	}		
//	}
//	printf("ok");

	
	
}

void path(Graph G){
	int i;
	for(i = 1; i <= G.n; i++){
		printf("dinh %d co (%d, %d)\n",i,G.vertices[i].dist,G.vertices[i].pre);
	}
}

int find_weight(Graph G, int u, int v){
	int e;
	for(e = 1; e <= G.m; e++){
		if(G.edges[e].u == u && G.edges[e].v == v) return G.edges[e].w;
	}
	return 0;
}
int lenght(Graph G){
	int len = 0, n = G.n, temp;
	while(1 != n){
		temp = G.vertices[n].pre;
		len += find_weight(G,temp,n);
		n = temp;
	}
	return len;
}
int main(){
//	freopen("d:\\LYTHUYETDOTHI\\filetest.txt", "r", stdin); //Nop b�i nho bo d�ng n�y.
	Graph G;
	int n, m, u, v, e, w;
	scanf("%d %d", &n, &m); //Doc du lieu n dinh m cung
	init_graph(&G, n);
	for(e = 1; e <= m; e++){
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	bellmanford(&G,1);
	printf("%d ",lenght(G));
//	path(G);
	//show(G);
}
