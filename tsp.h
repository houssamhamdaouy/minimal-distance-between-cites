#ifndef TSP_H
#define TSP_H

#include "graph.h"

void comitation(int *x,int *y);
void tsp_brute_force(Graphe *g,int cities[],int l,int r,int start,float *min_dist, int best_path[]);
void cal_tsp(Graphe *g,int start_city,int best_path[]);

#endif