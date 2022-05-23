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
#include "general.h"
#include "arene.h"
#include "deplacement.h"
#define NB_IMAGES 1
#define largeurIm 50 // caractéristiques de l'image
#define hauteurIm 70

void affichageMatrice();

void affichagePorteeDeplacement(Case tabCase[LIGNES_TAB][COLONNES_TAB], int ligneSouris, int colonneSouris, int ligne,
                                int colonne);

void afficherPositionJoueur(Case tabCase[LIGNES_TAB][COLONNES_TAB], Coords positionJoueur);

void deplacementJoueur(Case tabCase[LIGNES_TAB][COLONNES_TAB], Coords tabChemin);

void afficherPerso(Coords tabChemin[PM_MAX + 1], ALLEGRO_BITMAP *imageJ,Case tabCase[LIGNES_TAB][COLONNES_TAB], int ligneSouris, int colonneSouris, Image decor, int ligne, int colonne, int tabArene[LIGNES_TAB][COLONNES_TAB], int PMJoueur, int compteurImage, Joueurs * listeJ, Joueurs *jActuel,  rectangle rectNext, ALLEGRO_FONT* miniOrbitron,ALLEGRO_FONT* Orbitron,ALLEGRO_COLOR BLANC);
void affichage(int tabArene[LIGNES_TAB][COLONNES_TAB], int TabObstacle[LIGNES_TAB][COLONNES_TAB], Coords tabChemin[PM_MAX+1], Joueurs*joueur);
void destroy(Image decors, ALLEGRO_DISPLAY * display, ALLEGRO_TIMER* timer, ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_BITMAP* imageJ);
void dessinerTout(Case tabCase[LIGNES_TAB][COLONNES_TAB], int ligneSouris, int colonneSouris, Image decor, int ligne, int colonne,int tabArene[LIGNES_TAB][COLONNES_TAB], Coords tabChemin[PM_MAX + 1],Coords positionJoueur,ALLEGRO_BITMAP*imageJ, int cmptImage,  Joueurs* listeJ, Joueurs *jActuel,  rectangle rectNext, ALLEGRO_FONT* miniOrbitron,ALLEGRO_FONT* Orbitron,ALLEGRO_COLOR BLANC);
void dessinerMap(Case tabCase[LIGNES_TAB][COLONNES_TAB], int ligneSouris, int colonneSouris, Image decor, int ligne, int colonne,
                 int tabArene[LIGNES_TAB][COLONNES_TAB], Coords tabChemin[PM_MAX + 1],  Joueurs* listeJ, Joueurs *jActuel, ALLEGRO_BITMAP* imageJ);
void dessinerPerso(ALLEGRO_BITMAP *imageJ, int cmptImage, int positionJoueurLigne, int positionJoueurColonne,  Joueurs jA) ;
void InitImageJ(Joueurs* listeJ, ALLEGRO_BITMAP * ImPerso);
void afficherLesAutresJoueurs( Joueurs* listeJ, Joueurs *jActuel, ALLEGRO_BITMAP* ImPerso);
int valeureAbsolue(int i, int j);
void dessinerFond(int numClasseJA, Image decor);
void dessinerInterfaceJoueur(ALLEGRO_FONT* font, ALLEGRO_FONT* font1, char text[INFINI],Joueurs * J,ALLEGRO_BITMAP *sort1, ALLEGRO_BITMAP *sort2, ALLEGRO_BITMAP *sort3);
void affichagePorte(Case tabCase[LIGNES_TAB][COLONNES_TAB], int ligne, int colonne,int tabArene[LIGNES_TAB][COLONNES_TAB], int PMJ);
#endif //PROJET2_AFFICHAGE_H
