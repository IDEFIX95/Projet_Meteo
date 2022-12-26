#ifndef _ARBREBINAIRE_H_
#define _ARBREBINAIRE_H_


typedef struct arbre{
    int nb;
    struct arbre* fg;
    struct arbre* fd;
    int hauteur;
    int equilibre;
}Arbre;

typedef Arbre* pArbre;


int max(int a,int b);
pArbre creerArbre (int element);
int estVide(pArbre a);
int estFeuille(pArbre a);
int element (pArbre a);
int exitseFilsGauche(pArbre a);
int exitseFilsDroit(pArbre a);
pArbre ajouterFilsGauche(pArbre a, int e);
pArbre ajouterFilsDroite(pArbre a, int e);
void traiter(pArbre arbre);
void parcourPrefixe(pArbre a);
void parcourPostfixe(pArbre a);
int hauteur(pArbre a);
#endif 