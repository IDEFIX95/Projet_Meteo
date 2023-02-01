#ifndef TRIE_TAB_H_
#define TRIE_TAB_H_


typedef struct id{
    int num_station;
    double temperature;
    double temperature_min;
    double temperature_max;
    double pression_station;
    double pression_variation;
    double vent_direction;
    double vent_vitesse_moyenne;
    double altitude;
    double humidite;
} Donnees;

typedef Donnees *Station;

typedef struct chainon{
	double elmt;
	struct chainon *suivant;
}Chainon;

Chainon* creationChainon(double a);
Chainon* insertdebut(Chainon* pliste, double a);
Chainon* ajouterCroissant(Chainon* pliste, double a);

#endif