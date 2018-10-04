#include <stdio.h>
#include "llista.h"

int main() {
	// Used for testing the Llista module
	Llista numeros;
	int num = 0, read = 0;
	int i = 0, count = 0;

	numeros = LLISTA_crea();
	
	printf ("How many numbers do you want to enter? ");
	scanf ("%d", &count);
		
	while (i < count) {
		printf ("Enter an integer: ");
		scanf ("%d", &num);

		// Insert the number entered by user to the list of numbers
		LLISTA_insertDavant (&numeros, num);

		LLISTA_vesInici (&numeros);

		while (!LLISTA_final(numeros)) {
			read = LLISTA_consulta(numeros);
			printf ("Num %d: %d\n", i+1, read);
			LLISTA_avanca(&numeros);
		}
	}
	// Destroy the list
	LLISTA_destrueix (&numeros);

	return 0;
}

