//
// Created by Mona Lias on 5/7/22.
//

#ifndef PROJET2_JEU_H
#define PROJET2_JEU_H
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#define TAILLE_CASE 47
#define X_TAB 40
#define Y_TAB 70
#define largeurIm 50 // caractéristiques de l'image
#define hauteurIm 70

// DEPLACEMENT.H
#define PM_MAX 3
#define CASE_OBSTACLE 3
#define CASE_LIBRE 0
#define COLONNES_TAB 20
#define LIGNES_TAB 15
#define CASE_VIDE 9999

typedef struct {
    ALLEGRO_BITMAP * rocher, *fond, *perso, *cailloux,*fleur, *meteor;
}Image;

#endif //PROJET2_JEU_H
