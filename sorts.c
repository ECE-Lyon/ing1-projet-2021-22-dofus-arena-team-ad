//
// Created by Mona Lias on 5/20/22.
//
#include "general.h"

int verifPortee (Joueurs *JA, Joueurs *lJ, int n) {
    Joueurs *JS = lJ->next;
    int d = valeureAbsolue(JS->positionJ.ligne,JS->positionJ.colonne);
    if (JA->classeJ.sort[n].portee <= d){
        return 1;
    } else {return 0;}
}

void Eblouisssement(Joueurs *JoueurActuel, Joueurs *listeJ) {

    Joueurs *JoueurSuivant = listeJ->next;
    int v = verifPortee(JoueurActuel,listeJ,0);

    if (JoueurSuivant != listeJ && JoueurActuel->pa >= JoueurActuel->classeJ.sort[0].PA && v == 1) {
        JoueurActuel->pa = JoueurActuel->pa + JoueurActuel->classeJ.sort[0].PA;
        JoueurSuivant->Eblouissement = true;
    }
    else {
        return;
    }

    Eblouisssement(JoueurActuel, JoueurSuivant->next);
}

void Scintillement(Joueurs *JoueurActuel, Joueurs *listeJ){

    Joueurs *JoueurSuivant = listeJ->next;
    int v = verifPortee(JoueurActuel,listeJ,0);

    if (JoueurSuivant != listeJ && JoueurActuel->pa >= JoueurActuel->classeJ.sort[1].PA && v == 1){
        JoueurSuivant->pv = JoueurSuivant->pv + JoueurActuel->classeJ.sort[1].degat;
        JoueurActuel->pa = JoueurActuel->pa + JoueurActuel->classeJ.sort[1].PA;
        return;
    } else {
        printf("plus de PA");
        return;
    }
    /*else if (JoueurSuivant==listeJ){
        //printf(" PLus de joueur à tester, fin de boucle");
        return;
    }*/

    Scintillement(JoueurActuel, JoueurSuivant->next);

}


void ExtraSolar(Joueurs *JoueurActuel, Joueurs *listeJ){

    Joueurs *JoueurSuivant = listeJ->next;
    int v = verifPortee(JoueurActuel,listeJ,0);

    if (JoueurSuivant != listeJ && JoueurSuivant->positionJ.colonne - JoueurActuel->positionJ.colonne <= abs(3) || JoueurSuivant->positionJ.ligne -JoueurActuel->positionJ.ligne <= abs(3)
    && JoueurActuel->pa >= JoueurActuel->classeJ.sort[2].PA && v == 1){

        JoueurActuel->pa = JoueurActuel->pa + JoueurActuel->classeJ.sort[2].PA;
        JoueurSuivant->pv = JoueurSuivant->pv + JoueurActuel->classeJ.sort[2].degat;
        printf(" Succes Extra solar");
        return;

    }
    else if (JoueurSuivant==listeJ){
        // printf(" PAS EXTRA SOLAR");
        return;
    }

    ExtraSolar(JoueurActuel, JoueurSuivant->next);

}


void Guerison(Joueurs *JoueurActuel, Joueurs *listeJ){
    printf("Guerison\n");
    int v = verifPortee(JoueurActuel,listeJ,0);
    if (JoueurActuel->pa >= JoueurActuel->classeJ.sort[0].PA && v == 1) {
        JoueurActuel->pv = JoueurActuel->pv + JoueurActuel->classeJ.sort[0].degat;
        JoueurActuel->pa = JoueurActuel->pa + JoueurActuel->classeJ.sort[0].PA;
    } else {
        printf("pas assez de PA");
    }
}

void FlecheEmpoisonnee(Joueurs *JoueurActuel, Joueurs *listeJ) {

    Joueurs *JoueurSuivant = listeJ->next;
    printf("fleche empoisonnée\n");
    int v = verifPortee(JoueurActuel,listeJ,0);
    if (JoueurSuivant !=listeJ && JoueurSuivant->positionJ.colonne - JoueurActuel->positionJ.colonne <= abs(5) ||
        JoueurSuivant->positionJ.ligne - JoueurActuel->positionJ.ligne <= abs(5) &&
                JoueurActuel->pa >= JoueurActuel->classeJ.sort[1].PA && v == 1) {
        JoueurActuel->pa = JoueurActuel->pa + JoueurActuel->classeJ.sort[1].PA;
        JoueurSuivant->pv = JoueurSuivant->pv + JoueurActuel->classeJ.sort[1].degat;
        return;

    } else if (JoueurSuivant==listeJ) {
        return;

    } else {

        FlecheEmpoisonnee(JoueurActuel, JoueurSuivant->next);

    }
}


void TirDroit(Joueurs *JoueurActuel, Joueurs *listeJ){


    Joueurs *JoueurSuivant = listeJ->next;
    int v = verifPortee(JoueurActuel,listeJ,0);
    printf("Tir Droit\n");
    if (JoueurSuivant != listeJ && JoueurSuivant->positionJ.colonne - JoueurActuel->positionJ.colonne <= abs(5) ||
        JoueurSuivant->positionJ.ligne - JoueurActuel->positionJ.ligne <= abs(5) &&
                JoueurActuel->pa >= JoueurActuel->classeJ.sort[2].PA && v == 1) {

        JoueurActuel->pa = JoueurActuel->pa + JoueurActuel->classeJ.sort[2] .PA;
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
    int v = verifPortee(JoueurActuel,listeJ,0);
    printf("etincelle\n");
    if ( JoueurSuivant !=listeJ && JoueurSuivant->positionJ.colonne - JoueurActuel->positionJ.colonne <= abs(1) ||
         JoueurSuivant->positionJ.ligne - JoueurActuel->positionJ.ligne <= abs(1) &&
                 JoueurActuel->pa >= JoueurActuel->classeJ.sort[0].PA && v == 1) {

        JoueurActuel->pa = JoueurActuel->pa + JoueurActuel->classeJ.sort[0] .PA;
        JoueurSuivant->pv = JoueurSuivant->pv + JoueurActuel->classeJ.sort[0].degat;
        return;
    }
    else if ( JoueurSuivant == listeJ){
        //printf(" plus de joueur ok etincelle");
        return;
    }
    else{

        Etincelle(JoueurActuel, listeJ->next);

    }

}


void Lava(Joueurs *JoueurActuel, Joueurs *listeJ){


    Joueurs* JoueurSuivant = listeJ->next;

    printf("Lava\n");
    int v = verifPortee(JoueurActuel,listeJ,0);

    if ( JoueurSuivant != listeJ  && JoueurSuivant->positionJ.colonne - JoueurActuel->positionJ.colonne <= abs(4) ||
         JoueurSuivant->positionJ.ligne - JoueurActuel->positionJ.ligne <= abs(4) &&
                 JoueurActuel->pa >= JoueurActuel->classeJ.sort[1].PA && v == 1) {
        JoueurActuel->pa = JoueurActuel->pa + JoueurActuel->classeJ.sort[1].PA;
        JoueurSuivant->lava = true;

    }
    else if (JoueurSuivant == listeJ) {
        // printf( " la ok si plus de joueur ")
        return;
    }

    Lava(JoueurActuel, JoueurSuivant->next);

}

void LanceFlamme(Joueurs *JoueurActuel, Joueurs *listeJ) {


    Joueurs* JoueurSuivant = listeJ->next;
    int v = verifPortee(JoueurActuel,listeJ,0);

    if (JoueurSuivant != listeJ && JoueurSuivant->positionJ.ligne - JoueurActuel->positionJ.ligne <= abs(3) ||
        JoueurSuivant->positionJ.colonne - JoueurActuel->positionJ.colonne <= abs(3) &&
                JoueurActuel->pa >= JoueurActuel->classeJ.sort[2].PA && v == 1) {

        JoueurActuel->pa = JoueurActuel->pa + JoueurActuel->classeJ.sort[2].PA;
        JoueurSuivant->pv = JoueurSuivant->pv + JoueurActuel->classeJ.sort[2].degat;
        printf("Attaque réussie");
        printf(" %d", JoueurSuivant->pv);
    }
    else if( JoueurSuivant == listeJ) {
        printf( " LANCE FLAMME / portee non valide pour cette attaque");

        return;
    }else{

        LanceFlamme(JoueurActuel, listeJ->next);
        //printf( " AUTRE JOUEUR");

    }
}

void Elipse(Joueurs *JoueurActuel,Joueurs *listeJ){

    Joueurs* JoueurSuivant = listeJ->next;
    int v = verifPortee(JoueurActuel,listeJ,0);

    if ( JoueurSuivant != listeJ && JoueurActuel->positionJ.ligne == JoueurSuivant->positionJ.ligne ||
            JoueurActuel->positionJ.colonne == JoueurSuivant->positionJ.colonne &&
            JoueurActuel->pa >= JoueurActuel->classeJ.sort[0].PA && v == 1) {

        JoueurActuel->pa = JoueurActuel->pa + JoueurActuel->classeJ.sort[0].PA;
        JoueurSuivant->pv = JoueurSuivant->pv + JoueurActuel->classeJ.sort[0].degat;
        printf( " Attack reached Elipse ");
        return;

    } else if ( JoueurSuivant == listeJ){

        ///printf( " elispe fin car plus de joueur);
        return;
    }

    Elipse(JoueurActuel,listeJ->next);

}

void CercleVicieux(Joueurs *JoueurActuel, Joueurs *listeJ){
    int v = verifPortee(JoueurActuel,listeJ,0);
    if (JoueurActuel->pa >= JoueurActuel->classeJ.sort[1].PA && v == 1) {
        JoueurActuel->pm = INFINI; // il peut se délacer ou il veut
        printf("cercle Vicieux\n");
        JoueurActuel->pa = JoueurActuel->pa + JoueurActuel->classeJ.sort[1].PA;
    } else {
        printf("pas assez de PA");
    }
}

void DisqueTranchant(Joueurs *JoueurActuel, Joueurs *listeJ){
    Joueurs* JoueurSuivant = listeJ->next;
    int v = verifPortee(JoueurActuel,listeJ,0);

    if ((JoueurSuivant != listeJ && JoueurActuel->positionJ.ligne - JoueurSuivant->positionJ.ligne <= abs(2) ||
            JoueurActuel->positionJ.colonne - JoueurSuivant->positionJ.colonne <= abs(2)) &&
            JoueurActuel->pa >= JoueurActuel->classeJ.sort[2].PA && JoueurSuivant->positionJ.ligne && v== 1) {

        JoueurActuel->pa = JoueurActuel->pa + JoueurActuel->classeJ.sort[2].PA; // plus car initialisation en négatif
        JoueurSuivant->pv = JoueurSuivant->pv + JoueurSuivant->classeJ.sort[2].degat;
        printf(" Attack reached TRANCHANT ");
        return;

    } else if ( JoueurSuivant == listeJ){
        ///printf("tranchant fin car plus de joueur);
        return;
    }
    DisqueTranchant(JoueurActuel,listeJ->next);
    //  printf(" parcours liste joueur ok ");

}

