#include<stdio.h>
#include<stdlib.h>
#define ELEMENTNULL 0
#define ARBRENULL NULL
#include "arbrebinaire.h"    
#include "file.h"
#include "abr.h"
#include "avl.h"




int main(){
    pArbre nouveauarbre = creerArbre(1);
    pArbre pnvarbre = nouveauarbre;
    ajouterFilsDroite(nouveauarbre,8);
    ajouterFilsGauche(nouveauarbre,2);
    pnvarbre = nouveauarbre->fg;
    ajouterFilsGauche(pnvarbre,3);
    ajouterFilsDroite(pnvarbre,6);
    pnvarbre=pnvarbre->fg;
    ajouterFilsDroite(pnvarbre,5);
    ajouterFilsGauche(pnvarbre,4);
    pnvarbre=nouveauarbre->fg;
    pnvarbre=pnvarbre->fd;
    ajouterFilsDroite(pnvarbre,7);
    pnvarbre=nouveauarbre->fd;
    ajouterFilsGauche(pnvarbre,9);
    ajouterFilsDroite(pnvarbre,10);
    //parcourPostfixe(nouveauarbre);
    //parcourPrefixe(nouveauarbre);
    parcourLargeur(nouveauarbre);
    return 0;
}
