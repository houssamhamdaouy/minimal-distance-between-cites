#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "tsp.h"

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Graphe g;
    char file[100];
    int bon_chemain[max];
    float min_dist;
    int start;
    int choix;

    

    printf("\n============================================\n");
    printf("   PROJET TSP - OPTIMISATION DE TOURNEE   \n");
    printf("============================================\n");

    // step 6:
    printf("1. Charger un fichier specifique\n");
    printf("2. Charger 'cities.txt' par defaut\n");
    printf("Votre choix : ");
    if (scanf("%d", &choix) != 1) choix = 2; 
    if (choix == 1) {
        printf("Nom du fichier : ");
        scanf("%s", file);
        load_graph_from_file(&g,file);
    } else {
        load_graph_from_file(&g,"cities.txt");
    }

    float p[max][max];
    for(int i=0;i<g.nbv;i++){
        for(int j=0;j<g.nbv;j++){
            p[i][j]=g.mtx[i][j];
        }
        
    }

    //  step 3 
    printf("\n[1/3] Calcul des distances reelles (Dijkstra)... ");
    pre_mtx_dijkstra(&g);
    printf("Termine.\n");

    printf("\n--- VILLES DISPONIBLES ---\n");
    for(int i=0; i<g.nbv; i++) {
        printf(" %d -> %s\n", i, g.nomville[i]);
    }

    printf("\nEntrez le numero de la ville de depart : ");
    while (scanf("%d",&start)!= 1 || start<0 || start>=g.nbv){
        printf("Numero invalide. Reessayez : ");
        clear_buffer();
    }

    // step 7
    if (!is_graph_connected(&g,start)) {
        printf("\n[ERREUR] Impossible de faire une tournee complete.\n");
        printf("Certaines villes sont inaccessibles (pas de route).\n");
        return 1; 
    }

    //  step 4
    printf("\n[2/3] Recherche du circuit optimal (TSP)... ");
    cal_tsp(&g, start, bon_chemain,&min_dist);
    printf("Termine.\n");

    //  step 6
    printf("\n============================================\n");
    printf(" RESULTATS POUR DEPART : %s\n", g.nomville[start]);
    printf("============================================\n");
    
    if (min_dist >= inf) {
        printf("Aucun chemin trouve (Graphe deconnecte).\n");
    } else {
        printf("DISTANCE TOTALE : %.2f km\n", min_dist);
        printf("ITINERAIRE      : ");
        
        printf("%s", g.nomville[start]);
        for(int i=0; i<g.nbv-1; i++) {
            printf(" -> %s", g.nomville[bon_chemain[i]]);
        }
        printf(" -> %s\n", g.nomville[start]);
    }
    printf("============================================\n");
    printf("si tu veux les matrice de graphe press 1 si no press 0 : ");
    int a;
    scanf("%d",&a);
    if(a==1){

    printf("matrice avant le remplisage");
    printf("\n");
    for(int i=0;i<g.nbv;i++){
        for(int j=0;j<g.nbv;j++){
            if(p[i][j]==inf) 
                printf("+inf | ");
            else 
                printf("%.2f | ", p[i][j]);
        }
        printf("\n");
        

    }
    printf("\n");
    printf("matrice apret le remplisage");
    display(&g);}




    printf("============================================\n");



    return 0;
}