#include <stdio.h>
#include "graph.h"
#include "tsp.h"


int main(){
    Graphe g;
    int eficace[max];
    int s = 0;

    crea_graph(&g, 6);
    add_edge(&g,0,1,2);
    add_edge(&g,0,2,4);
    add_edge(&g,1,2,1); 
    add_edge(&g,1,3,4);
    add_edge(&g,1,4,2);
    add_edge(&g,2,4,3);
    add_edge(&g,3,5,2);
    add_edge(&g,4,3,3);
    add_edge(&g,4,5, 2);

    display(&g);
    
    pre_mtx_dijkstra(&g);
    

    display(&g);
    
    cal_tsp(&g, s, eficace);

    printf("Meilleur chemin : %d",s);
    for (int i=0;i<g.nbv-1;i++) {
        printf(" -> %d",eficace[i]);
    }
    printf(" -> %d\n",s);

    return 0;
}