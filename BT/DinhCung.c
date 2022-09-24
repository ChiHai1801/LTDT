#include<stdio.h>
Graph G;
int n, m, e, u, v;
FILE* file = fopen("dothi.txt", "r");
fscanf(file, "%d%d", &n, &m);
init_graph(&G, n, m);
for (e = 1; e <= m; e++) {
fscanf(file, "%d%d", &u, &v);
add_edge(&G, e, u, v);
}
for (v = 1; v <= n; v++)
printf("deg(%d) = %d\n", v, degree(&G, v));
return 0;
}
