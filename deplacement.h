//
// Created by Mona Lias on 4/27/22.
//

#ifndef PROJET2_DEPLACEMENT_H
#define PROJET2_DEPLACEMENT_H
#include <stdbool.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "jeu.h"
#include "arene.h"

bool isObstacle(int tabObstacle[LIGNES_TAB][COLONNES_TAB], Coords* joueurPI, int loop, int inc,bool depHorizon);
int determinerLeChemin(Coords *joueurPI, int *PM, Coords PF, int tabObstacle[LIGNES_TAB][COLONNES_TAB], Coords tabChemin[PM_MAX+1]);
void stockerTabChemin(Coords tabChemin[PM_MAX+1], int *indTab, Coords *joueurPI,int loop,  int inc, bool depHorizon);
int determinerSensDeplacement(int positionInitiale, int PF);
#endif //PROJET2_DEPLACEMENT_H
