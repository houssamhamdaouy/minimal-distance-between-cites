#include <stdio.h>
#include "tsp.h"


void comitation(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}


void tsp_brute_force(Graphe *g,int cities[],int l,int r,int start,float *min_dist,int best_path[]){
    if (l==r){
        float sdistance= 0;
        int k =start;
        for (int i=0;i<=r;i++){
            sdistance+= g->mtx[k][cities[i]];
            k = cities[i];
        }
        sdistance+=g->mtx[k][start];

        if(sdistance<*min_dist){
            *min_dist=sdistance;
            for (int i= 0;i<=r;i++) {
                best_path[i]=cities[i];
            }
        }
    } else{
        for(int i =l;i<=r;i++) {
            comitation(&cities[l],&cities[i]);
            tsp_brute_force(g,cities,l+1,r,start,min_dist,best_path);
            comitation(&cities[l],&cities[i]);
        }
    }
}


void cal_tsp(Graphe *g,int start_city,int best_path[]) {
    int cities[max];
    int count=0;
    for (int i=0;i<g->nbv;i++) {
        if (i!=start_city) {
            cities[count++]=i;
        }
    }
    float min_dist=inf;
    tsp_brute_force(g,cities,0,count-1,start_city,&min_dist,best_path);
    
    
    printf("\nDistance minimale trouvee : %.2f\n",min_dist);
}