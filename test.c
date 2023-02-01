#include <stdio.h>
#include <stdlib.h>



void AfficheListe(Chainon *pliste){
	if(pliste==NULL){
		printf("Liste NULL");
	}
	else{
		while(pliste!=NULL){
			printf("%lf->",pliste->elmt);
			pliste = pliste->suivant;
		}
	}
}



int Trie_TAB_croissant (){
	FILE *fichier1 = fopen("test","r");
	if(fichier1 == NULL){    
        return 2;
    }
	FILE * fichier2 = fopen("fichier_trie", "w+");
    if(fichier2 == NULL){
        return 2;
    }
	Chainon* liste = NULL;
	char c;
	double min, max, moy;
	min = 999;
	int i=0;
	double value;
	char ligne[100];
    while(!feof(fichier1)){
        while(c!=';'){
			c = fgetc(fichier1);
		}
		value = atof(fgets(ligne,100,fichier1));
        liste = ajouterCroissant(liste,value);
		i++;
		moy = moy + value;
		if(min > value){
			min = value;
		}
		else{
			min=min;
		}
		if(max < value){
			max = value;
		}
		else{
			max = max;
		}
	}
	moy = moy/i;
	printf ("La moyenne est de %lf, le minimum est de %lf et le maximum est de %lf",moy,min,max);
	Chainon* p1 = liste;
	while(p1->suivant != NULL){
		fprintf(fichier2,"%lf",p1->elmt);
		p1=p1->suivant;
	}
    return 0;
}

int Trie_TAB_decroissant(){
    FILE *fichier1 = fopen("test","r");
	if(fichier1 == NULL){    
        return 2;
    }
    FILE * fichier2 = fopen("fichier_trie", "w+");
    if(fichier2 == NULL){
        return 2;
    }
    Chainon* liste = malloc(sizeof(Chainon));
    char c;
    double min,max,moy;
	min=999;
	int i=0;
	double value;
	char ligne[100];
    while(!feof(fichier1)){
        while(c!=';'){
			c = fgetc(fichier1);
		}
		value = atof(fgets(ligne,100,fichier1));
        liste = ajouterDecroissant(liste,value);
		i++;
		moy = moy + value;
		if(min > value){
			min = value;
		}
		else{
			min=min;
		}
		if(max < value){
			max = value;
		}
		else{
			max = max;
		}
	}
	moy = moy/i;
	printf ("La moyenne est de %lf, le minimum est de %lf et le maximum est de %lf",moy,min,max);
    Chainon* p1 = liste;
	while(p1->suivant != NULL){
		fprintf(fichier2,"%lf",p1->elmt);
		p1=p1->suivant;
	}
    return 0;
}


int Trie_ABR_croissant(){
    FILE *fichier1 = fopen("test","r");
	if(fichier1 == NULL){    
        return 2;
    }
	FILE * fichier2 = fopen("fichier_trie", "w+");
    if(fichier2 == NULL){
        return 2;
    }
    parbre* arbre = malloc(sizeof(Arbre));
    char c;
    double min,max,moy;
	min=999;
	int i=0;
	double value;
	char ligne[100];
    while(!feof(fichier1)){
        while(c!=';'){
			c = fgetc(fichier1);
		}
		value = atof(fgets(ligne,100,fichier1));
        arbre = InsertABR(arbre,value);
        i++;
		moy = moy + value;
		if(min > value){
			min = value;
		}
		else{
			min=min;
		}
		if(max < value){
			max = value;
		}
		else{
			max = max;
		}
    }
    moy=moy/i;
    printf ("La moyenne est de %lf, le minimum est de %lf et le maximum est de %lf",moy,min,max);
    parcoursinfixe(arbre);
    return 0;
}

int Trie_ABR_decroissant(){
    FILE *fichier1 = fopen("test","r");
	if(fichier1 == NULL){    
        return 2;
    }
	FILE * fichier2 = fopen("fichier_trie", "w+");
    if(fichier2 == NULL){
        return 2;
    }
    parbre* arbre = malloc(sizeof(Arbre));
    char c;
    double min,max,moy;
	min=999;
	int i=0;
	double value;
	char ligne[100];
    while(!feof(fichier1)){
        while(c!=';'){
			c = fgetc(fichier1);
		}
		value = atof(fgets(ligne,100,fichier1));
        arbre = InsertABR(arbre,value);
        i++;
		moy = moy + value;
		if(min > value){
			min = value;
		}
		else{
			min=min;
		}
		if(max < value){
			max = value;
		}
		else{
			max = max;
		}
    }
    moy=moy/i;
    printf ("La moyenne est de %lf, le minimum est de %lf et le maximum est de %lf",moy,min,max);
    parcoursdecroissant(arbre);
    return 0;
}

int Trie_AVL_croissant(){
    FILE *fichier1 = fopen("test","r");
	if(fichier1 == NULL){    
        return 2;
    }
	FILE * fichier2 = fopen("fichier_trie", "w+");
    if(fichier2 == NULL){
        return 2;
    }
    parbre* arbre = malloc(sizeof(Arbre));
    char c;
    double min,max,moy;
	min=999;
	int i=0;
	double value;
	char ligne[100];
    while(!feof(fichier1)){
        while(c!=';'){
			c = fgetc(fichier1);
		}
		value = atof(fgets(ligne,100,fichier1));
        arbre = insertionAVL(arbre,value);
        i++;
		moy = moy + value;
		if(min > value){
			min = value;
		}
		else{
			min=min;
		}
		if(max < value){
			max = value;
		}
		else{
			max = max;
		}
    }
    moy=moy/i;
    printf ("La moyenne est de %lf, le minimum est de %lf et le maximum est de %lf",moy,min,max);
    parcoursinfixe(arbre);
    return 0;
}


int Trie_AVL_decroissant(){
    FILE *fichier1 = fopen("test","r");
	if(fichier1 == NULL){    
        return 2;
    }
	FILE * fichier2 = fopen("fichier_trie", "w+");
    if(fichier2 == NULL){
        return 2;
    }
    parbre* arbre = malloc(sizeof(Arbre));
    char c;
    double min,max,moy;
	min=999;
	int i=0;
	double value;
	char ligne[100];
    while(!feof(fichier1)){
        while(c!=';'){
			c = fgetc(fichier1);
		}
		value = atof(fgets(ligne,100,fichier1));
        arbre = insertionAVL(arbre,value);
        i++;
		moy = moy + value;
		if(min > value){
			min = value;
		}
		else{
			min=min;
		}
		if(max < value){
			max = value;
		}
		else{
			max = max;
		}
    }
    moy=moy/i;
    printf ("La moyenne est de %lf, le minimum est de %lf et le maximum est de %lf",moy,min,max);
    parcoursdecroissant(arbre);
    return 0;
}