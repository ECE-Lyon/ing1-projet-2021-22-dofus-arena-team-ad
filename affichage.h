//
// Created by Mona Lias on 4/30/22.
//

#ifndef PROJET2_AFFICHAGE_H
#define PROJET2_AFFICHAGE_H

#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include "jeu.h"
#include "arene.h"
#include "deplacement.h"
#define ECRAN_LONGUEUR 2880
#define ECRAN_LARGEUR 1694
#define TAILLE_CASE 100
#define X_TAB 80
#define Y_TAB 135
#define largeurIm 50 // caractéristiques de l'image
#define hauteurIm 70

void affichageMatrice(Case tabCase[LIGNES_TAB][COLONNES_TAB], int ligneSouris, int colonneSouris);

void affichagePorteeDeplacement(Case tabCase[LIGNES_TAB][COLONNES_TAB], int ligneSouris, int colonneSouris, int ligne,
                                int colonne);

void afficherPositionJoueur(Case tabCase[LIGNES_TAB][COLONNES_TAB], Coords positionJoueur);

void deplacementJoueur(Case tabCase[LIGNES_TAB][COLONNES_TAB], Coords tabChemin);

void afficherPerso(Coords tabChemin[PM_MAX + 1], ALLEGRO_BITMAP *perso, Case tabCase[LIGNES_TAB][COLONNES_TAB], int ligneSouris, int colonneSouris, Image decor, int ligne, int colonne, int tabArene[LIGNES_TAB][COLONNES_TAB], int PMJoueur);
void affichage(int tabArene[LIGNES_TAB][COLONNES_TAB], int TabObstacle[LIGNES_TAB][COLONNES_TAB], Coords tabChemin[PM_MAX+1], Coords positionJoueur);
void destroy(Image decors, ALLEGRO_DISPLAY * display, ALLEGRO_TIMER* timer, ALLEGRO_EVENT_QUEUE* queue);
void dessinerTout(Case tabCase[LIGNES_TAB][COLONNES_TAB], int ligneSouris, int colonneSouris, Image decor, int ligne, int colonne,int tabArene[LIGNES_TAB][COLONNES_TAB], Coords tabChemin[PM_MAX + 1],Coords positionJoueur);
void dessinerMap(Case tabCase[LIGNES_TAB][COLONNES_TAB], int ligneSouris, int colonneSouris, Image decor, int ligne, int colonne,
                 int tabArene[LIGNES_TAB][COLONNES_TAB], Coords tabChemin[PM_MAX + 1]);
void dessinerPerso(Image personnage,Coords positionJoueur );
#endif //PROJET2_AFFICHAGE_H
