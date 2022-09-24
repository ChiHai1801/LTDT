#include <stdio.h>
#define INFINITY 9999
#define MAXN 500
#define NO_EDGE 0

typedef struct {
	int n;
	int m;
	int L[MAXN][MAXN];
} Graph;

void init_graph(Graph* G, int n, int m) {
	G->n = n;
	G->m = m;
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			G->L[i][j] = NO_EDGE;
		}
	}
}

#include <stdio.h>
#define MAX_ELEMENTS 100

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

#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct {
	ElementType data[MAX_ELEMENTS];
	int size;
} List;

void make_null(List* L) {
	L->size = 0;
}

void push_back(List* L, ElementType x) {
	L->data[L->size] = x;
	L->size++;
}

ElementType element_at(List* L, int i) {
	return L->data[i-1];
}

int count_list(List* L) {
	return L->size;
}

int empty_list(List* L) {
	return L->size == 0;
}

int adjacent(Graph* G, int x, int y) {
	int e;
	for (e = 1; e <= G->m; e++)
		if (G->L[x][e] == 1 && G->L[y][e] == 1)
	return 1;
	return 0;
}

int degree(Graph* G, int x) {
	int e, deg = 0;
	for (e = 1; e <= G->m; e++)
		if (G->L[x][e] == 1)
			deg++;
	return deg;
}

void print_list(List L) {
	int i;
	for (i = 1; i <= L.size; i++) {
		printf("%d ", element_at(&L, i));
	}
}

List neighbors(Graph* G, int x){
	int y;
	List list;
	make_null(&list);
 	for(y = 1; y <= G->n; y++)
 		if(adjacent(G,x,y))
 			push_back(&list,y);
 	return list;
}

void add_edge(Graph* G, int x, int y) {
	G->L[x][y] = 1;
}

int min(int a, int b) {
	if (a <= b) return a;
	else return b;
}

#define MAX_VERTICES 1000
int on_stack[MAX_VERTICES];
int num[MAX_VERTICES];
int min_num[MAX_VERTICES];
int k, count_pop = 0;
Stack S;
void strong_connect(Graph* G, int x) {
	num[x] = k;
	min_num[x] = k;
	k++;
	push(&S, x);
	on_stack[x] = 1;
	List list = neighbors(G, x);
	int j;
	for (j = 1; j <= list.size; j++) {
	int y = element_at(&list, j);
	if (num[y] < 0) {
	strong_connect(G, y);
	min_num[x] = min(min_num[x], min_num[y]);
	}
	else if (on_stack[y]) {
	min_num[x] = min(min_num[x], num[y]);
	}
	}
	if (num[x] == min_num[x]) {
	int w;
	do {
	w = top(&S);
	pop(&S);
	count_pop++;
	on_stack[w] = 0;
	} while (w != x);
	}
}

int main() {
// freopen("dothi.txt", "r", stdin);
	Graph G;
	int n, m;
	int e,  u, v, t;
	scanf("%d%d", &n, &m);
	init_graph(&G, n, m);
	for (e = 1; e <= m; e++) {
	scanf("%d%d%d", &u, &v, &t);
	if (t == 1) {
	add_edge(&G, u, v);
	}
	else if (t == 2) {
	add_edge(&G, u, v);
	add_edge(&G, v, u);
	}
	}
	// Khoi tao num[] va on_stack[]
	for (v = 1; v <= n; v++) {
	num[v] = -1;
	on_stack[v] = 0;
	}
	// Kiem tra dinh treo
	int dk = 1;
	for (v = 1; v <= n; v++) {
	List list = neighbors(&G, v);
	if (empty_list(&list)) {
	printf("NO");
	dk = 0;
	break;
	}
	}
	make_null_stack(&S);
	k = 1;
	for (v = 1; v <= G.n; v++) {
		if (num[v] == -1) {
			strong_connect(&G, v);
	}
	}
	if (dk == 1) {
	if (count_pop == n) {
	printf("OKIE");
	}
	else {
	printf("NO");
	}
	}
	return 0;
}
