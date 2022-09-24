#include <stdio.h>
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


//Khai bao Queue
#define MAX_ELEMENTS 100
typedef struct {
	int data[MAX_ELEMENTS];
	int front, rear;
} Queue;
void make_null_queue(Queue* Q) {
	Q->front = 0;
	Q->rear = -1;
}
void push(Queue* Q, int x) {
	Q->rear++;
	Q->data[Q->rear] = x;
}
int top(Queue* Q) {
	return Q->data[Q->front];
}
void pop(Queue* Q) {
	Q->front++;
}
int empty(Queue* Q) {
	return Q->front > Q->rear;
}

//chieu sau de quy
	#include<stdio.h>
	#define MAX_VERTEXES  100 
	
	int mark[MAX_VERTEXES];

void traversal(Graph* G, int x) {

	if (mark[x] == 1)
	return;

	printf("%d\n", x);

	List list = neighbors(G, x);
	int j;
	for (j = 1; j <= list.size; j++) {
	int y = element_at(&list, j);
	traversal(G, y);
	}
}
List depth_first_search(Graph* G) {

	int j;
	for (j = 1; j <= G->n; j++)
	mark[j] = 0;
	traversal(G, 1);
}

int main(){
//	freopen("dt.txt", "r", stdin); 
	Graph G;
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	int mark_bfs[MAXV];
	for (e=1; e<=G.n; e++){
		mark_bfs[e]=0;
	}
	for (e=1; e<=G.n; e++){
		if (mark_bfs[e]==0){
		List L = depth_first_search(&G);
			//traversal(&G, x);
			for (u=1; u<=L.size; u++){
				v = element_at(&L, u);
				printf("%d\n", v);
				mark_bfs[v]=1;
			}
		}
	}
	return 0;		
}
