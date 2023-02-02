#include <stdio.h>
#include <stdlib.h>
#include "Tri_avl.h"


int max(inta, intb) {return(a<b ? b : a);}


int min(inta, intb) {return(a < b ? a : b);}


parbre creerArbre (float a1, float a2 , float a3 , float a4 , float a5){
    parbre arbre = malloc(sizeof(arbre));
    if( arbre == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(1);
    }
    arbre->element1=a1
    arbre->element2=a2
    arbre->element3=a3
    arbre->element4=a4
    arbre->element5=a5;
    arbre->fils_gauche = NULL;
    arbre->fils_droit = NULL;
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
        parcoursinfixe(a->fils_gauche);
        fprintf(fichier2,"%lf",a->elmt);
        parcoursinfixe(a->fils_droit);
    }
}

void parcoursdecroissant (parbre a){ //Parcours dans l'ordre décroissant
    if((estVide(a))!=1){
        parcoursdecroissant(a->fils_droit);
        fprintf(fichier2,"%lf",a->elmt);
        parcoursdecroissant(a->fils_gauche);
    }
}

parbre rotationGauche (parbre a){
    parbre pivot;
    int eq_a, eq_p;
    pivot = a->fils_droit;
    a->fils_droit = pivot->fils_gauche;
    pivot->fils_gauche = a;
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
    pivot = a->fils_gauche;
    a->fils_gauche = pivot->fils_droit;
    pivot->fils_droit = a;
    eq_a = a->equilibre;
    eq_p = pivot->equilibre;
    a->equilibre = eq_a - min(eq_p, 0) + 1;
    pivot->equilibre = max(eq_a+2, eq_a+eq_p+2, eq_p+1);
    a = pivot;
    return a;
}


parbre doubleRotationGauche (parbre a){
    a->fils_droit = rotationDroite(a->fils_droit);
    return rotationGauche(a);
}


parbre doubleRotationDroite (parbre a){
    a->fils_gauche = rotationGauche(a->fils_gauche);
    return rotationDroite(a);
}


parbre equilibrageAVL (parbre a){
    if(a->equilibre >= 2){
        if(a->fils_droit->equilibre >= 0){
            return rotationGauche(a);
        }
        else{
            return doubleRotationGauche(a);
        }
    }
    else if(a->equilibre <= -2){
        if(a->fils_gauche->equilibre <= 0){
            return rotationDroite(a);
        }
        else{
            return doubleRotationDroite(a);
        }
    }
    return a;
}

parbre insertionAVL (parbre a, float a1, float a2, float a3, float a4, float a5, double *h){
    if(a == NULL){
        *h = 1;
        return creerArbre(a1,a2,a3,a4,a5);
    }
    else if(a->element > (a1,a2,a3,a4,a5)){
        a->fils_gauche = insertionAVL(a->fils_gauche,a1,a2,a3,a4,a5,h);
        *h = -*h;
    }
    else if(a->element < (a1,a2,a3,a4,a5)){
        a->fils_droit= insertionAVL(a->fils_droit,a1,a2,a3,a4,a5,h);
    }
    else{
        *h = 0;
        return a;
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
    else{
        parbre doublons=creerArbre(a1,a2,a3,a4,a5);
        if (estVide(a->fils_droit)){
            a->fils_droit=doublons->fils_droit;
        }
        else{
            doublons->fils_droit=a->fils_droit;
            a->fils_droit=doublons;
            
        }
    }
    return a;
}

