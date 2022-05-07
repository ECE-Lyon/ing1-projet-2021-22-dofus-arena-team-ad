//
// Created by Mona Lias on 4/27/22.
//

#include "deplacement.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int determinerSensDeplacement(int positionInitiale, int PF) {
    int increment;
    if (positionInitiale > PF) {
        increment = -1;

    } else {
        if (positionInitiale < PF) {
            increment = 1;
        } else {
            increment = 0;
        }
    }
    return increment;
}

bool isObstacle(int tabObstacle[LIGNES_TAB][COLONNES_TAB], Coords *joueurPI, int loop, int inc,
                bool depHorizon) { // joueurPI= ligne ou colonne du joueur
    if (depHorizon) {
        if (tabObstacle[joueurPI->ligne][joueurPI->colonne + (loop * inc)] == CASE_LIBRE) {
            return false;
        } else {
            return true;
        }
    } else {
        if (tabObstacle[joueurPI->ligne + (loop * inc)][joueurPI->colonne] == CASE_LIBRE) {
            return false;
        } else {
            return true;
        }

    }
}

void stockerTabChemin(Coords tabChemin[PM_MAX + 1], int *indTab, Coords *joueurPI, int loop, int inc, bool depHorizon) {
    printf("indTab AVANT: %d\n", *indTab);
    if (depHorizon) {
        tabChemin[*indTab].colonne = joueurPI->colonne + (loop * inc);
        tabChemin[*indTab].ligne = joueurPI->ligne;
    } else {
        tabChemin[*indTab].colonne = joueurPI->colonne;
        tabChemin[*indTab].ligne = joueurPI->ligne + (loop * inc);
    }
    printf("Les coordonnes stokees sont : [%d;%d]\n", tabChemin[*indTab].ligne, tabChemin[*indTab].colonne);
    (*indTab) = (*indTab) + 1;
    printf("indTab APRES: %d\n", *indTab);
}

int determinerLeChemin(Coords *joueurPI, int *PM, Coords PF, int tabObstacle[LIGNES_TAB][COLONNES_TAB],
                       Coords tabChemin[PM_MAX + 1]) {
    bool depHorizon = true;  // true si le deplacement est sur les colonnes, false si lignes
    Coords positionInitiale;  // enregistrer la position initiale du joueur dans le cas ou le deplacement n'a pas lieu
    positionInitiale.ligne = joueurPI->ligne;
    positionInitiale.colonne = joueurPI->colonne;
    int indiceTab = 0;
    tabChemin[indiceTab] = positionInitiale;  // pour afficher la position initiale du joueur en premier
    indiceTab++;
    if (abs(PF.colonne - joueurPI->colonne) >
        PM_MAX) { // si l'ecart est plus grand que le nb de deplacement max --> on ne peut pas se deplacer
        //(*PM) = 0;
        return 1;
    } else if (tabObstacle[PF.ligne][PF.colonne] == CASE_OBSTACLE) { // cas ou on clique sur une case obstacle
        //(*PM) = 0;
        return 1;
    }
    do {
        // initialisation des variables
        int ecart = 0, loop = 1;
        int inc = 0; // increment
        int NBDC = 0; // nb de deplacement colonne
        bool obstacle = false; // par defaut il n'y a pas d'obstacles
        //calculer ecart ezntre PI et PF
        ecart = PF.colonne - joueurPI->colonne;
        if (ecart == 0) {
            depHorizon = false; //on reste sur la colonne
        }
        printf("deplacement horizontal =%d - ecart = %d  joueur col =%d lig %d - destination col %d lig %d\n",
               depHorizon, ecart, joueurPI->colonne, joueurPI->ligne, PF.colonne, PF.ligne);
        printf("tabChemin du while : colonnes: %d - ligne: %d\n", tabChemin[*PM].colonne, tabChemin[*PM].ligne);
        if (depHorizon) { // deplacement horizontal en cours
            // stocker le nb de deplacement colonne
            NBDC = abs(ecart);
            // determiner sens de deplacement
            inc = determinerSensDeplacement(joueurPI->colonne, PF.colonne);
        } else { // deplacement vertical  en cours
            NBDC = 1; //nb de deplacement ligne toujours a 1
            inc = determinerSensDeplacement(joueurPI->ligne, PF.ligne);
        }
        printf("PM Joueur =%d - ecart =%d - NBDC = %d - inc =%d - loop =%d - obstacle =%d\n", *PM, ecart, NBDC, inc,
               loop, obstacle);
        //tant qu'on a pas atteint l'ecart et pas trouve d'obstacle
        while (loop <= NBDC && !obstacle) {
            // determiner si le nb de deplacement est superieur au nb deplacement autorisé
            if (!isObstacle(tabObstacle, joueurPI, loop, inc, depHorizon)) {
                stockerTabChemin(tabChemin, &indiceTab, joueurPI, loop, inc,
                                 depHorizon); // PM+1 car tab initialisé avec en tab[0] la position init joueur
                printf("IL Y A PAS OBSTACLE\n");
            } // fin isObstacle
            else {
                printf("IL Y A UN OBSTACLE\n");
                obstacle = true;
            }
            loop++;
            (*PM) = (*PM) + 1;
        }
        // fin de loop sur colonne et pas d'obstacle
        //On change de trajectoire
        if (depHorizon) {
            depHorizon = false;
        } else {
            depHorizon = true;
        }
        if (!obstacle) {
            //les coordonees du joueur deviennent celle du chemin
            joueurPI->colonne = tabChemin[*PM].colonne;
            joueurPI->ligne = tabChemin[*PM].ligne;
            printf("[%d; %d]", joueurPI->ligne, joueurPI->colonne);
        }
        printf("determiner chemin ligne 109 - PM: %d - obstacle: %d\n", *PM, obstacle);
    } while ((joueurPI->colonne != PF.colonne) ||
             (joueurPI->ligne != PF.ligne) && (*PM) < PM_MAX); // la destination n'est pas atteinte on continue
    if ((joueurPI->colonne != PF.colonne) ||
        (joueurPI->ligne != PF.ligne)) {
        joueurPI->colonne = positionInitiale.colonne;
        joueurPI->ligne = positionInitiale.ligne;
    }
    //juste pour le test
    int i;
    for (i = 0; i <= *PM; i++) {
        printf("determinerLeChemin -Les coordonnes du chemin sont : [%d;%d]\n", tabChemin[i].ligne,
               tabChemin[i].colonne);
    }
    return 0;

}
