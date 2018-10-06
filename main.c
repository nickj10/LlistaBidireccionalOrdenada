#include <stdio.h>
#include "llista.h"

int main() {
	// Used for testing the Llista module
	Llista numeros;
	int num = 0, read = 0;
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
	

	printf ("\nTEST 2: Insert to the left (before PDI)\n");
		
	printf ("Enter number to insert to the right: ");
	scanf ("%d", &num);
	LLISTA_insertDarrere (&numeros, num);

	while (!print_ok) {
		printf ("\nEnter number to insert to the left: ");
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

	printf ("\nTEST 3: Delete something from the list.");
	printf ("\nLet's delete two of them!\n");

	LLISTA_elimina (&numeros);
	LLISTA_mostrarElements (numeros);
	LLISTA_elimina (&numeros);
	LLISTA_mostrarElements (numeros);

	printf ("\nTEST 4: Let's go to the end of the list and show the elements backwards!\n");
	
	LLISTA_vesFinal (&numeros);
	LLISTA_retrocedeix (&numeros);
	printf ("List of numbers backwards: \n");
	while (!LLISTA_inici (numeros)) {
		read = LLISTA_consulta (numeros);
		printf ("%d ", read);
		LLISTA_retrocedeix (&numeros);
	}
	
	printf ("\n");

	// Destroy the list
	LLISTA_destrueix (&numeros);

	return 0;
}

