#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 50
#define inf 46130    

typedef struct{
    int nbv;
    float mtx[max][max];
    char nomville[max][50]; 
}Graphe;


void crea_graph(Graphe *g,int num);
void add_edge(Graphe *g,int start,int end,float distance);
void display(Graphe *g);
void dijkstra(Graphe *g,int s,float dist[]);
void pre_mtx_dijkstra(Graphe *g);
void load_graph_from_file(Graphe *g,const char *file);
int is_graph_connected(Graphe *g,int start);

#endif