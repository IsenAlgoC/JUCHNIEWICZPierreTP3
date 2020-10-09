#include <stdlib.h>
#include<stdio.h>
#define carre(x) x * x 

int main() {
	int Nb = 5;
	int NbCarre = carre(Nb);
	int Nbplus1 = Nb + 1;
	int NbCarreplus1 = carre(Nbplus1);	//sans les paranthèses à l'intérieur, nous obtenions 11
	printf("Le carre de %d est %d\n", Nb, NbCarre);
	printf("Le carre de %d+1 est %d\n", Nb, NbCarreplus1);
}