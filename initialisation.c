#include "general.h"

void initialisation (){
    //initialisation1
    assert(al_init());
    assert(al_init_primitives_addon());
    al_init_font_addon();
    assert(al_init_ttf_addon());
    assert(al_init_image_addon());
    al_install_audio();
    al_init_acodec_addon();

    bool play = false;
    Joueurs* listeJoueurs = NULL;

    MENU(&play, &listeJoueurs);
    if(play){
        JEU(listeJoueurs);//Créer une fonction JEU comme dans le general.h et met ton code dedans
    }
    destructionListe(&listeJoueurs);
}