#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define NBMAXNOTES 30


int main() {
	//DECLARATION VARIABLES
	float Tab[NBMAXNOTES] = { -2 };					//init tableau
	int absent = 0;									//init nb d'absents
	float compteur = 0;								//init compteur de note
	float moyenne = 0;								//init moyenne
	float valtot = 0;								//init valeur totale des notes
	for (int i = 0; i < NBMAXNOTES; ++i) {
		float n = 0;
		printf("\nEntrez la note no%d : ", i + 1);
		scanf_s("%f", &n);
		if (n < 0 || n>20) {
			char choix;
			printf("Vous avez tape une note invalide, l'eleve no %d est-il (A)absent ou voulez-vous arreter la saisie (O)oui ou (N)non ?", i + 1);
			choix = _getch();
			printf("%c", choix);
			switch (choix) {
			case 'A':
				Tab[i] = -1;
				absent = absent + 1;
				break;

			case 'a':
				Tab[i] = -1;
				absent = absent + 1;
				break;

			case 'O':
				i = NBMAXNOTES;
				break;

			case 'o':
				i = NBMAXNOTES;
				break;

			case 'N':
				printf("Resaisir la valeur :");
				scanf_s("%f", &n);
				compteur = compteur + 1;
				Tab[i] = n;
				break;

			case 'n':
				printf("\nResaisir la valeur :");
				scanf_s("%f", &n);
				compteur = compteur + 1;
				Tab[i] = n;
				break;

			default :
				break;

			}
		}
			else {
				Tab[i] = n;
				compteur = compteur + 1;
			}
	}

	//addition de toutes les notes
	for (int i = 0; i < NBMAXNOTES; i++) {
		if (Tab[i] > 0) {
			valtot = valtot + Tab[i];
		}
	}

	//Détermination du max et du min
	float max = 0;
	float min = 20;
	for (int i = 0; i < NBMAXNOTES; i++) {
		if (Tab[i] > 0) {
			if (max < Tab[i]) {
				max = Tab[i];
			}
			if (min > Tab[i]) {
				min = Tab[i];
			}
		}
	}
	moyenne = valtot / compteur;
	printf("\nLa moyenne de ces %d notes est %0.2f",(int)(compteur),moyenne);
	printf("\nIl y a %d absent(s)\n", absent);
	printf("\nLa valeur min est %0.2f et max est %0.2f", min, max);


	float SommeEcartType = 0;
	float tmp = 0;
	for (int i = 0; i < NBMAXNOTES; ++i) {
		if (Tab[i] > 0) {
			tmp = pow(((double)Tab[i] - (double)moyenne), 2);
			SommeEcartType += tmp;
		}
	}
	float ecarttype = SommeEcartType / (compteur-1);
	ecarttype = sqrt(ecarttype);
	printf("\nL'ecart type est egal a %0.2f\n", ecarttype);

	float Tab2[30] = { 0 };
	

	//AFFICHAGE PREMIER TABLEAU
	printf("TABLEAU No 1 :\n");
	printf("\nNo note		Valeur note");
	for (int i = 0; i < NBMAXNOTES; ++i) {
		if (Tab[i] > 0) {
			printf("\n%d		%0.2f\n", i+1, Tab[i]);
		}
		Tab2[i] = Tab[i];
	}

	//TRI A BULLE 
	int desordre = 1;
	while (desordre) {
		desordre = 0;
		for (int i = 0; i < compteur; i++) {
				if (Tab2[i] > Tab2[i + 1]) {
					int tmp = Tab2[i + 1];
					Tab2[i + 1] = Tab2[i];
					Tab2[i] = tmp;
					desordre = 1;
				}
		}
	}

	printf("TABLEAU No 2 :\n");
	printf("\nNo note		Valeur note");

	for (int i = 0; i < NBMAXNOTES; ++i) {
		if (Tab2[i] > 0) {
			printf("\n%d		%0.2f\n", i, Tab2[i]);
		}
	}
}

