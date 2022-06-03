#include <stdio.h>
#include <allegro5/allegro.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>


#define LARGEUR 1365
#define HAUTEUR 835
#define ECRAN_LONGUEUR 1365
#define ECRAN_LARGEUR 835
#define NBLETTRE 21
#define INFINI 100
#define LIGNES_TAB 15
#define COLONNES_TAB 20
#define CASE_OBSTACLE 3
#define CASE_LIBRE 0
#define TAILLE_CASE 100
#define X_TAB 80
#define Y_TAB 135
#define CASE_VIDE 9999
#define TAILLE_POLICE_MAX 120
//#define BLANC al_map_rgb (255, 255, 255)

#ifndef PROJET_GENERAL_H
#define PROJET_GENERAL_H
/////////////////////////////////////////STRUCTURES////////////////////////////////////////////////

//DEPLACEMENT

typedef struct {
    float x,y;
    bool deplacement;
}Case;

typedef struct{
    int ligne, colonne;
}Coords;

//PERSONNAGES

typedef struct{
    char nom[100];
    int degat, PA, portee, timestour, timespart;
    float pourEchec;
}Sorts;

typedef struct{
    char nom[10];
    int pv;
    int numClasse;
    //voir tableau de pointeur sur fonction
    Sorts sort[4];
}classe;

typedef struct {
    ALLEGRO_BITMAP * rocher, *Soleil, *perso, *cailloux,*fleur, *meteor, *herbe, *Mars, *sort1, *sort2, *sort3, *imJ, *Terre, *Saturne, *etoile;
    char nom[100];
}Image;

typedef struct J{
    bool Eblouissement, lava; //à ini en false
    char nom[NBLETTRE];
    int pv, pa, pm, numJ;
    struct J* next;
    struct J*prev;
    ALLEGRO_BITMAP *image;
    classe classeJ;
    Coords positionJ;
}Joueurs;


//AFFICHAGE
typedef struct {
    int largeur;
    int longueur;
    int x;
    int y;
    bool gris;
}rectangle;

/////////////////////////////////////////FONCTIONS////////////////////////////////////////////////

void initialisation ();
void evenements(bool end, ALLEGRO_DISPLAY *display, ALLEGRO_KEYBOARD_STATE keyboard, ALLEGRO_EVENT_QUEUE *queue, ALLEGRO_EVENT event,
                ALLEGRO_MOUSE_STATE mouse,ALLEGRO_TIMER* timer, rectangle rectNom1, rectangle rectNom2, Joueurs J1, Joueurs J2, ALLEGRO_FONT*
                Montserrat, ALLEGRO_BITMAP* background);
void destruction(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *queue, ALLEGRO_TIMER* timer, ALLEGRO_FONT* Montserrat, ALLEGRO_BITMAP* background);

//clavier
void keyDown(ALLEGRO_EVENT event, char nom[]);
int placeLettre(char nom[]);
void actualiserNom(char nom[], rectangle rectNomJ, ALLEGRO_FONT* miniOrbitron);

//affichage
void MENU(bool* play, Joueurs** listeJoueurs);
void affichageMenu1(ALLEGRO_BITMAP* background, rectangle Carre1, rectangle Carre2, rectangle Carre3, rectangle Carre4,ALLEGRO_FONT* Megrim,ALLEGRO_FONT* Orbitron);
void affichageMenu0(ALLEGRO_BITMAP* background, rectangle rectNom1, rectangle rectNom2, ALLEGRO_FONT* Megrim,ALLEGRO_FONT* Orbitron);
void affichageMenu2(ALLEGRO_BITMAP* background, rectangle mini, rectangle CarreCredit, ALLEGRO_FONT* Megrim, ALLEGRO_FONT* miniOrbitron, ALLEGRO_FONT* microOrbitron);
void affichageMenu3(ALLEGRO_BITMAP* background, rectangle mini, ALLEGRO_FONT* Megrim, ALLEGRO_FONT* miniOrbitron);
void affichageMenu7(ALLEGRO_BITMAP* background, rectangle CarreCredit,ALLEGRO_FONT* Megrim);
void affichageRectangle(ALLEGRO_BITMAP* SOLARIS,ALLEGRO_BITMAP* TERRA,ALLEGRO_BITMAP* MARTIAN,ALLEGRO_BITMAP* SATURNA, bool peindrerect, int menu, rectangle rectNom1, rectangle rectNom2, rectangle mini,rectangle Carre1, rectangle Carre2,
                        rectangle Carre3, rectangle Carre4, rectangle NomClasse1, rectangle NomClasse2, rectangle NomClasse3, rectangle NomClasse4,
                        rectangle mini2, ALLEGRO_FONT* Orbitron, ALLEGRO_FONT* miniOrbitron, int nbJ);
void drawrectangle(rectangle r,ALLEGRO_FONT* font, char phase[]);
unsigned char hitBoxR(rectangle r, int x, int y);
void textCredit(rectangle r, ALLEGRO_FONT* microOrbiton);
void cadreClasse(rectangle CadreClasse1, rectangle CadreClasse2, rectangle CadreClasse3,rectangle CadreClasse4);
void AffichageIconePerso(ALLEGRO_BITMAP* SOLARIS,ALLEGRO_BITMAP* TERRA,ALLEGRO_BITMAP* MARTIAN,ALLEGRO_BITMAP* SATURNA, rectangle Carre1, rectangle Carre2,rectangle Carre3,rectangle Carre4);
int valeureAbsolue(int i, int j);

//personnages
Joueurs* initialisationJ(int nbJ, Joueurs* listeJ);
Joueurs* iniJ(int numJ);
void InitialiserClass(classe* Solaris, classe* Terra, classe* Martian, classe* Saturna);
void initialiserSort(Sorts tabsort[],classe* Solaris, classe* Terra, classe* Martian, classe* Saturna);
void passerJnext(Joueurs**JA, Joueurs* listeJ);
void initCaracteristiquesJoueurs(Joueurs **listeJ, classe Solaris, classe Terra, classe Martian, classe Saturna);
//jeu
void JEU(Joueurs* listeJ);
void libererListe( Joueurs ** liste);
void destroy(Image decors, ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *queue, ALLEGRO_FONT* Megrim,ALLEGRO_FONT* Orbitron, ALLEGRO_FONT*miniOrbitron, ALLEGRO_FONT*microOrbitron, ALLEGRO_SAMPLE *FightSong,ALLEGRO_SAMPLE_INSTANCE *FightSongInstance,ALLEGRO_SAMPLE *tic,ALLEGRO_SAMPLE *clik);
//affichage jeu
void affichageG(ALLEGRO_BITMAP* arene, ALLEGRO_BITMAP *sort1, ALLEGRO_BITMAP*sort2, ALLEGRO_BITMAP*sort3, rectangle rectNext, ALLEGRO_FONT* miniOrbitron, ALLEGRO_FONT* Orbitron,
                ALLEGRO_COLOR BLANC, Joueurs JA);
void affichageEchape(rectangle rectechape, rectangle rectfond, ALLEGRO_FONT* miniOrbitron, ALLEGRO_FONT* Orbitron);
void actuaRectEchape(rectangle rectreprendre, rectangle rectExit, ALLEGRO_FONT* miniOrbitron);
void actuaRect(rectangle rectNext, ALLEGRO_FONT* miniOrbitron);
void afficherTableau (int tab[LIGNES_TAB][COLONNES_TAB]);
void destructionListe(Joueurs** listeJ);

//sorts
void Eblouisssement(Joueurs *JoueurActuel, Joueurs *listeJ);
void Scintillement(Joueurs *JoueurActuel, Joueurs *listeJ);
void ExtraSolar(Joueurs *JoueurActuel, Joueurs *listeJ);
void Guerison(Joueurs *JoueurActuel, Joueurs *listeJ);
void FlecheEmpoisonnee(Joueurs *JoueurActuel, Joueurs *listeJ);
void TirDroit(Joueurs *JoueurActuel, Joueurs *listeJ);
void Etincelle(Joueurs *JoueurActuel, Joueurs *listeJ);
void Lava(Joueurs *JoueurActuel, Joueurs *listeJ);
void LanceFlamme(Joueurs *JoueurActuel, Joueurs *listeJ);
void Elipse(Joueurs *joueurActuel,Joueurs *listeJ);
void CercleVicieux(Joueurs *JoueurActuel, Joueurs *listeJ);
void DisqueTranchant(Joueurs *JA, Joueurs *listeJ);
#endif //PROJET_GENERAL_H
