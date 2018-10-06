#include <stdio.h>
#include "llista.h"

int main() {
	// Used for testing the Llista module
	Llista numeros;
	int num = 0, read = 0;
	int i = 0, count = 0;
	int print_ok = 0;
	char option;

	numeros = LLISTA_crea();

	printf ("TEST 1: Inserting to the left (before PDI)");	
	printf ("\nHow many numbers do you want to enter? ");
	scanf ("%d", &count);
		
	while (i < count) {
		printf ("Enter an integer: ");
		scanf ("%d", &num);

		// Insert the number entered by user to the list of numbers
		LLISTA_insertDavant (&numeros, num);
		i++;
	}
	
	i = 0;	
	LLISTA_vesInici (&numeros);
	while (!LLISTA_final(numeros)) {
		read = LLISTA_consulta(numeros);
		printf ("List of numbers: ");
		printf ("%d ", read);
		LLISTA_avanca(&numeros);
		i++;
	}

	printf ("\nTEST 2: Insert to the right (after PDI)"\n);
		
	while (!print_ok) {
		printf ("Enter number to insert to the right: ");
		scanf ("%d", &num);

		LLISTA_insertDarrere (&numeros, num);
		
		printf ("Do you want to enter another number? [Y/N] ");
		scanf ("%c", &option);
		if (option == 'Y' || option == 'y') {
			print_ok = 0;
		}
		else {
			print_ok = 1;
		}

	}

	// Destroy the list
	LLISTA_destrueix (&numeros);

	return 0;
}

