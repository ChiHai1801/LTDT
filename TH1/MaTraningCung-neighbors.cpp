int adjacent(Graph *G, int x, int y){ 
    int e; 
    for(e=1;e<=G->m;e++) 
        if(G->A[x][e]==1 && G->A[y][e]==1) 
    return 1; 
    return 0; 
} 

List neighbors(Graph *G, int x){ 
    List L; 
    make_null(&L); 
    int i; 
    for(i=1; i<=G->n; i++) 
        if(adjacent(G,x,i)==1 && x!=i) 
            push_back(&L,i); 
    return L; 
} 

//================================

List neighbors(Graph* G, int x) {
    List L;
    make_null(&L);
    int e, y;
    for (y = 1; y <= G->n; y++) {
    	if (x == y) continue;
        for (e = 1; e <= G->m; e++)
            if (G->A[x][e] > 0 && G->A[y][e] > 0) {
                push_back(&L, y);
                break;
            }
    }
    return L;
}

