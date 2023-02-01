#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trie_abr.h"

parbre creerArbre (double a){
    parbre arbre = malloc(sizeof(Arbre));
    if( Arbre == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(1);
    }
    arbre->elmt= a;
    arbre->left_son=NULL;
    arbre->right_son=NULL;
    return arbre;
}

int estVide (parbre a){
    if(a == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void parcoursinfixe (parbre a){ // Parcours dans l'ordre croissant
    if((estVide(a))!=1){
        parcoursinfixe(a->left_son);
        fprintf(fichier2,"%lf",a->elmt);
        parcoursinfixe(a->right_son);
    }
}

void parcoursdecroissant (parbre a){ //Parcours dans l'ordre décroissant
    if((estVide(a))!=1){
        parcoursdecroissant(a->right_son);
        fprintf(fichier2,"%lf",a->elmt);
        parcoursdecroissant(a->left_son);
    }
}

parbre InsertABR (parbre a, double e){
    if(a==NULL){
        a=creerArbre(e);
    }
    if(e > a->elmt){
        a->right_son = InsertABR(a->right_son,e);
    }
    else if(e < a->elmt){
        a->left_son = InsertABR(a->left_son);
    }
    return a;
}
