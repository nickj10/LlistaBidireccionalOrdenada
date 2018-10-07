/*********************************************************
 *
 * @Purpose: This file contains the implementation of the
 *	functions for the Sorted Bidirectional Linked List.
 * @Autor: Nicole Marie Jimenez Burayag
 * @Data creacio: 01/10/2018
 * @Data ultima modificacio: 07/10/2018
 * 
 ********************************************************/

#include "llista.h"

/*******************
*
* @Purpose: Create the bidirectional linked list
* @Parameters: -
* @Return: Returns an empty  bidirectional linked list
*
*******************/
Llista LLISTA_crea() {
	Llista l;

	// Create two "ghost" nodes that will represent the first and last node	
	l.pri = (Node*)malloc(sizeof(Node));
	if (l.pri == NULL) {
		printf ("\n Error, node cannot be created.");
	}
	else {
		l.ult = (Node*)malloc(sizeof(Node));
		if (l.ult == NULL) {
			printf ("\nError, node cannot be created.");
		}
		else {
			// PDI will be pointing at the first node when the list is created
			l.pdi = l.pri;
			l.pri->sig = l.ult;
			l.pri->ant = NULL;
			l.ult->ant = l.pri;
			l.ult->sig = NULL;
			l.ult->ant = l.pri;
		}
	}

	return l;
}

/*******************
*
* @Purpose: Gets the value of the element in the node where PDI is pointing at
* @Parameters: l = bidirectional linked list
* @Return: Returns an integer which is the value of the element
*
*******************/
int LLISTA_consulta (Llista l) {
	int e;
	
	// Ghost nodes do not have elements. Therefore, cannot be consulted
	if (l.pdi == l.pri || l.pdi == l.ult) {
		e = -1;
		printf ("\nError, cannot get the element inside the node.\n");
	}
	else {
		e = l.pdi->e;
	}
	return e;
}

/*******************
*
* @Purpose: Removes the node where PDI is pointing at
* @Parameters: l = bidirectional linked list
* @Return: -
*
*******************/
void LLISTA_elimina (Llista *l) {
	Node *aux; 
	// Ghost nodes cannod be removed from the list
	if (l->pdi == l->pri || l->pdi == l->ult) {
		printf ("\nError, cannot delete node.\n"); 
	}
	else {
		// Removes the node where PDI is pointing at
		aux = l->pdi; 
		aux->ant->sig = aux->sig; 
		aux->sig->ant = aux->ant;
		l->pdi = l->pdi->sig;
		free (aux);
	}
}

/*******************
*
* @Purpose: Points PDI to the next node
* @Parameters: l = bidirectional linked list
* @Return: -
*
*******************/
void LLISTA_avanca (Llista *l) {
	// We cannot go beyond the last node
	if (l->pdi == l->ult) { 
		printf ("\nError, cannot move forward.\n"); 
	} 
	else {
		// PDI will be pointing at the next node
		l->pdi = l->pdi->sig; 
	}
}

/*******************
*
* @Purpose: Points PDI to the node before it
* @Parameters: l = bidirectional linked list
* @Return: -
*
*******************/
void LLISTA_retrocedeix (Llista *l) {
	// We cannot go beyond the first node. That is the limit.
	if (l->pdi == l->pri) {
		printf ("\nError,cannot move backwards.\n");
	}
	else {
		// PDI will be pointing at the node before that
		l->pdi=l->pdi->ant;
	}
}

/*******************
*
* @Purpose: Go to the start of the list
* @Parameters: l = bidirectional linked list
* @Return: -
*
*******************/
void LLISTA_vesInici (Llista *l) {
	l->pdi = l->pri->sig;
}

/*******************
*
* @Purpose: Go to the end of the list
* @Parameters: l = bidirectional linked list
* @Return: -
*
*******************/
void LLISTA_vesFinal (Llista *l) {
	l->pdi = l->ult->ant;
}

/*******************
*
* @Purpose: Checks if PDI is at the start of the list
* @Parameters: l = bidirectional linked list
* @Return: Returns an integer. 1 for TRUE, 0 for FALSE
*
*******************/
int LLISTA_inici (Llista l) {
	return l.pdi == l.pri; 
}

/*******************
*
* @Purpose: Checks if PDI is at the end of the list
* @Parameters: l = bidirectional linked list
* @Return: Returns an integer. 1 for TRUE, 0 for FALSE
*
*******************/
int LLISTA_final (Llista l) {
	return l.pdi == l.ult;
}

/*******************
*
* @Purpose: Checks if the list is empty
* @Parameters: l = bidirectional linked list
* @Return: Returns an integer. 1 for TRUE, 0 for FALSE
*
*******************/
int LLISTA_buida (Llista l) {
	return l.pri->sig == l.ult;
}

/*******************
*
* @Purpose: Insert a node to the right of PDI in a sorted manner (min to max)
* @Parameters: l = bidirectional linked list
* @Return: -
*
*******************/
void LLISTA_insertDavant (Llista *l, int e) {
	Node *aux;
	int read = 0, trobat = 0;

	aux = (Node*)malloc(sizeof(Node));
	if (aux == NULL) {
		printf ("\nError, cannot allocate memory for auxiliar node.\n");
	}
	else {
		// Leave the PDI before the node that has a larger integer as element
		if (LLISTA_buida (*l)) {
			l->pdi = l->pri;
		}
		else {
			LLISTA_vesInici (l);
			read = LLISTA_consulta (*l);

			// Keep checking if we have reached the end of the list
			while (!LLISTA_final(*l) && !trobat) {
				if (e < read) {
					trobat = 1;
					LLISTA_retrocedeix (l);	
				}
				else {
					LLISTA_avanca (l);
					if (!LLISTA_final(*l))
						read = LLISTA_consulta(*l);
					else {
						// Reaching the end means e is the largest number
						LLISTA_retrocedeix (l);
						trobat = 1;
					}
				}
			}
		}
		// Insert the node to the right of PDI
		aux->e = e;
		aux->sig = l->pdi->sig;
		aux->ant = l->pdi;
		l->pdi->sig->ant = aux;
		l->pdi->sig = aux;
		
	}	
	
}

/*******************
*
* @Purpose: Insert a node to the left of PDI in a sorted manner (min to max)
* @Parameters: l = bidirectional linked list
* @Return: -
*
*******************/
void LLISTA_insertDarrere (Llista *l, int e) {
	Node *aux;
	int read = 0, trobat = 0;

	aux = (Node*)malloc(sizeof(Node));
	if (aux == NULL) {
		printf ("\nError, cannot allocate memory for auxiliar node.\n");
	}
	else {
		// Leave the PDI before the node that has a larger integer as element
		if (LLISTA_buida (*l)) {
			l->pdi = l->ult;
		}
		else {
			LLISTA_vesInici (l);
			read = LLISTA_consulta (*l);
			// Keep checking if we have reached the end of the list
			while (!LLISTA_final(*l) && !trobat) {
				if (e < read) {
					trobat = 1;
				}
				else {
					LLISTA_avanca (l);
					if (!LLISTA_final(*l))
						read = LLISTA_consulta(*l);
					else {
						// Reaching the end means e is the largest number
						// In this case, PDI is pointing at the last ghost node
						trobat = 1;
					}
				}
			}
		}
		// Insert the node to the left of of PDI
		aux->e = e;
		aux->sig = l->pdi;
		aux->ant = l->pdi->ant;
		l->pdi->ant->sig = aux;
		l->pdi->ant = aux;	
	}	
}

/*******************
*
* @Purpose: Destroys the list by removing all nodes
* @Parameters: l = bidirectional linked list
* @Return: -
*
*******************/
void LLISTA_destrueix (Llista *l) {
	Node *aux;
	// Keep deleting nodes until all nodes have been removed
	while (l->pri != NULL) {
		aux = l->pri;
		l->pri = l->pri->sig;
		free (aux);
	}

	// Put the ghost nodes as NULL
	l->ult = NULL;
	l->pdi = NULL;
}

/*******************
*
* @Purpose: Prints all the elements of the linked list on the screen
* @Parameters: l = bidirectional linked list
* @Return: -
*
*******************/
void LLISTA_mostrarElements (Llista l) {
	int read = 0;
	
	// Starting from the first non-ghost node, consult and print elements on the screen
	LLISTA_vesInici (&l);
	printf ("List of numbers: ");
	while (!LLISTA_final(l)) {
		read = LLISTA_consulta(l);
		printf ("%d ", read);
		LLISTA_avanca(&l);
	}
	printf ("\n");
}
