#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "arbrebinaire.h"


File initfile(){
    File f;
    f.tete=NULL;
    f.queue=NULL;
    return f;
}

Chainon *creationchainon(pArbre a){
    Chainon *c = malloc(sizeof(Chainon));
    if(c==NULL){
        exit(1);
    }
    c->element=a;
    c->suivant=NULL;
    return c;
}


int verificationFile(File *file){
    int result=0;
    if(file==NULL){
        result=-1;
    }
    else if(((file->tete==NULL && file->queue != NULL) && (file->queue==NULL && file->tete != NULL))){
        result=-2;
    }
    else if(((file->queue) != NULL) && ((file->queue->suivant) != NULL)){
        result=-3;
    }
    return result;
}


int enfiler(File *file,pArbre nb){
    Chainon *nouveau;
    int result = 0;
    result=verificationFile(file);
    if(result>-2){
        nouveau=creationchainon(nb);
        if(file->queue==NULL){
            file->tete=nouveau;
            file->queue=nouveau;
        }
        else{
            file->queue->suivant=nouveau;
            file->queue=nouveau;
        }
    }
    return result;
}


int defiler(File *file, pArbre *nb){
    Chainon * c= file->tete;
    int result=0;
    result=verificationFile(file);
    if(result==0){
        if(file->tete ==NULL && file->queue==NULL){
            result=1;
            printf("NULL");
        }
        if(file->tete == file->queue){
            printf("il reste 1 element ");
            *nb=c->element;
            free(file->tete);
            file->queue=NULL;
            file->tete=NULL;
        }
        else{
        *nb=file->tete->element;
        file->tete=file->tete->suivant;
        free(c);
        }
    }
    return result;
}



void parcourLargeur(pArbre a){
    File nouveaufile=initfile();
    pArbre noeud=a;
    if(!estVide(a)){
        enfiler(&nouveaufile,a);
        while(nouveaufile.queue!=NULL && nouveaufile.tete!=NULL){
            defiler(&nouveaufile,&noeud);
            traiter(noeud);
            if(exitseFilsGauche(noeud)){
                enfiler(&nouveaufile,noeud->fg);
            } 
            if(exitseFilsDroit(noeud)){
                enfiler(&nouveaufile,noeud->fd);
            }
        }
    }
}
