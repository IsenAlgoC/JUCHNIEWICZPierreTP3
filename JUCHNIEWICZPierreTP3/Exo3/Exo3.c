#include <stdlib.h>
#include <stdio.h>
#define NBMAXNOTES 30
int main() {
	float Tab[NBMAXNOTES] = { 0 };
	int absent = 0;
	float compteur = 0;
	float moyenne = 0;
	float valtot = 0;
	int ecrit0 = 0;
	for (int i = 0; i < NBMAXNOTES; ++i) {
		float n = 0;
		printf("\nEntrez la note no%d : ", i+1);
		scanf_s("%f", &n);
		if (n == 0) {
			ecrit0 = 1;
		}
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
		if (Tab[i] != -1) {
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
			if ((min > Tab[i]) & (ecrit0 == 1)) {
				min = Tab[i];
			}
			if ((min > Tab[i]) & (ecrit0 == 0) & (Tab[i] != 0)) {
				min = Tab[i];
			}
		}
	}
	moyenne = valtot / compteur;
	printf("\nLa moyenne de ces %d notes est %0.2f",(int)(compteur),moyenne);
	printf("\nIl y a %d absent(s)\n", absent);
	printf("\nLa valeur min est %0.2f et max est %0.2f", min, max);
}