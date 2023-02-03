#include <stdio.h>
#include <stdlib.h>
#include "Tri_avl.h"
#include <unistd.h>
#include <getopt.h>
#include <string.h>
//faire getopt

#define ligne_max 1024


int main(int argc, char *argv[])
{
    int opt;
    int tri=0;
    int numero_temp=0;
    int numero_pression=0;
    char *fichierdentree=malloc(sizeof(char));
    char *fichiersortie=malloc(sizeof(char));
    int option_oblig=0;
    int option_reverse=0;
    int *valeurs=NULL;
    char ligne[ligne_max];
    while ((opt = getopt(argc, argv, "rwhmf:n:o:t:p:-:")) != -1) {
        switch (opt) {
        case 'n':
                tri = atoi(optarg);
            break;

        case 'f':
            sprintf(fichierdentree, "%s", optarg);
            option_oblig=1;
            //printf ("bonjour");
            break;
        case 'o':
            sprintf(fichiersortie, "%s", optarg);
            option_oblig=1;
            //printf("bonjour");
            break;
        case 'r':
            option_reverse=1;
            break;      
        case 't':
            if ((strcmp(optarg,"1") == 0) && (tri ==) ){
                printf("bonjour");
            }
            else if (strcmp(optarg,"2") == 0)
                printf("bonjour");
            else if (strcmp(optarg,"3") == 0)
                printf("bonjour");
            else 
                printf("argument inconnu");
            break;
        case 'p':
            if (strcmp(optarg,"1") == 0)
                numero_pression == 1;
            else if (strcmp(optarg,"2") == 0)
                numero_pression == 2;
            else if (strcmp(optarg,"3") == 0)
                numero_pression == 3;
            else 
                printf("argument inconnu");
            break;
        case 'w':

            break;
        case 'h':
            break;
            
        case 'm':

            break;
        case '?':
            printf("Option inconnue\n");
            break;

        default:
            printf("Option par défaut\n");
    }
  }
  
        
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





 /*if (option_reverse = 1){
    FILE * fichier1 = fopen("fichier_filtre", "r");
    int n = 0;
    while (fgets(ligne, ligne_max, &fichierdentree) != NULL)
    {
        n++;
    }
    rewind(fichierdentree);
    valeurs = (int *) malloc(n * sizeof(int));
    if (valeurs == NULL)
    {
        printf("erreur impossible d'allouer la memoire\n");
        return 1;
    }
    i = 0;
    while (fgets(ligne, ligne_max, &fichierdentree) != NULL)
    {
        char *field;
        field = strtok(line, ",");
        valeurs[i++] = atoi(field);
    }
    fclose(fp);
    qsort(valeurs, n, sizeof(int), compare);
  */



 // free malloc
 free(fichierdentree);
 fclose(fichier1);
    fclose(fichier2);
    return 0;
}
