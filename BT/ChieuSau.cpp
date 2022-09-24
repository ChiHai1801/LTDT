#include<stdio.h>
main(){
	Graph G;
	int n, m, u, v, w, e;
	scanf("%d %d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}

    void depth_first_search(Graph* G) {
    Stack frontier;
    int mark[MAX_VERTEXES];
    make_null_stack(&frontier);
    
    int j;
    for (j = 1; j <= G->n; j++)
    mark[j] = 0;
    
    push(&frontier, 1);
    mark[1] = 1;
    while (!empty(&frontier)) {
    int x = top(&frontier); pop(&frontier);
    printf("Duyet %d\n", x);
    List list = neighbors(G, x);
    for (j = 1; j <= list.size; j++) {
    int y = element_at(&list, j);
    if (mark[y] == 0) {
    mark[y] = 1;
    push(&frontier, y);
    }
   }
  }
}
}
