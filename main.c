#include <stdio.h>

int main() {
	// Used for testing the Llista module
	Llista numeros;
	int num = 0;

	numeros = LLISTA_crea();
	
	printf ("Enter an integer: ");
	scanf ("%d", &num);

	// Insert the number entered by user to the list of numbers
	LLISTA_insertaDelante (&numeros, num);


	// Destroy the list
	LLISTA_destrueix (&numeros);

	return 0;
}

