#ifndef __PENDU__
#define __PENDU__


void affichageAccueil(void);
void afficherPendu(int);
int taille(char *);
int rechercheCaractere(char *,char *,char,int);
int compareChaine(char *, char *, int);
void pendaison(int,int *);
int propositionMot(char *, char *, int);
void creationMotARemplir(char *, int);
void motAleatoire(char * ,FILE * );
char * MajToMin(char * );


#endif



