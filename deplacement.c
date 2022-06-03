//
// Created by Mona Lias on 4/27/22.
//

#include "deplacement.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "general.h"

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

    if (depHorizon) {
        tabChemin[*indTab].colonne = joueurPI->colonne + (loop * inc);
        tabChemin[*indTab].ligne = joueurPI->ligne;
    } else {
        tabChemin[*indTab].colonne = joueurPI->colonne;
        tabChemin[*indTab].ligne = joueurPI->ligne + (loop * inc);
    }
    //printf("Les coordonnes stokees sont : [%d;%d]\n", tabChemin[*indTab].ligne, tabChemin[*indTab].colonne);
    (*indTab) = (*indTab) + 1;

}

int determinerLeChemin(Coords *joueurPI, int *PM, Coords PF, int tabObstacle[LIGNES_TAB][COLONNES_TAB],
                       Coords tabChemin[PM_MAX + 1]) {
    bool depHorizon = true;  // true si le deplacement est sur les colonnes, false si lignes
    Coords positionInitiale;  // enregistrer la position initiale du joueur dans le cas ou le deplacement n'a pas lieu
    int nbObstaclesDuDeplacement=0;
    // si l'ecart est plus grand que le nb de deplacement max --> on ne peut pas se deplacer
    if (abs(PF.colonne - joueurPI->colonne) > PM_MAX || abs(PF.ligne - joueurPI->ligne)>PM_MAX) {
        return 1;
    } else if (tabObstacle[PF.ligne][PF.colonne] == CASE_OBSTACLE) { // cas ou on clique sur une case obstacle
        return 1;
    }
    positionInitiale=(*joueurPI);
    int indiceTab = 0;
    tabChemin[indiceTab] = positionInitiale;  // pour afficher la position initiale du joueur en premier dans le tab
    indiceTab++;

    do {
        // initialisation des variables
        int ecart = 0, loop = 1;
        int inc = 0; // increment
        int NBDC = 0; // nb de deplacement colonne
        bool obstacle = false; // par defaut il n'y a pas d'obstacles
        //calculer ecart entre PI et PF
        ecart = PF.colonne - joueurPI->colonne;
        if (ecart == 0) { //on reste sur la colonne si ecart nul
            depHorizon = false;
        }
        if (depHorizon) { // deplacement horizontal en cours
            // stocker le nb de deplacement colonne
            NBDC = abs(ecart);
            // determiner sens de deplacement
            inc = determinerSensDeplacement(joueurPI->colonne, PF.colonne);
        } else { // deplacement vertical  en cours
            NBDC = 1; //nb de deplacement ligne toujours à 1
            inc = determinerSensDeplacement(joueurPI->ligne, PF.ligne);
        }

        //tant qu'on a pas atteint l'ecart et pas trouvé d'obstacle
        while (loop <= NBDC && !obstacle) {
            // verifier qu'il n'y a pas d'obstcale
            if (!isObstacle(tabObstacle, joueurPI, loop, inc, depHorizon)) {
                // on stocke la coordonnée dans tabChemin si pas d'obstacle
                stockerTabChemin(tabChemin, &indiceTab, joueurPI, loop, inc,
                                 depHorizon);
            } // fin isObstacle
            else {
                printf("IL Y A UN OBSTACLE\n");
                obstacle = true;
                nbObstaclesDuDeplacement++ ;
                (*joueurPI)= tabChemin[indiceTab-1]; //  le joueur retourne sur la case precedente
                *PM-=1; // il n'y a pas de deplacement comptabilisé
            }
            loop++;
            (*PM) = (*PM) + 1;
        } // fin de loop sur colonne et pas d'obstacle

        //On change de trajectoire
        if (depHorizon) {
            depHorizon = false;
        } else {
            depHorizon = true;
        }

        if (!obstacle) {
            //les coordonees du joueur deviennent celles du chemin (le joueur prend les coordonnées stockées dans la dernière case du tabChemin)
            joueurPI->colonne = tabChemin[indiceTab - 1].colonne;
            joueurPI->ligne = tabChemin[indiceTab - 1].ligne;
        } else {
            if (nbObstaclesDuDeplacement>=3){ // si le joueur rencontre 3 obstacles ou plus alors pas de deplacement possible
                return 1;
            }
            if (ecart == 0) { // on réinitialise tout (position joueur et tabChemin) / on cherche un nouveau chemin
                joueurPI->colonne = tabChemin[0].colonne;
                joueurPI->ligne = tabChemin[0].ligne;
                *PM = 3;
                initialiserTabChemin(tabChemin);
                indiceTab = 0;
                tabChemin[indiceTab] = positionInitiale;
                depHorizon = false;
                indiceTab++;

            }
        }
    }// tant que la destination n'est pas atteinte on continue
    while (((joueurPI->colonne != PF.colonne) ||  (joueurPI->ligne != PF.ligne) )
      && (*PM) <= PM_MAX);
    // on verifie que le joueur à atteint la position finale ou que PM n'est pas au max sinon on reste à la position initiale
    if (((joueurPI->colonne != PF.colonne) || (joueurPI->ligne != PF.ligne)  )
        || (*PM) > PM_MAX) {
        joueurPI->colonne = positionInitiale.colonne;
        joueurPI->ligne = positionInitiale.ligne;
    }

    //juste pour le test
    int i;
    for (i = 0; i <= *PM; i++) {
        printf("determinerLeChemin -Les coordonnes du chemin sont : [%d;%d]\n", tabChemin[i].ligne,tabChemin[i].colonne);
    }

    return 0;

}
