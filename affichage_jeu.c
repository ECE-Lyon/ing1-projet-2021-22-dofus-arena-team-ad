#include "general.h"

void affichageMenuPerso(ALLEGRO_BITMAP *sort1, ALLEGRO_BITMAP*sort2, ALLEGRO_BITMAP*sort3, rectangle rectNext, ALLEGRO_FONT* miniOrbitron,
                        ALLEGRO_FONT* Orbitron,
                        ALLEGRO_COLOR BLANC, Joueurs JA){
    al_draw_text(Orbitron, BLANC,1450,50, ALLEGRO_ALIGN_RIGHT, JA.nom);
    al_draw_text(miniOrbitron, BLANC,1300,150, ALLEGRO_ALIGN_RIGHT, "PV :");
    al_draw_textf(miniOrbitron,BLANC, 1380,150, ALLEGRO_ALIGN_RIGHT, "%d", JA.pv);
    al_draw_text(miniOrbitron, BLANC,1300,250,ALLEGRO_ALIGN_RIGHT, "PA : ");
    al_draw_textf(miniOrbitron,BLANC, 1350,250, ALLEGRO_ALIGN_RIGHT, "%d", JA.pa);
    al_draw_text(miniOrbitron, BLANC,1300,350,ALLEGRO_ALIGN_RIGHT, "PM : ");
    al_draw_textf(miniOrbitron,BLANC, 1350,350, ALLEGRO_ALIGN_RIGHT, "%d", JA.pm);
    al_draw_bitmap(sort1, 1050, 450, ALLEGRO_ALIGN_RIGHT);
    al_draw_bitmap(sort2, 1200,450, ALLEGRO_ALIGN_RIGHT);
    al_draw_bitmap(sort3,1350, 450, ALLEGRO_ALIGN_RIGHT);
    drawrectangle(rectNext, miniOrbitron, "Fin du Tour");
}

void affichageArene(ALLEGRO_BITMAP* arene){
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_scaled_bitmap(arene,0,0,2880,1694,0,0,LARGEUR,HAUTEUR,0);
}

void affichageMatrice(){
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

void affichageG(ALLEGRO_BITMAP* arene, ALLEGRO_BITMAP *sort1, ALLEGRO_BITMAP*sort2, ALLEGRO_BITMAP*sort3, rectangle rectNext, ALLEGRO_FONT*
miniOrbitron,
                ALLEGRO_FONT* Orbitron,
                ALLEGRO_COLOR BLANC, Joueurs JA){
    affichageArene(arene);
    affichageMenuPerso(sort1, sort2, sort3, rectNext, miniOrbitron, Orbitron, BLANC, JA);
    affichageMatrice();
    al_flip_display();
}

void affichageEchape(rectangle rectechape, rectangle rectfond, ALLEGRO_FONT* miniOrbitron, ALLEGRO_FONT* Orbitron){
    al_draw_filled_rectangle(rectfond.x, rectfond.y, rectfond.x + rectfond.longueur, rectfond.y + rectfond.largeur, al_map_rgba(0, 0, 0, 100));
    drawrectangle(rectechape, miniOrbitron, "");
    al_draw_text(Orbitron, al_map_rgb(255,255,255),LARGEUR/2,HAUTEUR/4-HAUTEUR/10,ALLEGRO_ALIGN_CENTER,"PAUSE");
}

void actuaRectEchape(rectangle rectreprendre, rectangle rectExit, ALLEGRO_FONT* miniOrbitron){
    drawrectangle(rectreprendre, miniOrbitron, "Reprendre");
    drawrectangle(rectExit, miniOrbitron, "EXIT");
    al_flip_display();
}

void actuaRect(rectangle rectNext, ALLEGRO_FONT* miniOrbitron){
    drawrectangle(rectNext, miniOrbitron, "Fin du Tour");
    al_flip_display();
}

