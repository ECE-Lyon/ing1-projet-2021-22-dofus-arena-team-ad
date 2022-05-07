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
    printf("\nClasse du joueur=%d\n",ClasseDuJoueur);
    switch (ClasseDuJoueur)
    {
        case 1:
            /* code */
            fichier = fopen("../arene1.txt", "r");
            break;
        case 2:
            /* code */
            fichier = fopen("../arene2.txt", "r");
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
    return;

}
void initialiserImages(Image* decor){
    decor->fond= al_load_bitmap("../background/fond.png");
    decor->rocher = al_load_bitmap("../background/rocher.png");
    decor->meteor = al_load_bitmap("../background/meteor.png");
    decor->fleur = al_load_bitmap("../background/fleur.png");
    decor->cailloux = al_load_bitmap("../background/cailloux.png");
    decor->perso = al_load_bitmap("../background/perso.png");
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