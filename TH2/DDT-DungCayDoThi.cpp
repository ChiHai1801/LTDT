#include <stdio.h>
#define MAX_Vertices 20
#define MAX_Element 40
#define MAX_Length 20
typedef struct {
int A[MAX_Vertices][MAX_Vertices];
int n;
} Graph;
void init_Graph (Graph *G, int n) {
int i, j;
G->n = n;
for (i = 1; i <= n; i++)
for (j = 1; j <= n; j++)
G->A[i][j] = 0;
}
void add_edge (Graph *G, int x, int y) {
G->A[x][y] = 1;
G->A[y][x] = 1;
}
// kiem tra co ke
int adjacent (Graph *G, int x, int y) {
return G->A[x][y] != 0;
}
int deg(Graph* G, int x){ 
int i, deg=0; 
for (i=1;i<=G->n;i++) 
if (adjacent(G,i,x))
deg++; 
return deg; 
} 

typedef struct {
int data [MAX_Element];
int size;
}List;

void make_null(List * list) {
list->size = 0;
}

void push_back(List *list, int x) {
list->data[list->size] = x;
list->size++;
}
int element_at(List * list, int i) {
return list->data[i-1];
}

List neighbors (Graph * G, int x) {
int i;
List L;
make_null(&L);
for (i = 1; i <= G->n; i++)
if (G->A[i][x]==1){
push_back(&L, i);
}
return L;
}
typedef struct {
int data [MAX_Element];
int front;
int rear;
}Queue;

void make_null_Queue(Queue *Q){ 
Q->front =0; 
Q->rear =-1; 
} 
void push_Queue(Queue *Q, int x){ 
Q->rear++; 
Q->data[Q->rear] =x; 
} 
int empty_Queue(Queue *Q){ 
return Q->front > Q->rear; 
} 

int top(Queue *Q){ 
return Q->data[Q->front]; 
} 
void pop(Queue *Q){ 
Q->front++; 
} 

List breath_first_search(Graph *G, int x,int parent[]){
    Queue Q;
    make_null_Queue(&Q);
    int mark[MAX_Vertices];
    int i;
    for(i=1;i<=G->n;i++){
        mark[i]=0;
        push_Queue(&Q,x);
    }
        parent[x]=0;
        List L_bfs;
        make_null(&L_bfs);
    
        while(!empty_Queue(&Q)){ 
            int u=top(&Q);
            pop(&Q);
            if(mark[u]==1)
            continue;
            push_back(&L_bfs,u);
            mark[u]=1;
            List L;
            make_null(&L);
            L=neighbors(G,u);
          int v;
            for(i=1; i<=L.size; i++){ 
            v= element_at(&L, i); 
                if(mark[v] ==0){
                 push_Queue(&Q,v);
                 if(parent[v]==-1)
                 parent[v]=u;
                }
            }
    }
   return L_bfs; 
}
int main(){
    Graph G;
    int n,m;
    scanf("%d%d", &n, &m); 
    init_Graph(&G, n); 
int e, x, y; 
for(e=1; e<=m; e++){ 
scanf("%d%d", &x, &y); 
add_edge(&G, x, y); 
} 
int mark_bfs[MAX_Vertices], parent[MAX_Vertices],u;
 for(u=1; u<=G.n; u++){ 
  mark_bfs[u]=0;
  parent[u]=-1;
 }

for(u=1; u<=G.n; u++){ 
    if(mark_bfs[u]==0){
        List L= breath_first_search(&G,u,parent);
        int i,v;
        for(i=1; i<=L.size; i++){ 
         v= element_at(&L, i); 
            //printf("%d\n",v);
              mark_bfs[v]=1;
    }
    }
}
for(u=1; u<=G.n; u++){
    printf("%d %d\n",u,parent[u]);
}
    return 0;
}


==============================================

#include <stdio.h>
#define MAX_Vertices 20
#define MAX_Element 40
#define MAX_Length 20
typedef struct {
int A[MAX_Vertices][MAX_Vertices];
int n;
} Graph;
void init_Graph (Graph *G, int n) {
int i, j;
G->n = n;
for (i = 1; i <= n; i++)
for (j = 1; j <= n; j++)
G->A[i][j] = 0;
}
void add_edge (Graph *G, int x, int y) {
G->A[x][y] = 1;
G->A[y][x] = 1;
}
// kiem tra co ke
int adjacent (Graph *G, int x, int y) {
return G->A[x][y] != 0;
}
int deg(Graph* G, int x){ 
int i, deg=0; 
for (i=1;i<=G->n;i++) 
if (adjacent(G,i,x))
deg++; 
return deg; 
} 

typedef int ElementType;
typedef struct {
ElementType data [MAX_Element];
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

typedef struct {
int data[MAX_Element];
int size;
} Stack;
void make_null_stack(Stack *stack) {
 stack->size = 0;
}
void push_stack(Stack* stack, int x) {
 stack->data[stack->size] = x;
 stack->size++;
}
int top(Stack* stack) {
return  stack->data[stack->size - 1];
}
void pop(Stack*  stack) {
 stack->size--;
}
int empty(Stack* stack) {
return stack->size == 0;
}
List depth_first_search(Graph* G, int x,int parent[]) {
    Stack S;
    make_null_stack(&S);
    push_stack(&S,x);
    parent[x]=0;
    List list_dfs;
    make_null(&list_dfs);
    int mark[MAX_Vertices];
    int i;
    for (i = 1; i <= G->n; i++)
        mark[i] = 0;
    while (!empty(&S)) {
        int u=top(&S);
        pop(&S);
        if(mark[u]==1)
        continue;
        push_back(&list_dfs,u);
        mark[u]=1;
        List list =neighbors(G,u);
        for (i= 1; i <= list.size; i++) {
int v = element_at(&list, i);
if(mark[v]==0){
    push_stack(&S,v);
    parent[v]=u;
}
    }
}
return list_dfs;
}

int main(){
    Graph G;
    int n,m,i,j;
   scanf("%d%d", &n, &m);
   init_Graph(&G, n);
   int e,u,v;
   for (e = 0; e <=m; e++) {
scanf("%d%d", &u, &v);
add_edge(&G, u, v);
   }
   
   int parent[MAX_Vertices];
   for(i=1;i<=G.n;i++){
       parent[i]=-1;
   }
   int mark_dfs[MAX_Vertices];
   for(i=1;i<=G.n;i++){
    mark_dfs[i]=0;   
   }
     for(i=1;i<=G.n;i++){
         if(mark_dfs[i]==0){
             List dfs=depth_first_search(&G,i,parent);
              for(j=1;j<=dfs.size;j++){
                  int k= element_at(&dfs,j);
                  mark_dfs[k]=1;
         }
         }
     }
      for(u=1;u<=G.n;u++)
          printf("%d %d\n",u,parent[u]);
    return 0;
}


============================================

#include <stdio.h>
#define MAX_Vertices 20
#define MAX_Length 20
typedef struct {
int A[MAX_Vertices][MAX_Vertices];
int n;
} Graph;
void init_Graph (Graph *G, int n) {
int i, j;
G->n = n;
for (i = 1; i <= n; i++)
for (j = 1; j <= n; j++)
G->A[i][j] = 0;
}
void add_edge (Graph *G, int x, int y) {
G->A[x][y] = 1;
G->A[y][x] = 1;
}
// kiem tra co ke
int adjacent (Graph *G, int x, int y) {
return G->A[x][y] != 0;
}
int deg(Graph* G, int x){ 
int i, deg=0; 
for (i=1;i<=G->n;i++) 
if (adjacent(G,i,x))
deg++; 
return deg; 
} 
typedef struct {
int data [MAX_Length];
int size;
}List;
// tao rong
void make_null(List * list) {
list->size = 0;
}
// them phan tu
void push_back(List *list, int x) {
list->data[list->size] = x;
list->size++;
}
// lay phan tu tai vi tri i, phan tu dat o bat ky dau
int element_at(List * list, int i) {
return list->data[i-1];
}
// tim cac dinh ke
List neighbors (Graph * G, int x) {
List L;
make_null(&L);
int i;
for (i = 1; i <= G->n; i++)
if (G->A[i][x]==1){
push_back(&L, i);
}
return L;
}
int mark[MAX_Vertices];
int parent[MAX_Vertices];
void DFS(Graph *G,int u,int p){
    if(mark[u]==1)
        return;
           parent[u]=p;
        mark[u]=1;
    List list=neighbors(G,u);
    int i;
    for(i=1;i<=list.size;i++){
        int v=element_at(&list,i);
        DFS(G,v,u);
    }
}
int main(){
    Graph G;
    int m,n;
   scanf("%d%d", &n, &m);
init_Graph(&G, n);
int u,v,i;
for (i = 1; i <=m; i++) {
scanf("%d%d", &u, &v);
add_edge(&G, u, v);
} 
    for (i = 1; i <=n; i++){ 
    mark[i]=0;
    parent[i]=-1;
    }
    for (i = 1; i <=n; i++)
    if(mark[i]==0)
    DFS(&G,i,0);
    for (i = 1; i <=n; i++) 
     printf("%d %d\n",i,parent[i]);  
    return 0;
}

