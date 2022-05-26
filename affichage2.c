#include "general.h"

void affichageMenu0(ALLEGRO_BITMAP* background, rectangle rectNom1, rectangle rectNom2, ALLEGRO_FONT* Megrim,ALLEGRO_FONT* Orbitron){
    al_draw_scaled_bitmap(background,0,0,1300,800,0,0,LARGEUR,HAUTEUR,ALLEGRO_FLIP_HORIZONTAL);
    al_draw_filled_rectangle(rectNom1.x, rectNom1.y, rectNom1.x + rectNom1.longueur, rectNom1.y + rectNom1.largeur, al_map_rgb(224,176,255));
    al_draw_rectangle(rectNom1.x, rectNom1.y, rectNom1.x + rectNom1.longueur, rectNom1.y + rectNom1.largeur, al_map_rgb(127,0,255), 2);
    al_draw_filled_rectangle(rectNom2.x, rectNom2.y, rectNom2.x + rectNom2.longueur, rectNom2.y + rectNom2.largeur, al_map_rgb(224,176,255));
    al_draw_rectangle(rectNom2.x, rectNom2.y, rectNom2.x + rectNom2.longueur, rectNom2.y + rectNom2.largeur, al_map_rgb(127,0,255), 2);
    al_draw_text(Megrim, al_map_rgb(255,255,255), 10, 10, ALLEGRO_ALIGN_LEFT, "STELLAR WARS");
    al_flip_display();
}

void textCredit(rectangle r, ALLEGRO_FONT* microOrbiton){
    al_draw_text(microOrbiton, al_map_rgb(255,255,255), LARGEUR/2, r.y+ r.largeur/30, ALLEGRO_ALIGN_CENTER, "Jeu basé sur le système de combat de "
                                                                                                            "Dofus");
    al_draw_text(microOrbiton, al_map_rgb(255,255,255), LARGEUR/2, r.y+ r.largeur/30+(HAUTEUR/10), ALLEGRO_ALIGN_CENTER, "Codé par :");
    al_draw_text(microOrbiton, al_map_rgb(255,255,255), LARGEUR/2, r.y+ r.largeur/30+((HAUTEUR/20)*1)+(HAUTEUR/10), ALLEGRO_ALIGN_CENTER, "Vadim LE"
                                                                                                                                          " MOULLEC,");
    al_draw_text(microOrbiton, al_map_rgb(255,255,255), LARGEUR/2, r.y+ r.largeur/30+((HAUTEUR/20)*2)+(HAUTEUR/10), ALLEGRO_ALIGN_CENTER, "Mona LIAS,");
    al_draw_text(microOrbiton, al_map_rgb(255,255,255), LARGEUR/2, r.y+ r.largeur/30+((HAUTEUR/20)*3)+(HAUTEUR/10), ALLEGRO_ALIGN_CENTER, "Eva DARMON,");
    al_draw_text(microOrbiton, al_map_rgb(255,255,255), LARGEUR/2, r.y+ r.largeur/30+((HAUTEUR/20)*4)+(HAUTEUR/10), ALLEGRO_ALIGN_CENTER, "Esteban MARTIN GARCIA,");
    al_draw_text(microOrbiton, al_map_rgb(255,255,255), LARGEUR/2, r.y+ r.largeur/30+((HAUTEUR/20)*4)+2*(HAUTEUR/10), ALLEGRO_ALIGN_CENTER, "Arène créé par "
                                                                                                                                 "Vadim LE "
                                                                                                                      "MOULLEC");
    al_draw_text(microOrbiton, al_map_rgb(255,255,255), LARGEUR/2, r.y+ r.largeur/30+((HAUTEUR/20)*5)+(HAUTEUR/10)*2, ALLEGRO_ALIGN_CENTER, "(À partir des tuiles de "
                                                                                                                        "Pokémon)");
    al_draw_text(microOrbiton, al_map_rgb(255,255,255), LARGEUR/2, r.y+ r.largeur/30+((HAUTEUR/20)*5)+(HAUTEUR/10)*3, ALLEGRO_ALIGN_CENTER, "Musique de xDeviruchi");
    al_draw_text(microOrbiton, al_map_rgb(255,255,255), LARGEUR/2, r.y+ r.largeur/30+((HAUTEUR/20)*5)+(HAUTEUR/10)*4, ALLEGRO_ALIGN_CENTER, "Dessin"
                                                                                                                                            " d'accueil de Trix");
}

void affichageMenu2(ALLEGRO_BITMAP* background, rectangle mini, rectangle CarreCredit, ALLEGRO_FONT* Megrim,ALLEGRO_FONT* miniOrbitron,
                    ALLEGRO_FONT* microOrbitron){
    al_draw_scaled_bitmap(background,0,0,1300,800,0,0,LARGEUR,HAUTEUR,ALLEGRO_FLIP_HORIZONTAL);
    al_draw_filled_rectangle(CarreCredit.x, CarreCredit.y, CarreCredit.x + CarreCredit.longueur, CarreCredit.y + CarreCredit.largeur, al_map_rgb(242, 184, 216));
    al_draw_rectangle(CarreCredit.x, CarreCredit.y, CarreCredit.x + CarreCredit.longueur, CarreCredit.y + CarreCredit.largeur, al_map_rgb(127,0,255), 2);
    textCredit(CarreCredit, miniOrbitron);
    al_draw_text(Megrim, al_map_rgb(255,255,255), 10, 10, ALLEGRO_ALIGN_LEFT, "STELLAR WARS");
    al_flip_display();
}

void ecritMini(int menu, rectangle mini, ALLEGRO_FONT* miniOrbitron){
    switch (menu){
        case 0:
            if (mini.gris) {
                al_draw_text(miniOrbitron, al_map_rgb(255, 255, 255), mini.x + mini.longueur / 8, mini.y + mini.largeur / 6,
                             ALLEGRO_ALIGN_LEFT, "Credit");
            }
            if (!mini.gris) {
                al_draw_text(miniOrbitron, al_map_rgb(0, 0, 0), mini.x + mini.longueur / 8, mini.y + mini.largeur / 6,
                             ALLEGRO_ALIGN_LEFT, "Credit");
            }
            break;
        case 1 :
        case 2 :
        case 3:
        case 4:
        case 5:
        case 6:
            if (mini.gris) {
                al_draw_text(miniOrbitron, al_map_rgb(255, 255, 255), mini.x + mini.longueur / 8, mini.y + mini.largeur / 6,
                             ALLEGRO_ALIGN_LEFT, "Retour");
            }
            if (!mini.gris) {
                al_draw_text(miniOrbitron, al_map_rgb(0, 0, 0), mini.x + mini.longueur / 8, mini.y + mini.largeur / 6,
                             ALLEGRO_ALIGN_LEFT, "Retour");
            }
            break;
    }
}

void ecritMini2(int menu, rectangle mini2, ALLEGRO_FONT* miniOrbitron, int nbJ){
    switch (menu){
        case 3:
            if(nbJ==1){
                if (mini2.gris) {
                    al_draw_text(miniOrbitron, al_map_rgb(255, 255, 255), mini2.x + mini2.longueur / 8, mini2.y + mini2.largeur / 6,
                                 ALLEGRO_ALIGN_LEFT, "Jouer");
                }
                if (!mini2.gris) {
                    al_draw_text(miniOrbitron, al_map_rgb(0, 0, 0), mini2.x + mini2.longueur / 8, mini2.y + mini2.largeur / 6,
                                 ALLEGRO_ALIGN_LEFT, "Jouer");
                }
            }
            else {
                if (mini2.gris) {
                    al_draw_text(miniOrbitron, al_map_rgb(255, 255, 255), mini2.x + mini2.longueur / 8, mini2.y + mini2.largeur / 6,
                                 ALLEGRO_ALIGN_LEFT, "Suivant");
                }
                if (!mini2.gris) {
                    al_draw_text(miniOrbitron, al_map_rgb(0, 0, 0), mini2.x + mini2.longueur / 8, mini2.y + mini2.largeur / 6,
                                 ALLEGRO_ALIGN_LEFT, "Suivant");
                }
            }
            break;
        case 4:
            if(nbJ==2){
                if (mini2.gris) {
                    al_draw_text(miniOrbitron, al_map_rgb(255, 255, 255), mini2.x + mini2.longueur / 8, mini2.y + mini2.largeur / 6,
                                 ALLEGRO_ALIGN_LEFT, "Jouer");
                }
                if (!mini2.gris) {
                    al_draw_text(miniOrbitron, al_map_rgb(0, 0, 0), mini2.x + mini2.longueur / 8, mini2.y + mini2.largeur / 6,
                                 ALLEGRO_ALIGN_LEFT, "Jouer");
                }
            }
            else {
                if (mini2.gris) {
                    al_draw_text(miniOrbitron, al_map_rgb(255, 255, 255), mini2.x + mini2.longueur / 8, mini2.y + mini2.largeur / 6,
                                 ALLEGRO_ALIGN_LEFT, "Suivant");
                }
                if (!mini2.gris) {
                    al_draw_text(miniOrbitron, al_map_rgb(0, 0, 0), mini2.x + mini2.longueur / 8, mini2.y + mini2.largeur / 6,
                                 ALLEGRO_ALIGN_LEFT, "Suivant");
                }
            }
            break;
        case 5:
            if(nbJ==3){
                if (mini2.gris) {
                    al_draw_text(miniOrbitron, al_map_rgb(255, 255, 255), mini2.x + mini2.longueur / 8, mini2.y + mini2.largeur / 6,
                                 ALLEGRO_ALIGN_LEFT, "Jouer");
                }
                if (!mini2.gris) {
                    al_draw_text(miniOrbitron, al_map_rgb(0, 0, 0), mini2.x + mini2.longueur / 8, mini2.y + mini2.largeur / 6,
                                 ALLEGRO_ALIGN_LEFT, "Jouer");
                }
            }
            else {
                if (mini2.gris) {
                    al_draw_text(miniOrbitron, al_map_rgb(255, 255, 255), mini2.x + mini2.longueur / 8, mini2.y + mini2.largeur / 6,
                                 ALLEGRO_ALIGN_LEFT, "Suivant");
                }
                if (!mini2.gris) {
                    al_draw_text(miniOrbitron, al_map_rgb(0, 0, 0), mini2.x + mini2.longueur / 8, mini2.y + mini2.largeur / 6,
                                 ALLEGRO_ALIGN_LEFT, "Suivant");
                }
            }
            break;
        case 6:
            if (mini2.gris) {
                al_draw_text(miniOrbitron, al_map_rgb(255, 255, 255), mini2.x + mini2.longueur / 8, mini2.y + mini2.largeur / 6,
                             ALLEGRO_ALIGN_LEFT, "Jouer");
            }
            if (!mini2.gris) {
                al_draw_text(miniOrbitron, al_map_rgb(0, 0, 0), mini2.x + mini2.longueur / 8, mini2.y + mini2.largeur / 6,
                             ALLEGRO_ALIGN_LEFT, "Jouer");
            }
            break;
    }
}

void cadreClasse( rectangle CadreClasse1, rectangle CadreClasse2, rectangle CadreClasse3,rectangle CadreClasse4){
    if(CadreClasse1.gris){
        al_draw_rectangle(CadreClasse1.x, CadreClasse1.y, CadreClasse1.x + CadreClasse1.longueur, CadreClasse1.y + CadreClasse1.largeur, al_map_rgb
        (0, 128, 255), 2);
    }
    else if(CadreClasse2.gris){
        al_draw_rectangle(CadreClasse2.x, CadreClasse2.y, CadreClasse2.x + CadreClasse2.longueur, CadreClasse2.y + CadreClasse2.largeur, al_map_rgb
                (0, 128, 255), 2);
    }
    else if(CadreClasse3.gris){
        al_draw_rectangle(CadreClasse3.x, CadreClasse3.y, CadreClasse3.x + CadreClasse3.longueur, CadreClasse3.y + CadreClasse3.largeur, al_map_rgb
                (0, 128, 255), 2);
    }
    else if(CadreClasse4.gris){
        al_draw_rectangle(CadreClasse4.x, CadreClasse4.y, CadreClasse4.x + CadreClasse4.longueur, CadreClasse4.y + CadreClasse4.largeur, al_map_rgb
                (0, 128, 255), 2);
    }
}

void drawrectangle(rectangle r, ALLEGRO_FONT* font, char mot[]) {
    if (r.gris) {
        al_draw_filled_rectangle(r.x, r.y, r.x + r.longueur, r.y + r.largeur, al_map_rgb(224, 176, 255));
        al_draw_rectangle(r.x, r.y, r.x + r.longueur, r.y + r.largeur, al_map_rgb(127, 0, 255), 2);
        al_draw_text(font, al_map_rgb(255, 255, 255), r.x + r.longueur / 8, r.y + r.largeur / 6,
                     ALLEGRO_ALIGN_LEFT, mot);
    }
    if (!r.gris) {
        al_draw_filled_rectangle(r.x, r.y, r.x + r.longueur, r.y + r.largeur,
                                 al_map_rgb(242, 184, 216));
        al_draw_rectangle(r.x, r.y, r.x + r.longueur, r.y + r.largeur, al_map_rgb(127, 0, 255), 2);
        al_draw_text(font, al_map_rgb(0,0,0), r.x + r.longueur / 8, r.y + r.largeur / 6,
                     ALLEGRO_ALIGN_LEFT, mot);
    }
}

void drawrectangleNom(rectangle r, ALLEGRO_FONT* font, char mot[]) {
    if (r.gris) {
        al_draw_filled_rectangle(r.x, r.y, r.x + r.longueur, r.y + r.largeur, al_map_rgb(224, 176, 255));
        al_draw_rectangle(r.x, r.y, r.x + r.longueur, r.y + r.largeur, al_map_rgb(127, 0, 255), 2);
        al_draw_text(font, al_map_rgb(255, 255, 255), r.x + r.longueur / 8, r.y + r.largeur / 6,
                     ALLEGRO_ALIGN_LEFT, mot);
    }
}

void affichageRectangle(ALLEGRO_BITMAP* SOLARIS,ALLEGRO_BITMAP* TERRA,ALLEGRO_BITMAP* MARTIAN,ALLEGRO_BITMAP* SATURNA, bool peindrerect, int menu, rectangle rectNom1, rectangle rectNom2, rectangle mini, rectangle Carre1,
                        rectangle Carre2,rectangle Carre3,rectangle Carre4, rectangle NomClasse1, rectangle NomClasse2, rectangle NomClasse3, rectangle NomClasse4, rectangle mini2,
                        ALLEGRO_FONT* Orbitron, ALLEGRO_FONT* miniOrbitron, int nbJ){
    if (menu == 0) {
        drawrectangle(rectNom1,Orbitron,"PLAY");
        drawrectangle(rectNom2,Orbitron,"EXIT");
    }

    if (menu == 1){
        drawrectangle(Carre1,Orbitron,"  1");
        drawrectangle(Carre2,Orbitron," 2");
        drawrectangle(Carre3,Orbitron," 3");
        drawrectangle(Carre4,Orbitron," 4");
    }

    if (menu >= 0 && menu <= 6) {
        drawrectangle(mini,Orbitron,"");
        ecritMini(menu, mini, miniOrbitron);
    }
    if (menu >= 3 && menu <= 6){
        Carre1.y=HAUTEUR/3;
        Carre2.y=HAUTEUR/3;
        Carre3.y=HAUTEUR/3;
        Carre4.y=HAUTEUR/3;
        drawrectangle(Carre1,Orbitron," ");
        drawrectangle(Carre2,Orbitron," ");
        drawrectangle(Carre3,Orbitron," ");
        drawrectangle(Carre4,Orbitron," ");
        if(peindrerect) {
            AffichageIconePerso(SOLARIS,TERRA,MARTIAN,SATURNA, Carre1, Carre2, Carre3, Carre4);
        }
        drawrectangleNom(NomClasse1, Orbitron, "Solaris");
        drawrectangleNom(NomClasse2, Orbitron, "Terra");
        drawrectangleNom(NomClasse3, Orbitron, "Martian");
        drawrectangleNom(NomClasse4, Orbitron, "Saturna");
        drawrectangle(mini2,Orbitron,"");
        ecritMini2(menu, mini2, miniOrbitron, nbJ);
    }
    al_flip_display();
}

unsigned char hitBoxR(rectangle r, int x, int y){
    if(x >= r.x && x <= r.x+r.longueur && y >= r.y && y <= r.y+r.largeur) {
        return 1;
    }
    return 0;
}

void affichageMenu1(ALLEGRO_BITMAP* background, rectangle Carre1, rectangle Carre2, rectangle Carre3, rectangle Carre4,ALLEGRO_FONT* Megrim,
                    ALLEGRO_FONT* Orbitron){
    al_draw_scaled_bitmap(background,0,0,1300,800,0,0,LARGEUR,HAUTEUR,ALLEGRO_FLIP_HORIZONTAL);
    al_draw_text(Megrim, al_map_rgb(255,255,255), 10, 10, ALLEGRO_ALIGN_LEFT, "STELLAR WARS");
    al_draw_text(Orbitron, al_map_rgb(255,255,255), LARGEUR/20,HAUTEUR/4,ALLEGRO_ALIGN_LEFT, "Nombre de Joueurs :");
    al_flip_display();
}

void affichageMenu3(ALLEGRO_BITMAP* background, rectangle rectNomJ, ALLEGRO_FONT* Megrim, ALLEGRO_FONT* miniOrbitron){
    al_draw_scaled_bitmap(background,0,0,1300,800,0,0,LARGEUR,HAUTEUR,ALLEGRO_FLIP_HORIZONTAL);
    al_draw_text(Megrim, al_map_rgb(255,255,255), 10, 10, ALLEGRO_ALIGN_LEFT, "STELLAR WARS");
    drawrectangle(rectNomJ,miniOrbitron,"");
}

void affichageMenu7(ALLEGRO_BITMAP* background, rectangle CarreCredit, ALLEGRO_FONT* Megrim){
    al_draw_scaled_bitmap(background,0,0,1300,800,0,0,LARGEUR,HAUTEUR,ALLEGRO_FLIP_HORIZONTAL);
    al_draw_filled_rectangle(CarreCredit.x, CarreCredit.y, CarreCredit.x + CarreCredit.longueur, CarreCredit.y + CarreCredit.largeur, al_map_rgb(242, 184, 216));
    al_draw_rectangle(CarreCredit.x, CarreCredit.y, CarreCredit.x + CarreCredit.longueur, CarreCredit.y + CarreCredit.largeur, al_map_rgb(127,0,255), 2);
    al_draw_text(Megrim, al_map_rgb(255,255,255), 10, 10, ALLEGRO_ALIGN_LEFT, "STELLAR WARS");
    al_draw_text(Megrim, al_map_rgb(255,255,255), LARGEUR/2, HAUTEUR/2, ALLEGRO_ALIGN_CENTER, "LE JEU");
    al_flip_display();
}

void AffichageIconePerso(ALLEGRO_BITMAP* SOLARIS,ALLEGRO_BITMAP* TERRA,ALLEGRO_BITMAP* MARTIAN,ALLEGRO_BITMAP* SATURNA, rectangle Carre1, rectangle
Carre2,rectangle Carre3,rectangle Carre4){
    al_draw_scaled_bitmap(SOLARIS,0,0, 100, 117, Carre1.x+((Carre1.longueur-(((float)100/117)*Carre1.longueur))/2), Carre1.y, ((float)100/117)
    *Carre1.longueur,Carre1.longueur, 0);
    al_draw_scaled_bitmap(TERRA,0,0, 256, 268, Carre2.x+((Carre2.longueur-(((float)256/268)*Carre2.longueur))/2), Carre2.y, ((float)256/268)*Carre2
    .longueur,Carre2.longueur, 0);
    al_draw_scaled_bitmap(MARTIAN,0,0, 480, 571, Carre3.x+((Carre3.longueur-(((float)480/571)*Carre3.longueur))/2), Carre3.y, ((float)480/571)
    *Carre3.longueur,Carre3.longueur, 0);
    al_draw_scaled_bitmap(SATURNA,0,0, 254, 360, Carre4.x+((Carre4.longueur-(((float)254/360)*Carre4.longueur))/2), Carre4.y, ((float)254/360)
    *Carre4.longueur,Carre4.longueur, 0);
}

void MENU(bool* play, Joueurs** listeJoueurs){
    //déclaration
    bool end = false;
    int menu=0;
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_KEYBOARD_STATE keyboard;
    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_EVENT event;
    ALLEGRO_MOUSE_STATE mouse;
    ALLEGRO_TIMER* timer = NULL;
    ALLEGRO_SAMPLE* tic = NULL;
    ALLEGRO_SAMPLE* clik = NULL;
    ALLEGRO_SAMPLE* TitleTheme = NULL;
    ALLEGRO_SAMPLE_INSTANCE* TitleThemeInstance = NULL;
    ALLEGRO_FONT* Megrim = al_load_ttf_font("../Font/Megrim-Regular.ttf", TAILLE_POLICE_MAX*((float)5/3), 0);
    ALLEGRO_FONT* Orbitron = al_load_ttf_font("../Font/Orbitron.ttf", TAILLE_POLICE_MAX, 0);
    ALLEGRO_FONT* miniOrbitron = al_load_ttf_font("../Font/Orbitron.ttf", TAILLE_POLICE_MAX/2, 0);
    ALLEGRO_FONT* microOrbitron = al_load_ttf_font("../Font/Orbitron.ttf", TAILLE_POLICE_MAX/4, 0);
    ALLEGRO_BITMAP* background = al_load_bitmap("../Image/background.png");
    ALLEGRO_BITMAP* TERRA = al_load_bitmap("../Image/TERRA.png");
    ALLEGRO_BITMAP* MARTIAN = al_load_bitmap("../Image/MARTIAN.png");
    ALLEGRO_BITMAP* SOLARIS = al_load_bitmap("../Image/SOLARIS.png");
    ALLEGRO_BITMAP* SATURNA = al_load_bitmap("../Image/SATURNA.png");
    ALLEGRO_BITMAP* icon = al_load_bitmap("../Image/icone.png");

    srand(time(NULL));
    assert(background);
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

    //création + affichage 1

    al_reserve_samples(10);
    bool ticRdy = true;
    tic = al_load_sample("../Music/fast-magic.ogg");
    assert(tic);
    clik = al_load_sample("../Music/light-spell.ogg");
    assert(clik);
    TitleTheme = al_load_sample("../Music/Title-Theme.ogg");
    assert(TitleTheme);

    TitleThemeInstance = al_create_sample_instance(TitleTheme);
    al_set_sample_instance_playmode(TitleThemeInstance,ALLEGRO_PLAYMODE_LOOP);

    al_attach_sample_instance_to_mixer(TitleThemeInstance, al_get_default_mixer());

    al_set_new_display_flags(ALLEGRO_RESIZABLE);
    al_set_new_display_option(ALLEGRO_SINGLE_BUFFER,1,ALLEGRO_REQUIRE);
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

    //création
    rectangle rectNom1;
    rectNom1.longueur = LARGEUR/4;
    rectNom1.largeur = HAUTEUR/6;
    rectNom1.x = (LARGEUR/2)+(LARGEUR/8);
    rectNom1.y = (HAUTEUR/2)-(HAUTEUR/6);
    rectNom1.gris=false;

    rectangle rectNom2;
    rectNom2.longueur = LARGEUR/4;
    rectNom2.largeur = HAUTEUR/6;
    rectNom2.x = (LARGEUR/2)+(LARGEUR/8);
    rectNom2.y = (HAUTEUR/2)+(HAUTEUR/6);
    rectNom2.gris=false;

    rectangle mini;
    mini.longueur = LARGEUR/8;
    mini.largeur = HAUTEUR/15;
    mini.x = LARGEUR/45;
    mini.y = HAUTEUR - HAUTEUR/10;
    mini.gris=false;

    rectangle mini2;
    mini2.longueur = LARGEUR/8;
    mini2.largeur = HAUTEUR/15;
    mini2.x = (LARGEUR - LARGEUR/45) - mini2.longueur;
    mini2.y = HAUTEUR - HAUTEUR/10;
    mini2.gris=false;

    rectangle Carre1;
    Carre1.longueur = LARGEUR/10;
    Carre1.largeur = Carre1.longueur;
    Carre1.x = (LARGEUR/5) - ((float)Carre1.longueur/2);
    Carre1.y = (HAUTEUR/2);
    Carre1.gris=false;
    rectangle Carre2;
    Carre2.longueur = LARGEUR/10;
    Carre2.largeur = Carre2.longueur;
    Carre2.x = (LARGEUR*((float)2/5)) - ((float)Carre2.longueur/2);
    Carre2.y = (HAUTEUR/2);
    Carre2.gris=false;
    rectangle Carre3;
    Carre3.longueur = LARGEUR/10;
    Carre3.largeur = Carre3.longueur;
    Carre3.x = (LARGEUR*((float)3/5)) - ((float)Carre2.longueur/2);
    Carre3.y = (HAUTEUR/2);
    Carre3.gris=false;
    rectangle Carre4;
    Carre4.longueur = LARGEUR/10;
    Carre4.largeur = Carre4.longueur;
    Carre4.x = (LARGEUR*((float)4/(float)5)) - ((float)Carre2.longueur/2);
    Carre4.y = (HAUTEUR/2);
    Carre4.gris=false;

    rectangle CarreCredit;
    CarreCredit.longueur = LARGEUR* (float)3/(float)5;
    CarreCredit.largeur = ((float)(3*CarreCredit.longueur)/4);
    CarreCredit.x = (LARGEUR/2) - ((float)CarreCredit.longueur/2);
    CarreCredit.y = (HAUTEUR/6);
    CarreCredit.gris=false;

    rectangle rectNomJ;
    rectNomJ.longueur = LARGEUR/4;
    rectNomJ.largeur = HAUTEUR/10;
    rectNomJ.x = (LARGEUR/2)- ((float)rectNomJ.longueur/2);
    rectNomJ.y = (HAUTEUR/2)+(HAUTEUR/4);
    rectNomJ.gris=false;

    rectangle CadreClasse1;
    CadreClasse1.longueur = LARGEUR/10+6;
    CadreClasse1.largeur = Carre1.longueur+6;
    CadreClasse1.x = (LARGEUR/5) - ((float)Carre1.longueur/2)-3;
    CadreClasse1.y = (HAUTEUR/3)-3;
    CadreClasse1.gris=false;
    rectangle CadreClasse2;
    CadreClasse2.longueur = LARGEUR/10+6;
    CadreClasse2.largeur = Carre2.longueur+6;
    CadreClasse2.x = (LARGEUR*((float)2/5)) - ((float)Carre2.longueur/2)-3;
    CadreClasse2.y = (HAUTEUR/3)-3;
    CadreClasse2.gris=false;
    rectangle CadreClasse3;
    CadreClasse3.longueur = LARGEUR/10+6;
    CadreClasse3.largeur = Carre3.longueur+6;
    CadreClasse3.x = (LARGEUR*((float)3/5)) - ((float)Carre2.longueur/2)-3;
    CadreClasse3.y = (HAUTEUR/3)-3;
    CadreClasse3.gris=false;
    rectangle CadreClasse4;
    CadreClasse4.longueur = LARGEUR/10+6;
    CadreClasse4.largeur = Carre4.longueur+6;
    CadreClasse4.x = (LARGEUR*((float)4/(float)5)) - ((float)Carre2.longueur/2)-3;
    CadreClasse4.y = (HAUTEUR/3)-3;
    CadreClasse4.gris=false;

    rectangle NomClasse1;
    NomClasse1.longueur = LARGEUR/3;
    NomClasse1.largeur =  Carre1.longueur + Carre1.longueur/2;
    NomClasse1.x = (LARGEUR/5) - ((float)Carre1.longueur/2)+2+LARGEUR/10;
    NomClasse1.y = (HAUTEUR/3);
    NomClasse1.gris=false;
    rectangle NomClasse2;
    NomClasse2.longueur = LARGEUR/3;
    NomClasse2.largeur = Carre1.longueur + Carre1.longueur/2;
    NomClasse2.x = (LARGEUR*((float)2/5)) - ((float)Carre2.longueur/2)+2+LARGEUR/10;
    NomClasse2.y = (HAUTEUR/3);
    NomClasse2.gris=false;
    rectangle NomClasse3;
    NomClasse3.longueur = LARGEUR/3;
    NomClasse3.largeur = Carre1.longueur + Carre1.longueur/2;
    NomClasse3.x = (LARGEUR*((float)3/5)) - ((float)Carre2.longueur/2)+2+LARGEUR/10;
    NomClasse3.y = (HAUTEUR/3);
    NomClasse3.gris=false;
    rectangle NomClasse4;
    NomClasse4.longueur = LARGEUR/3;
    NomClasse4.largeur = Carre1.longueur + Carre1.longueur/2;
    NomClasse4.x = (LARGEUR*((float)4/(float)5)) - ((float)Carre2.longueur/2)- NomClasse4.longueur;
    NomClasse4.y = (HAUTEUR/3);
    NomClasse4.gris=false;

    bool peindre=false;

    int nbJ = 0;

    bool menu0=true;
    bool menu1=false;
    bool menu2=false;
    bool menu3=false;
    bool menu4=false;
    bool menu5=false;
    bool menu6=false;
    bool menu7=false;

    Joueurs* listeJ = NULL;

    classe Solaris;
    classe Terra;
    classe Martian;
    classe Saturna;
    InitialiserClass(&Solaris, &Terra, &Martian, &Saturna);

    //premier affichage
    affichageMenu0(background, rectNom1, rectNom2, Megrim, Orbitron);
    bool Jprenom = false;
    bool Jclasse = false;
    bool peindrerect=false;


    while (end == false) {
        al_wait_for_event(queue, &event);

        al_play_sample_instance(TitleThemeInstance);

        switch (menu) {
            case 0:
                if(menu0==false){
                    affichageMenu0(background, rectNom1, rectNom2, Megrim, Orbitron);
                    menu0=true;
                    menu1=false;
                    menu2=false;
                    menu3=false;
                    menu4=false;
                    menu5=false;
                    menu6=false;
                    menu7=false;
                }
                switch (event.type) {
                    case ALLEGRO_EVENT_DISPLAY_CLOSE:
                        al_stop_sample_instance(TitleThemeInstance);
                        end = true;
                        break;

                    case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                        /*if(event.mouse.x > rectNom1.x && event.mouse.x < rectNom1.x + rectNom1.longueur && event.mouse.y > rectNom1.y && event.mouse.y
                                <rectNom1.y + rectNom1.largeur){
                            J1prenom = true;
                        }else{J1prenom = false;}
                        if (event.mouse.x > rectNom2.x && event.mouse.x < rectNom2.x + rectNom2.longueur && event.mouse.y > rectNom2.y && event.mouse.y < rectNom2.y + rectNom2
                                .largeur){
                            J2prenom = true;
                        }else{J2prenom = false;}*/

                        if (hitBoxR(rectNom1, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            menu = 1;
                        }
                        if (hitBoxR(rectNom2, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            end = true;
                        }
                        if (hitBoxR(mini, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            menu = 2;
                        }
                        break;

                    case ALLEGRO_EVENT_MOUSE_AXES:
                        if (hitBoxR(rectNom1, event.mouse.x, event.mouse.y) && rectNom1.gris == false) {
                            rectNom1.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (hitBoxR(rectNom2, event.mouse.x, event.mouse.y) && rectNom2.gris == false) {
                            rectNom2.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (hitBoxR(mini, event.mouse.x, event.mouse.y) && mini.gris == false) {
                            mini.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (!(hitBoxR(rectNom1, event.mouse.x, event.mouse.y)) && rectNom1.gris == true) {
                            rectNom1.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                            }
                        }
                        if (!(hitBoxR(rectNom2, event.mouse.x, event.mouse.y)) && rectNom2.gris == true) {
                            rectNom2.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                            }
                        }
                        if (!(hitBoxR(mini, event.mouse.x, event.mouse.y)) && mini.gris == true) {
                            mini.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                            }
                        }
                        break;

                    case ALLEGRO_EVENT_TIMER:


                        affichageRectangle(SOLARIS,TERRA,MARTIAN,SATURNA, peindrerect, menu ,rectNom1, rectNom2, mini,Carre1,Carre2,Carre3,Carre4, NomClasse1, NomClasse2,NomClasse3,
                                           NomClasse4, mini2, Orbitron, miniOrbitron, nbJ);

                        break;
                }
                break;

                /////////////////////////////////////////////////////////////////////////////////////

            case 1:
                if(menu1==false){
                    affichageMenu1(background,Carre1,Carre2,Carre3,Carre4, Megrim, Orbitron);
                    menu0=false;
                    menu1=true;
                    menu2=false;
                    menu3=false;
                    menu4=false;
                    menu5=false;
                    menu6=false;
                    menu7=false;
                    Carre1.y=HAUTEUR/2;
                    Carre2.y=HAUTEUR/2;
                    Carre3.y=HAUTEUR/2;
                    Carre4.y=HAUTEUR/2;
                }

                switch (event.type){
                    case ALLEGRO_EVENT_DISPLAY_CLOSE:
                        al_stop_sample_instance(TitleThemeInstance);
                        end = true;
                        break;
                    case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                        if (hitBoxR(mini, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            menu = 0;
                        }
                        if (hitBoxR(Carre1, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            listeJ = iniJ(1);
                            nbJ = 1;
                            menu = 3;
                        }
                        if (hitBoxR(Carre2, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            listeJ = iniJ(1);
                            nbJ = 2;
                            menu = 3;
                        }
                        if (hitBoxR(Carre3, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            listeJ = iniJ(1);
                            nbJ = 3;
                            menu = 3;
                        }
                        if (hitBoxR(Carre4, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            listeJ = iniJ(1);
                            nbJ = 4;
                            menu = 3;
                        }
                        break;
                    case ALLEGRO_EVENT_MOUSE_AXES:
                        if (hitBoxR(mini, event.mouse.x, event.mouse.y) && mini.gris == false) {
                            mini.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (hitBoxR(Carre1, event.mouse.x, event.mouse.y) && Carre1.gris == false) {
                            Carre1.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (hitBoxR(Carre2, event.mouse.x, event.mouse.y) && Carre2.gris == false) {
                            Carre2.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (hitBoxR(Carre3, event.mouse.x, event.mouse.y) && Carre3.gris == false) {
                            Carre3.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (hitBoxR(Carre4, event.mouse.x, event.mouse.y) && Carre4.gris == false) {
                            Carre4.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (!(hitBoxR(mini, event.mouse.x, event.mouse.y)) && mini.gris == true) {
                            mini.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                            }
                        }
                        if (!(hitBoxR(Carre1, event.mouse.x, event.mouse.y)) && Carre1.gris == true) {
                            Carre1.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                            }
                        }
                        if (!(hitBoxR(Carre2, event.mouse.x, event.mouse.y)) && Carre2.gris == true) {
                            Carre2.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                            }
                        }
                        if (!(hitBoxR(Carre3, event.mouse.x, event.mouse.y)) && Carre3.gris == true) {
                            Carre3.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                            }
                        }
                        if (!(hitBoxR(Carre4, event.mouse.x, event.mouse.y)) && Carre4.gris == true) {
                            Carre4.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                            }
                        }
                        break;
                    case ALLEGRO_EVENT_TIMER:
                        affichageRectangle(SOLARIS,TERRA,MARTIAN,SATURNA,peindrerect, menu ,rectNom1, rectNom2, mini,Carre1,Carre2,Carre3,Carre4, NomClasse1, NomClasse2, NomClasse3, NomClasse4, mini2, Orbitron, miniOrbitron, nbJ);
                        break;
                }
                break;

                ////////////////////////////////////////////////////////////////////////////////////////////

            case 2 :

                if(menu2==false){
                    affichageMenu2(background, mini, CarreCredit, Megrim, miniOrbitron, microOrbitron);
                    menu0=false;
                    menu1=false;
                    menu2=true;
                    menu3=false;
                    menu4=false;
                    menu5=false;
                    menu6=false;
                    menu7=false;
                }
                switch (event.type){
                    case ALLEGRO_EVENT_DISPLAY_CLOSE:
                        al_stop_sample_instance(TitleThemeInstance);
                        end = true;
                        break;
                    case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                        if (hitBoxR(mini, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            menu = 0;
                        }
                        break;
                    case ALLEGRO_EVENT_MOUSE_AXES:
                        if (hitBoxR(mini, event.mouse.x, event.mouse.y) && mini.gris == false) {
                            mini.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (!(hitBoxR(mini, event.mouse.x, event.mouse.y)) && mini.gris == true) {
                            mini.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                            }
                        }
                        break;
                    case ALLEGRO_EVENT_TIMER:
                        affichageRectangle(SOLARIS,TERRA,MARTIAN,SATURNA,peindrerect, menu ,rectNom1, rectNom2, mini,Carre1,Carre2,Carre3,Carre4, NomClasse1, NomClasse2, NomClasse3, NomClasse4, mini2, Orbitron, miniOrbitron, nbJ);
                        break;
                }
                break;

                /////////////////////////////////////////////////////////////////

            case 3 :
                if(menu3==false){
                    affichageMenu3(background, rectNomJ, Megrim, miniOrbitron);
                    menu0=false;
                    menu1=false;
                    menu2=false;
                    menu3=true;
                    menu4=false;
                    menu5=false;
                    menu6=false;
                    menu7=false;
                    Carre1.y=HAUTEUR/3;
                    Carre2.y=HAUTEUR/3;
                    Carre3.y=HAUTEUR/3;
                    Carre4.y=HAUTEUR/3;
                }

                switch (event.type) {
                    case ALLEGRO_EVENT_DISPLAY_CLOSE:
                        al_stop_sample_instance(TitleThemeInstance);
                        end = true;
                        break;
                    case ALLEGRO_EVENT_KEY_DOWN:
                        keyDown(event, listeJ->nom);
                        peindre=true;
                        if(!Jprenom){
                            Jprenom=true;
                        }
                        break;
                    case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                        if (hitBoxR(mini, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            menu = 1;
                            Jprenom=false;
                            Jclasse=false;
                            free(listeJ);
                        }
                        if (hitBoxR(mini2, event.mouse.x, event.mouse.y)) {
                            if(Jprenom&&Jclasse) {
                                al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                if (nbJ > 1) {
                                    listeJ->pv=listeJ->classeJ.pv;
                                    listeJ->positionJ.colonne=19;
                                    listeJ->positionJ.ligne=14;
                                    listeJ->next = iniJ(2);
                                    menu = 4;
                                } else {
                                    menu = 7;
                                    listeJ->pv=listeJ->classeJ.pv;
                                    listeJ->positionJ.colonne=19;
                                    listeJ->positionJ.ligne=14;
                                    listeJ->next = listeJ;
                                }
                                Jprenom=false;
                                Jclasse=false;
                            }
                        }
                        if (hitBoxR(Carre1, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            CadreClasse1.gris=true;
                            CadreClasse2.gris=false;
                            CadreClasse3.gris=false;
                            CadreClasse4.gris=false;
                            listeJ->classeJ = Solaris;
                            peindre = true;
                            if(!Jclasse){
                                Jclasse=true;
                            }
                        }
                        if (hitBoxR(Carre2, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            CadreClasse1.gris=false;
                            CadreClasse2.gris=true;
                            CadreClasse3.gris=false;
                            CadreClasse4.gris=false;
                            listeJ->classeJ = Terra;
                            peindre = true;
                            if(!Jclasse){
                                Jclasse=true;
                            }
                        }
                        if (hitBoxR(Carre3, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            CadreClasse1.gris=false;
                            CadreClasse2.gris=false;
                            CadreClasse3.gris=true;
                            CadreClasse4.gris=false;
                            listeJ->classeJ = Martian;
                            peindre = true;
                            if(!Jclasse){
                                Jclasse=true;
                            }
                        }
                        if (hitBoxR(Carre4, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            CadreClasse1.gris=false;
                            CadreClasse2.gris=false;
                            CadreClasse3.gris=false;
                            CadreClasse4.gris=true;
                            listeJ->classeJ = Saturna;
                            peindre = true;
                            if(!Jclasse){
                                Jclasse=true;
                            }
                        }
                        break;
                    case ALLEGRO_EVENT_MOUSE_AXES:
                        if (hitBoxR(mini, event.mouse.x, event.mouse.y) && mini.gris == false) {
                            mini.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (hitBoxR(mini2, event.mouse.x, event.mouse.y) && mini2.gris == false) {
                            if(Jprenom&&Jclasse) {
                                mini2.gris = true;
                                if (ticRdy) {
                                    al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                    ticRdy = false;
                                }
                            }
                        }
                        if (hitBoxR(Carre1, event.mouse.x, event.mouse.y) && Carre1.gris == false) {
                            Carre1.gris = true;
                            NomClasse1.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (hitBoxR(Carre2, event.mouse.x, event.mouse.y) && Carre2.gris == false) {
                            Carre2.gris = true;
                            NomClasse2.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (hitBoxR(Carre3, event.mouse.x, event.mouse.y) && Carre3.gris == false) {
                            Carre3.gris = true;
                            NomClasse3.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (hitBoxR(Carre4, event.mouse.x, event.mouse.y) && Carre4.gris == false) {
                            Carre4.gris = true;
                            NomClasse4.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (!(hitBoxR(mini, event.mouse.x, event.mouse.y)) && mini.gris == true) {
                            mini.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                            }
                        }
                        if (!(hitBoxR(mini2, event.mouse.x, event.mouse.y)) && mini2.gris == true) {
                            mini2.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                            }
                        }
                        if (!(hitBoxR(Carre1, event.mouse.x, event.mouse.y)) && Carre1.gris == true) {
                            Carre1.gris = false;
                            NomClasse1.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                                peindre = true;
                            }
                        }
                        if (!(hitBoxR(Carre2, event.mouse.x, event.mouse.y)) && Carre2.gris == true) {
                            Carre2.gris = false;
                            NomClasse2.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                                peindre = true;
                            }
                        }
                        if (!(hitBoxR(Carre3, event.mouse.x, event.mouse.y)) && Carre3.gris == true) {
                            Carre3.gris = false;
                            NomClasse3.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                                peindre = true;
                            }
                        }
                        if (!(hitBoxR(Carre4, event.mouse.x, event.mouse.y)) && Carre4.gris == true) {
                            Carre4.gris = false;
                            NomClasse4.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                                peindre = true;
                            }
                        }
                        break;
                    case ALLEGRO_EVENT_TIMER:
                        if (peindre) {
                            affichageMenu3(background, rectNomJ, Megrim, miniOrbitron);
                            actualiserNom(listeJ->nom, rectNomJ, miniOrbitron);
                            cadreClasse(CadreClasse1, CadreClasse2, CadreClasse3, CadreClasse4);
                            peindrerect=true;
                            peindre = false;
                        }
                        affichageRectangle(SOLARIS,TERRA,MARTIAN,SATURNA, peindrerect,menu ,rectNom1, rectNom2, mini,Carre1,Carre2,Carre3,Carre4, NomClasse1, NomClasse2, NomClasse3, NomClasse4, mini2,Orbitron, miniOrbitron, nbJ);

                        break;
                }
                break;

                ////////////////////////////////////////////////////////////////////

            case 4 :
                if(menu4==false){
                    affichageMenu3(background, rectNomJ, Megrim, miniOrbitron);
                    menu0=false;
                    menu1=false;
                    menu2=false;
                    menu3=false;
                    menu4=true;
                    menu5=false;
                    menu6=false;
                    menu7=false;
                    Carre1.y=HAUTEUR/3;
                    Carre2.y=HAUTEUR/3;
                    Carre3.y=HAUTEUR/3;
                    Carre4.y=HAUTEUR/3;
                }

                switch (event.type) {
                    case ALLEGRO_EVENT_DISPLAY_CLOSE:
                        al_stop_sample_instance(TitleThemeInstance);
                        end = true;
                        break;
                    case ALLEGRO_EVENT_KEY_DOWN:
                        keyDown(event, listeJ->next->nom);
                        peindre=true;
                        if(!Jprenom){
                            Jprenom=true;
                        }
                        break;
                    case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                        if (hitBoxR(mini, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            menu = 3;
                            Jprenom=false;
                            Jclasse=false;
                            free(listeJ->next);
                        }
                        if (hitBoxR(mini2, event.mouse.x, event.mouse.y)) {
                            if(Jprenom&&Jclasse) {
                                al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                if (nbJ > 2) {
                                    listeJ->next->pv=listeJ->next->classeJ.pv;
                                    listeJ->next->positionJ.colonne=0;
                                    listeJ->next->positionJ.ligne=0;
                                    listeJ->next->next = iniJ(3);
                                    menu = 5;
                                } else {
                                    menu = 7;
                                    listeJ->next->pv=listeJ->next->classeJ.pv;
                                    listeJ->next->positionJ.colonne=0;
                                    listeJ->next->positionJ.ligne=0;
                                    listeJ->next->next = listeJ;
                                }
                                Jprenom=false;
                                Jclasse=false;
                            }
                        }
                        if (hitBoxR(Carre1, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            CadreClasse1.gris=true;
                            CadreClasse2.gris=false;
                            CadreClasse3.gris=false;
                            CadreClasse4.gris=false;
                            listeJ->next->classeJ = Solaris;
                            peindre = true;
                            if(!Jclasse){
                                Jclasse=true;
                            }
                        }
                        if (hitBoxR(Carre2, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            CadreClasse1.gris=false;
                            CadreClasse2.gris=true;
                            CadreClasse3.gris=false;
                            CadreClasse4.gris=false;
                            listeJ->next->classeJ = Terra;
                            peindre = true;
                            if(!Jclasse){
                                Jclasse=true;
                            }
                        }
                        if (hitBoxR(Carre3, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            CadreClasse1.gris=false;
                            CadreClasse2.gris=false;
                            CadreClasse3.gris=true;
                            CadreClasse4.gris=false;
                            listeJ->next->classeJ = Martian;
                            peindre = true;
                            if(!Jclasse){
                                Jclasse=true;
                            }
                        }
                        if (hitBoxR(Carre4, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            CadreClasse1.gris=false;
                            CadreClasse2.gris=false;
                            CadreClasse3.gris=false;
                            CadreClasse4.gris=true;
                            listeJ->next->classeJ = Saturna;
                            peindre = true;
                            if(!Jclasse){
                                Jclasse=true;
                            }
                        }
                        break;
                    case ALLEGRO_EVENT_MOUSE_AXES:
                        if (hitBoxR(mini, event.mouse.x, event.mouse.y) && mini.gris == false) {
                            mini.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (hitBoxR(mini2, event.mouse.x, event.mouse.y) && mini2.gris == false) {
                            if(Jprenom&&Jclasse) {
                                mini2.gris = true;
                                if (ticRdy) {
                                    al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                    ticRdy = false;
                                }
                            }
                        }
                        if (hitBoxR(Carre1, event.mouse.x, event.mouse.y) && Carre1.gris == false) {
                            Carre1.gris = true;
                            NomClasse1.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (hitBoxR(Carre2, event.mouse.x, event.mouse.y) && Carre2.gris == false) {
                            Carre2.gris = true;
                            NomClasse2.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (hitBoxR(Carre3, event.mouse.x, event.mouse.y) && Carre3.gris == false) {
                            Carre3.gris = true;
                            NomClasse3.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (hitBoxR(Carre4, event.mouse.x, event.mouse.y) && Carre4.gris == false) {
                            Carre4.gris = true;
                            NomClasse4.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (!(hitBoxR(mini, event.mouse.x, event.mouse.y)) && mini.gris == true) {
                            mini.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                            }
                        }
                        if (!(hitBoxR(mini2, event.mouse.x, event.mouse.y)) && mini2.gris == true) {
                            mini2.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                            }
                        }
                        if (!(hitBoxR(Carre1, event.mouse.x, event.mouse.y)) && Carre1.gris == true) {
                            Carre1.gris = false;
                            NomClasse1.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                                peindre = true;
                            }
                        }
                        if (!(hitBoxR(Carre2, event.mouse.x, event.mouse.y)) && Carre2.gris == true) {
                            Carre2.gris = false;
                            NomClasse2.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                                peindre = true;
                            }
                        }
                        if (!(hitBoxR(Carre3, event.mouse.x, event.mouse.y)) && Carre3.gris == true) {
                            Carre3.gris = false;
                            NomClasse3.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                                peindre = true;
                            }
                        }
                        if (!(hitBoxR(Carre4, event.mouse.x, event.mouse.y)) && Carre4.gris == true) {
                            Carre4.gris = false;
                            NomClasse4.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                                peindre = true;
                            }
                        }
                        break;
                    case ALLEGRO_EVENT_TIMER:
                        if (peindre) {
                            affichageMenu3(background, rectNomJ, Megrim, miniOrbitron);
                            actualiserNom(listeJ->next->nom, rectNomJ, miniOrbitron);
                            cadreClasse(CadreClasse1, CadreClasse2, CadreClasse3, CadreClasse4);
                            peindrerect=true;
                            peindre = false;
                        }
                        affichageRectangle(SOLARIS,TERRA,MARTIAN,SATURNA,peindrerect, menu ,rectNom1, rectNom2, mini,Carre1,Carre2,Carre3,Carre4, NomClasse1, NomClasse2, NomClasse3, NomClasse4, mini2,Orbitron, miniOrbitron, nbJ);
                        break;
                }
                break;

                //////////////////////////////////////////////////////////////////////////////////////////

            case 5 :
                if(menu5==false){
                    affichageMenu3(background, rectNomJ, Megrim, miniOrbitron);
                    menu0=false;
                    menu1=false;
                    menu2=false;
                    menu3=false;
                    menu4=false;
                    menu5=true;
                    menu6=false;
                    menu7=false;
                    Carre1.y=HAUTEUR/3;
                    Carre2.y=HAUTEUR/3;
                    Carre3.y=HAUTEUR/3;
                    Carre4.y=HAUTEUR/3;
                }

                switch (event.type) {
                    case ALLEGRO_EVENT_DISPLAY_CLOSE:
                        al_stop_sample_instance(TitleThemeInstance);
                        end = true;
                        break;
                    case ALLEGRO_EVENT_KEY_DOWN:
                        keyDown(event, listeJ->next->next->nom);
                        peindre=true;
                        if(!Jprenom){
                            Jprenom=true;
                        }
                        break;
                    case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                        if (hitBoxR(mini, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            menu = 4;
                            Jprenom=false;
                            Jclasse=false;
                            free(listeJ->next->next);
                        }
                        if (hitBoxR(mini2, event.mouse.x, event.mouse.y)) {
                            if(Jprenom&&Jclasse) {
                                al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                if (nbJ > 3) {
                                    listeJ->next->next->pv=listeJ->next->next->classeJ.pv;
                                    listeJ->next->next->positionJ.colonne=19;
                                    listeJ->next->next->positionJ.ligne=0;
                                    listeJ->next->next->next = iniJ(4);
                                    menu = 6;
                                } else {
                                    menu = 7;
                                    listeJ->next->next->pv=listeJ->next->next->classeJ.pv;
                                    listeJ->next->next->positionJ.colonne=19;
                                    listeJ->next->next->positionJ.ligne=0;
                                    listeJ->next->next->next = listeJ;
                                }
                                Jclasse=false;
                                Jprenom=false;
                            }
                        }
                        if (hitBoxR(Carre1, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            CadreClasse1.gris=true;
                            CadreClasse2.gris=false;
                            CadreClasse3.gris=false;
                            CadreClasse4.gris=false;
                            listeJ->next->next->classeJ = Solaris;
                            peindre = true;
                            if(!Jclasse){
                                Jclasse=true;
                            }
                        }
                        if (hitBoxR(Carre2, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            CadreClasse1.gris=false;
                            CadreClasse2.gris=true;
                            CadreClasse3.gris=false;
                            CadreClasse4.gris=false;
                            listeJ->next->next->classeJ = Terra;
                            peindre = true;
                            if(!Jclasse){
                                Jclasse=true;
                            }
                        }
                        if (hitBoxR(Carre3, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            CadreClasse1.gris=false;
                            CadreClasse2.gris=false;
                            CadreClasse3.gris=true;
                            CadreClasse4.gris=false;
                            listeJ->next->next->classeJ = Martian;
                            peindre = true;
                            if(!Jclasse){
                                Jclasse=true;
                            }
                        }
                        if (hitBoxR(Carre4, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            CadreClasse1.gris=false;
                            CadreClasse2.gris=false;
                            CadreClasse3.gris=false;
                            CadreClasse4.gris=true;
                            listeJ->next->next->classeJ = Saturna;
                            peindre = true;
                            if(!Jclasse){
                                Jclasse=true;
                            }
                        }
                        break;
                    case ALLEGRO_EVENT_MOUSE_AXES:
                        if (hitBoxR(mini, event.mouse.x, event.mouse.y) && mini.gris == false) {
                            mini.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (hitBoxR(mini2, event.mouse.x, event.mouse.y) && mini2.gris == false) {
                            if(Jprenom&&Jclasse) {
                                mini2.gris = true;
                                if (ticRdy) {
                                    al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                    ticRdy = false;
                                }
                            }
                        }
                        if (hitBoxR(Carre1, event.mouse.x, event.mouse.y) && Carre1.gris == false) {
                            Carre1.gris = true;
                            NomClasse1.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (hitBoxR(Carre2, event.mouse.x, event.mouse.y) && Carre2.gris == false) {
                            Carre2.gris = true;
                            NomClasse2.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (hitBoxR(Carre3, event.mouse.x, event.mouse.y) && Carre3.gris == false) {
                            Carre3.gris = true;
                            NomClasse3.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (hitBoxR(Carre4, event.mouse.x, event.mouse.y) && Carre4.gris == false) {
                            Carre4.gris = true;
                            NomClasse4.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (!(hitBoxR(mini, event.mouse.x, event.mouse.y)) && mini.gris == true) {
                            mini.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                            }
                        }
                        if (!(hitBoxR(mini2, event.mouse.x, event.mouse.y)) && mini2.gris == true) {
                            mini2.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                            }
                        }
                        if (!(hitBoxR(Carre1, event.mouse.x, event.mouse.y)) && Carre1.gris == true) {
                            Carre1.gris = false;
                            NomClasse1.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                                peindre = true;
                            }
                        }
                        if (!(hitBoxR(Carre2, event.mouse.x, event.mouse.y)) && Carre2.gris == true) {
                            Carre2.gris = false;
                            NomClasse2.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                                peindre = true;
                            }
                        }
                        if (!(hitBoxR(Carre3, event.mouse.x, event.mouse.y)) && Carre3.gris == true) {
                            Carre3.gris = false;
                            NomClasse3.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                                peindre = true;
                            }
                        }
                        if (!(hitBoxR(Carre4, event.mouse.x, event.mouse.y)) && Carre4.gris == true) {
                            Carre4.gris = false;
                            NomClasse4.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                                peindre = true;
                            }
                        }
                        break;
                    case ALLEGRO_EVENT_TIMER:
                        if (peindre) {
                            affichageMenu3(background, rectNomJ, Megrim, miniOrbitron);
                            actualiserNom(listeJ->next->next->nom, rectNomJ, miniOrbitron);
                            cadreClasse(CadreClasse1, CadreClasse2, CadreClasse3, CadreClasse4);
                            peindrerect=true;
                            peindre = false;
                        }
                        affichageRectangle(SOLARIS,TERRA,MARTIAN,SATURNA,peindrerect, menu ,rectNom1, rectNom2, mini,Carre1,Carre2,Carre3,Carre4, NomClasse1, NomClasse2, NomClasse3,
                                           NomClasse4, mini2,Orbitron, miniOrbitron, nbJ);
                        break;
                }
                break;

                //////////////////////////////////////////////////////////////////////////////////////

            case 6 :
                if(menu6==false){
                    affichageMenu3(background, rectNomJ, Megrim, miniOrbitron);
                    menu0=false;
                    menu1=false;
                    menu2=false;
                    menu3=false;
                    menu4=false;
                    menu5=false;
                    menu6=true;
                    menu7=false;
                    Carre1.y=HAUTEUR/3;
                    Carre2.y=HAUTEUR/3;
                    Carre3.y=HAUTEUR/3;
                    Carre4.y=HAUTEUR/3;
                }

                switch (event.type) {
                    case ALLEGRO_EVENT_DISPLAY_CLOSE:
                        al_stop_sample_instance(TitleThemeInstance);
                        end = true;
                        break;
                    case ALLEGRO_EVENT_KEY_DOWN:
                        keyDown(event, listeJ->next->next->next->nom);
                        peindre=true;
                        if(!Jprenom){
                            Jprenom=true;
                        }
                        break;
                    case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                        if (hitBoxR(mini, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            menu = 5;
                            Jprenom=false;
                            Jclasse=false;
                            free(listeJ->next->next->next);
                        }
                        if (hitBoxR(mini2, event.mouse.x, event.mouse.y)) {
                            if(Jprenom&&Jclasse) {
                                al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                menu = 7;
                                listeJ->next->next->next->pv=listeJ->next->next->next->classeJ.pv;
                                listeJ->next->next->next->positionJ.colonne=0;
                                listeJ->next->next->next->positionJ.ligne=14;
                                listeJ->next->next->next->next = listeJ;
                                Jclasse=false;
                                Jprenom=false;
                            }
                        }
                        if (hitBoxR(Carre1, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            CadreClasse1.gris=true;
                            CadreClasse2.gris=false;
                            CadreClasse3.gris=false;
                            CadreClasse4.gris=false;
                            listeJ->next->next->next->classeJ = Solaris;
                            peindre = true;
                            if(!Jclasse){
                                Jclasse=true;
                            }
                        }
                        if (hitBoxR(Carre2, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            CadreClasse1.gris=false;
                            CadreClasse2.gris=true;
                            CadreClasse3.gris=false;
                            CadreClasse4.gris=false;
                            listeJ->next->next->next->classeJ = Terra;
                            peindre = true;
                            if(!Jclasse){
                                Jclasse=true;
                            }
                        }
                        if (hitBoxR(Carre3, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            CadreClasse1.gris=false;
                            CadreClasse2.gris=false;
                            CadreClasse3.gris=true;
                            CadreClasse4.gris=false;
                            listeJ->next->next->next->classeJ = Martian;
                            peindre = true;
                            if(!Jclasse){
                                Jclasse=true;
                            }
                        }
                        if (hitBoxR(Carre4, event.mouse.x, event.mouse.y)) {
                            al_play_sample(clik, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                            CadreClasse1.gris=false;
                            CadreClasse2.gris=false;
                            CadreClasse3.gris=false;
                            CadreClasse4.gris=true;
                            listeJ->next->next->next->classeJ = Saturna;
                            peindre = true;
                            if(!Jclasse){
                                Jclasse=true;
                            }
                        }
                        break;
                    case ALLEGRO_EVENT_MOUSE_AXES:
                        if (hitBoxR(mini, event.mouse.x, event.mouse.y) && mini.gris == false) {
                            mini.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (hitBoxR(mini2, event.mouse.x, event.mouse.y) && mini2.gris == false) {
                            if(Jprenom&&Jclasse) {
                                mini2.gris = true;
                                if (ticRdy) {
                                    al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                    ticRdy = false;
                                }
                            }
                        }
                        if (hitBoxR(Carre1, event.mouse.x, event.mouse.y) && Carre1.gris == false) {
                            Carre1.gris = true;
                            NomClasse1.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (hitBoxR(Carre2, event.mouse.x, event.mouse.y) && Carre2.gris == false) {
                            Carre2.gris = true;
                            NomClasse2.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (hitBoxR(Carre3, event.mouse.x, event.mouse.y) && Carre3.gris == false) {
                            Carre3.gris = true;
                            NomClasse3.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (hitBoxR(Carre4, event.mouse.x, event.mouse.y) && Carre4.gris == false) {
                            Carre4.gris = true;
                            NomClasse4.gris = true;
                            if (ticRdy) {
                                al_play_sample(tic, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
                                ticRdy = false;
                            }
                        }
                        if (!(hitBoxR(mini, event.mouse.x, event.mouse.y)) && mini.gris == true) {
                            mini.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                            }
                        }
                        if (!(hitBoxR(mini2, event.mouse.x, event.mouse.y)) && mini2.gris == true) {
                            mini2.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                            }
                        }
                        if (!(hitBoxR(Carre1, event.mouse.x, event.mouse.y)) && Carre1.gris == true) {
                            Carre1.gris = false;
                            NomClasse1.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                                peindre = true;
                            }
                        }
                        if (!(hitBoxR(Carre2, event.mouse.x, event.mouse.y)) && Carre2.gris == true) {
                            Carre2.gris = false;
                            NomClasse2.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                                peindre = true;
                            }
                        }
                        if (!(hitBoxR(Carre3, event.mouse.x, event.mouse.y)) && Carre3.gris == true) {
                            Carre3.gris = false;
                            NomClasse3.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                                peindre = true;
                            }
                        }
                        if (!(hitBoxR(Carre4, event.mouse.x, event.mouse.y)) && Carre4.gris == true) {
                            Carre4.gris = false;
                            NomClasse4.gris = false;
                            if (!(ticRdy)) {
                                ticRdy = true;
                                peindre = true;
                            }
                        }
                        break;
                    case ALLEGRO_EVENT_TIMER:
                        if (peindre) {
                            affichageMenu3(background, rectNomJ, Megrim, miniOrbitron);
                            actualiserNom(listeJ->next->next->next->nom, rectNomJ, miniOrbitron);
                            cadreClasse(CadreClasse1, CadreClasse2, CadreClasse3, CadreClasse4);
                            peindrerect=true;
                            peindre = false;
                        }
                        affichageRectangle(SOLARIS,TERRA,MARTIAN,SATURNA, peindrerect,menu ,rectNom1, rectNom2, mini,Carre1,Carre2,Carre3,Carre4, NomClasse1, NomClasse2, NomClasse3, NomClasse4, mini2,Orbitron, miniOrbitron, nbJ);
                        break;
                }
                break;

                ///////////////////////////////////////////////////////////////////////////////////////

            case 7 :
                *play = true;
                *listeJoueurs=listeJ;
                end=true;
                break;
        }
    }

    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    al_destroy_sample(tic);
    al_destroy_sample(clik);
    al_destroy_sample(TitleTheme);
    al_destroy_sample_instance(TitleThemeInstance);
    al_destroy_font(Megrim);
    al_destroy_font(Orbitron);
    al_destroy_font(miniOrbitron);
    al_destroy_font(microOrbitron);
    al_destroy_bitmap(background);
    al_destroy_bitmap(TERRA);
    al_destroy_bitmap(MARTIAN);
    al_destroy_bitmap(SATURNA);
    al_destroy_bitmap(SOLARIS);
    al_destroy_bitmap(icon);
}