#include <stdlib.h>
#include <stdio.h>

int main() {
	unsigned int entierNonSigne = 2868838400;
	int NbOctetEntierNonSigne = sizeof(entierNonSigne);
    int NbBitEntierNonSigne = NbOctetEntierNonSigne*8;

	printf("%lu est code sur %d octets et sur %d bits\n", entierNonSigne, NbOctetEntierNonSigne, NbBitEntierNonSigne);
	for (int i = 0; i < NbBitEntierNonSigne; i++) {
		if (entierNonSigne & (1<<i)) {
			printf("bit %d: ON\n", i+1);
		}
		else {
			printf("bit %d: OFF\n", i+1);
		}
	}
	printf("\nBYE\n");
}