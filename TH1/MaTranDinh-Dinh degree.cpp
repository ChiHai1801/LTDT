int deg(Graph* G, int x){ 
    int i, d=0; 
    for (i=1;i<=G->n;i++) 
        if (G->A[i][x]==1) d++; 
    return d; 
} 
