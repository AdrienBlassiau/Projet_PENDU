#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "pendu.h"




void afficherPendu(int mode)
{

	const char *l1[]={"          ","   ______ "};

	const char *l2[]={"          ","  |       ","  |      |","  |/     |"};

	const char *l3[]={"          ","  |       ","  |      o"};

	const char *l4[]={"           ","  |        ","  |      I ","  |     -I-"};

	const char *l5[]={"          ","  |       ","  |      ^"};

	const char *l6[]={"     ","__ __","__|__"};


	int tabmode[10][6]={{0,0,0,0,0,0},{0,0,0,0,0,1},{0,1,1,1,1,2},{1,1,1,1,1,2},
	{1,2,1,1,1,2},{1,2,2,1,1,2},{1,2,2,2,1,2},{1,2,2,3,1,2},{1,2,2,3,2,2},{1,3,2,3,2,2}};


	printf("%s\n",l1[tabmode[mode][0]]);
    printf("%s\n",l2[tabmode[mode][1]]);
    printf("%s\n",l3[tabmode[mode][2]]);
    printf("%s\n",l4[tabmode[mode][3]]);
    printf("%s\n",l5[tabmode[mode][4]]);
	printf("%s\n",l6[tabmode[mode][5]]);

	printf("\n\n");

}

void pendaison(int compare,int *progpendaison)
{
	if (compare == 0)
		*progpendaison+=1;

	afficherPendu(*progpendaison);
}

void affichageAccueil(void)
{
	
	printf("\n----Le jeu du pendu----\n");


	afficherPendu(9);
	
}

int taille(char * mot1)
{
	int i=0;
	while (mot1[i] != '\0')
	{
		i++;
	}

	return i;
}

void creationMotARemplir(char *mot,int l)
{
	int i=0;

	for (i = 0 ; i !=l ; i++)
	{
		mot[i] = '_';
	}	

	mot[i] = '\0';

}

int rechercheCaractere(char * mot1,char * mot2,char lettre,int l)
{
	int i,reussite=0;

	for (i = 0 ; i <l ; i++)
	{
		if (mot1[i] == lettre)
		{
			mot2[i] = lettre;
			reussite+=1;
		}

	}	

	return reussite;
}

int compareChaine(char * mot1, char * mot2, int l)
{

	int i;

	for (i = 0 ; i <l ; i++)
	{
		if (mot1[i] != mot2[i])
		{
			return 0;
		}
	}

	return 1;
}


int propositionMot(char * mot1, char * mot, int l)
{
	if (taille(mot) != l)
	{
		return 0;
	}

	if(compareChaine(mot1,mot,l) == 1)
	{
		return 1;
	}

	return 0;
}

void motAleatoire(char * mot,FILE *fic)
{
	int alea,i=0;
	srand(time(NULL));  // 1 a 22 740

	alea=(rand()%22739);

	while ( i<= alea)
	{
		fgets(mot,256,fic);
		i+=1;
	}

	mot=MajToMin(mot);
}



char * MajToMin(char * mot)
{
	int i=0,l; 

	l=taille(mot);
	for (i = 0 ; i < l ; i++)
	{
		mot[i]=tolower(mot[i]);
	}

	return mot;
}
