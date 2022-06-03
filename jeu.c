#include "general.h"
#include "deplacement.h"
#include "affichage.h"
#include "arene.h"

void JEU(Joueurs* listeJ){
    Coords positionJoueur;
    Joueurs joueurActuel;
    Coords tabChemin[PM_MAX];
    int tabArene[LIGNES_TAB][COLONNES_TAB];
    int TabObstacle[LIGNES_TAB][COLONNES_TAB];
    //création de l'arène
    intialisationArene(tabArene, TabObstacle);
    //affichage du jeu complet + deplacement du joueur
    affichage(tabArene, TabObstacle, tabChemin, listeJ);
    destructionListe(&listeJ);
}

void libererListe( Joueurs ** liste){
        Joueurs * stock=NULL;
        while (*liste != NULL){
            stock= (*liste)->next;
            free(*liste);
            *liste= stock;
        }
        * liste =NULL;
}
void destroy(Image decors, ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *queue, ALLEGRO_FONT *Megrim, ALLEGRO_FONT *Orbitron, ALLEGRO_FONT *miniOrbitron,
             ALLEGRO_FONT *microOrbitron, ALLEGRO_SAMPLE *FightSong, ALLEGRO_SAMPLE_INSTANCE *FightSongInstance,
             ALLEGRO_SAMPLE *tic, ALLEGRO_SAMPLE *clik) {
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_bitmap(decors.perso);
    al_destroy_bitmap(decors.Soleil);
    al_destroy_bitmap(decors.rocher);
    al_destroy_bitmap(decors.meteor);
    al_destroy_bitmap(decors.cailloux);
    al_destroy_bitmap(decors.fleur);
    al_destroy_event_queue(queue);
    al_destroy_font(Megrim);
    al_destroy_font(Orbitron);
    al_destroy_font(miniOrbitron);
    al_destroy_font(microOrbitron);
    al_destroy_sample(FightSong);
    al_destroy_sample_instance(FightSongInstance);
    al_destroy_sample(tic);
    al_destroy_sample(clik);
}

/*void JEU2(Joueurs* listeJ){
    Coords positionJoueur;
    Coords tabChemin[PM_MAX];
    int tabArene[LIGNES_TAB][COLONNES_TAB];
    int TabObstacle[LIGNES_TAB][COLONNES_TAB];
    intialisationArene(tabArene, TabObstacle);
    bool end = false;
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_KEYBOARD_STATE keyboard;
    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_EVENT event;
    ALLEGRO_MOUSE_STATE mouse;
    ALLEGRO_TIMER* timer = NULL;
    ALLEGRO_FONT* Megrim = al_load_ttf_font("../Font/Megrim-Regular.ttf", 100, 0);
    ALLEGRO_FONT* Orbitron = al_load_ttf_font("../Font/Orbitron.ttf", 70, 0);
    ALLEGRO_FONT* miniOrbitron = al_load_ttf_font("../Font/Orbitron.ttf", 40, 0);
    ALLEGRO_FONT* microOrbitron = al_load_ttf_font("../Font/Orbitron.ttf", 15, 0);
    ALLEGRO_SAMPLE* FightSong = NULL;
    ALLEGRO_SAMPLE_INSTANCE* FightSongInstance = NULL;
    ALLEGRO_BITMAP *sort1, *sort2, *sort3;
    ALLEGRO_BITMAP* arene = al_load_bitmap("../Image/background_arene.jpg");
    ALLEGRO_BITMAP* icon = al_load_bitmap("../Image/icone.png");
    ALLEGRO_COLOR BLANC= al_map_rgb(255,255,255);
    ALLEGRO_SAMPLE* tic = NULL;
    ALLEGRO_SAMPLE* clik = NULL;

    srand(time(NULL));

    assert(Megrim);
    assert(Orbitron);
    if (!al_install_keyboard()) {
        al_install_keyboard();
    }
    assert(al_install_keyboard());

    if (!al_install_mouse()) {
        al_install_mouse();
    }
    assert(al_install_mouse());

    sort1 = al_load_bitmap("../Image/feu.png");
    sort2 = al_load_bitmap("../Image/vent.png");
    sort3 = al_load_bitmap("../Image/flaqueorageuse.png");

    tic = al_load_sample("../Music/fast-magic.ogg");
    clik = al_load_sample("../Music/light-spell.ogg");
    FightSong = al_load_sample("../Music/The-Icy-Cave-.ogg");
    assert(FightSong);

    FightSongInstance = al_create_sample_instance(FightSong);
    al_set_sample_instance_playmode(FightSongInstance,ALLEGRO_PLAYMODE_LOOP);

    al_attach_sample_instance_to_mixer(FightSongInstance, al_get_default_mixer());

    display = al_create_display(LARGEUR, HAUTEUR);
    assert(display != NULL);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_set_window_title(display, "Stellar Wars");
    al_set_display_icon(display, icon);
    al_set_window_position(display, 0, 0);

    timer = al_create_timer(1.0/60.0);
    al_start_timer(timer);

    queue = al_create_event_queue();
    assert(queue != NULL);
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());


    classe Solaris;
    classe Terra;
    classe Martian;
    classe Saturna;
    InitialiserClass(&Solaris, &Terra, &Martian, &Saturna);
    Sorts tabsort[12];
    initialiserSort(tabsort, &Solaris, &Terra, &Martian, &Saturna);
    Joueurs JA = *listeJ;

    rectangle rectechape;
    rectechape.longueur = LARGEUR/3;
    rectechape.largeur = HAUTEUR/2 + HAUTEUR/4;
    rectechape.x = (LARGEUR/2) - (rectechape.longueur/2);
    rectechape.y = (HAUTEUR/2)- (rectechape.largeur/2);
    rectechape.gris=false;

    rectangle rectreprendre;
    rectreprendre.longueur = LARGEUR/3-LARGEUR/8;
    rectreprendre.largeur = HAUTEUR/4 - HAUTEUR/10;
    rectreprendre.x = (LARGEUR/2) - (rectreprendre.longueur/2);
    rectreprendre.y = (HAUTEUR/2)- (rectechape.largeur/2)+HAUTEUR/4;
    rectreprendre.gris=false;

    rectangle rectExit;
    rectExit.longueur = LARGEUR/3-LARGEUR/8;
    rectExit.largeur = HAUTEUR/4 - HAUTEUR/10;
    rectExit.x = (LARGEUR/2) - (rectExit.longueur/2);
    rectExit.y = (HAUTEUR/2) - (rectechape.largeur/2)+HAUTEUR/4+HAUTEUR/4;
    rectExit.gris = false;

    rectangle rectfond;
    rectfond.longueur = LARGEUR;
    rectfond.largeur = HAUTEUR;
    rectfond.x = 0;
    rectfond.y = 0;
    rectfond.gris=false;

    rectangle rectNext;
    rectNext.longueur = LARGEUR/5+LARGEUR/25;
    rectNext.largeur = HAUTEUR/6;
    rectNext.x = (3*LARGEUR)/4;
    rectNext.y = (2*HAUTEUR)/3+(HAUTEUR/10);
    rectNext.gris=false;

    affichageG(arene, sort1, sort2, sort3, rectNext, miniOrbitron, Orbitron, BLANC, JA);
    bool peindre=false;
    bool echape=false;
    bool peindreEchape=false;
    bool ticRdy=false;
    int time=0;

    Image decor;
    Case tabCase[LIGNES_TAB][COLONNES_TAB] = {0};
    int xCase, yCase = Y_TAB;
    int ligneSouris = 0, colonneSouris = 0;
    int xSouris;
    int ySouris;
    int i, ligne = 0, colonne = 0, PM = 0, decors = 0;
    int determinerChemin = 0;
    Coords positionFinale;

    while(!end){
        al_wait_for_event(queue, &event);
        al_play_sample_instance(FightSongInstance);
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                al_stop_sample_instance(FightSongInstance);
                end = true;
                break;
            case ALLEGRO_EVENT_KEY_DOWN:
                if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                    al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                    if (!echape) {
                        echape = true;
                        peindreEchape=true;
                    }else{
                        echape = false;
                        peindre = true;
                    }
                }
                break;
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                if(echape) {
                    if (hitBoxR(rectreprendre, event.mouse.x, event.mouse.y)) {
                        al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                        echape = false;
                        peindre = true;
                    }
                    if (hitBoxR(rectExit, event.mouse.x, event.mouse.y)) {
                        al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                        end = true;
                    }
                }
                else{
                    if (hitBoxR(rectNext, event.mouse.x, event.mouse.y)) {
                        al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                        passerJnext(JA,listeJ);
                        peindre=true;
                    }
                }
                break;

            case ALLEGRO_EVENT_MOUSE_AXES:
                if(echape){
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
                }
                else{
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
            case ALLEGRO_EVENT_TIMER:
                time = al_get_timer_count(timer)%1800;
                if (time == 1799) {
                    JA = *JA.next;
                    peindre=true;
                }
                if(peindre){
                    affichageG(arene, sort1, sort2, sort3, rectNext, miniOrbitron, Orbitron, BLANC, JA);
                    peindre = false;
                }
                if(echape){
                    if (peindreEchape) {
                        affichageEchape(rectechape, rectfond, miniOrbitron, Orbitron);
                        peindreEchape = false;
                    }
                    actuaRectEchape(rectreprendre, rectExit, miniOrbitron);
                }
                else{
                    actuaRect(rectNext, miniOrbitron);
                }
                break;
        }
    }
    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    al_destroy_font(Megrim);
    al_destroy_font(Orbitron);
    al_destroy_font(miniOrbitron);
    al_destroy_font(microOrbitron);
    al_destroy_sample(FightSong);
    al_destroy_sample_instance(FightSongInstance);
    al_destroy_sample(tic);
    al_destroy_sample(clik);
    al_destroy_bitmap(sort1);
    al_destroy_bitmap(sort2);
    al_destroy_bitmap(sort3);
    al_destroy_bitmap(arene);
    al_destroy_bitmap(icon);
}

*/