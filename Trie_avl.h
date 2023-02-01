#ifndef TRIE_AVL_H_
#define TRIE_AVL_H_

typedef struct  noeud{
    double element;
    struct noeud * left_son;
    struct noeud * right_son;
    int equilibre;
    int hauteur;
} Arbre;

typedef Arbre *parbre;

parbre creerArbre (double a);
int estVide (parbre a);
void parcoursinfixe (parbre a);
void parcoursdecroissant (parbre a);
parbre rotationGauche (parbre a);
parbre rotationDroite (parbre a);
parbre doubleRotationGauche (parbre a);
parbre doubleRotationDroite (parbre a);
parbre equilibrageAVL (parbre a);
parbre insertionAVL (parbre a, double c, double *h);

#endif