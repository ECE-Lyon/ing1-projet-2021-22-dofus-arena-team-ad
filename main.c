#include <stdio.h>
#include <allegro5/allegro.h>

// AFFICHAGE MATRICE ALLEGRO
#include "affichage.h"
#include "arene.h"

int main() {

    Coords positionJoueur;
    Coords tabChemin[PM_MAX];
    int tabArene[LIGNES_TAB][COLONNES_TAB];
    int TabObstacle[LIGNES_TAB][COLONNES_TAB];
    // init de la position joueur initiale (test)
    positionJoueur.colonne = 12;
    positionJoueur.ligne = 7;

    //création de l'arène
    intialisationArene(tabArene,TabObstacle);
    //affichage du jeu complet + deplacement du joueur
    affichage(tabArene, TabObstacle, tabChemin, positionJoueur);
    return 0;
}

