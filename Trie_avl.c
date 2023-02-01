#include <stdio.h>
#include <stdlib.h>
#include "Trie_avl.h"

parbre creerArbre (double a){
    parbre arbre = malloc(sizeof(arbre));
    if( arbre == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(1);
    }
    arbre->element = a;
    arbre->left_son = NULL;
    arbre->right_son = NULL;
    arbre->equilibre = 0;
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

parbre rotationGauche (parbre a){
    parbre pivot;
    int eq_a, eq_p;
    pivot = a->right_son;
    a->right_son = pivot->left_son;
    pivot->left_son = a;
    eq_a = a->equilibre;
    eq_p = pivot->equilibre;
    a->equilibre = eq_a - max(eq_p, 0) - 1;
    pivot->equilibre = min(eq_a-2, eq_a+eq_p-2, eq_p-1);
    a = pivot;
    return a;
}

parbre rotationDroite (parbre a){
    parbre pivot;
    int eq_a, eq_p;
    pivot = a->left_son;
    a->left_son = pivot->right_son;
    pivot->right_son = a;
    eq_a = a->equilibre;
    eq_p = pivot->equilibre;
    a->equilibre = eq_a - min(eq_p, 0) + 1;
    pivot->equilibre = max(eq_a+2, eq_a+eq_p+2, eq_p+1);
    a = pivot;
    return a;
}

parbre doubleRotationGauche (parbre a){
    a->right_son = rotationDroite(a->right_son);
    return rotationGauche(a);
}

parbre doubleRotationDroite (parbre a){
    a->left_son = rotationGauche(a->left_son);
    return rotationDroite(a);
}

parbre equilibrageAVL (parbre a){
    if(a->equilibre >= 2){
        if(a->right_son->equilibre >= 0){
            return rotationGauche(a);
        }
        else{
            return doubleRotationGauche(a);
        }
    }
    else if(a->equilibre <= -2){
        if(a->left_son->equilibre <= 0){
            return rotationDroite(a);
        }
        else{
            return doubleRotationDroite(a);
        }
    }
    return a;
}

parbre insertionAVL (parbre a, double c, double *h){
    if(a == NULL){
        *h = 1;
        return creerArbre(c);
    }
    else if(a->element > c){
        a->left_son = insertionAVL(a->left_son,c,h);
        *h = -*h;
    }
    else if(a->element < c){
        a->right_son = insertionAVL(a->right_son,c,h);
    }
    else{
        *h = 0;
    }
    if(*h != 0){
        a->equilibre = a->equilibre + *h;
        a = equilibrageAVL(a);
        if(a->equilibre == 0){
            *h = 0;
        }
        else{
            *h = 1;
        }
    }
    return a;
}

