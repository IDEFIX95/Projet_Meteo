#include<stdio.h>
#include<stdlib.h>
//#include<stdbool.h>
#define ELEMENTNULL 0
#define ARBRENULL NULL
#include "arbrebinaire.h"    
#include "file.h"
#include "abr.h"


int max(int a,int b){
    return(a<b ? b : a);
}


pArbre creerArbre(int element){
    pArbre noeud= malloc(sizeof(pArbre));
    if (noeud==NULL){
        exit(1);
    }
    noeud->nb=element;
    noeud->fg=NULL;
    noeud->fd=NULL;
    noeud->equilibre=0;
    return noeud;
}

int estVide(pArbre a){
    return (a == ARBRENULL);
}

int estFeuille(pArbre a){
    return (a && !(a->fg || a->fd));
}


int element (pArbre a){
    return(a ? a->nb : ELEMENTNULL);
}

int exitseFilsGauche(pArbre a){
    return (a->fg ? 1 : ELEMENTNULL);
}

int exitseFilsDroit(pArbre a){
   return (a->fd ? 1 : ELEMENTNULL);
}

pArbre ajouterFilsGauche(pArbre a, int e){
    pArbre nouveau;
    if(exitseFilsGauche(a)){
        return a;
    }
    nouveau = creerArbre(e);
    a->fg = nouveau;
    return a;
}

pArbre ajouterFilsDroite(pArbre a, int e){
    pArbre nouveau;
    if(exitseFilsDroit(a)){
        return a;
    }
    nouveau = creerArbre(e);
    a->fd = nouveau;
    return a;
}

void traiter(pArbre arbre)
{
    printf("%d,",arbre->nb);
}

void parcourPrefixe(pArbre a){
    if (a!=NULL){
        traiter(a);
        parcourPrefixe(a->fg);
        parcourPrefixe(a->fd);
        
    }
}

void parcourPostfixe(pArbre a){
     if (a!=NULL){
        parcourPrefixe(a->fg);
        parcourPrefixe(a->fd);
        traiter(a);
    }
}


pArbre parbremodifierracine(pArbre a, int e){
    a->nb=e;
    return a;
}


int hauteur(pArbre a){
    if(estVide(a)){
        return -1;
    }
    return 1 + max(hauteur(a->fg), hauteur(a->fd)); 
}


pArbre supprimerFilsGauche(pArbre a){
    if(!a){ //a==NULL
        return a;
    }
    if(exitseFilsGauche(a->fg)){
        a->fg=supprimerFilsGauche(a->fg);
    }
    if(exitseFilsDroit(a->fg)){
        a->fd=supprimerFilsDroit(a->fd);
    }
    free(a->fg);
    a->fg=NULL;
    return a;
}


pArbre supprimerFilsDroit(pArbre a){
    if(!a){ //a==NULL
        return a;
    }
    if(exitseFilsDroit(a->fd)){
        a->fd=supprimerFilsDroit(a->fd);
    }
    if(exitseFilsGauche(a->fd)){
        a->fg=supprimerFilsGauche(a->fg);
    }
    free(a->fd);
    a->fd=NULL;
    return a;
}

int nombrefeuille(pArbre a){
    if(!a){
      if(a->fg=NULL && a->fd=NULL){
        return ELEMENTNULL;
      }  
    }
    return 1;
}


