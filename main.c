#include <stdio.h>
#include "llista.h"

int main() {
	// Used for testing the Llista module
	Llista numeros;
	int num = 0;
	int i = 0, count = 0;
	int print_ok = 0;
	char option, buff;

	numeros = LLISTA_crea();

	printf ("TEST 1: Inserting to the right (after PDI)");
	printf ("\nHow many numbers do you want to enter? ");
	scanf ("%d", &count);
		
	while (i < count) {
		printf ("\nEnter an integer: ");
		scanf ("%d", &num);

		// Insert the number entered by user to the list of numbers
		LLISTA_insertDavant (&numeros, num);
		LLISTA_mostrarElements (numeros);
		i++;
	}
	

	printf ("\nTEST 2: Insert to the right (after PDI)\n");
		
	printf ("Enter number to insert to the right: ");
	scanf ("%d", &num);
	LLISTA_insertDavant (&numeros, num);

	//printf ("\nCorrect, we cannot add another element to the list because PDI is at the start of the list. Move forward twice.\n");
	//LLISTA_avanca (&numeros);
	//LLISTA_avanca (&numeros);
	
	while (!print_ok) {
		printf ("\nEnter number to insert to the right: ");
		scanf ("%d", &num);

		LLISTA_insertDarrere (&numeros, num);
		
		LLISTA_mostrarElements (numeros);
		
		scanf ("%c", &buff);	
		printf ("\nDo you want to enter another number? [Y/N] ");
		scanf ("%c", &option);


		if (option == 'Y' || option == 'y') {
			print_ok = 0;
		}
		else {
			print_ok = 1;
		}

	}
	
	printf ("\n");

	// Destroy the list
	LLISTA_destrueix (&numeros);

	return 0;
}

