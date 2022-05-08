//
// Created by Mona Lias on 4/30/22.
//

#include "affichage.h"

void affichageMatrice(Case tabCase[LIGNES_TAB][COLONNES_TAB], int ligneSouris, int colonneSouris) {
    for (int i = 0; i <= LIGNES_TAB; ++i) {
        al_draw_line(X_TAB, Y_TAB + i * TAILLE_CASE,
                     X_TAB + TAILLE_CASE * COLONNES_TAB, Y_TAB + i * TAILLE_CASE,
                     al_map_rgb(0, 0, 0), 1);
    }
    for (int j = 0; j <= COLONNES_TAB; ++j) {
        al_draw_line(X_TAB + j * TAILLE_CASE, Y_TAB,
                     X_TAB + j * TAILLE_CASE, Y_TAB + TAILLE_CASE * LIGNES_TAB,
                     al_map_rgb(0, 0, 0), 1);
    }

}

void affichagePorteeDeplacement(Case tabCase[LIGNES_TAB][COLONNES_TAB], int ligneSouris, int colonneSouris, int ligne,
                                int colonne) {
    al_clear_to_color(al_map_rgb(255, 255, 255));
    for (int i = 0; i <= LIGNES_TAB; ++i) {
        al_draw_line(X_TAB, Y_TAB + i * TAILLE_CASE,
                     X_TAB + TAILLE_CASE * COLONNES_TAB, Y_TAB + i * TAILLE_CASE,
                     al_map_rgb(0, 0, 0), 1);
    }
    for (int j = 0; j <= COLONNES_TAB; ++j) {
        al_draw_line(X_TAB + j * TAILLE_CASE, Y_TAB,
                     X_TAB + j * TAILLE_CASE, Y_TAB + TAILLE_CASE * LIGNES_TAB,
                     al_map_rgb(0, 0, 0), 1);
    }

    //DEPLACEMENT :
    for (int i = 0; i < LIGNES_TAB; ++i) {
        for (int j = 0; j < COLONNES_TAB; ++j) {
            if (tabCase[i][j].deplacement == true) {
                al_draw_filled_rectangle(tabCase[i][j].x + 3, tabCase[i][j].y + 3,
                                         tabCase[i][j].x + TAILLE_CASE - 4, tabCase[i][j].y + TAILLE_CASE - 4,
                                         al_map_rgb(200, 200, 200));
            }
        }
    }
    //SOURIS :
    al_draw_filled_rectangle(tabCase[ligneSouris][colonneSouris].x + 3, tabCase[ligneSouris][colonneSouris].y + 3,
                             tabCase[ligneSouris][colonneSouris].x + TAILLE_CASE - 4,
                             tabCase[ligneSouris][colonneSouris].y + TAILLE_CASE - 4,
                             al_map_rgb(20, 20, 20));
}

void afficherPositionJoueur(Case tabCase[LIGNES_TAB][COLONNES_TAB], Coords positionJoueur) {
    al_draw_filled_rectangle(tabCase[positionJoueur.ligne][positionJoueur.colonne].x + 3,
                             tabCase[positionJoueur.ligne][positionJoueur.colonne].y + 3,
                             tabCase[positionJoueur.ligne][positionJoueur.colonne].x + TAILLE_CASE - 4,
                             tabCase[positionJoueur.ligne][positionJoueur.colonne].y + TAILLE_CASE - 4,
                             al_map_rgb(20, 20, 20));
    // al_flip_display();
}

void deplacementJoueur(Case tabCase[LIGNES_TAB][COLONNES_TAB], Coords tabChemin) {
    al_draw_filled_rectangle(tabCase[tabChemin.ligne][tabChemin.colonne].x + 3,
                             tabCase[tabChemin.ligne][tabChemin.colonne].y + 3,
                             tabCase[tabChemin.ligne][tabChemin.colonne].x + TAILLE_CASE - 4,
                             tabCase[tabChemin.ligne][tabChemin.colonne].y + TAILLE_CASE - 4,
                             al_map_rgba(0, 128, 0, 150));
    //al_flip_display();
}

void dessinerTout(Case *tabCase, int ligneSouris, int colonneSouris, Image decor, int ligne, int colonne,
                  int tabArene[LIGNES_TAB][COLONNES_TAB], Coords tabChemin[PM_MAX + 1]) {
    int decors = 0;
    // affichage du fond
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_bitmap(decor.fond, 0, 0, 0);
    affichageMatrice(tabCase, ligneSouris, colonneSouris);

    // affichage du décor après lecture du tab Arene
    for (ligne = 0; ligne < LIGNES_TAB; ligne++) { // boucle sur les lignes
        //boucle sur les colonnes
        for (colonne = 0; colonne < COLONNES_TAB; colonne++) {
            decors = tabArene[ligne][colonne];
            //printf("obstacles:%d\n", obstacles);
            switch (decors) {
                case 3: {
                    //printf("rocher\n");
                    al_draw_bitmap(decor.rocher, (100 * colonne) + 80, ((100 * ligne) - 10) + 135, 0);
                    break;
                }
                case 4: {
                    al_draw_bitmap(decor.meteor, (100 * colonne) + 80, ((100 * ligne) - 10) + 135, 0);
                    break;
                }
                case 5: {
                    al_draw_bitmap(decor.cailloux, (100 * colonne) + 80, ((100 * ligne) + 20) + 135, 0);
                    break;
                }
                case 6 : {
                    al_draw_bitmap(decor.fleur, (100 * colonne) + 80, ((100 * ligne) - 50) + 135, 0);
                    break;
                }
                default: {
                    break;
                }
            }
        }
    }
}

void afficherPerso(Coords tabChemin[PM_MAX + 1], ALLEGRO_BITMAP *perso, Case tabCase[LIGNES_TAB][COLONNES_TAB],
                   int ligneSouris, int colonneSouris, Image decor, int ligne, int colonne,
                   int tabArene[LIGNES_TAB][COLONNES_TAB]) {
    int tailleTab = 0; // (taille Logique) pour parcourir le tab de chemin et faire se deplacer le joueur
    Coords positionJoueur;
    Coords positionFinale;

    // recherche de la taille logique du tab
    for (int i = 0; i <= PM_MAX; i++) {
        if (tabChemin[i].colonne != CASE_VIDE) {
            tailleTab += 1;
        }
    }

    for (int i = 0; i < tailleTab - 1; i++) {
        positionJoueur = tabChemin[i];
        positionFinale = tabChemin[i + 1];

        printf("tabChemin.colone: %d, tabchemin.ligne:%d, positionJoueur.colonne:%d, positionJoueur.ligne: %d, tailleTab: %d\n",
               positionFinale.colonne, positionFinale.ligne, positionJoueur.colonne, positionJoueur.ligne, tailleTab);

        if (positionFinale.colonne > positionJoueur.colonne) {
            int x = (100 * (positionJoueur.colonne)) + 80; // position actuelle joueur
            while (x < ((100 * (positionJoueur.colonne)) + 80) + 100) {
                al_flip_display();
                al_draw_bitmap(perso, x, (100 * (positionJoueur.ligne) - 50) + 135, 0);
                al_flip_display();
                sleep(1);
                x += 150;
            }

        }
        if (positionFinale.colonne < positionJoueur.colonne) {
            int x = (100 * (positionJoueur.colonne)) + 80;
            while (x > ((100 * (positionJoueur.colonne)) + 80) - 100) {
                al_flip_display();
                al_draw_bitmap(perso, x, (100 * (positionJoueur.ligne) - 50) + 135, 0);
                al_flip_display();
                sleep(1);
                x -= 150;
            }
        }
        if (positionFinale.ligne > positionJoueur.ligne) {
            int y = (100 * (positionJoueur.ligne) - 50) + 135;
            while (y < ((100 * (positionJoueur.ligne) - 50) + 135) + 100) {
                al_flip_display();
                al_draw_bitmap(perso, (100 * (positionJoueur.colonne)) + 80, y, 0);
                al_flip_display();
                sleep(1);
                y += 150;
            }
        }
        if (positionFinale.ligne < positionJoueur.ligne) {
            int y = (100 * (positionJoueur.ligne) - 50) + 135;
            while (y > ((100 * (positionJoueur.ligne) - 50) + 135) - 100) {
                al_flip_display();
                al_draw_bitmap(perso, (100 * (positionJoueur.colonne)) + 80, y, 0);
                al_flip_display();
                sleep(1);
                y -= 150;
            }
        }
        dessinerTout(*tabCase, ligneSouris, colonneSouris, decor, ligne, colonne, tabArene, tabChemin);
    }
}

int valeureAbsolue(int i, int j) {
    if (i >= j) {
        return i - j;
    } else {
        return j - i;
    }
}

void affichage(int tabArene[LIGNES_TAB][COLONNES_TAB], int TabObstacle[LIGNES_TAB][COLONNES_TAB],
               Coords tabChemin[PM_MAX + 1], Coords positionJoueur) {
    bool end = false;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_EVENT event;
// init des bitmaps
    Image decor;
    Case tabCase[LIGNES_TAB][COLONNES_TAB] = {0};
    int nbImage = 10;
    int xCase, yCase = Y_TAB;
    int ligneSouris = 0, colonneSouris = 0;
    int xSouris;
    int ySouris;
    int i, ligne = 0, colonne = 0, PM = 0, decors = 0;
    int determinerChemin = 0;
    Coords positionFinale;
// init du timer
    srand(time(NULL));
    al_init();
    al_init_primitives_addon();
    al_init_image_addon();
    al_install_mouse();
    al_init_font_addon();
    al_init_ttf_addon();

// chargement des images
    initialiserImages(&decor);

    display = al_create_display(ECRAN_LONGUEUR, ECRAN_LARGEUR);
    timer = al_create_timer(1.0 / 60.0);
    queue = al_create_event_queue();
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));

    for (int i = 0; i < LIGNES_TAB; ++i) {
        xCase = X_TAB;
        for (int j = 0; j < COLONNES_TAB; ++j) {
            tabCase[i][j].x = (float) xCase;
            tabCase[i][j].y = (float) yCase;
            xCase += TAILLE_CASE;
        }
        yCase += TAILLE_CASE;
    }

    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_flip_display();
    al_start_timer(timer);

// premier affichage du fond
    while (!end) {
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                end = true;
                break;
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: {
                xSouris = event.mouse.x + TAILLE_CASE;
                ySouris = event.mouse.y + TAILLE_CASE;

                for (int i = 0; i < LIGNES_TAB; ++i) {
                    if ((float) tabCase[i][0].y<(float) ySouris && (float) ySouris>(float)tabCase[i][0].y +
                                                                                          TAILLE_CASE) {
                        ligneSouris = i;
                        positionFinale.ligne = i;
                    }
                }
                for (int j = 0; j < COLONNES_TAB; ++j) {
                    if ((float) tabCase[0][j].x<(float) xSouris && (float) xSouris>(float)tabCase[0][j].x +
                                                                                          TAILLE_CASE) {
                        colonneSouris = j;
                        positionFinale.colonne = j;
                    }
                }
                printf("AFFICHAGE PM: %d\n", PM);
// tant que le joueur n'a pas atteind la position finale et n'as pas fait 3PM de deplacement
                if (PM < PM_MAX && (positionJoueur.colonne != positionFinale.colonne ||
                                    positionJoueur.ligne != positionFinale.ligne)) {

                    while (determinerChemin == 0 && PM < PM_MAX && (positionJoueur.colonne != positionFinale.colonne ||
                                                                    positionJoueur.ligne != positionFinale.ligne)) {
                        printf("ligne:%d - col: %d\n", positionJoueur.ligne, positionJoueur.colonne);
                        determinerChemin = determinerLeChemin(&positionJoueur, &PM, positionFinale, TabObstacle,
                                                              tabChemin);
                        if (tabChemin[0].colonne == CASE_VIDE) {
//tab de chemin vide --> pas de deplacement joueur
                        }
                        printf("PM: %d - ligne:%d - col: %d\n", PM, positionJoueur.ligne, positionJoueur.colonne);
                    }
                    if (determinerChemin == 0) {
                        printf("deplacer perso\n");
                        afficherPerso(tabChemin, decor.perso, tabCase, ligneSouris, colonneSouris, decor,
                                      ligne, colonne, tabArene);
                    }
                }
                if (PM>=3){
                  PM=0;
                }
                break;
            }

            case ALLEGRO_EVENT_TIMER: {
                dessinerTout(*tabCase, ligneSouris, colonneSouris, decor, ligne, colonne, tabArene, tabChemin);
                al_draw_bitmap(decor.perso, (100 * (positionJoueur.colonne)) + 80,
                               (100 * (positionJoueur.ligne) - 50) + 135, 0);
                al_flip_display();
//al_draw_bitmap(perso, (100*(positionJoueur.colonne))+80, (100*(positionJoueur.ligne)-50)+135, 0);

// test pour animation perso
/*for (int index = 0; index < nbImage; index++) {
    al_draw_bitmap_region(solaris, largeurIm * index, 0, largeurIm, hauteurIm,
                          (100 * (positionJoueur.colonne)) + 80,
                          (100 * (positionJoueur.ligne) - 50) + 135, 0);

    if (index == nbImage) {
        index = 0;
    }*/
                break;
            }
        }


    }
}
