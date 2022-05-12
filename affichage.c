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


void deplacementJoueur(Case tabCase[LIGNES_TAB][COLONNES_TAB], Coords tabChemin) {
    al_draw_filled_rectangle(tabCase[tabChemin.ligne][tabChemin.colonne].x + 3,
                             tabCase[tabChemin.ligne][tabChemin.colonne].y + 3,
                             tabCase[tabChemin.ligne][tabChemin.colonne].x + TAILLE_CASE - 4,
                             tabCase[tabChemin.ligne][tabChemin.colonne].y + TAILLE_CASE - 4,
                             al_map_rgba(0, 128, 0, 150));
    //al_flip_display();
}

void dessinerPerso(Image personnage, Coords positionJoueur) {
    al_draw_bitmap(personnage.perso, (100 * (positionJoueur.colonne)) + 80, (100 * (positionJoueur.ligne) - 50) + 135,
                   0);
}

void dessinerMap(Case tabCase[LIGNES_TAB][COLONNES_TAB], int ligneSouris, int colonneSouris, Image decor, int ligne,
                 int colonne,
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

            switch (decors) {
                case 3: {

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

void dessinerTout(Case tabCase[LIGNES_TAB][COLONNES_TAB], int ligneSouris, int colonneSouris, Image decor, int ligne,
                  int colonne, int tabArene[LIGNES_TAB][COLONNES_TAB], Coords tabChemin[PM_MAX + 1],
                  Coords positionJoueur) {
    dessinerMap(tabCase, ligneSouris, colonneSouris, decor, ligne, colonne, tabArene, tabChemin);
    dessinerPerso(decor, positionJoueur);
    al_flip_display();
}

void afficherPerso(Coords tabChemin[PM_MAX + 1], ALLEGRO_BITMAP *perso, Case tabCase[LIGNES_TAB][COLONNES_TAB],
                   int ligneSouris, int colonneSouris, Image decor, int ligne, int colonne,
                   int tabArene[LIGNES_TAB][COLONNES_TAB], int PMJoueur) {


    int tailleTab = 0; // (taille Logique) pour parcourir le tab de chemin et faire se deplacer le joueur en fonction du nb de PM
    Coords positionJoueur;
    Coords positionIntermediaire; // pour faire glisser le perso de cases en cases
    Coords positionFinale;
    int i = 0;
    // recherche de la taille logique du tab en fonction du nombre de PM que le joueur va faire
    for (int i = 0; i <= PM_MAX; i++) { //<= pour prendre en compte le deplacement lorsque PM=3
        if (tabChemin[i].colonne != CASE_VIDE) {
            tailleTab += 1;
        }
    }
    positionFinale = tabChemin[tailleTab];
    // printf("positionFinale:[%d;%d]\n", positionFinale.ligne, positionFinale.colonne);

    // on boucle tant que l'on a pas atteint la position finale (tant que la taille du tab n'est pas atteinte)
    for (i = 0; i < tailleTab; i++) {
        positionJoueur = tabChemin[i];
        positionIntermediaire = tabChemin[i + 1];

        // cas ou le joueur arrive à sa position finale
        if (positionFinale.colonne == positionJoueur.colonne && positionJoueur.ligne == positionFinale.ligne) {
            printf("position atteinte\n");
            dessinerTout(tabCase, ligneSouris, colonneSouris, decor, ligne, colonne, tabArene, tabChemin,
                         positionJoueur);
        }

        // on va verifier à chaque fois que le perso bouge son placeement par rapport a la position finale ( deplacement horizontal / vertical...)
        if (positionIntermediaire.colonne > positionJoueur.colonne) {
            int x = (100 * (positionJoueur.colonne)) + 80; // position actuelle joueur
            while (x < ((100 * (positionJoueur.colonne)) + 80) +
                       100) { // tant que l'on a pas atteint la case suivante on deplace le perso
                dessinerMap(tabCase, ligneSouris, colonneSouris, decor, ligne, colonne, tabArene, tabChemin);
                al_draw_bitmap(perso, x, (100 * (positionJoueur.ligne) - 50) + 135, 0);
                al_flip_display();
                sleep(1);
                x += 150; // on l'affiche tous les 150 pixels (effet glissement)
            }
        }

        if (positionIntermediaire.colonne < positionJoueur.colonne) {
            int x = (100 * (positionJoueur.colonne)) + 80;
            while (x > ((100 * (positionJoueur.colonne)) + 80) - 100) {
                dessinerMap(tabCase, ligneSouris, colonneSouris, decor, ligne, colonne, tabArene, tabChemin);
                al_draw_bitmap(perso, x, (100 * (positionJoueur.ligne) - 50) + 135, 0);
                al_flip_display();
                sleep(1);
                x -= 150;
            }
        }
        if (positionIntermediaire.ligne > positionJoueur.ligne) {
            int y = (100 * (positionJoueur.ligne) - 50) + 135;
            while (y < ((100 * (positionJoueur.ligne) - 50) + 135) + 100) {
                dessinerMap(tabCase, ligneSouris, colonneSouris, decor, ligne, colonne, tabArene, tabChemin);
                al_draw_bitmap(perso, (100 * (positionJoueur.colonne)) + 80, y, 0);
                al_flip_display();
                sleep(1);
                y += 150;
            }
        }
        if (positionIntermediaire.ligne < positionJoueur.ligne) {
            int y = (100 * (positionJoueur.ligne) - 50) + 135;
            while (y > ((100 * (positionJoueur.ligne) - 50) + 135) - 100) {
                dessinerMap(tabCase, ligneSouris, colonneSouris, decor, ligne, colonne, tabArene, tabChemin);
                al_draw_bitmap(perso, (100 * (positionJoueur.colonne)) + 80, y, 0);
                al_flip_display();
                sleep(1);
                y -= 150;
            }
        }

    }
}

void destroy(Image decors, ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *queue) {
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_bitmap(decors.perso);
    al_destroy_bitmap(decors.fond);
    al_destroy_bitmap(decors.rocher);
    al_destroy_bitmap(decors.meteor);
    al_destroy_bitmap(decors.cailloux);
    al_destroy_bitmap(decors.fleur);
    al_destroy_event_queue(queue);
}

// fonction pour afficher toute la map + deplacement joueur
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
// init et installations
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
    al_start_timer(timer);
    // on dessine la Map et les persos une première fois
    dessinerTout(tabCase, ligneSouris, colonneSouris, decor, ligne, colonne, tabArene, tabChemin, positionJoueur);

// mise en place de la boucle d'evenements
    while (!end) {
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                end = true;
                break;

                // detecter le clic de la souris sur une case quelconque
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
                // variable pour determiner si le deplacement et possible ou non (cas d'un obstacle/ d'un PM> PM max)
                determinerChemin = 0;

                // on verifie que le joueur n'a pas atteint la position finale et n'as pas fait 3PM de deplacement
                if (PM < PM_MAX && (positionJoueur.colonne != positionFinale.colonne ||
                                    positionJoueur.ligne != positionFinale.ligne)) {
// on va determiner le chemin si la position finale n'est pas atteinte et si le deplacement est possible
                    while (determinerChemin == 0 && PM < PM_MAX && (positionJoueur.colonne != positionFinale.colonne ||
                                                                    positionJoueur.ligne != positionFinale.ligne)) {

                        initialiserTabChemin(tabChemin);
                        // on determine le chemin a parcourir
                        determinerChemin = determinerLeChemin(&positionJoueur, &PM, positionFinale, TabObstacle,
                                                              tabChemin);

                        // on verifie que le tab chemin n'est pas vide si oui pas de deplacement effectué
                        if (tabChemin[0].colonne == CASE_VIDE) {
                        }
                    }
                    // si le deplacement est possible et si le nb de PM n'est pas dépassé alors on va faire glisser le joueur sur la case cliquée
                    if (determinerChemin == 0 && PM <= PM_MAX) {
                        afficherPerso(tabChemin, decor.perso, tabCase, ligneSouris, colonneSouris, decor,
                                      ligne, colonne, tabArene, PM);

                    }
                }
                // juste pour pouvoir tester sans prendre trop de temps je réinitialise ici les PM à 0 a chaque fois que j'ai atteint les 3PM
                // mais ça sera à gerer dans le Tour Joueur plutôt
                if (PM >= PM_MAX) {
                    PM = 0;
                }
                break;
            }
            case ALLEGRO_EVENT_TIMER: {

                break;
            }
        }


    }
    destroy(decor, display, timer, queue);
}
