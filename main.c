#include <stdio.h>
#include <allegro5/allegro.h>

// AFFICHAGE MATRICE ALLEGRO
#include "affichage.h"
#include "arene.h"
int main() {

    int tabArene[LIGNES_TAB][COLONNES_TAB];
    int TabObstacle[LIGNES_TAB][COLONNES_TAB];
    Coords tabChemin[PM_MAX];
    int ligne = 0, colonne = 0;
    // init de la position du joueur
    Coords positionJoueur;

    //Init du tableau pour stoquer l'arene
    initialiserTableau(tabArene);
    //Init du tableau pour stoquer les obstacles
    initialiserTableau(TabObstacle);

    construireLarene(1, tabArene);

    //le Tableau avec les cases correspondants a l'arene est construit, construisons le tableau des obstacles :
    // Pas de 0 , si 1 c'est de l'herbe , si 2 c'est du sable , si 3 c'est un rocher, si 4 c'est un vaiseau
    // donc si la case continent un chiffre > 3(CASE_OBSTACLE) c'est un obstacle
    for (colonne = 0; colonne < COLONNES_TAB; colonne++) {
        for (ligne = 0; ligne < LIGNES_TAB; ligne++) {
            if (tabArene[ligne][colonne] >= CASE_OBSTACLE) {
                TabObstacle[ligne][colonne] = CASE_OBSTACLE;
            }
        }
    }
// Verification du bon fonctionnement code
    // Affichage tab Arene
    printf("tab Arene:\n");
    afficherTableau(tabArene);
    // affichage tab Obstacle
    printf(" tab d'obstacle\n");
    afficherTableau(TabObstacle);

    // init de la position joueur initiale (test)
    positionJoueur.colonne = 12;
    positionJoueur.ligne = 7;

    // init du tab chemin
    initialiserTabChemin(tabChemin);
    affichage(tabArene, TabObstacle, tabChemin, positionJoueur);
    return 0;
}

