#include "general.h"

Joueurs *iniJ(int numJ) {
    Joueurs *tempo = malloc(sizeof(Joueurs));
    tempo->next = NULL;
    tempo->pm = 3;
    tempo->pa = 10;
    tempo->nom[0] = '\0';
    tempo->numJ = numJ;
    return tempo;
}

void InitialiserClass(classe *Solaris, classe *Terra, classe *Martian, classe *Saturna) {
    strcpy (Solaris->nom, " Solaris");
    Solaris->numClasse = 0;
    Solaris->pv = 50;
    

    strcpy (Terra->nom, " Terra");
    Terra->numClasse = 1;
    Terra->pv = 50;
   

    strcpy (Martian->nom, " Martian");
    Martian->numClasse = 2;
    Martian->pv = 75;
  

    strcpy (Saturna->nom, " Saturna");
    Saturna->numClasse = 3;
    Saturna->pv = 60;
}

void initialiserSort(Sorts tabsort[], classe *Solaris, classe *Terra, classe *Martian, classe *Saturna) {

    //Solaris :
    strcpy(tabsort[0].nom, "Eblouissement");
    tabsort[0].degat = 0;
    tabsort[0].PA = -5;
    tabsort[0].portee = INFINI;
    tabsort[0].pourEchec = 0.3;
    tabsort[0].timestour = 1;
    tabsort[0].timespart =  1;
    Solaris->sort[0] = tabsort[0];

    strcpy(tabsort[1].nom, "Scintillement");
    tabsort[1].degat = -5;
    tabsort[1].PA = -5;
    tabsort[1].portee = 30;
    tabsort[1].pourEchec = 0.3;
    tabsort[1].timestour = 2;
    tabsort[1].timespart =  INFINI;
    Solaris->sort[1] = tabsort[1];

    strcpy(tabsort[2].nom, "Extra-Solar");
    tabsort[2].degat = -30;
    tabsort[2].PA = -10;
    tabsort[2].portee = 3;
    tabsort[2].pourEchec = 0.3;
    tabsort[2].timestour = INFINI;
    tabsort[2].timespart =  INFINI;
    Solaris->sort[2] = tabsort[2];

    //Terra :
    strcpy(tabsort[3].nom, "Guerison");
    tabsort[3].degat = 10; // + degat sur lui meme
    tabsort[3].PA = -4;
    tabsort[3].portee = INFINI;
    tabsort[3].pourEchec = 0.3;
    tabsort[3].timestour = 2;
    tabsort[3].timespart =  5;
    Terra->sort[0] = tabsort[3];

    strcpy(tabsort[4].nom, "fleche empoisonne");
    tabsort[4].degat = -5;
    tabsort[4].PA = -2;
    tabsort[4].portee = 5;
    tabsort[4].pourEchec = 0.33;
    tabsort[4].timestour = 5;
    tabsort[4].timespart =  15;
    Terra->sort[1] = tabsort[4];

    strcpy(tabsort[5].nom, "Tir Droit");
    tabsort[5].degat = -10;
    tabsort[5].PA = -5;
    tabsort[5].portee = 5;
    tabsort[5].pourEchec = 0.3;
    tabsort[5].timestour = INFINI;
    tabsort[5].timespart =  INFINI;
    Terra->sort[2] = tabsort[5];

    //Martian :
    strcpy(tabsort[6].nom, "Etincelle");
    tabsort[6].degat = -20;
    tabsort[6].PA = -5;
    tabsort[6].portee = 1;
    tabsort[6].pourEchec = 0.3;
    tabsort[6].timestour = 2;
    tabsort[6].timespart =  INFINI;
    Martian->sort[0] = tabsort[6];

    strcpy(tabsort[7].nom, "Lava");
    tabsort[7].degat = 0;
    tabsort[7].PA = -4;
    tabsort[7].portee = 4;
    tabsort[7].pourEchec = 0.3;
    tabsort[7].timestour = INFINI;
    tabsort[7].timespart =  INFINI;
    Martian->sort[1] = tabsort[7];

    strcpy(tabsort[8].nom, "Lance-Flamme");
    tabsort[8].degat = -5;
    tabsort[8].PA = -3;
    tabsort[8].portee = 3;
    tabsort[8].pourEchec = 0.3;
    tabsort[8].timestour = 2;
    tabsort[8].timespart =  INFINI;
    Martian->sort[2] = tabsort[8];

    //Saturna :
    strcpy(tabsort[9].nom, "Elipse");
    tabsort[9].degat = -10;
    tabsort[9].PA = -4;
    tabsort[9].portee = 3;// en ligne portée inifini
    tabsort[9].pourEchec = 0.3;
    tabsort[9].timestour = INFINI;
    tabsort[9].timespart =  INFINI;
    Saturna->sort[0] = tabsort[9];

    strcpy(tabsort[10].nom, "Cercle Vicieux");
    tabsort[10].degat = 0; //
    tabsort[10].PA = -6;
    tabsort[10].portee = 3;
    tabsort[10].pourEchec = 0.3;
    tabsort[10].timestour = 2;
    tabsort[10].timespart =  20;
    Saturna->sort[1] = tabsort[10];

    strcpy(tabsort[11].nom, "Disque Tranchant");
    tabsort[11].degat = -10;
    tabsort[11].PA = -2;
    tabsort[11].portee = 2;
    tabsort[11].pourEchec = 0.3;
    tabsort[11].timestour = INFINI;
    tabsort[11].timespart =  INFINI;
    Saturna->sort[2] = tabsort[11];

}

void initCaracteristiquesJoueurs(Joueurs **listeJ, classe Solaris, classe Terra, classe Martian, classe Saturna) {
    Joueurs *tmp = *listeJ;
    switch (tmp->classeJ.numClasse) {
        case 0: {
            tmp->classeJ = Solaris;
            break;
        }
        case 1: {
            tmp->classeJ = Terra;
            break;
        }
        case 2: {
            tmp->classeJ = Martian;
            break;
        }
        case 3: {
            tmp->classeJ = Saturna;
            break;
        }
        default: {
            printf("erreur classe joueur\n");
            break;
        }
    }
    tmp= tmp->next;
    while (tmp != *listeJ) {
        switch (tmp->classeJ.numClasse) {
            case 0: {
                tmp->classeJ = Solaris;
                break;
            }
            case 1: {
                tmp->classeJ = Terra;
                break;
            }
            case 2: {
                tmp->classeJ = Martian;
                break;
            }
            case 3: {
                tmp->classeJ = Saturna;
                break;
            }
            default: {
                printf("erreur classe joueur\n");
                break;
            }
        }
        tmp = tmp->next;
    }
}


/*
Joueurs* initialisationJ(int nbJ, Joueurs* listeJ){
    Joueurs *tempo = NULL;
    Joueurs *fin = NULL;
    Joueurs *head = listeJ;

    for(int i=0; i<nbJ; i++){
        if (head == NULL){
            head = iniJ();
        }else {
            tempo = iniJ();
            fin = head;
            while (fin->next != NULL) {
                fin = fin->next;
            }
            fin->next = tempo;
        }
    }
    tempo->next = head;
    return head;
}
*/

    void passerJnext(Joueurs **JA, Joueurs *listeJ) {
        Joueurs *tempo = listeJ;
        while ((*JA)->numJ != tempo->numJ) {
            tempo = tempo->next;
        }
        tempo->pv = (*JA)->pv;
        *JA = (*JA)->next;
        (*JA)->pm = 0;
    }

void destructionListe(Joueurs** listeJ){
    Joueurs *head = *listeJ;
    Joueurs *temp = NULL;

    while (head!=NULL){
        temp = head->next;
        free(head);
        head = temp;
    }
    *listeJ = NULL;
}