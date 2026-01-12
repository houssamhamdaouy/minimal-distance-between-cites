#include <stdio.h>
#include "graph.h"


void crea_graph(Graphe *g,int n){
    g->nbv=n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j) 
               g->mtx[i][j]=0;
            else 
                g->mtx[i][j]=inf; 
        }
    }
}


void add_edge(Graphe *g,int start,int end,float distance){
    if(start<g->nbv && end<g->nbv){
        g->mtx[start][end]=distance;
        g->mtx[end][start]=distance; 
    }
}


void display(Graphe *g){
    printf("\nrepresantation de la matrice des ville (Total des villes: %d):\n", g->nbv);
    for(int i=0;i<g->nbv;i++){
        for(int j=0;j<g->nbv;j++){
            if(g->mtx[i][j]==inf) 
                printf("+INF | ");
            else 
                printf("%.2f | ", g->mtx[i][j]);
        }
        printf("\n");
        

    }
}


void dijkstra(Graphe *g,int s, float dist[]) {
    int visited[max]={0};
    for (int i=0;i<g->nbv;i++){
        dist[i]=inf;
    }
    dist[s]=0;

    for(int i=0;i<g->nbv-1;i++){
        float min=inf;
        int u;
        for(int v=0;v<g->nbv;v++){
            if(!visited[v] && dist[v]<= min){
                min=dist[v];
                u=v;
            }
        }
        visited[u]=1;
        for (int v =0; v <g->nbv;v++){
            if(!visited[v] && g->mtx[u][v]!= inf &&dist[u]!=inf 
                && dist[u]+g->mtx[u][v]<dist[v]) {
                dist[v]=dist[u]+g->mtx[u][v];
            }
        }
    }
}


void pre_mtx_dijkstra(Graphe *g){
    float nouv[max][max];
    float temp[max];

   
    for (int i=0;i<g->nbv;i++){
        dijkstra(g,i,temp);
        for (int j=0;j<g->nbv;j++) {
            nouv[i][j]=temp[j];
        }
    }


    for (int i =0;i<g->nbv;i++){
        for (int j=0; j<g->nbv;j++){
            g->mtx[i][j]=nouv[i][j];
        }
    }
}

void load_graph(Graphe *g, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }
    int n;
    fscanf(fp, "%d", &n); 
    crea_graph(g, n);
    
    int u, v;
    float w;
    while (fscanf(fp, "%d %d %f", &u, &v, &w) != EOF) {
        add_edge(g, u, v, w);
    }
    
    fclose(fp);
}
