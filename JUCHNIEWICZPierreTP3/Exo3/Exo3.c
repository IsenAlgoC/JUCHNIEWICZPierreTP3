#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define NBMAXNOTES 30
int main() {
	float Tab[NBMAXNOTES] = { -2 };
	int absent = 0;
	float compteur = 0;
	float moyenne = 0;
	float valtot = 0;
	int ecrit0 = 0;
	for (int i = 0; i < NBMAXNOTES; ++i) {
		float n = 0;
		printf("\nEntrez la note no%d : ", i+1);
		scanf_s("%f", &n);
		if (n < 0 || n>20) {
			int choix = 0;
			printf("Vous avez tape une note invalide, l'eleve no %d est-il (2)absent ou voulez-vous arreter la saisie (1)oui ou (0)non ?",i+1);
			scanf_s("%d", &choix);
			if (choix == 2) {
				Tab[i] = -1;
				absent = absent + 1;
			}
			if (choix == 1) {
				break;
			}
			if (choix == 0) {
				printf("Resaisir la valeur :");
				scanf_s("%f", &n);
				compteur = compteur + 1;
				Tab[i] = n;
			}
		}
		else{

			Tab[i] = n;
			compteur = compteur + 1;
		}
	}
	for (int i = 0; i < NBMAXNOTES; i++) {
		if (Tab[i] > 0) {
			valtot = valtot + Tab[i];
		}
	}
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

	printf("TABLEAU No 1 :\n");
	printf("\nNo note		Valeur note");

	for (int i = 0; i < NBMAXNOTES; ++i) {
		if (Tab[i] > 0) {
			printf("\n%d		%0.2f\n", i, Tab[i]);
		}
	}

	float tmp2 = 0;
	for (int d = NBMAXNOTES; d > 0; --d) {
		for (int i = 0; i < d; i++) {
			if (Tab[i] < Tab[i + 1]) {
				tmp2 = Tab[i];
				Tab[i] = Tab[i + 1];
				Tab[i + 1] = tmp;
			}
		}
	}
	printf("TABLEAU No 2 :\n");
	printf("\nNo note		Valeur note");

}

