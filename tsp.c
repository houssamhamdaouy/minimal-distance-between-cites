#include <stdio.h>
#include "tsp.h"


void comitation(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}


void tsp_brute_force(Graphe *g,int villes[],int l,int r,int start,float *min_dist,int bon_chemain[]){
    if (l==r){
        float sdistance= 0;
        int k =start;
        for (int i=0;i<=r;i++){
            sdistance+= g->mtx[k][villes[i]];
            k = villes[i];
        }
        sdistance+=g->mtx[k][start];

        if(sdistance<*min_dist){
            *min_dist=sdistance;
            for (int i= 0;i<=r;i++) {
                bon_chemain[i]=villes[i];
            }
        }
    } else{
        for(int i =l;i<=r;i++) {
            comitation(&villes[l],&villes[i]);
            tsp_brute_force(g,villes,l+1,r,start,min_dist,bon_chemain);
            comitation(&villes[l],&villes[i]);
        }
    }
}


void cal_tsp(Graphe *g,int start,int bon_chemain[],float *min_dist) {
    int villes[max];
    int count=0;
    for (int i=0;i<g->nbv;i++) {
        if (i!=start) {
            villes[count++]=i;
        }
    }
    *min_dist=inf;
    tsp_brute_force(g,villes,0,count-1,start,min_dist,bon_chemain);
    
    
    printf("\nDistance minimale trouvee : %.2f\n",min_dist);
}