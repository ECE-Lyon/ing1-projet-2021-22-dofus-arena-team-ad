//
// Created by Mona Lias on 5/2/22.
//

#include "arene.h"
#include <stdio.h>

void construireLarene(int ClasseDuJoueur,int tabArene[LIGNES_TAB][COLONNES_TAB]) {
    char caractereLu;
    //Initialisation des variables
    int ligne=0,colonne=0,myCaractere=0;
    FILE* fichier = NULL;
    switch (ClasseDuJoueur)
    {
        case 1:
            /* code */
            fichier = fopen("../arene1.txt", "r");
            printf("fichier Ok\n");
            break;
        case 2:
            /* code */
            fichier = fopen("../arene1.txt", "r");
            break;
        default:
            printf("Classe du joueur inconnue\n");
            break;
    }

    if (fichier != NULL){
        do {
            for(colonne=0;colonne<=COLONNES_TAB;colonne++) {
                caractereLu= fgetc(fichier);
                myCaractere=caractereLu-'0';
                //printf("ligne = %d, colonne = %d, myCaractere = %d \n",ligne,colonne,myCaractere);
                if (colonne==COLONNES_TAB) { //caractere fin de ligne
                    ligne++;
                }
                else {//stocker le caractere dans le TabArene
                    tabArene[ligne][colonne]=myCaractere;
                }
            }
        } while (caractereLu != EOF); // On continue tant le caractere lu n'est pas EndOfFile (fin de fichier)

        fclose(fichier); // On ferme le fichier
    }
    else {
        printf("fichier vide\n");
    }
}
void initialiserImages(Image* decor){
    decor->Soleil= al_load_bitmap("../background/Soleil.png");
    decor->rocher = al_load_bitmap("../background/rocher.png");
    decor->meteor = al_load_bitmap("../background/meteor.png");
    decor->fleur = al_load_bitmap("../background/fleur.png");
    decor->cailloux = al_load_bitmap("../background/cailloux.png");
    decor->herbe = al_load_bitmap("../background/herbe.png");
    decor->perso = al_load_bitmap("../background/Solaris0.png");
    decor->Mars= al_load_bitmap("../background/Mars.png");
    decor->sort1 = al_load_bitmap("../Image/feu.png");
    decor->sort2 = al_load_bitmap("../Image/vent.png");
    decor->sort3 = al_load_bitmap("../Image/flaqueorageuse.png");
}
void initialiserTableau( int tab[LIGNES_TAB][COLONNES_TAB]){
    int  ligne,colonne;
    for (ligne=0;ligne<LIGNES_TAB;ligne++){
        //boucle sur les colonnes
        for (colonne=0;colonne<COLONNES_TAB;colonne++){
            tab[ligne][colonne]=CASE_LIBRE;
        }
    }
}
void afficherTableau (int tab[LIGNES_TAB][COLONNES_TAB]) {
    int ligne, colonne = 0;
    for (ligne = 0; ligne < LIGNES_TAB; ligne++) {
        for (colonne = 0; colonne < COLONNES_TAB; colonne++) {
            printf("%d ", tab[ligne][colonne]);
        }
        printf("\n");
    }
}
void initialiserTabChemin(Coords tabChemin[PM_MAX+1]){
    for (int i = 0; i < PM_MAX + 1; i++) {
        tabChemin[i].ligne = CASE_VIDE;
        tabChemin[i].colonne = CASE_VIDE;
    }
}

void intialisationArene(int tabArene[LIGNES_TAB][COLONNES_TAB],int TabObstacle[LIGNES_TAB][COLONNES_TAB]){

    int ligne = 0, colonne = 0;

    //Init du tableau pour stoquer l'arene
    initialiserTableau(tabArene);
    //Init du tableau pour stoquer les obstacles
    initialiserTableau(TabObstacle);
    printf("initialisation tab ok\n");
    construireLarene(1, tabArene);

    //le Tableau avec les cases correspondants a l'arene est construit, construisons le tableau des obstacles :
    // Pas de 0 , si 1 c'est de l'herbe , si 2 c'est du sable , si 3 c'est un rocher, si 4 c'est un vaiseau
    // donc si la case continent un chiffre > 3(CASE_OBSTACLE) c'est un obstacle
    for (colonne = 0; colonne < COLONNES_TAB; colonne++) {
        for (ligne = 0; ligne < LIGNES_TAB; ligne++) {
            if (tabArene[ligne][colonne] >= CASE_OBSTACLE) {
                TabObstacle[ligne][colonne] = CASE_OBSTACLE;
            }
        }
    }
}