#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "pendu.h"


int main(int argc, char const *argv[])
{

	FILE *fic =fopen("dico.txt","r");

	if (fic ==NULL)
	{
		exit(1);
	}

	char motADeviner[256],motARemplir[256],motPropose[256],lettreProposee;
	int i,l,choix=1,compare,progpendaison=0,test=0;

	
	motAleatoire(motADeviner,fic);

	affichageAccueil();

	l=taille(motADeviner)-2;
	creationMotARemplir(motARemplir,l);
	
	compare=compareChaine(motADeviner,motARemplir,l) ;


	while (compare!=1)
	{
		printf("                                                 %s\n",motARemplir);
		printf("Voulez vous : \n");
		printf("1-Proposer une lettre ? \n");
		printf("2-Proposer un mot ? \n");

		scanf("%d",&choix);

		if (choix == 1)
		{
			printf("-----Entrez votre proposition de lettre : -----\n");
			while (getchar() != '\n');
			scanf("%c",&lettreProposee);
			test=rechercheCaractere(motADeviner,motARemplir,lettreProposee,l);
			pendaison(test,&progpendaison);
			compare=propositionMot(motADeviner,motARemplir,l);
		}

		if (choix == 2)
		{
			printf("-----Entrez votre proposition de mot : -----\n");
			scanf("%s",motPropose);
			compare=propositionMot(motADeviner,motPropose,l);
			pendaison(compare,&progpendaison);
		}

		if (progpendaison == 9)
		{
			printf("Perdu !\n");
			printf("La réponse était : %s\n",motADeviner);
			exit(1);
		}

	}

	printf("                                                 %s\n",motADeviner);
	printf("Gagné !\n");

	fclose(fic);

	return 0;
}