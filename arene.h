//
// Created by Mona Lias on 5/2/22.
//

#ifndef PROJET2_ARENE_H
#define PROJET2_ARENE_H
#include <stdbool.h>
#include "jeu.h"
#include "general.h"

void initialiserImages(Image* decor);
void construireLarene(int ClasseDuJoueur,int tabArene[LIGNES_TAB][COLONNES_TAB]) ;
void initialiserTableau( int tab[LIGNES_TAB][COLONNES_TAB]);
void initialiserTabChemin(Coords tabChemin[PM_MAX+1]);
void intialisationArene(int tabArene[LIGNES_TAB][COLONNES_TAB],
                        int TabObstacle[LIGNES_TAB][COLONNES_TAB]);

#endif //PROJET2_ARENE_H
