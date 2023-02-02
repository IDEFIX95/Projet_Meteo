#include <stdio.h>
#include <stdlib.h>
#include "Tri_abr.h"
#include "Tri_avl.h"
#include "Tri_tab.h"
#include <unistd.h>
//faire getopt

int main(int argc, char *argv[])
{
    int flags, opt;
    int nsecs, tfnd;
    nsecs = 0;
    tfnd = 0;
    flags = 0;
    while ((opt = getopt(argc, argv, "rf:o:-:")) != -1) {
        switch (opt) {
        case 'f':
            
            break;
        case 'o':
            
            break;
        case 'r':

            break
        

    if (argc < 2){
        fprintf(stderr, "Erreur : Aucun fichier spécifié \n");
        return 1;
    }
    FILE * fichier1 = fopen("fichier_filtre", "r");
    if(fichier1 == NULL){    
        return 2;
    }
    FILE * fichier2 = fopen("fichier_trie", "w+");
    if(fichier2 == NULL){
        return 2;
    }
   

    char recursif[] = "-r";
    char abr[] = "--abr";
    char avl[] = "--avl";
    char tab[] = "--tab";
    int res;
    int a=0;
    for(int i=0; i < argc; i++){
        if(argv[i]=="--abr"){
            printf("bonjour");
        })



















        res = strcmp(recursif,argv[i]);
        if(res==0){
            a=1;
            for(int i=0; i < argc; i++){
                res = strcmp(abr,argv[i]);
                if(res==0){
                a=1;
            //Faut faire un tri abr croissant
            }
        }
    }
            //Faut faire un tri decroissant
        }
    }
    for(int i=0; i < argc; i++){
        res = strcmp(tab,argv[i]);
        if(res==0){
            a=1;
            //Faut faire un tri par liste chainee croissant
        }
    }
    for(int i=0; i < argc; i++){
        res = strcmp(abr,argv[i]);
        if(res==0){
            a=1;
            //Faut faire un tri abr croissant
        }
    }
    for(int i=0; i < argc; i++){
        res = strcmp(avl,argv[i]);
        if(res==0){
            a=1;
            //Faut faire un tri avl croissant
        }
    }
    if(a==0){
        //Faire un tri avl croissant
    }


// free malloc
    fclose(fichier1);
    fclose(fichier2);
    return 0;
}


