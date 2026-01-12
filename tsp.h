#ifndef TSP_H
#define TSP_H

#include "graph.h"

void comitation(int *x,int *y);
void tsp_brute_force(Graphe *g,int villes[],int l,int r,int start,float *min_dist, int bon_chemain[]);
void cal_tsp(Graphe *g,int start,int bon_chemain[],float *min_dist);

#endif