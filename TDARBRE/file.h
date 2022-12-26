#ifndef _FILE_H_
#define _FILE_H_
#include "arbrebinaire.h"

typedef struct chainon{
    pArbre element;
    struct chainon* suivant;
}Chainon;


typedef struct file{
    Chainon  *queue;
    Chainon  *tete;
}File;



File initfile();
Chainon *creationchainon(pArbre a);
int verificationFile(File *file);
int enfiler(File *file,pArbre nb);
int defiler(File *file, pArbre *nb);
void parcourLargeur(pArbre a);
#endif