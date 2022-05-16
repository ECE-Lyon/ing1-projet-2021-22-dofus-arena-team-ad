#include "general.h"

char quelLettre(ALLEGRO_EVENT event, bool* effacer){
    printf("touche : %d\n", event.keyboard.keycode);
    if (event.keyboard.keycode>= 0 && event.keyboard.keycode<=25){
        return (char)(event.keyboard.keycode + 96);
    }
    else if (event.keyboard.keycode == 63){
        *effacer=true;
        return '\0';
    }
    else{
        return -1;
    }
}

void keyDown(ALLEGRO_EVENT event, char nom[]){
    int i=0;
    char lettre;
    bool effacer=false;
    lettre = quelLettre(event, &effacer);
    i = placeLettre(nom);
    if (lettre != -1) {
        if (effacer) {
            nom[i - 1] = '\0';
            effacer=false;
        } else {
            nom[i] = lettre;
            nom[i + 1] = '\0';
        }
    }

    /*switch (event.keyboard.keycode) {
        case ALLEGRO_KEY_A:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "a");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_Z:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "z");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_E:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "e");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_R:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "r");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_T:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "t");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_Y:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "y");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_U:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "u");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_I:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "i");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_O:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "o");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_P:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "p");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_Q:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "q");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_S:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "s");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_D:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "d");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_F:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "f");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_G:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "g");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_H:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "h");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_J:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "j");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_K:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "k");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_L:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "l");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_M:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "m");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_W:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "w");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_X:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "x");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_C:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "c");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_V:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "v");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_B:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "b");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_N:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, "n");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_SPACE:
            i = placeLettre(nom);
            if (i != NBLETTRE) {
                strcat(nom, " ");
            }
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
        case ALLEGRO_KEY_DELETE:
            i = placeLettre(nom);
            nom[i-1] = '\0';
            affichageMenu3(background, mini, Megrim, miniOrbitron);
            actualiserNom(nom, rectNomJ, miniOrbitron);
            break;
    }
    if(event.keyboard.keycode == ALLEGRO_KEY_LSHIFT || event.keyboard.keycode == ALLEGRO_KEY_RSHIFT) {
        switch (event.keyboard.keycode) {
            case ALLEGRO_KEY_A:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "A");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_Z:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "Z");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_E:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "E");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_R:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "R");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_T:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "T");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_Y:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "Y");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_U:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "U");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_I:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "I");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_O:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "O");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_P:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "P");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_Q:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "Q");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_S:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "S");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_D:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "D");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_F:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "F");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_G:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "G");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_H:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "H");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_J:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "J");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_K:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "K");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_L:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "L");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_M:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "M");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_W:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "W");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_X:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "X");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_C:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "C");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_V:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "V");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_B:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "B");
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
            case ALLEGRO_KEY_N:
                i = placeLettre(nom);
                if (i != NBLETTRE) {
                    strcat(nom, "N");
                    i++;
                }
                affichageMenu3(background, mini, Megrim, miniOrbitron);
                actualiserNom(nom, rectNomJ, miniOrbitron);
                break;
        }
    }*/
}

int placeLettre(char nom[]){
    int i = 0;
    for(;nom[i] != '\0'; i++){}
    return i;
}

void actualiserNom(char nom[], rectangle rectNomJ, ALLEGRO_FONT* miniOrbitron){
    al_draw_textf(miniOrbitron, al_map_rgb(0,0,0), rectNomJ.x+(rectNomJ.longueur/2), rectNomJ.y+(rectNomJ.largeur/2),ALLEGRO_ALIGN_CENTER,"%s",nom);
}