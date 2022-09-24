include
define MAX_N 100
define MAX_M 500
typedef struct {
int A[MAX_N][MAX_M];
int n, m;
} Graph;
void init_graph(Graph *pG, int n, int m){
int i,j;
pG->n=n;
pG->m=m;
for (i=1; i<= n; i++) for(j=1; j<= m; j++) pG->A[i][j]=0;
}
void add_edge(Graph *pG, int e, int x, int y){
if(x==y)
pG->A[x][e]=2;
else {
pG->A[x][e]=1; pG->A[y][e]=1; }
}
int degree(Graph *pG, int x){
int i, deg=0;
for(i=1; i<= pG->m; i++){
if(pG->A[x][i]==1)
deg++;
} return deg;
}
int main(){
Graph G;
int n, m, u, v, e, i;
scanf("%d %d", &n, &m);
init_graph(&G, n, m);
for(e=1; e<=m; e++){
scanf("%d %d", &u, &v);
add_edge(&G, e, u, v);
}
for(i=1; i<= n; i++)
printf("%d\n", degree(&G,i));
return 0;
}

===================================================

include
define MAX_N 100
define MAX_M 500
typedef struct {
int A[MAX_N][MAX_M];
int n, m;
} Graph;
void init_graph(Graph *pG, int n, int m){
int i,j;
pG->n=n;
pG->m=m;
for (i=1; i<= n; i++) for(j=1; j<= m; j++) pG->A[i][j]=0;
}
void add_edge(Graph *pG, int e, int x, int y){
if(x==y)
pG->A[x][e]=2;
else {
pG->A[x][e]=1; pG->A[y][e]=1; }
}
int degree(Graph *pG, int x){
int i, deg=0;
for(i=1; i<= pG->m; i++){
if(pG->A[x][i]==1)
deg++;
} return deg;
}
int main(){
Graph G;
int n, m, u, v, e, i;
scanf("%d %d", &n, &m);
init_graph(&G, n, m);
for(e=1; e<=m; e++){
scanf("%d %d", &u, &v);
add_edge(&G, e, u, v);
}
int max= degree(&G, 1);
for(i=2; i<= n; i++){
if(max <degree(&G, i))
max= degree(&G, i);
}
printf("%d", max);
return 0;
}
