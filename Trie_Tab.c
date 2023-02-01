#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trie_Tab.h"
#include "Station.h"


Chainon* creationChainon(double a){
	Chainon *c = malloc(sizeof(*c));
	if(c==NULL){
		exit(1);
		}
	c->elmt=a;
	c->suivant=NULL;
	return c;
	}

Chainon *insertDebut(Chainon* pliste, double a){
	Chainon* nouveau = creationChainon(a);
	nouveau->suivant = pliste;
	return nouveau;
}

Chainon *ajouterCroissant(Chainon *pliste, double a) {
	Chainon *nouveau = malloc(sizeof(*nouveau));
	Chainon *p1 = pliste;
	if(pliste == NULL){// si la liste est vide
		pliste = creationChainon(nouveau->elmt);
	}
	else if (pliste->elmt > a) { // dans ce cas il faut placer l'element au début
		pliste = insertDebut(pliste,a);
	}
	else{
		//on parcours la liste jusqu'à trouver où doit aller le nouveau élément
		while((p1->suivant != NULL) && (p1->suivant->elmt < a)){ 
			p1 = p1->suivant;
		}
		if(p1->suivant == NULL){ // s'il faut placer le nouvel élément en fin de chaîne
			p1->suivant = nouveau;
		}
		else{ // il faut inserer le maillon en millieu de chaîne, après p1
			if(p1->suivant->elmt == a){
				*r=1;
			}
			nouveau->suivant = p1->suivant;
			p1->suivant = nouveau;
			
		}
	}
	return pliste;
}

Chainon *ajouterDecroissant(Chainon *pliste, double a){
    Chainon *nouveau = creationChainon(a);
    Chainon *p1 = pliste;
    if(pliste == NULL){ //si la liste est vide
        pliste = nouveau;
    }
	else if (pliste->elmt < a){ //dans le cas où il faut placer l'élément au début
		pliste = insertDebut(pliste,a);

	}
    else{
		//on parcours la liste jusqu'à trouver où on doit aller pour ajouter le nouvel élément
        while(p1->suivant != NULL && p1->suivant->elmt > a){
            p1 = p1->suivant; 
        }
        if(p1->suivant == NULL){ // s'il faut placer le nouvel élément en fin de chaine
            p1->suivant = nouveau;
        }
		else{ // il faut insérer le maillon en milieu de chaine après p1
			nouveau->suivant = p1->suivant;
			p1->suivant = nouveau;
		}
    }
	return pliste;
}


//T1 et P1
/*int T1_croissant(){
    Station un = malloc(sizeof(*un));
    if( un == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    un->num_station = 07558;
    un->temperature_min = 999;
    un->temperature_max = 0;
    Station deux = malloc(sizeof(*deux));
    if( deux == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    deux->num_station = 07110;
    deux->temperature_min = 999;
    deux->temperature_max = 0;
    Station trois = malloc(sizeof(*trois));
    if( trois == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    trois->num_station = 61976;
    trois->temperature_min = 999;
    trois->temperature_max = 0;
    Station quatre = malloc(sizeof(*quatre));
    if( quatre == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quatre->num_station = 07027;
    quatre->temperature_min = 999;
    quatre->temperature_max = 0;
    Station cinq = malloc(sizeof(*cinq));
    if( cinq == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    cinq->num_station = 07591;
    cinq->temperature_min = 999;
    cinq->temperature_max = 0;
    Station six = malloc(sizeof(*six));
    if( six == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    six->num_station = 71805;
    six->temperature_min = 999;
    six->temperature_max = 0;
    Station sept = malloc(sizeof(*sept));
    if( sept == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    sept->num_station = 78925;
    sept->temperature_min = 999;
    sept->temperature_max = 0;
    Station huit = malloc(sizeof(*huit));
    if( huit == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    huit->num_station = 07015;
    huit->temperature_min = 999;
    huit->temperature_max = 0;
    Station neuf = malloc(sizeof(*neuf));
    if( neuf == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    neuf->num_station = 07149;
    neuf->temperature_min = 999;
    neuf->temperature_max = 0;
    Station dix = malloc(sizeof(*dix));
    if( dix == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    dix->num_station = 81408;
    dix->temperature_min = 999;
    dix->temperature_max = 0;
    Station onze = malloc(sizeof(*onze));
    if( onze == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    onze->num_station = 89642;
    onze->temperature_min = 999;
    onze->temperature_max = 0;
    Station douze = malloc(sizeof(*douze));
    if( douze == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    douze->num_station = 07020;
    douze->temperature_min = 999;
    douze->temperature_max = 0;
    Station treize = malloc(sizeof(*treize));
    if( treize == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    treize->num_station = 07761;
    treize->temperature_min = 999;
    treize->temperature_max = 0;
    Station quatorze = malloc(sizeof(*quatorze));
    if( quatorze == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quatorze->num_station = 81405;
    quatorze->temperature_min = 999;
    quatorze->temperature_max = 0;
    Station quinze = malloc(sizeof(*quinze));
    if( quinze == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quinze->num_station = 07168;
    quinze->temperature_min = 999;
    quinze->temperature_max = 0;
    Station seize = malloc(sizeof(*seize));
    if( seize == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    seize->num_station = 07607;
    seize->temperature_min = 999;
    seize->temperature_max = 0;
    Station dix_sept = malloc(sizeof(*dix_sept));
    if( dix_sept == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    dix_sept->num_station = 07650;
    dix_sept->temperature_min = 999;
    dix_sept->temperature_max = 0;
    Station dix_huit = malloc(sizeof(*dix_huit));
    if( dix_huit == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    dix_huit->num_station = 61972;
    dix_huit->temperature_min = 999;
    dix_huit->temperature_max = 0;
    Station dix_neuf = malloc(sizeof(*dix_neuf));
    if( dix_neuf == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    dix_neuf->num_station = 07280;
    dix_neuf->temperature_min = 999;
    dix_neuf->temperature_max = 0;
    Station vingt = malloc(sizeof(*vingt));
    if( vingt == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    vingt->num_station = 07434;
    vingt->temperature_min = 999;
    vingt->temperature_max = 0;
    Station vingt_un = malloc(sizeof(*vingt_un));
    if( vingt_un == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    vingt_un->num_station = 07137;
    vingt_un->temperature_min = 999;
    vingt_un->temperature_max = 0;
    Station vingt_deux = malloc(sizeof(*vingt_deux));
    if( vingt_deux == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    vingt_deux->num_station = 07690;
    vingt_deux->temperature_min = 999;
    vingt_deux->temperature_max = 0;
    Station vingt_trois = malloc(sizeof(*vingt_trois));
    if( vingt_trois == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    vingt_trois->num_station = 61970;
    vingt_trois->temperature_min = 999;
    vingt_trois->temperature_max = 0;
    Station vingt_quatre = malloc(sizeof(*vingt_quatre));
    if( vingt_quatre == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    vingt_quatre->num_station = 07181;
    vingt_quatre->temperature_min = 999;
    vingt_quatre->temperature_max = 0;
    Station vingt_cinq = malloc(sizeof(*vingt_cinq));
    if( vingt_cinq == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    vingt_cinq->num_station = 07222;
    vingt_cinq->temperature_min = 999;
    vingt_cinq->temperature_max = 0;
    Station vingt_six = malloc(sizeof(*vingt_six));
    if( vingt_six == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    vingt_six->num_station = 07335;
    vingt_six->temperature_min = 999;
    vingt_six->temperature_max = 0;
    Station vingt_sept = malloc(sizeof(*vingt_sept));
    if( vingt_sept == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    vingt_sept->num_station = 07207;
    vingt_sept->temperature_min = 999;
    vingt_sept->temperature_max = 0;
    Station vingt_huit = malloc(sizeof(*vingt_huit));
    if( vingt_huit == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    vingt_huit->num_station = 07621;
    vingt_huit->temperature_min = 999;
    vingt_huit->temperature_max = 0;
    Station vingt_neuf = malloc(sizeof(*vingt_neuf));
    if( vingt_neuf == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    vingt_neuf->num_station = 07747;
    vingt_neuf->temperature_min = 999;
    vingt_neuf->temperature_max = 0;
    Station trente = malloc(sizeof(*trente));
    if( trente == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    trente->num_station = 61998;
    trente->temperature_min = 999;
    trente->temperature_max = 0;
    Station trente_un = malloc(sizeof(*trente_un));
    if( trente_un == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    trente_un->num_station = 07314;
    trente_un->temperature_min = 999;
    trente_un->temperature_max = 0;
    Station trente_deux = malloc(sizeof(*trente_deux));
    if( trente_deux == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    trente_deux->num_station = 07630;
    trente_deux->temperature_min = 999;
    trente_deux->temperature_max = 0;
    Station trente_trois = malloc(sizeof(*trente_trois));
    if( trente_trois == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    trente_trois->num_station = 07481;
    trente_trois->temperature_min = 999;
    trente_trois->temperature_max = 0;
    Station trente_quatre = malloc(sizeof(*trente_quatre));
    if( trente_quatre == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    trente_quatre->num_station = 07627;
    trente_quatre->temperature_min = 999;
    trente_quatre->temperature_max = 0;
    Station trente_cinq = malloc(sizeof(*trente_cinq));
    if( trente_cinq == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    trente_cinq->num_station = 07510;
    trente_cinq->temperature_min = 999;
    trente_cinq->temperature_max = 0;
    Station trente_six = malloc(sizeof(*trente_six));
    if( trente_six == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    trente_six->num_station = 61980;
    trente_six->temperature_min = 999;
    trente_six->temperature_max = 0;
    Station trente_sept = malloc(sizeof(*trente_sept));
    if( trente_sept == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    trente_sept->num_station = 61996;
    trente_sept->temperature_min = 999;
    trente_sept->temperature_max = 0;
    Station trente_huit = malloc(sizeof(*trente_huit));
    if( trente_huit == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    trente_huit->num_station = 07577;
    trente_huit->temperature_min = 999;
    trente_huit->temperature_max = 0;
    Station trente_neuf = malloc(sizeof(*neuf));
    if( trente_neuf == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    trente_neuf->num_station = 07240;
    trente_neuf->temperature_min = 999;
    trente_neuf->temperature_max = 0;
    Station quarante = malloc(sizeof(*quarante));
    if( quarante == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quarante->num_station = 07117;
    quarante->temperature_min = 999;
    quarante->temperature_max = 0;
    Station quarante_un = malloc(sizeof(*quarante_un));
    if( quarante_un == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quarante_un->num_station = 07130;
    quarante_un->temperature_min = 999; 
    quarante_un->temperature_max = 0;
    Station quarante_deux = malloc(sizeof(*quarante_deux));
    if( quarante_deux == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quarante_deux->num_station = 07190;
    quarante_deux->temperature_min = 999;
    quarante_deux->temperature_max = 0;
    Station quarante_trois = malloc(sizeof(*quarante_trois));
    if( quarante_trois == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quarante_trois->num_station = 78897;
    quarante_trois->temperature_min = 999;
    quarante_trois->temperature_max = 0;
    Station quarante_quatre = malloc(sizeof(*quarante_quatre));
    if( quarante_quatre == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quarante_quatre->num_station = 67005;
    quarante_quatre->temperature_min = 999;
    quarante_quatre->temperature_max = 0;
    Station quarante_cinq = malloc(sizeof(*quarante_cinq));
    if( quarante_cinq == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quarante_cinq->num_station = 78922;
    quarante_cinq->temperature_min = 999;
    quarante_cinq->temperature_max = 0;
    Station quarante_six = malloc(sizeof(*quarante_six));
    if( quarante_six == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quarante_six->num_station = 61997;
    quarante_six->temperature_min = 999;
    quarante_six->temperature_max = 0;
    Station quarante_sept = malloc(sizeof(*quarante_sept));
    if( quarante_sept == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quarante_sept->num_station = 07255;
    quarante_sept->temperature_min = 999;
    quarante_sept->temperature_max = 0;
    Station quarante_huit = malloc(sizeof(*quarante_huit));
    if( quarante_huit == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quarante_huit->num_station = 07005;
    quarante_huit->temperature_min = 999;
    quarante_huit->temperature_max = 0;
    Station quarante_neuf = malloc(sizeof(*quarante_neuf));
    if( quarante_neuf == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quarante_neuf->num_station = 07460;
    quarante_neuf->temperature_min = 999;
    quarante_neuf->temperature_max = 0;
    Station cinquante = malloc(sizeof(*cinquante));
    if( cinquante == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    cinquante->num_station = 07471;
    cinquante->temperature_min = 999; 
    cinquante->temperature_max = 0;
    Station cinquante_un = malloc(sizeof(*cinquante_un));
    if( cinquante_un == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    cinquante_un->num_station = 07299;
    cinquante_un->temperature_min = 999;
    cinquante_un->temperature_max = 0;
    Station cinquante_deux = malloc(sizeof(*cinquante_deux));
    if( cinquante_deux == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    cinquante_deux->num_station = 07790;
    cinquante_deux->temperature_min = 999;
    cinquante_deux->temperature_max = 0;
    Station cinquante_trois = malloc(sizeof(*cinquante_trois));
    if( cinquante_trois == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    cinquante_trois->num_station = 61976;
    cinquante_trois->temperature_min = 999;
    cinquante_trois->temperature_max = 0;
    Station cinquante_quatre = malloc(sizeof(*cinquante_quatre));
    if( cinquante_quatre == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    cinquante_quatre->num_station = 81401;
    cinquante_quatre->temperature_min = 999;
    cinquante_quatre->temperature_max = 0;
    Station cinquante_cinq = malloc(sizeof(*cinquante_cinq));
    if( cinquante_cinq == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    cinquante_cinq->num_station = 07643;
    cinquante_cinq->temperature_min = 999;
    cinquante_cinq->temperature_max = 0;
    Station cinquante_six = malloc(sizeof(*cinquante_six));
    if( cinquante_six == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    cinquante_six->num_station = 07661;
    cinquante_six->temperature_min = 999;
    cinquante_six->temperature_max = 0;
    Station cinquante_sept = malloc(sizeof(*cinquante_sept));
    if( cinquante_sept == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    cinquante_sept->num_station = 81415;
    cinquante_sept->temperature_min = 999;
    cinquante_sept->temperature_max = 0;
    Station cinquante_huit = malloc(sizeof(*cinquante_huit));
    if( cinquante_huit == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    cinquante_huit->num_station = 61968;
    cinquante_huit->temperature_min = 999;
    cinquante_huit->temperature_max = 0;
    Station cinquante_neuf = malloc(sizeof(*cinquante_neuf));
    if( cinquante_neuf == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    cinquante_neuf->num_station = 07139;
    cinquante_neuf->temperature_min = 999;
    cinquante_neuf->temperature_max = 0;
    Station soixante = malloc(sizeof(*soixante));
    if( soixante == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    soixante->num_station = 07535;
    soixante->temperature_min = 999;
    soixante->temperature_max = 0;
    Station soixante_un = malloc(sizeof(*soixante_un));
    if( soixante_un == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    soixante_un->num_station = 07037;
    soixante_un->temperature_min = 999;
    soixante_un->temperature_max = 0;
	Chainon* liste = NULL;
	char buffer[1000];
	int ligne=0;
	int colonne=0;
	double value=0;
    double value2=0;
	while((fgets(buffer,1000,fichier1))!=NULL){
		colonne=0;
		ligne++;
		if(ligne==1){
			continue;
		}
		char *element = strtok(buffer,";");
		while(element){
			if(colonne == 0){
				value = atof(*element);
				liste = ajouterCroissant(liste,value);
			}
			if(colonne == 1){
                value2 = atof(*element);
                if(value == un->num_station){
                    if(un->temperature_min > value2){
                        un->temperature_min = value2;
                    }
                    else{
                        un->temperature_min = un->temperature_min;
                    }
                    if(un->temperature_max < value2){
                        un->temperature_max = value2;
                    }
                    else{
                        un->temperature_max = un->temperature_max;
                    }
                }
                if(value == deux->num_station){
                    if(deux->temperature_min > value2){
                        deux->temperature_min = value2;
                    }
                    else{
                        deux->temperature_min = deux->temperature_min;
                    }
                    if(deux->temperature_max < value2){
                        deux->temperature_max = value2;
                    }
                    else{
                        deux->temperature_max = deux->temperature_max;
                    }
                }
                if(value == trois->num_station){
                    if(trois->temperature_min > value2){
                        trois->temperature_min = value2;
                    }
                    else{
                        trois->temperature_min = trois->temperature_min;
                    }
                    if(trois->temperature_max < value2){
                        trois->temperature_max = value2;
                    }
                    else{
                        trois->temperature_max = trois->temperature_max;
                    }
                }
                if(value == quatre->num_station){
                    if(quatre->temperature_min > value2){
                        quatre->temperature_min = value2;
                    }
                    else{
                        quatre->temperature_min = quatre->temperature_min;
                    }
                    if(quatre->temperature_max < value2){
                        quatre->temperature_max = value2;
                    }
                    else{
                        quatre->temperature_max = quatre->temperature_max;
                    }
                }
                if(value == cinq->num_station){
                    if(cinq->temperature_min > value2){
                        cinq->temperature_min = value2;
                    }
                    else{
                        cinq->temperature_min = cinq->temperature_min;
                    }
                    if(cinq->temperature_max < value2){
                        cinq->temperature_max = value2;
                    }
                    else{
                        cinq->temperature_max = cinq->temperature_max;
                    }
                }
                if(value == six->num_station){
                    if(six->temperature_min > value2){
                        six->temperature_min = value2;
                    }
                    else{
                        six->temperature_min = six->temperature_min;
                    }
                    if(six->temperature_max < value2){
                        six->temperature_max = value2;
                    }
                    else{
                        six->temperature_max = six->temperature_max;
                    }
                }
                if(value == sept->num_station){
                    if(sept->temperature_min > value2){
                        sept->temperature_min = value2;
                    }
                    else{
                        sept->temperature_min = sept->temperature_min;
                    }
                    if(sept->temperature_max < value2){
                        sept->temperature_max = value2;
                    }
                    else{
                        sept->temperature_max = sept->temperature_max;
                    }
                }
                if(value == huit->num_station){
                    if(huit->temperature_min > value2){
                        huit->temperature_min = value2;
                    }
                    else{
                        huit->temperature_min = huit->temperature_min;
                    }
                    if(huit->temperature_max < value2){
                        huit->temperature_max = value2;
                    }
                    else{
                        huit->temperature_max = huit->temperature_max;
                    }
                }
                if(value == neuf->num_station){
                    if(neuf->temperature_min > value2){
                        neuf->temperature_min = value2;
                    }
                    else{
                        neuf->temperature_min = neuf->temperature_min;
                    }
                    if(neuf->temperature_max < value2){
                        neuf->temperature_max = value2;
                    }
                    else{
                        neuf->temperature_max = neuf->temperature_max;
                    }
                }
                if(value == dix->num_station){
                    if(dix->temperature_min > value2){
                        dix->temperature_min = value2;
                    }
                    else{
                        dix->temperature_min = dix->temperature_min;
                    }
                    if(dix->temperature_max < value2){
                        dix->temperature_max = value2;
                    }
                    else{
                        dix->temperature_max = dix->temperature_max;
                    }
                }
                if(value == onze->num_station){
                    if(onze->temperature_min > value2){
                        onze->temperature_min = value2;
                    }
                    else{
                        onze->temperature_min = onze->temperature_min;
                    }
                    if(onze->temperature_max < value2){
                        onze->temperature_max = value2;
                    }
                    else{
                        onze->temperature_max = onze->temperature_max;
                    }
                }
                if(value == douze->num_station){
                    if(douze->temperature_min > value2){
                        douze->temperature_min = value2;
                    }
                    else{
                        douze->temperature_min = douze->temperature_min;
                    }
                    if(douze->temperature_max < value2){
                        douze->temperature_max = value2;
                    }
                    else{
                        douze->temperature_max = douze->temperature_max;
                    }
                }
                if(value == treize->num_station){
                    if(treize->temperature_min > value2){
                        treize->temperature_min = value2;
                    }
                    else{
                        treize->temperature_min = treize->temperature_min;
                    }
                    if(treize->temperature_max < value2){
                        treize->temperature_max = value2;
                    }
                    else{
                        treize->temperature_max = treize->temperature_max;
                    }
                }
                if(value == quatorze->num_station){
                    if(quatorze->temperature_min > value2){
                        quatorze->temperature_min = value2;
                    }
                    else{
                        quatorze->temperature_min = quatorze->temperature_min;
                    }
                    if(quatorze->temperature_max < value2){
                        quatorze->temperature_max = value2;
                    }
                    else{
                        quatorze->temperature_max = quatorze->temperature_max;
                    }
                }
                if(value == quinze->num_station){
                    if(quinze->temperature_min > value2){
                        quinze->temperature_min = value2;
                    }
                    else{
                        quinze->temperature_min = quinze->temperature_min;
                    }
                    if(quinze->temperature_max < value2){
                        quinze->temperature_max = value2;
                    }
                    else{
                        quinze->temperature_max = quinze->temperature_max;
                    }
                }
                if(value == seize->num_station){
                    if(seize->temperature_min > value2){
                        seize->temperature_min = value2;
                    }
                    else{
                        seize->temperature_min = seize->temperature_min;
                    }
                    if(seize->temperature_max < value2){
                        seize->temperature_max = value2;
                    }
                    else{
                        seize->temperature_max = seize->temperature_max;
                    }
                }
                if(value == dix_sept->num_station){
                    if(dix_sept->temperature_min > value2){
                        dix_sept->temperature_min = value2;
                    }
                    else{
                        dix_sept->temperature_min = dix_sept->temperature_min;
                    }
                    if(dix_sept->temperature_max < value2){
                        dix_sept->temperature_max = value2;
                    }
                    else{
                        dix_sept->temperature_max = dix_sept->temperature_max;
                    }
                }
                if(value == dix_huit->num_station){
                    if(dix_huit->temperature_min > value2){
                        dix_huit->temperature_min = value2;
                    }
                    else{
                        dix_huit->temperature_min = dix_huit->temperature_min;
                    }
                    if(dix_huit->temperature_max < value2){
                        dix_huit->temperature_max = value2;
                    }
                    else{
                        dix_huit->temperature_max = dix_huit->temperature_max;
                    }
                }
                if(value == dix_neuf->num_station){
                    if(dix_neuf->temperature_min > value2){
                        dix_neuf->temperature_min = value2;
                    }
                    else{
                        dix_neuf->temperature_min = dix_neuf->temperature_min;
                    }
                    if(dix_neuf->temperature_max < value2){
                        dix_neuf->temperature_max = value2;
                    }
                    else{
                        dix_neuf->temperature_max = dix_neuf->temperature_max;
                    }
                }
                if(value == vingt->num_station){
                    if(vingt->temperature_min > value2){
                        vingt->temperature_min = value2;
                    }
                    else{
                        vingt->temperature_min = vingt->temperature_min;
                    }
                    if(vingt->temperature_max < value2){
                        vingt->temperature_max = value2;
                    }
                    else{
                        vingt->temperature_max = vingt->temperature_max;
                    }
                }
                if(value == vingt_un->num_station){
                    if(vingt_un->temperature_min > value2){
                        vingt_un->temperature_min = value2;
                    }
                    else{
                        vingt_un->temperature_min = vingt_un->temperature_min;
                    }
                    if(vingt_un->temperature_max < value2){
                        vingt_un->temperature_max = value2;
                    }
                    else{
                        vingt_un->temperature_max = vingt_un->temperature_max;
                    }
                }
                if(value == vingt_deux->num_station){
                    if(vingt_deux->temperature_min > value2){
                        vingt_deux->temperature_min = value2;
                    }
                    else{
                        vingt_deux->temperature_min = vingt_deux->temperature_min;
                    }
                    if(vingt_deux->temperature_max < value2){
                        vingt_deux->temperature_max = value2;
                    }
                    else{
                        vingt_deux->temperature_max = vingt_deux->temperature_max;
                    }
                }
                if(value == vingt_trois->num_station){
                    if(vingt_trois->temperature_min > value2){
                        vingt_trois->temperature_min = value2;
                    }
                    else{
                        vingt_trois->temperature_min = vingt_trois->temperature_min;
                    }
                    if(vingt_trois->temperature_max < value2){
                        vingt_trois->temperature_max = value2;
                    }
                    else{
                        vingt_trois->temperature_max = vingt_trois->temperature_max;
                    }
                }
                if(value == vingt_quatre->num_station){
                    if(vingt_quatre->temperature_min > value2){
                        vingt_quatre->temperature_min = value2;
                    }
                    else{
                        vingt_quatre->temperature_min = vingt_quatre->temperature_min;
                    }
                    if(vingt_quatre->temperature_max < value2){
                        vingt_quatre->temperature_max = value2;
                    }
                    else{
                        vingt_quatre->temperature_max = vingt_quatre->temperature_max;
                    }
                }
                if(value == vingt_cinq->num_station){
                    if(vingt_cinq->temperature_min > value2){
                        vingt_cinq->temperature_min = value2;
                    }
                    else{
                        vingt_cinq->temperature_min = vingt_cinq->temperature_min;
                    }
                    if(vingt_cinq->temperature_max < value2){
                        vingt_cinq->temperature_max = value2;
                    }
                    else{
                        vingt_cinq->temperature_max = vingt_cinq->temperature_max;
                    }
                }
                if(value == vingt_six->num_station){
                    if(vingt_six->temperature_min > value2){
                        vingt_six->temperature_min = value2;
                    }
                    else{
                        vingt_six->temperature_min = vingt_six->temperature_min;
                    }
                    if(vingt_six->temperature_max < value2){
                        vingt_six->temperature_max = value2;
                    }
                    else{
                        vingt_six->temperature_max = vingt_six->temperature_max;
                    }
                }
                if(value == vingt_sept->num_station){
                    if(vingt_sept->temperature_min > value2){
                        vingt_sept->temperature_min = value2;
                    }
                    else{
                        vingt_sept->temperature_min = vingt_sept->temperature_min;
                    }
                    if(vingt_sept->temperature_max < value2){
                        vingt_sept->temperature_max = value2;
                    }
                    else{
                        vingt_sept->temperature_max = vingt_sept->temperature_max;
                    }
                }
                if(value == vingt_huit->num_station){
                    if(vingt_huit->temperature_min > value2){
                        vingt_huit->temperature_min = value2;
                    }
                    else{
                        vingt_huit->temperature_min = vingt_huit->temperature_min;
                    }
                    if(vingt_huit->temperature_max < value2){
                        vingt_huit->temperature_max = value2;
                    }
                    else{
                        vingt_huit->temperature_max = vingt_huit->temperature_max;
                    }
                }
                if(value == vingt_neuf->num_station){
                    if(vingt_neuf->temperature_min > value2){
                        vingt_neuf->temperature_min = value2;
                    }
                    else{
                        vingt_neuf->temperature_min = vingt_neuf->temperature_min;
                    }
                    if(vingt_neuf->temperature_max < value2){
                        vingt_neuf->temperature_max = value2;
                    }
                    else{
                        vingt_neuf->temperature_max = vingt_neuf->temperature_max;
                    }
                }
                if(value == trente->num_station){
                    if(trente->temperature_min > value2){
                        trente->temperature_min = value2;
                    }
                    else{
                        trente->temperature_min = trente->temperature_min;
                    }
                    if(trente->temperature_max < value2){
                        trente->temperature_max = value2;
                    }
                    else{
                        trente->temperature_max = trente->temperature_max;
                    }
                }
                if(value == trente_un->num_station){
                    if(trente_un->temperature_min > value2){
                        trente_un->temperature_min = value2;
                    }
                    else{
                        trente_un->temperature_min = trente_un->temperature_min;
                    }
                    if(trente_un->temperature_max < value2){
                        trente_un->temperature_max = value2;
                    }
                    else{
                        trente_un->temperature_max = trente_un->temperature_max;
                    }
                }
                if(value == trente_deux->num_station){
                    if(trente_deux->temperature_min > value2){
                        trente_deux->temperature_min = value2;
                    }
                    else{
                        trente_deux->temperature_min = trente_deux->temperature_min;
                    }
                    if(trente_deux->temperature_max < value2){
                        trente_deux->temperature_max = value2;
                    }
                    else{
                        trente_deux->temperature_max = trente_deux->temperature_max;
                    }
                }
                if(value == trente_trois->num_station){
                    if(trente_trois->temperature_min > value2){
                        trente_trois->temperature_min = value2;
                    }
                    else{
                        trente_trois->temperature_min = trente_trois->temperature_min;
                    }
                    if(trente_trois->temperature_max < value2){
                        trente_trois->temperature_max = value2;
                    }
                    else{
                        trente_trois->temperature_max = trente_trois->temperature_max;
                    }
                }
                if(value == trente_quatre->num_station){
                    if(trente_quatre->temperature_min > value2){
                        trente_quatre->temperature_min = value2;
                    }
                    else{
                        trente_quatre->temperature_min = trente_quatre->temperature_min;
                    }
                    if(trente_quatre->temperature_max < value2){
                        trente_quatre->temperature_max = value2;
                    }
                    else{
                        trente_quatre->temperature_max = trente_quatre->temperature_max;
                    }
                }
                if(value == trente_cinq->num_station){
                    if(trente_cinq->temperature_min > value2){
                        trente_cinq->temperature_min = value2;
                    }
                    else{
                        trente_cinq->temperature_min = trente_cinq->temperature_min;
                    }
                    if(trente_cinq->temperature_max < value2){
                        trente_cinq->temperature_max = value2;
                    }
                    else{
                        trente_cinq->temperature_max = trente_cinq->temperature_max;
                    }
                }
                if(value == trente_six->num_station){
                    if(trente_six->temperature_min > value2){
                        trente_six->temperature_min = value2;
                    }
                    else{
                        trente_six->temperature_min = trente_six->temperature_min;
                    }
                    if(trente_six->temperature_max < value2){
                        trente_six->temperature_max = value2;
                    }
                    else{
                        trente_six->temperature_max = trente_six->temperature_max;
                    }
                }
                if(value == trente_sept->num_station){
                    if(trente_sept->temperature_min > value2){
                        trente_sept->temperature_min = value2;
                    }
                    else{
                        trente_sept->temperature_min = trente_sept->temperature_min;
                    }
                    if(trente_sept->temperature_max < value2){
                        trente_sept->temperature_max = value2;
                    }
                    else{
                        trente_sept->temperature_max = trente_sept->temperature_max;
                    }
                }
                if(value == trente_huit->num_station){
                    if(trente_huit->temperature_min > value2){
                        trente_huit->temperature_min = value2;
                    }
                    else{
                        trente_huit->temperature_min = trente_huit->temperature_min;
                    }
                    if(trente_huit->temperature_max < value2){
                        trente_huit->temperature_max = value2;
                    }
                    else{
                        trente_huit->temperature_max = trente_huit->temperature_max;
                    }
                }
                if(value == trente_neuf->num_station){
                    if(trente_neuf->temperature_min > value2){
                        trente_neuf->temperature_min = value2;
                    }
                    else{
                        trente_neuf->temperature_min = trente_neuf->temperature_min;
                    }
                    if(trente_neuf->temperature_max < value2){
                        trente_neuf->temperature_max = value2;
                    }
                    else{
                        trente_neuf->temperature_max = trente_neuf->temperature_max;
                    }
                }
                if(value == quarante->num_station){
                    if(quarante->temperature_min > value2){
                        quarante->temperature_min = value2;
                    }
                    else{
                        quarante->temperature_min = quarante->temperature_min;
                    }
                    if(quarante->temperature_max < value2){
                        quarante->temperature_max = value2;
                    }
                    else{
                        quarante->temperature_max = quarante->temperature_max;
                    }
                }
                if(value == quarante_un->num_station){
                    if(quarante_un->temperature_min > value2){
                        quarante_un->temperature_min = value2;
                    }
                    else{
                        quarante_un->temperature_min = quarante_un->temperature_min;
                    }
                    if(quarante_un->temperature_max < value2){
                        quarante_un->temperature_max = value2;
                    }
                    else{
                        quarante_un->temperature_max = quarante_un->temperature_max;
                    }
                }
                if(value == quarante_deux->num_station){
                    if(quarante_deux->temperature_min > value2){
                        quarante_deux->temperature_min = value2;
                    }
                    else{
                        quarante_deux->temperature_min = quarante_deux->temperature_min;
                    }
                    if(quarante_deux->temperature_max < value2){
                        quarante_deux->temperature_max = value2;
                    }
                    else{
                        quarante_deux->temperature_max = quarante_deux->temperature_max;
                    }
                }
                if(value == quarante_trois->num_station){
                    if(quarante_trois->temperature_min > value2){
                        quarante_trois->temperature_min = value2;
                    }
                    else{
                        quarante_trois->temperature_min = quarante_trois->temperature_min;
                    }
                    if(quarante_trois->temperature_max < value2){
                        quarante_trois->temperature_max = value2;
                    }
                    else{
                        quarante_trois->temperature_max = quarante_trois->temperature_max;
                    }
                }
                if(value == quarante_quatre->num_station){
                    if(quarante_quatre->temperature_min > value2){
                        quarante_quatre->temperature_min = value2;
                    }
                    else{
                        quarante_quatre->temperature_min = quarante_quatre->temperature_min;
                    }
                    if(quarante_quatre->temperature_max < value2){
                        quarante_quatre->temperature_max = value2;
                    }
                    else{
                        quarante_quatre->temperature_max = quarante_quatre->temperature_max;
                    }
                }
                if(value == quarante_cinq->num_station){
                    if(quarante_cinq->temperature_min > value2){
                        quarante_cinq->temperature_min = value2;
                    }
                    else{
                        quarante_cinq->temperature_min = quarante_cinq->temperature_min;
                    }
                    if(quarante_cinq->temperature_max < value2){
                        quarante_cinq->temperature_max = value2;
                    }
                    else{
                        quarante_cinq->temperature_max = quarante_cinq->temperature_max;
                    }
                }
                if(value == quarante_six->num_station){
                    if(quarante_six->temperature_min > value2){
                        quarante_six->temperature_min = value2;
                    }
                    else{
                        quarante_six->temperature_min = quarante_six->temperature_min;
                    }
                    if(quarante_six->temperature_max < value2){
                        quarante_six->temperature_max = value2;
                    }
                    else{
                        quarante_six->temperature_max = quarante_six->temperature_max;
                    }
                }
                if(value == quarante_sept->num_station){
                    if(quarante_sept->temperature_min > value2){
                        quarante_sept->temperature_min = value2;
                    }
                    else{
                        quarante_sept->temperature_min = quarante_sept->temperature_min;
                    }
                    if(quarante_sept->temperature_max < value2){
                        quarante_sept->temperature_max = value2;
                    }
                    else{
                        quarante_sept->temperature_max = quarante_sept->temperature_max;
                    }
                }
                if(value == quarante_huit->num_station){
                    if(quarante_huit->temperature_min > value2){
                        quarante_huit->temperature_min = value2;
                    }
                    else{
                        quarante_huit->temperature_min = quarante_huit->temperature_min;
                    }
                    if(quarante_huit->temperature_max < value2){
                        quarante_huit->temperature_max = value2;
                    }
                    else{
                        quarante_huit->temperature_max = quarante_huit->temperature_max;
                    }
                }
                if(value == quarante_neuf->num_station){
                    if(quarante_neuf->temperature_min > value2){
                        quarante_neuf->temperature_min = value2;
                    }
                    else{
                        quarante_neuf->temperature_min = quarante_neuf->temperature_min;
                    }
                    if(quarante_neuf->temperature_max < value2){
                        quarante_neuf->temperature_max = value2;
                    }
                    else{
                        quarante_neuf->temperature_max = quarante_neuf->temperature_max;
                    }
                }
                if(value == cinquante->num_station){
                    if(cinquante->temperature_min > value2){
                        cinquante->temperature_min = value2;
                    }
                    else{
                        cinquante->temperature_min = cinquante->temperature_min;
                    }
                    if(cinquante->temperature_max < value2){
                        cinquante->temperature_max = value2;
                    }
                    else{
                        cinquante->temperature_max = cinquante->temperature_max;
                    }
                }
                if(value == cinquante_un->num_station){
                    if(cinquante_un->temperature_min > value2){
                        cinquante_un->temperature_min = value2;
                    }
                    else{
                        cinquante_un->temperature_min = cinquante_un->temperature_min;
                    }
                    if(cinquante_un->temperature_max < value2){
                        cinquante_un->temperature_max = value2;
                    }
                    else{
                        cinquante_un->temperature_max = cinquante_un->temperature_max;
                    }
                }
                if(value == cinquante_deux->num_station){
                    if(cinquante_deux->temperature_min > value2){
                        cinquante_deux->temperature_min = value2;
                    }
                    else{
                        cinquante_deux->temperature_min = cinquante_deux->temperature_min;
                    }
                    if(cinquante_deux->temperature_max < value2){
                        cinquante_deux->temperature_max = value2;
                    }
                    else{
                        cinquante_deux->temperature_max = cinquante_deux->temperature_max;
                    }
                }
                if(value == cinquante_trois->num_station){
                    if(cinquante_trois->temperature_min > value2){
                        cinquante_trois->temperature_min = value2;
                    }
                    else{
                        cinquante_trois->temperature_min = cinquante_trois->temperature_min;
                    }
                    if(cinquante_trois->temperature_max < value2){
                        cinquante_trois->temperature_max = value2;
                    }
                    else{
                        cinquante_trois->temperature_max = cinquante_trois->temperature_max;
                    }
                }
                if(value == cinquante_quatre->num_station){
                    if(cinquante_quatre->temperature_min > value2){
                        cinquante_quatre->temperature_min = value2;
                    }
                    else{
                        cinquante_quatre->temperature_min = cinquante_quatre->temperature_min;
                    }
                    if(cinquante_quatre->temperature_max < value2){
                        cinquante_quatre->temperature_max = value2;
                    }
                    else{
                        cinquante_quatre->temperature_max = cinquante_quatre->temperature_max;
                    }
                }
                if(value == cinquante_cinq->num_station){
                    if(cinquante_cinq->temperature_min > value2){
                        cinquante_cinq->temperature_min = value2;
                    }
                    else{
                        cinquante_cinq->temperature_min = cinquante_cinq->temperature_min;
                    }
                    if(cinquante_cinq->temperature_max < value2){
                        cinquante_cinq->temperature_max = value2;
                    }
                    else{
                        cinquante_cinq->temperature_max = cinquante_cinq->temperature_max;
                    }
                }
                if(value == cinquante_six->num_station){
                    if(cinquante_six->temperature_min > value2){
                        cinquante_six->temperature_min = value2;
                    }
                    else{
                        cinquante_six->temperature_min = cinquante_six->temperature_min;
                    }
                    if(cinquante_six->temperature_max < value2){
                        cinquante_six->temperature_max = value2;
                    }
                    else{
                        cinquante_six->temperature_max = cinquante_six->temperature_max;
                    }
                }
                if(value == cinquante_sept->num_station){
                    if(cinquante_sept->temperature_min > value2){
                        cinquante_sept->temperature_min = value2;
                    }
                    else{
                        cinquante_sept->temperature_min = cinquante_sept->temperature_min;
                    }
                    if(cinquante_sept->temperature_max < value2){
                        cinquante_sept->temperature_max = value2;
                    }
                    else{
                        cinquante_sept->temperature_max = cinquante_sept->temperature_max;
                    }
                }
                if(value == cinquante_huit->num_station){
                    if(cinquante_huit->temperature_min > value2){
                        cinquante_huit->temperature_min = value2;
                    }
                    else{
                        cinquante_huit->temperature_min = cinquante_huit->temperature_min;
                    }
                    if(cinquante_huit->temperature_max < value2){
                        cinquante_huit->temperature_max = value2;
                    }
                    else{
                        cinquante_huit->temperature_max = cinquante_huit->temperature_max;
                    }
                }
                if(value == cinquante_neuf->num_station){
                    if(cinquante_neuf->temperature_min > value2){
                        cinquante_neuf->temperature_min = value2;
                    }
                    else{
                        cinquante_neuf->temperature_min = cinquante_neuf->temperature_min;
                    }
                    if(cinquante_neuf->temperature_max < value2){
                        cinquante_neuf->temperature_max = value2;
                    }
                    else{
                        cinquante_neuf->temperature_max = cinquante_neuf->temperature_max;
                    }
                }
                if(value == soixante->num_station){
                    if(soixante->temperature_min > value2){
                        soixante->temperature_min = value2;
                    }
                    else{
                        soixante->temperature_min = soixante->temperature_min;
                    }
                    if(soixante->temperature_max < value2){
                        soixante->temperature_max = value2;
                    }
                    else{
                        soixante->temperature_max = soixante->temperature_max;
                    }
                }
                if(value == soixante_un->num_station){
                    if(soixante_un->temperature_min > value2){
                        soixante_un->temperature_min = value2;
                    }
                    else{
                        soixante_un->temperature_min = soixante_un->temperature_min;
                    }
                    if(soixante_un->temperature_max < value2){
                        soixante_un->temperature_max = value2;
                    }
                    else{
                        soixante_un->temperature_max = soixante_un->temperature_max;
                    }
                }
			}
			element = strtok(NULL,";");
			colonne++;
		} 
	}
    free(un);
    free(deux);
    free(trois);
    free(quatre);
    free(cinq);
    free(six);
    free(sept);
    free(huit);
    free(neuf);
    free(dix);
    free(onze);
    free(douze);
    free(treize);
    free(quatorze);
    free(quinze);
    free(seize);
    free(dix_sept);
    free(dix_huit);
    free(dix_neuf);
    free(vingt);
    free(vingt_un);
    free(vingt_deux);
    free(vingt_trois);
    free(vingt_quatre);
    free(vingt_cinq);
    free(vingt_six);
    free(vingt_sept);
    free(vingt_huit);
    free(vingt_neuf);
    free(trente);
    free(trente_un);
    free(trente_deux);
    free(trente_trois);
    free(trente_quatre);
    free(trente_cinq);
    free(trente_six);
    free(trente_sept);
    free(trente_huit);
    free(trente_neuf);
    free(quarante);
    free(quarante_un);
    free(quarante_deux);
    free(quarante_trois);
    free(quarante_quatre);
    free(quarante_cinq);
    free(quarante_six);
    free(quarante_sept);
    free(quarante_huit);
    free(quarante_neuf);
    free(cinquante);
    free(cinquante_un);
    free(cinquante_deux);
    free(cinquante_trois);
    free(cinquante_quatre);
    free(cinquante_cinq);
    free(cinquante_six);
    free(cinquante_sept);
    free(cinquante_huit);
    free(cinquante_neuf);
    free(soixante);
    free(soixante_un);
}*/

//T1 et P1
int main(){
	Chainon* liste = NULL;
	char buffer[1000];
	int ligne=0;
	int colonne=0;
	int i=0;
	double moyenne=0;
	double value=0;
	double date=0;
	while((fgets(buffer,1000,fichier1))!=NULL){
		colonne=0;
		ligne++;
		if(ligne==1){
			continue;
		}
		char *element = strtok(buffer,";");
		while(element){
			if(colonne == 0){
				value = atof(*element);
				liste = ajouterCroissant(liste,value);

			}
			if(colonne == 1){
				value = atof(*element);
				moyenne = moyenne + value;
			}
			element = strtok(NULL,";");
			colonne++;
		} 
		i++;
	}
	moy = moy/i;
}


//T2 et P2
int main(){
	Chainon* liste = NULL;
	char buffer[1000];
	int ligne=0;
	int colonne=0;
	int i=0;
	double moyenne=0;
	double value=0;
	double date=0;
	while((fgets(buffer,1000,fichier1))!=NULL){
		colonne=0;
		ligne++;
		if(ligne==1){
			continue;
		}
		char *element = strtok(buffer,";");
		while(element){
			if(colonne == 0){
				char *DATE = strtok(*element,"-");
				date = atof(*DATE);

			}
			if(colonne == 1){
				value = atof(*element);
				moyenne = moyenne + value;
			}
			element = strtok(NULL,";");
			colonne++;
		} 
		i++;
	}
	moy = moy/i;
}

2010-01-05T10:00:00+01:00


// w
int main(){
	Chainon* liste = NULL;
	char buffer[1000];
	int ligne=0;
	int colonne=0;
		double value=0;
	while((fgets(buffer,1000,fichier1))!=NULL){
		colonne=0;
		ligne++;
		if(ligne==1){
			continue;
		}
		char *element = strtok(buffer,";");
		while(element){
			if(colonne == 0){
				value = atof(*element);
				liste = ajouterCroissant(liste,value);
			}
			if(colonne == 1){

			}
			if(colonne == 2){

			}
			element = strtok(NULL,";");
			colonne++;
		} 
	}
}

// h
int main(){
	Chainon* liste = NULL;
	char buffer[1000];
	int ligne=0;
	int colonne=0;
		double value=0;
	while((fgets(buffer,1000,fichier1))!=NULL){
		colonne=0;
		ligne++;
		if(ligne==1){
			continue;
		}
		char *element = strtok(buffer,";");
		while(element){
			if(colonne == 1){
				value = atof(*element);
				liste = ajouterDecroissant(liste,value);
			}
			element = strtok(NULL,";");
			colonne++;
		} 
	}
}

// m
int main(){
    Station un = malloc(sizeof(*un));
    if( un == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    un->num_station = 07558;
    Station deux = malloc(sizeof(*deux));
    if( deux == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    deux->num_station = 07110;
    Station trois = malloc(sizeof(*trois));
    if( trois == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    trois->num_station = 61976;
    Station quatre = malloc(sizeof(*quatre));
    if( quatre == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quatre->num_station = 07027;
    Station cinq = malloc(sizeof(*cinq));
    if( cinq == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    cinq->num_station = 07591;
    Station six = malloc(sizeof(*six));
    if( six == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    six->num_station = 71805;
    Station sept = malloc(sizeof(*sept));
    if( sept == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    sept->num_station = 78925;
    Station huit = malloc(sizeof(*huit));
    if( huit == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    huit->num_station = 07015;
    Station neuf = malloc(sizeof(*neuf));
    if( neuf == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    neuf->num_station = 07149;
    Station dix = malloc(sizeof(*dix));
    if( dix == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    dix->num_station = 81408;
    Station onze = malloc(sizeof(*onze));
    if( onze == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    onze->num_station = 89642;
    Station douze = malloc(sizeof(*douze));
    if( douze == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    douze->num_station = 07020;
    Station treize = malloc(sizeof(*treize));
    if( treize == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    treize->num_station = 07761;
    Station quatorze = malloc(sizeof(*quatorze));
    if( quatorze == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quatorze->num_station = 81405;
    Station quinze = malloc(sizeof(*quinze));
    if( quinze == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quinze->num_station = 07168;
    Station seize = malloc(sizeof(*seize));
    if( seize == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    seize->num_station = 07607;
    Station dix_sept = malloc(sizeof(*dix_sept));
    if( dix_sept == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    dix_sept->num_station = 07650;
    Station dix_huit = malloc(sizeof(*dix_huit));
    if( dix_huit == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    dix_huit->num_station = 61972;
    Station dix_neuf = malloc(sizeof(*dix_neuf));
    if( dix_neuf == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    dix_neuf->num_station = 07280;
    Station vingt = malloc(sizeof(*vingt));
    if( vingt == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    vingt->num_station = 07434;
    Station vingt_un = malloc(sizeof(*vingt_un));
    if( vingt_un == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    vingt_un->num_station = 07137;
    Station vingt_deux = malloc(sizeof(*vingt_deux));
    if( vingt_deux == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    vingt_deux->num_station = 07690;
    Station vingt_trois = malloc(sizeof(*vingt_trois));
    if( vingt_trois == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    vingt_trois->num_station = 61970;
    Station vingt_quatre = malloc(sizeof(*vingt_quatre));
    if( vingt_quatre == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    vingt_quatre->num_station = 07181;
    Station vingt_cinq = malloc(sizeof(*vingt_cinq));
    if( vingt_cinq == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    vingt_cinq->num_station = 07222;
    Station vingt_six = malloc(sizeof(*vingt_six));
    if( vingt_six == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    vingt_six->num_station = 07335;
    Station vingt_sept = malloc(sizeof(*vingt_sept));
    if( vingt_sept == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    vingt_sept->num_station = 07207;
    Station vingt_huit = malloc(sizeof(*vingt_huit));
    if( vingt_huit == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    vingt_huit->num_station = 07621;
    Station vingt_neuf = malloc(sizeof(*vingt_neuf));
    if( vingt_neuf == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    vingt_neuf->num_station = 07747;
    Station trente = malloc(sizeof(*trente));
    if( trente == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    trente->num_station = 61998;
    Station trente_un = malloc(sizeof(*trente_un));
    if( trente_un == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    trente_un->num_station = 07314;
    Station trente_deux = malloc(sizeof(*trente_deux));
    if( trente_deux == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    trente_deux->num_station = 07630;
    Station trente_trois = malloc(sizeof(*trente_trois));
    if( trente_trois == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    trente_trois->num_station = 07481;
    Station trente_quatre = malloc(sizeof(*trente_quatre));
    if( trente_quatre == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    trente_quatre->num_station = 07627;
    Station trente_cinq = malloc(sizeof(*trente_cinq));
    if( trente_cinq == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    trente_cinq->num_station = 07510;
    Station trente_six = malloc(sizeof(*trente_six));
    if( trente_six == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    trente_six->num_station = 61980;
    Station trente_sept = malloc(sizeof(*trente_sept));
    if( trente_sept == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    trente_sept->num_station = 61996;
    Station trente_huit = malloc(sizeof(*trente_huit));
    if( trente_huit == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    trente_huit->num_station = 07577;
    Station trente_neuf = malloc(sizeof(*neuf));
    if( trente_neuf == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    trente_neuf->num_station = 07240;
    Station quarante = malloc(sizeof(*quarante));
    if( quarante == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quarante->num_station = 07117;
    Station quarante_un = malloc(sizeof(*quarante_un));
    if( quarante_un == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quarante_un->num_station = 07130;
    Station quarante_deux = malloc(sizeof(*quarante_deux));
    if( quarante_deux == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quarante_deux->num_station = 07190;
    Station quarante_trois = malloc(sizeof(*quarante_trois));
    if( quarante_trois == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quarante_trois->num_station = 78897;
    Station quarante_quatre = malloc(sizeof(*quarante_quatre));
    if( quarante_quatre == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quarante_quatre->num_station = 67005;
    Station quarante_cinq = malloc(sizeof(*quarante_cinq));
    if( quarante_cinq == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quarante_cinq->num_station = 78922;
    Station quarante_six = malloc(sizeof(*quarante_six));
    if( quarante_six == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quarante_six->num_station = 61997;
    Station quarante_sept = malloc(sizeof(*quarante_sept));
    if( quarante_sept == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quarante_sept->num_station = 07255;
    Station quarante_huit = malloc(sizeof(*quarante_huit));
    if( quarante_huit == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quarante_huit->num_station = 07005;
    Station quarante_neuf = malloc(sizeof(*quarante_neuf));
    if( quarante_neuf == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    quarante_neuf->num_station = 07460;
    Station cinquante = malloc(sizeof(*cinquante));
    if( cinquante == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    cinquante->num_station = 07471;
    Station cinquante_un = malloc(sizeof(*cinquante_un));
    if( cinquante_un == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    cinquante_un->num_station = 07299;
    Station cinquante_deux = malloc(sizeof(*cinquante_deux));
    if( cinquante_deux == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    cinquante_deux->num_station = 07790;
    Station cinquante_trois = malloc(sizeof(*cinquante_trois));
    if( cinquante_trois == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    cinquante_trois->num_station = 61976;
    Station cinquante_quatre = malloc(sizeof(*cinquante_quatre));
    if( cinquante_quatre == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    cinquante_quatre->num_station = 81401;
    Station cinquante_cinq = malloc(sizeof(*cinquante_cinq));
    if( cinquante_cinq == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    cinquante_cinq->num_station = 07643;
    Station cinquante_six = malloc(sizeof(*cinquante_six));
    if( cinquante_six == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    cinquante_six->num_station = 07661;
    Station cinquante_sept = malloc(sizeof(*cinquante_sept));
    if( cinquante_sept == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    cinquante_sept->num_station = 81415;
    Station cinquante_huit = malloc(sizeof(*cinquante_huit));
    if( cinquante_huit == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    cinquante_huit->num_station = 61968;
    Station cinquante_neuf = malloc(sizeof(*cinquante_neuf));
    if( cinquante_neuf == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    cinquante_neuf->num_station = 07139;
    Station soixante = malloc(sizeof(*soixante));
    if( soixante == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    soixante->num_station = 07535;
    Station soixante_un = malloc(sizeof(*soixante_un));
    if( soixante_un == NULL){
        fprintf(stderr, "ALLOCATION DYNAMIQUE IMPOSSIBLE %d");
        exit(4);
    }
    soixante_un->num_station = 07037;
	Chainon* liste = NULL;
	char buffer[1000];
	int ligne=0;
	int colonne=0;
	int *r=0;
	double max;
	double value=0;
    double value2=0;
	while((fgets(buffer,1000,fichier1))!=NULL){
		colonne=0;
		ligne++;
		if(ligne==1){
			continue;
		}
		char *element = strtok(buffer,";");
		while(element){
			if(colonne == 0){
				value = atof(*element);
				liste = ajouterCroissant(liste,value);
			}
			if(colonne == 1){
				value2 = atof(*element);
				if(value == un->num_station){
                    if(un->humidite_max < value2){
                        sept->temperature_max = value2;
                    }
                    else{
                        sept->temperature_max = sept->temperature_max;
                    }
                }
				}
			}
			element = strtok(NULL,";");
			colonne++;
		} 
	}
}
