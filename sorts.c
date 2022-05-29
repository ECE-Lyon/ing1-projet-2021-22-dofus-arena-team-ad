//
// Created by Mona Lias on 5/20/22.
//
#include "general.h"

// A AJOUTER DANS AFFCICHAGE POUR LES SORTSS //

/* case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN : {

    classe = J->classeJ.numClasse;

    if (event.mouse.x >= LARGEUR*(0.659) && event.mouse.x <= LARGEUR*(0.659) + 100 && event.mouse.y >= LONGUEUR*(0.538) &&
    event.mouse.y <= LONGUEUR*(0.538) + 100) {

            //printf(" %s", J->classeJ.sort[0].nom);

        switch (classe) {

            case 0 : {

                    Eblouisssement(&JA, listeJ);
                    break;
                            }
            case 1 : {
                    Guerison(&JA);
                    break;
                    }
            case 2 : {

            Etincelle(&JA, listeJ);
            break;
            }
            case 3 : {

              Elipse(&JA,listeJ);
               break;
              }
            }

    DessinerTout(font, font1,text,J->next,sort1,  sort2, sort3);

    }
if (event.mouse.x >= LARGEUR*(0.783) && event.mouse.x <= LARGEUR*(0.783) + 100 && event.mouse.y >= LONGUEUR*(0.538) &&
event.mouse.y <= LONGUEUR*(0.538) + 100) {

printf(" %s", J->classeJ.sort[1].nom);

switch (classe) {

case 0 : {
Scintillement(&JA, listeJ);
break;
}
case 1 : {

FlecheEmpoisonnee(&JA, listeJ);
break;
}
case 2 : {
Lava(&JA, listeJ);
break;
}
case 3 : {

CercleVicieux(&JA);
break;
}

}
}

if (event.mouse.x >= LARGEUR*(0.89) && event.mouse.x <= LARGEUR*(0.89) + 100 && event.mouse.y >= LONGUEUR*(0.538) &&
event.mouse.y <= LONGUEUR*(0.538) + 100) {

printf(" %s", J->classeJ.sort[2].nom);


switch (classe) {

case 0 : {

ExtraSolar(&JA, listeJ);
break;
}
case 1 : {

TirDroit(&JA, listeJ);
break;
}
case 2 : {

LanceFlamme(&JA, listeJ);
break;
}
case 3 : {
DisqueTranchant(&JA, listeJ);
break;
}

}
}
break; */

//  .H A completer sur le git

void Eblouisssement(Joueurs *JoueurActuel, Joueurs *listeJ) {

    Joueurs *JoueurSuivant = listeJ->next;


    JoueurActuel->pa = JoueurActuel->pa + JoueurActuel->classeJ.sort[0].PA;

    if ( JoueurSuivant != NULL) {

        JoueurSuivant->Eblouissement = true;

    }
    else if(JoueurSuivant == NULL) {
        return;
    }

    Eblouisssement(JoueurActuel, JoueurSuivant->next);
}

void Scintillement(Joueurs *JoueurActuel, Joueurs *listeJ){

    Joueurs *JoueurSuivant = listeJ->next;
    JoueurActuel->pa = JoueurActuel->pa + JoueurActuel->classeJ.sort[1].PA;

    if ( JoueurSuivant != NULL){

        JoueurSuivant->pv = JoueurSuivant->pv + JoueurActuel->classeJ.sort[1].degat;
        return;

    }
    else if (JoueurSuivant == NULL){

        //printf(" PLus de joueur à tester, fin de boucle");
        return;
    }

    Scintillement(JoueurActuel, JoueurSuivant->next);


}


void ExtraSolar(Joueurs *JoueurActuel, Joueurs *listeJ){


    Joueurs *JoueurSuivant = listeJ->next;

    JoueurActuel->pa = JoueurActuel->pa + JoueurActuel->classeJ.sort[2].PA;


    if (JoueurSuivant != NULL && JoueurSuivant->positionJ.colonne - JoueurActuel->positionJ.colonne <= abs(3) || JoueurSuivant->positionJ.ligne -JoueurActuel->positionJ.ligne <= abs(3)  ){

        JoueurSuivant->pv = JoueurSuivant->pv + JoueurActuel->classeJ.sort[2].degat;
        //printf(" Succes Extra solar");
        return;

    }
    else if (JoueurSuivant == NULL){
        // printf(" PAS EXTRA SOLAR");
        return;
    }

    ExtraSolar(JoueurActuel, JoueurSuivant->next);

}


void Guerison(Joueurs *JoueurActuel){

    JoueurActuel->pv = JoueurActuel->pv + JoueurActuel->classeJ.sort[0].degat;
    JoueurActuel->pa = JoueurActuel->pa + JoueurActuel->classeJ.sort[0].PA;

}

void FlecheEmpoisonnee(Joueurs *JoueurActuel, Joueurs *listeJ) {



    Joueurs *JoueurSuivant = listeJ->next;
    JoueurActuel->pa = JoueurActuel->pa + JoueurActuel->classeJ.sort[1].PA;

    if (JoueurSuivant != NULL && JoueurSuivant->positionJ.colonne - JoueurActuel->positionJ.colonne <= abs(5) ||
        JoueurSuivant->positionJ.ligne - JoueurActuel->positionJ.ligne <= abs(5)) {

        JoueurSuivant->pv = JoueurSuivant->pv + JoueurActuel->classeJ.sort[1].degat;
        return;

    } else if (JoueurSuivant == JoueurActuel) {
        return;

    } else {

        FlecheEmpoisonnee(JoueurActuel, JoueurSuivant->next);

    }
}


void TirDroit(Joueurs *JoueurActuel, Joueurs *listeJ){


    Joueurs *JoueurSuivant = listeJ->next;
    JoueurActuel->pa = JoueurActuel->pa + JoueurActuel->classeJ.sort[2] .PA;
    if (JoueurSuivant != NULL && JoueurSuivant->positionJ.colonne - JoueurActuel->positionJ.colonne <= abs(5) ||
        JoueurSuivant->positionJ.ligne - JoueurActuel->positionJ.ligne <= abs(5)) {

        JoueurSuivant->pv = JoueurSuivant->pv + JoueurActuel->classeJ.sort[2].degat;

        return;

    } else if (JoueurSuivant == JoueurActuel) {
        return;

    } else {

        TirDroit(JoueurActuel, JoueurSuivant->next);

    }

}


void Etincelle(Joueurs *JoueurActuel, Joueurs *listeJ){

    Joueurs* JoueurSuivant = listeJ->next;

    JoueurActuel->pa = JoueurActuel->pa + JoueurActuel->classeJ.sort[0] .PA;

    if ( JoueurSuivant !=NULL && JoueurSuivant->positionJ.colonne - JoueurActuel->positionJ.colonne <= abs(1) ||
         JoueurSuivant->positionJ.ligne - JoueurActuel->positionJ.ligne <= abs(1) ) {

        JoueurSuivant->pv = JoueurSuivant->pv + JoueurActuel->classeJ.sort[0].degat;

        return;
    }
    else if ( JoueurSuivant == NULL){
        //printf(" plus de joueur ok etincelle");
        return;
    }
    else{

        Etincelle(JoueurActuel, listeJ->next);

    }

}


void Lava(Joueurs *JoueurActuel, Joueurs *listeJ){


    Joueurs* JoueurSuivant = listeJ->next;

    JoueurActuel->pa = JoueurActuel->pa + JoueurActuel->classeJ.sort[1].PA;


    if ( JoueurSuivant != NULL  && JoueurSuivant->positionJ.colonne - JoueurActuel->positionJ.colonne <= abs(4) ||
         JoueurSuivant->positionJ.ligne - JoueurActuel->positionJ.ligne <= abs(4)) {

        JoueurSuivant->lava = true;

    }
    else if (JoueurSuivant == NULL) {
        // printf( " la ok si plus de joueur ")
        return;
    }

    Lava(JoueurActuel, JoueurSuivant->next);

}

void LanceFlamme(Joueurs *JoueurActuel, Joueurs *listeJ) {


    Joueurs* JoueurSuivant = listeJ->next;
    JoueurActuel->pa = JoueurActuel->pa + JoueurActuel->classeJ.sort[2].PA;

    if (JoueurSuivant != NULL && JoueurSuivant->positionJ.ligne - JoueurActuel->positionJ.ligne <= abs(3) ||
        JoueurSuivant->positionJ.colonne - JoueurActuel->positionJ.colonne <= abs(3)) {

        JoueurSuivant->pv = JoueurSuivant->pv + JoueurActuel->classeJ.sort[2].degat;
        // printf("Attaque réussie");
        // printf(" %d", JoueurSuivant->pv);
    }
    else if( JoueurSuivant == NULL) {

        //printf( " LANCE FLAMME / portee non valide pour cette attaque");

        return;
    }else{

        LanceFlamme(JoueurActuel, listeJ->next);
        //printf( " AUTRE JOUEUR");

    }
}

void Elipse(Joueurs *joueurActuel,Joueurs *listeJ){

    Joueurs* JoueurSuivant = listeJ->next;
    joueurActuel->pa = joueurActuel->pa + joueurActuel->classeJ.sort[0].PA;

    if ( JoueurSuivant != NULL && joueurActuel->positionJ.ligne == JoueurSuivant->positionJ.ligne || joueurActuel->positionJ.colonne == JoueurSuivant->positionJ.colonne) {

        JoueurSuivant->pv = JoueurSuivant->pv + joueurActuel->classeJ.sort[0].degat;

        //  printf( " Attack reached Elipse ")
        return;

    } else if (JoueurSuivant == NULL){

        ///printf( " elispe fin car plus de joueur);
        return;
    }

    Elipse(joueurActuel,listeJ->next);

}

void CercleVicieux(Joueurs *JoueurActuel){

    JoueurActuel->pm = INFINI; // il peut se délacer ou il veut

    JoueurActuel->pa = JoueurActuel->pa + JoueurActuel->classeJ.sort[1].PA;

}

void DisqueTranchant(Joueurs *JA, Joueurs *listeJ){

    Joueurs* JoueurSuivant = listeJ->next;
    JA->pa = JA->pa + JA->classeJ.sort[2].PA; // plus car initialisation en négatif

    if ( JoueurSuivant != NULL && JA->positionJ.ligne - JoueurSuivant->positionJ.ligne <= abs(2)
         || JA->positionJ.colonne - JoueurSuivant->positionJ.colonne <= abs(2)) {

        JoueurSuivant->pv = JoueurSuivant->pv + JoueurSuivant->classeJ.sort[2].degat;

        //  printf( " Attack reached TRANCHANT ")
        return;

    } else if (JoueurSuivant == NULL){

        ///printf( " tranchant fin car plus de joueur);
        return;
    }

    DisqueTranchant(JA,listeJ->next);
    //  printf(" parcours liste joueur ok ");

}