#include <stdio.h>
#include "graph.h"

int main() {
    Graphe g;
    float distances[max]; 
    
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

    int start=0;
    dijkstra(&g,start,distances);

    printf("\nla plus court distance de la vile %d:\n",start);
    for (int i=0;i<g.nbv;i++){
        printf("a la ville %d: %.1f\n", i, distances[i]);
    }

    return 0;
}