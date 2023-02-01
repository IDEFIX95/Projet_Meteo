#ifndef TRIE_ABR_H_
#define TRIE_ABR_H_

typedef struct noeud{
    int elmt;
    struct noeud* left_son;
    struct noeud* right_son;
    int equilibre;
    int hauteur;
} Arbre;

typedef Arbre *parbre;

parbre creerArbre (double a);
int estVide (parbre a);
void parcoursinfixe (parbre a);
void parcoursdecroissant (parbre a);
parbre InsertABR (parbre a, double e);

#endif