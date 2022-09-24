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


#define MAX_VERTEXES 100
typedef struct {
    int data[MAX_VERTEXES];
    int size;
} Stack;
void make_null_stack(Stack* S) {
    S->size = 0;
}
void push(Stack* S, int x) {
    S->data[S->size] = x;
    S->size++;
}
int top(Stack* S) {
    return S->data[S->size - 1];
}
void pop(Stack* S) {
    S->size--;
}
int empty(Stack* S) {
    return S->size == 0;
}

List depth_first_search(Graph* G) {
Stack L;
int mark[MAX_VERTEXES];
make_null_stack(&L);

int j;
for (j = 1; j <= G->n; j++)
    mark[j] = 0;

    push(&L, 1);
    //mark[1] = 1;

    while (!empty(&L)) {

    int x = top(&L); pop(&L);
    printf("%d\n", x);

    List list = neighbors(G, x);

    for (j = 1; j <= list.size; j++) {
    int y = element_at(&list, j);
    if (mark[y] == 0) {
    mark[y] = 1;
    push(&L, y);
            }
        }
    }
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
