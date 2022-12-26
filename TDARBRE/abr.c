#include<stdio.h>
#include<stdlib.h>
#include "arbrebinaire.h"   
#include "abr.h"
#include<stdbool.h>



bool recherche(pArbre a, int e){
    if(a==NULL){
        return false;
    }
    else if(a->nb==e){
        return true;
    }
    else if(e<a->nb){
        return recherche(a->fg,e);
    }
    else{
        return recherche(a->fd,e);
    }
}

//De maniere recursive 

pArbre insertABR(pArbre a,int e){
    if (a==NULL){
        return creerArbre(e);
    }
    else if (e < a->nb){
        a->fg=insertABR(a->fg,e);
    }
    else if(e > a->nb){
        a->fd=insertABR(a->fd,e);
    }
    return a;
}

//De maniere iterative

pArbre suppmax(pArbre a, int *element){
    pArbre tmp;
    if(exitseFilsDroit(a)){
        a->fd=suppmax(a->fd,element);
    }
    else{
        *element=a->nb;
        tmp=a;
        a=a->fg;
        free(tmp);
    }
    return a;
}

pArbre suppresion(pArbre a, int element){
    pArbre tmp;
    if(a==NULL){
        return a;
    }
    if(element > a->nb){
        a->fd=suppresion(a->fd,element);
    }
    else if(element < a->nb){
        a->fg=suppresion(a->fg,element);
    }
    else if(!exitseFilsGauche(a)){
        tmp=a;
        a=a->fd;
        free(tmp);
    }
    else{
      a->fg=suppmax(a->fg,&(a->nb));        
    }
    return a;
}

void moyenne2(pArbre a, int *compteur, int *somme){
    if(a!=NULL){
        moyenne2(a->fg,compteur,somme);
        *compteur += 1;
        *somme+=a->nb;
        moyenne2(a->fd,compteur,somme);
    }
}

float moyennesousarbregauche2(pArbre a){
    int somme=0;
    int compteur=0;
    float moy;
    moyenne2(a->fg,&compteur,&somme);
    moy=(float)somme/compteur;
    return moy;
}