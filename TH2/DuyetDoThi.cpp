#include<stdio.h> 
#define MAX_Vertices 20 
#define MAX_Length 20 
#define MAX_Element 40 
typedef struct{ 
    int A[MAX_Vertices][MAX_Vertices]; 
int n; 
}Graph; 
void init_Graph(Graph *G, int n){ 
G->n=n; 
int i, j; 
for(i=1; i<=G->n; i++) 
for(j=1; j<=G->n; j++) 
G->A[i][j] = 0; 
} 
void print_Graph(Graph G){ 
int i, j; 
for(i=1; i<=G.n; i++){ 
for(j=1; j<=G.n; j++) 
printf("%d ", G.A[i][j]); 
printf("\n"); 
    }  
    printf("\n"); 
} 
void add_edge(Graph *G, int x, int y){ 
G->A[x][y] =1; 
G->A[y][x] =1; 
} 
int adjacent(Graph *G, int x, int y){ 
return(G->A[x][y] !=0 ); 
} 
int degree(Graph *G, int x){ 
int i, deg=0; 
for(i=1; i<=G->n; i++){ 
if(adjacent(G, i, x)) deg++; 
} 
return deg; 
} 
typedef struct{ 
int data[MAX_Length]; 
int size; 
}List; 
void make_null(List *list){ 
list->size=0; 
} 
void push_back(List *list, int x){ 
list->data[list->size] =x; 
list->size++; 
} 
int element_at(List *list, int i){ 
return list->data[i-1]; 
} 
List neighbors(Graph *G, int x){ 
List L; 
make_null(&L); 
int i; 
for(i=1; i<=G->n; i++) 
if(adjacent(G, i, x)) push_back(&L, i);	 
return L; 
} 
typedef struct { 
int data[MAX_Element]; 
int front, rear; 
}Queue; 
void make_null_queue(Queue *Q){ 
Q->front =0; 
Q->rear =-1; 
} 
int empty(Queue *Q){ 
return Q->front > Q->rear; 
} 
void push(Queue *Q, int x){ 
Q->rear++; 
Q->data[Q->rear] =x; 
} 
int top(Queue *Q){ 
return Q->data[Q->front]; 
} 
void pop(Queue *Q){ 
Q->front++; 
} 
int mark[MAX_Vertices]; 
void breath_first_search(Graph *G, int k){ 
Queue frontier; 
make_null_queue(&frontier); 
int i;  
push(&frontier, k); 
mark[k] =1; 
while(!empty(&frontier)){ 
int x = top(&frontier); 
pop(&frontier); 
printf("%d\n", x); 
List list = neighbors(G, x); 
for(i=1; i<=list.size; i++){ 
int y = element_at(&list, i); 
if(mark[y] ==0){ 
mark[y] =1; 
push(&frontier, y); 
} 
} 
}
} 
int main(){ 
Graph G;	 
int n, m; 
//	freopen("DFS_Recursion.txt", "r", stdin); 
scanf("%d%d", &n, &m); 
init_Graph(&G, n); 
int u, v, i; 
for(i=1; i<=m; i++){ 
scanf("%d%d", &u, &v); 
add_edge(&G, u, v); 
} 
for(i=1; i<=G.n; i++) mark[i] =0; 
for(i=1; i<=n; i++) 
if(mark[i] ==0) 
breath_first_search(&G, i);							 
return 0; 
} 

=====================================================
#include <stdio.h>
#define MAX_ELEMENTS 100
#define MAX_VERTICES 100
typedef int Element_Type;
typedef struct {
Element_Type data[MAX_ELEMENTS];
int size;
}List;
void make_null_list(List *L){
L->size=0;
}
void push_back(List *L, Element_Type x){
L->data[L->size]=x;
L->size++;
}
Element_Type element_at(List *L, int i){
return L->data[i-1];
}
int count_list(List *L){
return L->size;
}
typedef struct {
int n;
List adj[MAX_VERTICES];
}Graph;
void init_graph(Graph *G, int n){
G->n=n;
int i;
for(i=1; i<=n; i++)
make_null_list(&G->adj[i]);
}
void add_edge(Graph *G, int x, int y){
push_back(&G->adj[x], y);
push_back(&G->adj[y], x);
}
int adjacent(Graph *G, int x, int y){
int i;
for(i=1; i<=G->adj[x].size; i++)
if(element_at(&G->adj[x],i) == y)
return 1;
return 0;
}
int degree(Graph *G, int x){
return G->adj[x].size;
}
List neighbors(Graph *G, int x){
List L;
make_null_list(&L);
int y;
for(y=1 ;y<=G->n; y++)
if(adjacent(G,x,y) ) push_back(&L, y);
return L;
}
int mark[MAX_VERTICES];
void traversal(Graph *G, int x){
if(mark[x] == 1) return;
mark[x]=1;
printf("%d\n",x);
List L=neighbors(G,x);
int i;
for(i=1; i<=L.size; i++){
int y=element_at(&L,i);
traversal(G,y);
}
}
void depth_first_search(Graph *G, int x){
int i;
for(i=1; i<=G->n; i++)
//mark[i]=0;
traversal(G,x);
}
int main(){
// freopen("dt.txt", "r", stdin);
Graph G;
int n, m, u, v, w, e;
scanf("%d%d", &n, &m);
init_graph(&G, n);
for (e = 0; e < m; e++) {
scanf("%d%d", &u, &v);
add_edge(&G, u, v);
}
depth_first_search(&G, 1);
for (w = 1; w <= n; w++)
if (mark[w] == 0)
depth_first_search(&G,w);
}

======================================

#include <stdio.h>
#define MAX_VERTEXES 100
#define MAX_ELEMENTS 100
#define MAX_NODES 100
/* Khai bao Stack*/
typedef struct {
int data[MAX_ELEMENTS];
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
// khi bao do thi
typedef struct {
int n, m;
int A[MAX_VERTEXES][MAX_VERTEXES];
}Graph;
// khoi tao do thi
void init_graph (Graph *G, int n) {
int i, j;
G->n = n;
for (i = 1; i <= n; i++)
for (j = 1; j <= n; j++)
G->A[i][j] = 0;
}
// them cung
void add_edge (Graph *G, int x, int y) {
G->A[x][y] = 1;
G->A[y][x] = 1;
}
// kiem tra co ke
int adjacent (Graph *G, int x, int y) {
return G->A[x][y] != 0;
}
// khai bao danh sach
typedef int ElementType;
typedef struct {
ElementType data [MAX_ELEMENTS];
int size;
}List;
// tao rong
void make_null(List * L) {
L->size = 0;
}
// them phan tu
void push_back(List *L, ElementType x) {
L->data[L->size] = x;
L->size++;
}
// lay phan tu tai vi tri i, phan tu dat o bat ky dau
ElementType element_at(List * L, int i) {
return L->data[i-1];
}
// tra ve so phan tu danh sach
int count_list(List *L) {
return L->size;
}
// tim cac dinh ke
List neighbors (Graph * G, int x) {
int y;
List list;
make_null(&list);
for (y = 1; y <= G->n; y++)
if (adjacent(G, x, y))
push_back(&list, y);
return list;
}
int mark[MAX_VERTEXES];
/* Duyet do thi theo chieu sau */
void depth_first_search(Graph* G, int x) {
Stack frontier;
//int mark[MAX_VERTEXES];
//int duyet[MAX_NODES];
//make_null_stack(&frontier);
/* Khoi tao mark, chua dinh n�o duoc x�t */
int j;
for (j = 1; j <= G->n; j++)
//mark[j] = 0;
/* �ua 1 v�o frontier */
push(&frontier, x);
/* Vong lap chinh dung de duyet */
while (!empty(&frontier)) {
/* Lay phan tu dau ti�n trong frontier ra */
int x = top(&frontier); pop(&frontier);
if (mark[x] != 0)
continue;
printf("%d\n", x);
mark[x] = 1; //��nh d?u n� d� duy?t
/* L?y c�c d?nh k? c?a n� */
List list = neighbors(G, x);
/* X�t c�c d?nh k? c?a n� */
for (j = 1; j <= list.size; j++) {
int y = element_at(&list, j);
push(&frontier, y);
}
}
}
int main () {
//freopen("dt.txt", "r", stdin);
Graph G;
int n, m, u, v, w, e;
scanf("%d%d", &n, &m);
init_graph(&G, n);
for (e = 0; e < m; e++) {
scanf("%d%d", &u, &v);
add_edge(&G, u, v);
//depth_first_search(&G);
}
depth_first_search(&G, 1);
for (w = 1; w <= n; w++)
if (mark[w] == 0)
depth_first_search(&G, w);
return 0;
}
