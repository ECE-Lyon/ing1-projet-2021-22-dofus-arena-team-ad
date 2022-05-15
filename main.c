#include <stdio.h>
#include <allegro5/allegro.h>

// AFFICHAGE MATRICE ALLEGRO
#include "affichage.h"
#include "arene.h"

int main() {

    Coords positionJoueur;
    Joueurs joueurActuel;
    Coords tabChemin[PM_MAX];
    int tabArene[LIGNES_TAB][COLONNES_TAB];
    int TabObstacle[LIGNES_TAB][COLONNES_TAB];
    Joueurs *listeJ = NULL;
    Joueurs * joueurActuel1;
            //création de la liste joueur
    listeJ = malloc(sizeof(Joueurs));
    listeJ->next = listeJ;
    listeJ->prev = listeJ;
    joueurActuel1 = listeJ;

    // init de la position joueur initiale (test)

    /* joueurActuel.positionJ.colonne = 12;
     joueurActuel.positionJ.ligne = 7;
     joueurActuel.classeJ.numJ=3;
     */

    strcpy(listeJ->nom, "Solaris");
    listeJ->classeJ.numJ = 1;
    listeJ->positionJ.colonne = 12;
    listeJ->positionJ.ligne = 7;
    listeJ->next= malloc(sizeof(Joueurs));
    listeJ->prev=listeJ->next;
    strcpy(listeJ->next->nom, "Saturna");
    listeJ->next->classeJ.numJ = 3;
    listeJ->next->positionJ.colonne = 3;
    listeJ->next->positionJ.ligne = 10;
    listeJ->next->next=NULL;

    //création de l'arène
    intialisationArene(tabArene, TabObstacle);
    //affichage du jeu complet + deplacement du joueur
    affichage(tabArene, TabObstacle, tabChemin, &listeJ, joueurActuel1);
    return 0;
}

