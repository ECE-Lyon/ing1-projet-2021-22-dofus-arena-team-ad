//
// Created by Mona Lias on 5/13/22.
//

#ifndef PROJET_JOUEUR_H
#define PROJET_JOUEUR_H
#include "jeu.h"
typedef struct{
    char nom[10];
    int degat, PA, portee, timestour, timespart;
    float pourEchec;
}Sorts;

typedef struct{
    char nom[10];
    int pv, numJ;
    //voir tableau de pointeur sur fonction
    Sorts sort[4];
}classe;

typedef struct J{
    bool Eblouissement, lava; //à ini en false
    char nom[10];
    int pv, pa, pm;
    struct J* next;
    struct J* prev;
    classe classeJ;
    Coords positionJ;
}Joueurs;
#endif //PROJET_JOUEUR_H
