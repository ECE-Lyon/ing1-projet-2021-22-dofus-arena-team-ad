//
// Created by Mona Lias on 4/30/22.
//

#include "affichage.h"
#include "general.h"


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
                             al_map_rgba(20, 20, 20, 200));
}

int valeureAbsolue(int i, int j) {
    if (i >= j) {
        return i - j;
    } else {
        return j - i;
    }
}

void affichagePorte(Case tabCase[LIGNES_TAB][COLONNES_TAB], int ligne, int colonne, int tabArene[LIGNES_TAB][COLONNES_TAB],
               int PMJ) {
    for (int i = 0; i < LIGNES_TAB; ++i) {
        for (int j = 0; j < COLONNES_TAB; ++j) {
            if (valeureAbsolue(i, ligne) + valeureAbsolue(j, colonne) <= (PM_MAX - PMJ)) {
                tabCase[i][j].deplacement = true;
            } else {
                tabCase[i][j].deplacement = false;
            }
        }
    }
    for (int i = 0; i < LIGNES_TAB; ++i) {
        for (int j = 0; j < COLONNES_TAB; ++j) {
            if ((tabCase[i][j].deplacement == true) && (tabArene[i][j] < CASE_OBSTACLE)) {
                al_draw_filled_rectangle(tabCase[i][j].x + 3, tabCase[i][j].y + 3,
                                         tabCase[i][j].x + TAILLE_CASE - 4, tabCase[i][j].y + TAILLE_CASE - 4,
                                         al_map_rgba(100, 100, 100, 50));
            }
        }
    }
}

void deplacementJoueur(Case tabCase[LIGNES_TAB][COLONNES_TAB], Coords tabChemin) {
    al_draw_filled_rectangle(tabCase[tabChemin.ligne][tabChemin.colonne].x + 3,
                             tabCase[tabChemin.ligne][tabChemin.colonne].y + 3,
                             tabCase[tabChemin.ligne][tabChemin.colonne].x + TAILLE_CASE - 4,
                             tabCase[tabChemin.ligne][tabChemin.colonne].y + TAILLE_CASE - 4,
                             al_map_rgba(0, 128, 0, 150));
}

void chargerAnimation(Joueurs **listeJ, ALLEGRO_BITMAP *ImPerso[]) {
    // charger l'animation
    char nom[256];
    Joueurs *tmp = *listeJ;
    do {
        for (int j = 0; j < NB_IMAGES; j++) {
            switch (tmp->classeJ.numClasse) {
                case 0: {
                    sprintf(nom, "../background/Solaris%d.png", j);
                    break;
                }
                case 3: {
                    sprintf(nom, "../background/Saturna%d.png", j);
                    break;
                }
                case 2: {
                    sprintf(nom, "../background/Martian%d.png", j);
                    break;
                }
                case 1: {
                    sprintf(nom, "../background/Terra%d.png", j);
                    break;
                }
                default: {
                    printf("erreur classe joueur\n");
                    break;
                }
            }
            tmp->image = al_load_bitmap(nom);
            if (!ImPerso[j]) {
                printf("pas d'image\n");
            }
        }
        tmp = tmp->next;
    } while (tmp->next != *listeJ);
    if (tmp->next == *listeJ) {
        for (int j = 0; j < NB_IMAGES; j++) {
            switch (tmp->classeJ.numClasse) {
                case 0: {
                    sprintf(nom, "../background/Solaris%d.png", j);
                    break;
                }
                case 3: {
                    sprintf(nom, "../background/Saturna%d.png", j);
                    break;
                }
                case 2: {
                    sprintf(nom, "../background/Martian%d.png", j);
                    break;
                }
                case 1: {
                    sprintf(nom, "../background/Terra%d.png", j);
                    break;
                }
                default: {
                    printf("erreur classe joueur\n");
                    break;
                }
            }
            tmp->image = al_load_bitmap(nom);
            if (!ImPerso[j]) {
                printf("pas d'image\n");
            }
        }
    }
}

void dessinerPerso(ALLEGRO_BITMAP *anim[], int cmptImage, int positionJoueurLigne, int positionJoueurColonne,
                   Joueurs joueur) {
    switch (joueur.classeJ.numClasse) {
        case 0: {
            al_draw_scaled_bitmap(joueur.image, 0, 0, 157, 199, ((100 * (positionJoueurColonne)) + 80) - 20,
                                  (100 * (positionJoueurLigne) - 50) + 135, 140, 180, 0);
            break;
        }
        case 1: {
            al_draw_scaled_bitmap(joueur.image, 0, 0, 303, 338, ((100 * (positionJoueurColonne)) + 80),
                                  (100 * (positionJoueurLigne) - 50) + 135, 120, 150, 0);
            break;
        }
        case 2: {
            al_draw_scaled_bitmap(joueur.image, 0, 0, 199, 157, (100 * (positionJoueurColonne)) + 80,
                                  (100 * (positionJoueurLigne) - 30) + 135, 180, 140, 0);
            break;
        }
        case 3 : {
            al_draw_scaled_bitmap(joueur.image, 0, 0, 157, 199, ((100 * (positionJoueurColonne)) + 80) - 20,
                                  (100 * (positionJoueurLigne) - 80) + 135, 160, 200, 0);
            break;
        }
    }
}

void afficherLesAutresJoueurs(Joueurs *listeJ, Joueurs *jActuel) {
    ALLEGRO_BITMAP *ImPerso[NB_IMAGES];
    Joueurs *tmp = listeJ;
    if ((jActuel->positionJ.ligne != tmp->positionJ.ligne) ||
        (jActuel->positionJ.colonne != tmp->positionJ.colonne)) {
        //chargerAnimation(tmp, ImPerso);
        dessinerPerso(&tmp->image, 0, tmp->positionJ.ligne, tmp->positionJ.colonne, *tmp);
    }
    tmp = tmp->next;
    while (tmp != listeJ) {
        if ((jActuel->positionJ.ligne != tmp->positionJ.ligne) ||
            (jActuel->positionJ.colonne != tmp->positionJ.colonne)) {
            //chargerAnimation(tmp, ImPerso);
            dessinerPerso(&tmp->image, 0, tmp->positionJ.ligne, tmp->positionJ.colonne, *tmp);
        }
        tmp = tmp->next;
    }
}

void dessinerFond(int numClasseJA, Image decor) {
    switch (numClasseJA) {
        case 0 : {
            al_draw_bitmap(decor.Soleil, 0, 0, 0);
            break;
        }
        case 2 : {
            al_draw_bitmap(decor.Mars, 0, 0, 0);
            break;
        }
        case 1: {
            al_draw_bitmap(decor.Terre, 0, 0, 0);
            break;
        }
        case 3: {
            al_draw_bitmap(decor.Saturne, 0, 0, 0);
            break;
        }

    }
}

void dessinerMap(Case tabCase[LIGNES_TAB][COLONNES_TAB], int ligneSouris, int colonneSouris, Image decor, int ligne,
                 int colonne,
                 int tabArene[LIGNES_TAB][COLONNES_TAB], Coords tabChemin[PM_MAX + 1], Joueurs *listeJ,
                 Joueurs *jActuel) {
    int decors = 0;
    // affichage du fond
    al_clear_to_color(al_map_rgb(255, 255, 255));
    dessinerFond(jActuel->classeJ.numClasse, decor);
    affichageMatrice();
    // affichage du décor après lecture du tab Arene
    for (ligne = 0; ligne < LIGNES_TAB; ligne++) { // boucle sur les lignes
        //boucle sur les colonnes
        for (colonne = 0; colonne < COLONNES_TAB; colonne++) {
            decors = tabArene[ligne][colonne];

            switch (decors) {
                case 3: {

                    al_draw_bitmap(decor.rocher, (float) (100 * colonne) + 80, (float) ((100 * ligne) - 10) + 135, 0);
                    break;
                }
                case 4: {
                    al_draw_scaled_bitmap(decor.meteor,0,0,150,150,tabCase[ligne][colonne].x,tabCase[ligne][colonne].y,TAILLE_CASE + 8,TAILLE_CASE + 8,0);
                    //al_draw_bitmap(decor.meteor, (float) (100 * colonne) + 80, (float) ((100 * ligne) - 10) + 135,0);
                    break;
                }
                case 5: {
                    //al_draw_bitmap(decor.cailloux, (float) (100 * colonne) + 80, (float) ((100 * ligne) + 20) + 135,0);
                    al_draw_scaled_bitmap(decor.cailloux,0,0,80,80,tabCase[ligne][colonne].x + 25,tabCase[ligne][colonne].y + 25,(float)TAILLE_CASE/2,(float)TAILLE_CASE/2,0);
                    al_draw_scaled_bitmap(decor.cailloux,0,0,80,80,tabCase[ligne][colonne].x,tabCase[ligne][colonne].y + 25,(float)TAILLE_CASE/2,(float)TAILLE_CASE/2,0);
                    al_draw_scaled_bitmap(decor.cailloux,0,0,80,80,tabCase[ligne][colonne].x + 25,tabCase[ligne][colonne].y,(float)TAILLE_CASE/2,(float)TAILLE_CASE/2,0);
                    al_draw_scaled_bitmap(decor.cailloux,0,0,80,80,tabCase[ligne][colonne].x + 50,tabCase[ligne][colonne].y + 25,(float)TAILLE_CASE/2,(float)TAILLE_CASE/2,0);
                    al_draw_scaled_bitmap(decor.cailloux,0,0,80,80,tabCase[ligne][colonne].x,tabCase[ligne][colonne].y,(float)TAILLE_CASE/2,(float)TAILLE_CASE/2,0);
                    al_draw_scaled_bitmap(decor.cailloux,0,0,80,80,tabCase[ligne][colonne].x + (float)TAILLE_CASE/2,tabCase[ligne][colonne].y + (float)TAILLE_CASE/2,(float)TAILLE_CASE/2,(float)TAILLE_CASE/2,0);
                    al_draw_scaled_bitmap(decor.cailloux,0,0,80,80,tabCase[ligne][colonne].x + (float)TAILLE_CASE/2,tabCase[ligne][colonne].y,(float)TAILLE_CASE/2,(float)TAILLE_CASE/2,0);
                    al_draw_scaled_bitmap(decor.cailloux,0,0,80,80,tabCase[ligne][colonne].x,tabCase[ligne][colonne].y + (float)TAILLE_CASE/2,(float)TAILLE_CASE/2,(float)TAILLE_CASE/2,0);
                    break;
                }
                case 6 : {
                    al_draw_scaled_bitmap(decor.herbe,0,0,211,209,tabCase[ligne][colonne].x,tabCase[ligne][colonne].y,TAILLE_CASE-1,TAILLE_CASE-1,0);
                    al_draw_scaled_bitmap(decor.fleur,0,0,45,90,tabCase[ligne][colonne].x + 23,tabCase[ligne][colonne].y - 40,(float)TAILLE_CASE/2 + 10,TAILLE_CASE + 10,0);
                    //al_draw_bitmap(decor.fleur, (float) (100 * colonne) + 80, (float) ((100 * ligne) - 50) + 135,0);
                    break;
                }
                default: {
                    break;
                }
            }
        }
    }
    afficherLesAutresJoueurs(listeJ, jActuel);


}

void affichageMenuPerso(ALLEGRO_BITMAP *sort1, ALLEGRO_BITMAP *sort2, ALLEGRO_BITMAP *sort3, rectangle rectNext,
                        ALLEGRO_FONT *miniOrbitron,
                        ALLEGRO_FONT *Orbitron,
                        ALLEGRO_COLOR BLANC, Joueurs JA) {
    al_draw_text(Orbitron, BLANC, LARGEUR * (0.88), HAUTEUR * (0.05), ALLEGRO_ALIGN_RIGHT, JA.nom);
    al_draw_text(miniOrbitron, BLANC, LARGEUR * (0.88), HAUTEUR * (0.15), ALLEGRO_ALIGN_RIGHT, "PV :");
    al_draw_textf(miniOrbitron, BLANC, LARGEUR * (0.95), HAUTEUR * (0.15), ALLEGRO_ALIGN_RIGHT, "%d", JA.pv);
    al_draw_text(miniOrbitron, BLANC, LARGEUR * (0.88), HAUTEUR * (0.20), ALLEGRO_ALIGN_RIGHT, "PA : ");
    al_draw_textf(miniOrbitron, BLANC, LARGEUR * (0.95), HAUTEUR * (0.20), ALLEGRO_ALIGN_RIGHT, "%d", JA.pa);
    al_draw_text(miniOrbitron, BLANC, LARGEUR * (0.88), HAUTEUR * (0.25), ALLEGRO_ALIGN_RIGHT, "PM : ");
    al_draw_textf(miniOrbitron, BLANC, LARGEUR * (0.95), HAUTEUR * (0.25), ALLEGRO_ALIGN_RIGHT, "%d",PM_MAX - (JA.pm));
    al_draw_bitmap(sort1, LARGEUR * (0.82), HAUTEUR * (0.35), 0);
    al_draw_bitmap(sort2, LARGEUR * (0.87), HAUTEUR * (0.35), 0);
    al_draw_bitmap(sort3, LARGEUR * (0.92), HAUTEUR * (0.35), 0);
    drawrectangle(rectNext, miniOrbitron, "Fin du Tour");


}

void dessinerTout(Case tabCase[LIGNES_TAB][COLONNES_TAB], int ligneSouris, int colonneSouris, Image decor, int ligne,
                  int colonne, int tabArene[LIGNES_TAB][COLONNES_TAB], Coords tabChemin[PM_MAX + 1],
                  Coords positionJoueur, ALLEGRO_BITMAP *anim[], int cmptImage, Joueurs *listeJ, Joueurs *jActuel,
        //modifs 21/05
                  rectangle rectNext, ALLEGRO_FONT *miniOrbitron, ALLEGRO_FONT *Orbitron, ALLEGRO_COLOR BLANC) {
    dessinerMap(tabCase, ligneSouris, colonneSouris, decor, ligne, colonne, tabArene, tabChemin, listeJ, jActuel);
    //modifs 21/05
    affichageMenuPerso(decor.sort1, decor.sort2, decor.sort3, rectNext, miniOrbitron, Orbitron, BLANC, *jActuel);
    affichagePorte(tabCase, jActuel->positionJ.ligne, jActuel->positionJ.colonne, tabArene, jActuel->pm);
    dessinerPerso(anim, cmptImage, positionJoueur.ligne, positionJoueur.colonne, *jActuel);
    al_flip_display();

}

void afficherPerso(Coords tabChemin[PM_MAX + 1], ALLEGRO_BITMAP *anim[], Case tabCase[LIGNES_TAB][COLONNES_TAB],
                   int ligneSouris, int colonneSouris, Image decor, int ligne, int colonne,
                   int tabArene[LIGNES_TAB][COLONNES_TAB], int PMJoueur, int compteurImage, Joueurs *listeJ,
                   Joueurs *jActuel,
        //modifs 21/05
                   rectangle rectNext, ALLEGRO_FONT *miniOrbitron, ALLEGRO_FONT *Orbitron, ALLEGRO_COLOR BLANC) {

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
    printf("positionFinale:[%d;%d]\n", positionFinale.ligne, positionFinale.colonne);
    // on boucle tant que l'on a pas atteint la position finale (tant que la taille du tab n'est pas atteinte)
    for (i = 0; i < tailleTab; i++) {
        positionJoueur = tabChemin[i];
        positionIntermediaire = tabChemin[i + 1];

        // cas ou le joueur arrive à sa position finale
        if (positionFinale.colonne == positionJoueur.colonne && positionJoueur.ligne == positionFinale.ligne) {
            printf("position atteinte\n");
            dessinerTout(tabCase, ligneSouris, colonneSouris, decor, ligne, colonne, tabArene, tabChemin,
                         positionJoueur, anim, compteurImage, listeJ, jActuel, rectNext, miniOrbitron, Orbitron,
                         BLANC);
        }

        // on va verifier à chaque fois que le perso bouge son placeement par rapport a la position finale ( deplacement horizontal / vertical...)
        if (positionIntermediaire.colonne > positionJoueur.colonne) {
            int x = (100 * (positionJoueur.colonne)) + 80; // position actuelle joueur
            while (x < ((100 * (positionJoueur.colonne)) + 80) +
                       100) { // tant que l'on a pas atteint la case suivante on deplace le perso
                dessinerMap(tabCase, ligneSouris, colonneSouris, decor, ligne, colonne, tabArene, tabChemin, listeJ,
                            jActuel);
                affichageMenuPerso(decor.sort1, decor.sort2, decor.sort3, rectNext, miniOrbitron, Orbitron, BLANC,
                                   *jActuel);
                dessinerPerso(anim, compteurImage, positionJoueur.ligne, (x - 80) / 100, *jActuel);
                al_flip_display();
                sleep(1);
                x += 150; // on l'affiche tous les 150 pixels (effet glissement)
            }
        }

        if (positionIntermediaire.colonne < positionJoueur.colonne) {
            int x = (100 * (positionJoueur.colonne)) + 80;
            while (x > ((100 * (positionJoueur.colonne)) + 80) - 100) {

                dessinerMap(tabCase, ligneSouris, colonneSouris, decor, ligne, colonne, tabArene, tabChemin, listeJ,
                            jActuel);
                affichageMenuPerso(decor.sort1, decor.sort2, decor.sort3, rectNext, miniOrbitron, Orbitron, BLANC,
                                   *jActuel);
                dessinerPerso(anim, compteurImage, positionJoueur.ligne, (x - 80) / 100, *jActuel);
                al_flip_display();
                sleep(1);
                x -= 150;
            }
        }
        if (positionIntermediaire.ligne > positionJoueur.ligne) {
            int y = (100 * (positionJoueur.ligne) - 50) + 135;
            /* y -135 = 100* (poJ) - 50
             * y - 85 = 100 * pJ
             * (y -85 )/100 = PJ */
            while (y < ((100 * (positionJoueur.ligne) - 50) + 135) + 100) {
                dessinerMap(tabCase, ligneSouris, colonneSouris, decor, ligne, colonne, tabArene, tabChemin, listeJ,
                            jActuel);
                affichageMenuPerso(decor.sort1, decor.sort2, decor.sort3, rectNext, miniOrbitron, Orbitron, BLANC,
                                   *jActuel);
                dessinerPerso(anim, compteurImage, (y - 85) / 100, positionJoueur.colonne, *jActuel);
                al_flip_display();
                sleep(1);
                y += 150;
            }
        }
        if (positionIntermediaire.ligne < positionJoueur.ligne) {
            int y = (100 * (positionJoueur.ligne) - 50) + 135;
            while (y > ((100 * (positionJoueur.ligne) - 50) + 135) - 100) {
                dessinerMap(tabCase, ligneSouris, colonneSouris, decor, ligne, colonne, tabArene, tabChemin, listeJ,
                            jActuel);
                affichageMenuPerso(decor.sort1, decor.sort2, decor.sort3, rectNext, miniOrbitron, Orbitron, BLANC,
                                   *jActuel);
                dessinerPerso(anim, compteurImage, (y - 85) / 100, positionJoueur.colonne, *jActuel);

                al_flip_display();
                sleep(1);
                y -= 150;
            }
        }
    }
    printf("position joueur: [%d; %d]\n", jActuel->positionJ.ligne, jActuel->positionJ.colonne);
    affichagePorte(tabCase, jActuel->positionJ.ligne, jActuel->positionJ.colonne, tabArene,
                   jActuel->pm);// affichage de la portée
    dessinerPerso(anim, compteurImage, jActuel->positionJ.ligne, jActuel->positionJ.colonne,
                  *jActuel); // reaffichage du perso par dessus la portée pour qu'il soit visible
    al_flip_display();
}


// fonction pour afficher toute la map + deplacement joueur
void affichage(int tabArene[LIGNES_TAB][COLONNES_TAB], int TabObstacle[LIGNES_TAB][COLONNES_TAB],
               Coords tabChemin[PM_MAX + 1], Joueurs *listeJ) {
    bool end = false;

    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_EVENT event;
    ALLEGRO_BITMAP *anim[NB_IMAGES];
    Joueurs *joueurActuel;
    //joueurActuel = *listeJ;

    // modifs pour les sorts + affichage interfaceJ 21/05
    ALLEGRO_FONT *Megrim = al_load_ttf_font("../Font/Megrim-Regular.ttf", 100, 0);
    ALLEGRO_FONT *Orbitron = al_load_ttf_font("../Font/Orbitron.ttf", 70, 0);
    ALLEGRO_FONT *miniOrbitron = al_load_ttf_font("../Font/Orbitron.ttf", 40, 0);
    ALLEGRO_FONT *microOrbitron = al_load_ttf_font("../Font/Orbitron.ttf", 15, 0);
    ALLEGRO_SAMPLE *FightSong = NULL;
    ALLEGRO_SAMPLE_INSTANCE *FightSongInstance = NULL;
    ALLEGRO_BITMAP *icon = al_load_bitmap("../Image/icone.png");
    ALLEGRO_COLOR BLANC = al_map_rgb(255, 255, 255);
    ALLEGRO_SAMPLE *tic = NULL;
    ALLEGRO_SAMPLE *clik = NULL;


    // position, compteur
    int cmptimage;
// init des bitmaps
    Image decor;
    Case tabCase[LIGNES_TAB][COLONNES_TAB] = {0};
    int xCase, yCase = Y_TAB;
    int ligneSouris = 0, colonneSouris = 0;
    int xSouris;
    int ySouris;
    int i, ligne = 0, colonne = 0, decors = 0;
    int determinerChemin = 0;
    long tempsTour = 0;
    Coords positionFinale;
    joueurActuel = listeJ;
    joueurActuel->pm = 0; // init du PM joueur pour le modifier en fonction du deplacement --> (à faire dans init des joueurs)

// init du timer
    srand(time(NULL));
    al_init();
    al_init_primitives_addon();
    al_init_image_addon();
    al_install_mouse();
    al_init_font_addon();
    al_init_ttf_addon();
//modif 21/05
    tic = al_load_sample("../Music/fast-magic.ogg");
    clik = al_load_sample("../Music/light-spell.ogg");
    FightSong = al_load_sample("../Music/The-Icy-Cave-.ogg");

    FightSongInstance = al_create_sample_instance(FightSong);
    al_set_sample_instance_playmode(FightSongInstance, ALLEGRO_PLAYMODE_LOOP);

    al_attach_sample_instance_to_mixer(FightSongInstance, al_get_default_mixer());

// chargement des images
    initialiserImages(&decor);

// init et installations
    display = al_create_display(ECRAN_LONGUEUR, ECRAN_LARGEUR);
    al_set_window_position(display, 0, 0);
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

    chargerAnimation(&listeJ, anim);
    // modif init des classes joueurs + sorts 21/05
    classe Solaris;
    classe Terra;
    classe Martian;
    classe Saturna;
    InitialiserClass(&Solaris, &Terra, &Martian, &Saturna);
    printf("init classe OK\n");
    Sorts tabsort[12];
    initialiserSort(tabsort, &Solaris, &Terra, &Martian, &Saturna);
    printf("init sorts OK\n");
    initCaracteristiquesJoueurs(&listeJ, Solaris, Terra, Martian, Saturna);

    rectangle rectechape;
    rectechape.longueur = LARGEUR / 3;
    rectechape.largeur = HAUTEUR / 2 + HAUTEUR / 4;
    rectechape.x = (LARGEUR / 2) - (rectechape.longueur / 2);
    rectechape.y = (HAUTEUR / 2) - (rectechape.largeur / 2);
    rectechape.gris = false;

    rectangle rectreprendre;
    rectreprendre.longueur = LARGEUR / 3 - LARGEUR / 8;
    rectreprendre.largeur = HAUTEUR / 4 - HAUTEUR / 10;
    rectreprendre.x = (LARGEUR / 2) - (rectreprendre.longueur / 2);
    rectreprendre.y = (HAUTEUR / 2) - (rectechape.largeur / 2) + HAUTEUR / 4;
    rectreprendre.gris = false;

    rectangle rectExit;
    rectExit.longueur = LARGEUR / 3 - LARGEUR / 8;
    rectExit.largeur = HAUTEUR / 4 - HAUTEUR / 10;
    rectExit.x = (LARGEUR / 2) - (rectExit.longueur / 2);
    rectExit.y = (HAUTEUR / 2) - (rectechape.largeur / 2) + HAUTEUR / 4 + HAUTEUR / 4;
    rectExit.gris = false;

    rectangle rectfond;
    rectfond.longueur = LARGEUR;
    rectfond.largeur = HAUTEUR;
    rectfond.x = 0;
    rectfond.y = 0;
    rectfond.gris = false;

    rectangle rectNext;
    rectNext.longueur = LARGEUR / 5 + LARGEUR / 25;
    rectNext.largeur = HAUTEUR / 6;
    rectNext.x = (3 * LARGEUR) / 4;
    rectNext.y = (2 * HAUTEUR) / 3 + (HAUTEUR / 10);
    rectNext.gris = false;

    bool peindre = false;
    bool echape = false;
    bool peindreEchape = false;
    bool ticRdy = false;
    int time = 0;


    // initialisation position joueu
    printf("jA position: [ %d ; %d]\n", joueurActuel->positionJ.ligne, joueurActuel->positionJ.colonne);
    printf("j2 position: [%d ; %d]\n", listeJ->next->positionJ.ligne, listeJ->next->positionJ.colonne);
    cmptimage = 0;
    al_start_timer(timer);
    // on dessine la Map et les persos une première fois
    dessinerTout(tabCase, ligneSouris, colonneSouris, decor, ligne, colonne, tabArene, tabChemin,
                 joueurActuel->positionJ,
                 anim, cmptimage, listeJ, joueurActuel, rectNext, miniOrbitron, Orbitron, BLANC);
// mise en place de la boucle d'evenements
    while (!end) {
        al_wait_for_event(queue, &event);
        al_play_sample_instance(FightSongInstance);
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE: {
                end = true;
                break;
            }
                //modifs 22/05
                //detecter si touche escape enfoncé
            case ALLEGRO_EVENT_KEY_DOWN: {
                if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                    al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                    if (!echape) {
                        echape = true;
                        peindreEchape = true;
                    } else {
                        echape = false;
                        peindre = true;
                    }
                }
                break;
            }


            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: {

                printf("allegro button down\n");
                xSouris = event.mouse.x + TAILLE_CASE;
                ySouris = event.mouse.y + TAILLE_CASE;
                //modifs 22/05

                //pour detecter le clic si on a cliquer sur escape
                if (echape) {
                    if (hitBoxR(rectreprendre, event.mouse.x, event.mouse.y)) {
                        al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                        echape = false;
                        peindre = true;
                    }
                    if (hitBoxR(rectExit, event.mouse.x, event.mouse.y)) {
                        al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                        end = true;
                    }
                } else {
                    if (hitBoxR(rectNext, event.mouse.x, event.mouse.y)) {
                        al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                        passerJnext(&joueurActuel, listeJ);
                        printf("joueur suivant\n");
                        peindre = true;
                    }
                }
                // pour determiner si on a cliquer  sur un sort
                int classe = -1;

                classe = joueurActuel->classeJ.numClasse;

                /*if (event.mouse.x >= LARGEUR * (0.659) && event.mouse.x <= LARGEUR * (0.659) + 100 &&
                    event.mouse.y >= HAUTEUR * (0.538) &&
                    event.mouse.y <= HAUTEUR * (0.538) + 100) {
*/
                if (event.mouse.x >= LARGEUR * (0.72) && event.mouse.x <= LARGEUR * (0.72) + 100 &&
                    event.mouse.y >= HAUTEUR * (0.538) &&
                    event.mouse.y <= HAUTEUR * (0.538) + 100) {

                    printf(" SORT 1 OK : %s", joueurActuel->classeJ.sort[0].nom);

                    switch (classe) {

                        case 0 : {
                            Eblouisssement(joueurActuel, listeJ);
                            break;
                        }
                        case 1 : {
                            Guerison(joueurActuel);
                            break;
                        }
                        case 2 : {

                            Etincelle(joueurActuel, listeJ);
                            break;
                        }
                        case 3 : {

                            Elipse(joueurActuel, listeJ);
                            break;
                        }
                    }

                    dessinerTout(tabCase, ligneSouris, colonneSouris, decor, ligne, colonne, tabArene, tabChemin,
                                 joueurActuel->positionJ,
                                 anim, cmptimage, listeJ, joueurActuel, rectNext, miniOrbitron, Orbitron, BLANC);
                }
                /*if (event.mouse.x >= LARGEUR * (0.783) && event.mouse.x <= LARGEUR * (0.783) + 100 &&
                    event.mouse.y >= HAUTEUR * (0.538) &&
                    event.mouse.y <= HAUTEUR * (0.538) + 100) {
*/
                if (event.mouse.x >= LARGEUR * (0.82) && event.mouse.x <= LARGEUR * (0.82) + 100 &&
                    event.mouse.y >= HAUTEUR * (0.538) &&
                    event.mouse.y <= HAUTEUR * (0.538) + 100) {
                    printf(" SORT 2 OK: %s", joueurActuel->classeJ.sort[1].nom);

                    switch (classe) {

                        case 0 : {
                            Scintillement(joueurActuel, listeJ);
                            break;
                        }
                        case 1 : {

                            FlecheEmpoisonnee(joueurActuel, listeJ);
                            break;
                        }
                        case 2 : {
                            Lava(joueurActuel, listeJ);
                            break;
                        }
                        case 3 : {

                            CercleVicieux(joueurActuel);
                            break;
                        }
                            dessinerTout(tabCase, ligneSouris, colonneSouris, decor, ligne, colonne, tabArene,
                                         tabChemin,
                                         joueurActuel->positionJ,
                                         anim, cmptimage, listeJ, joueurActuel, rectNext, miniOrbitron, Orbitron,
                                         BLANC);

                    }
                }

                /* if (event.mouse.x >= LARGEUR * (0.89) && event.mouse.x <= LARGEUR * (0.89) + 100 &&
                     event.mouse.y >= HAUTEUR * (0.538) &&
                     event.mouse.y <= HAUTEUR * (0.538) + 100) {
 */
                if (event.mouse.x >= LARGEUR * (0.92) && event.mouse.x <= LARGEUR * (0.92) + 100 &&
                    event.mouse.y >= HAUTEUR * (0.538) &&
                    event.mouse.y <= HAUTEUR * (0.538) + 100) {
                    printf(" SORT 3 OK: %s", joueurActuel->classeJ.sort[2].nom);

                    switch (classe) {

                        case 0 : {

                            ExtraSolar(joueurActuel, listeJ);
                            break;
                        }
                        case 1 : {

                            TirDroit(joueurActuel, listeJ);
                            break;
                        }
                        case 2 : {

                            LanceFlamme(joueurActuel, listeJ);
                            break;
                        }
                        case 3 : {
                            DisqueTranchant(joueurActuel, listeJ);
                            break;
                        }

                    }
                }
                // debut de determiner le chemin --> DEPLACEMENT
                for (int i = 0; i < LIGNES_TAB; ++i) {
                    if (tabCase[i][0].y < ySouris && ySouris > tabCase[i][0].y + TAILLE_CASE) {
                        ligneSouris = i;
                        positionFinale.ligne = i + 1;
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
                if (joueurActuel->pm < PM_MAX && (joueurActuel->positionJ.colonne != positionFinale.colonne ||
                                                  joueurActuel->positionJ.ligne != positionFinale.ligne)) {
// on va determiner le chemin si la position finale n'est pas atteinte et si le deplacement est possible
                    while (determinerChemin == 0 && joueurActuel->pm < PM_MAX &&
                           (joueurActuel->positionJ.colonne != positionFinale.colonne ||
                            joueurActuel->positionJ.ligne != positionFinale.ligne)) {

                        initialiserTabChemin(tabChemin);
                        // on determine le chemin a parcourir
                        determinerChemin = determinerLeChemin(&(joueurActuel)->positionJ, &(joueurActuel)->pm,
                                                              positionFinale, TabObstacle,
                                                              tabChemin);

                        // on verifie que le tab chemin n'est pas vide si oui pas de deplacement effectué
                        if (tabChemin[0].colonne == CASE_VIDE) {
                        }
                    }
                    // si le deplacement est possible et si le nb de PM n'est pas dépassé alors on va faire glisser le joueur sur la case cliquée
                    /*if (tabCase[ligneSouris][colonneSouris].deplacement == true) {
                        joueurActuel.positionJ.ligne = ligneSouris;
                        joueurActuel.positionJ.colonne = colonneSouris;
                    }*/
                    if (determinerChemin == 0 && joueurActuel->pm <= PM_MAX) {
                        afficherPerso(tabChemin, anim, tabCase, ligneSouris, colonneSouris, decor,
                                      ligne, colonne, tabArene, joueurActuel->pm, cmptimage, listeJ, joueurActuel,
                                      rectNext, miniOrbitron, Orbitron, BLANC);
                    }
                    if (joueurActuel->pm >= PM_MAX) {
                        joueurActuel->pm = 0;
                    }
                }
                break;
            }
                //modifs 22/05

           case ALLEGRO_EVENT_MOUSE_AXES: {
    // afficher le nom du sort en fonction du sort cliqué
                if (event.mouse.x >= LARGEUR * (0.82) && event.mouse.x <= LARGEUR * (0.82) + 100 &&
                    event.mouse.y >= HAUTEUR * (0.35) &&
                    event.mouse.y <= HAUTEUR * (0.35) + 100) {
                    al_draw_text(Megrim, BLANC, LARGEUR*(0.75), HAUTEUR*(0.42), 0, joueurActuel->classeJ.sort[0].nom);
                    al_draw_text(miniOrbitron,BLANC,LARGEUR*(0.76),HAUTEUR*(0.5),0,"Dégats : ");
                    al_draw_textf(miniOrbitron, BLANC, LARGEUR * (0.95), HAUTEUR * (0.5), ALLEGRO_ALIGN_RIGHT, "%d", joueurActuel->classeJ.sort[0].degat);
                    al_draw_text(miniOrbitron,BLANC,LARGEUR*(0.76),HAUTEUR*(0.55),0,"Consomation : ");
                    al_draw_textf(miniOrbitron, BLANC, LARGEUR * (0.95), HAUTEUR * (0.55), ALLEGRO_ALIGN_RIGHT, "%d", joueurActuel->classeJ.sort[0].PA);
                    al_draw_text(miniOrbitron,BLANC,LARGEUR*(0.76),HAUTEUR*(0.6),0,"Portée : ");
                    al_draw_textf(miniOrbitron, BLANC, LARGEUR * (0.95), HAUTEUR * (0.6), ALLEGRO_ALIGN_RIGHT, "%d", joueurActuel->classeJ.sort[0].portee);
                    al_flip_display();
                }

              else  if (event.mouse.x >= LARGEUR * (0.87) && event.mouse.x <= LARGEUR * (0.87) + 100 &&
                    event.mouse.y >= HAUTEUR * (0.35) &&
                    event.mouse.y <= HAUTEUR * (0.35) + 100) {
                    if (joueurActuel->classeJ.numClasse == 1) {
                        al_draw_text(Megrim, BLANC, LARGEUR*(0.75), HAUTEUR*(0.42), 0,"Flèche");
                        al_draw_text(Megrim, BLANC, LARGEUR*(0.75), HAUTEUR*(0.48), 0,"empoisonée");
                        al_draw_text(miniOrbitron,BLANC,LARGEUR*(0.76),HAUTEUR*(0.55),0,"Dégats : ");
                        al_draw_textf(miniOrbitron, BLANC, LARGEUR * (0.95), HAUTEUR * (0.55), ALLEGRO_ALIGN_RIGHT, "%d", joueurActuel->classeJ.sort[1].degat);
                        al_draw_text(miniOrbitron,BLANC,LARGEUR*(0.76),HAUTEUR*(0.6),0,"Consomation : ");
                        al_draw_textf(miniOrbitron, BLANC, LARGEUR * (0.95), HAUTEUR * (0.6), ALLEGRO_ALIGN_RIGHT, "%d", joueurActuel->classeJ.sort[1].PA);
                        al_draw_text(miniOrbitron,BLANC,LARGEUR*(0.76),HAUTEUR*(0.65),0,"Portée : ");
                        al_draw_textf(miniOrbitron, BLANC, LARGEUR * (0.95), HAUTEUR * (0.65), ALLEGRO_ALIGN_RIGHT, "%d", joueurActuel->classeJ.sort[1].portee);
                    } else {
                        al_draw_text(Megrim, BLANC, LARGEUR*(0.75), HAUTEUR*(0.42), 0, joueurActuel->classeJ.sort[1].nom);
                        al_draw_text(miniOrbitron,BLANC,LARGEUR*(0.76),HAUTEUR*(0.5),0,"Dégats : ");
                        al_draw_textf(miniOrbitron, BLANC, LARGEUR * (0.95), HAUTEUR * (0.5), ALLEGRO_ALIGN_RIGHT, "%d", joueurActuel->classeJ.sort[1].degat);
                        al_draw_text(miniOrbitron,BLANC,LARGEUR*(0.76),HAUTEUR*(0.55),0,"Consomation : ");
                        al_draw_textf(miniOrbitron, BLANC, LARGEUR * (0.95), HAUTEUR * (0.55), ALLEGRO_ALIGN_RIGHT, "%d", joueurActuel->classeJ.sort[1].PA);
                        al_draw_text(miniOrbitron,BLANC,LARGEUR*(0.76),HAUTEUR*(0.6),0,"Portée : ");
                        al_draw_textf(miniOrbitron, BLANC, LARGEUR * (0.95), HAUTEUR * (0.6), ALLEGRO_ALIGN_RIGHT, "%d", joueurActuel->classeJ.sort[1].portee);
                    }
                    al_flip_display();
                
                }
               else if (event.mouse.x >= LARGEUR * (0.92) && event.mouse.x <= LARGEUR * (0.92) + 100 &&
                    event.mouse.y >= HAUTEUR * (0.35) &&
                    event.mouse.y <= HAUTEUR * (0.35) + 100) {
                    if (joueurActuel->classeJ.numClasse == 3) {
                        al_draw_text(Megrim, BLANC,LARGEUR*(0.75), HAUTEUR*(0.42), 0,"Disque");
                        al_draw_text(Megrim, BLANC,LARGEUR*(0.75), HAUTEUR*(0.48), 0,"tranchant");
                        al_draw_text(miniOrbitron,BLANC,LARGEUR*(0.76),HAUTEUR*(0.55),0,"Dégats : ");
                        al_draw_textf(miniOrbitron, BLANC, LARGEUR * (0.95), HAUTEUR * (0.55), ALLEGRO_ALIGN_RIGHT, "%d", joueurActuel->classeJ.sort[2].degat);
                        al_draw_text(miniOrbitron,BLANC,LARGEUR*(0.76),HAUTEUR*(0.6),0,"Consomation : ");
                        al_draw_textf(miniOrbitron, BLANC, LARGEUR * (0.95), HAUTEUR * (0.6), ALLEGRO_ALIGN_RIGHT, "%d", joueurActuel->classeJ.sort[2].PA);
                        al_draw_text(miniOrbitron,BLANC,LARGEUR*(0.76),HAUTEUR*(0.65),0,"Portée : ");
                        al_draw_textf(miniOrbitron, BLANC, LARGEUR * (0.95), HAUTEUR * (0.65), ALLEGRO_ALIGN_RIGHT, "%d", joueurActuel->classeJ.sort[2].portee);
                    } else {
                        al_draw_text(Megrim, BLANC, LARGEUR * (0.75), HAUTEUR * (0.42), 0,
                                     joueurActuel->classeJ.sort[2].nom);
                        al_draw_text(miniOrbitron, BLANC, LARGEUR * (0.76), HAUTEUR * (0.5), 0, "Dégats : ");
                        al_draw_textf(miniOrbitron, BLANC, LARGEUR * (0.95), HAUTEUR * (0.5), ALLEGRO_ALIGN_RIGHT, "%d",
                                      joueurActuel->classeJ.sort[2].degat);
                        al_draw_text(miniOrbitron, BLANC, LARGEUR * (0.76), HAUTEUR * (0.55), 0, "Consomation : ");
                        al_draw_textf(miniOrbitron, BLANC, LARGEUR * (0.95), HAUTEUR * (0.55), ALLEGRO_ALIGN_RIGHT,
                                      "%d", joueurActuel->classeJ.sort[2].PA);
                        al_draw_text(miniOrbitron, BLANC, LARGEUR * (0.76), HAUTEUR * (0.6), 0, "Portée : ");
                        al_draw_textf(miniOrbitron, BLANC, LARGEUR * (0.95), HAUTEUR * (0.6), ALLEGRO_ALIGN_RIGHT, "%d",
                                      joueurActuel->classeJ.sort[2].portee);
                    }
                    al_flip_display();

                } else {
                    dessinerTout(tabCase, ligneSouris, colonneSouris, decor, ligne, colonne, tabArene, tabChemin,
                                 joueurActuel->positionJ,
                                 anim, cmptimage, listeJ, joueurActuel, rectNext, miniOrbitron, Orbitron, BLANC);

                }

                // determiner sur quel sort le joueur clique en fonction de la position souris et afficher des couleurs/son
                if (echape) {
                    if (hitBoxR(rectExit, event.mouse.x, event.mouse.y) && rectExit.gris == false) {
                        rectExit.gris = true;
                        if (ticRdy) {
                            al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            ticRdy = false;
                        }
                    }
                    if (hitBoxR(rectreprendre, event.mouse.x, event.mouse.y) && rectreprendre.gris == false) {
                        rectreprendre.gris = true;
                        if (ticRdy) {
                            al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            ticRdy = false;
                        }
                    }
                    if (!(hitBoxR(rectExit, event.mouse.x, event.mouse.y)) && rectExit.gris == true) {
                        rectExit.gris = false;
                        if (!(ticRdy)) {
                            ticRdy = true;
                        }
                    }
                    if (!(hitBoxR(rectreprendre, event.mouse.x, event.mouse.y)) && rectreprendre.gris == true) {
                        rectreprendre.gris = false;
                        if (!(ticRdy)) {
                            ticRdy = true;
                        }
                    }
                } else {
                    if (hitBoxR(rectNext, event.mouse.x, event.mouse.y) && rectNext.gris == false) {
                        rectNext.gris = true;
                        if (ticRdy) {
                            al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            ticRdy = false;
                        }
                    }
                    if (!(hitBoxR(rectNext, event.mouse.x, event.mouse.y)) && rectNext.gris == true) {
                        rectNext.gris = false;
                        if (!(ticRdy)) {
                            ticRdy = true;
                        }
                    }
                }
                break;
            }
            case ALLEGRO_EVENT_TIMER: {
                cmptimage = (cmptimage + 1) % NB_IMAGES;
                tempsTour = al_get_timer_count(timer)%1800;
                if (tempsTour == 1799) {
                    joueurActuel = joueurActuel->next;
                }
                break;
            }
        }
    }
    destroy(decor, display, timer, queue, Megrim, Orbitron, miniOrbitron, microOrbitron, FightSong,
            FightSongInstance, tic, clik);
}
