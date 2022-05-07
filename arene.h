//
// Created by Mona Lias on 5/2/22.
//

#ifndef PROJET2_ARENE_H
#define PROJET2_ARENE_H
#include <stdbool.h>
#include "jeu.h"

void initialiserImages(Image* decor);
void construireLarene(int ClasseDuJoueur,int tabArene[LIGNES_TAB][COLONNES_TAB]) ;
void initialiserTableau( int tab[LIGNES_TAB][COLONNES_TAB]);
void afficherTableau (int tab[LIGNES_TAB][COLONNES_TAB]);
#endif //PROJET2_ARENE_H
