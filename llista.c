#include "llista.h"

Llista LLISTA_crea() {
	Llista l;
	
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

int LLISTA_consulta (Llista l) {
	int e;
	
	if (l.pdi == l.pri || l.pdi == l.ult) {
		e = -1;
		printf ("\nError, cannot get the element inside the node.\n");
	}
	else {
		e = l.pdi->e;
	}
	return e;
}

void LLISTA_elimina (Llista *l) {
	Node *aux; 
	if (l->pdi == l->pri || l->pdi == l->ult) {
		printf ("\nError, cannot delete node.\n"); 
	}
	else {
		aux = l->pdi; 
		aux->ant->sig = aux->sig; 
		aux->sig->ant = aux->ant;
		l->pdi = l->pdi->sig;
		free (aux);
	}
}

void LLISTA_avanca (Llista *l) {
	if (l->pdi == l->ult) { 
		printf ("\nError, cannot move forward.\n"); 
	} 
	else {
		l->pdi = l->pdi->sig; 
	}
}

void LLISTA_retrocedeix (Llista *l) {
	if (l->pdi == l->pri) {
		printf ("\nError,cannot move backwards.\n");
	}
	else {
		l->pdi=l->pdi->ant;
	}
}

void LLISTA_vesInici (Llista *l) {
	l->pdi = l->pri->sig;
}

void LLISTA_vesFinal (Llista *l) {
	l->pdi = l->ult->ant;
}

int LLISTA_inici (Llista l) {
	return l.pdi == l.pri; 
}

int LLISTA_final (Llista l) {
	return l.pdi == l.ult;
}

int LLISTA_buida (Llista l) {
	return l.pri->sig == l.ult;
}

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
						LLISTA_retrocedeix (l);
						trobat = 1;
					}
				}
			}
		}
		aux->e = e;
		aux->sig = l->pdi->sig;
		aux->ant = l->pdi;
		l->pdi->sig->ant = aux;
		l->pdi->sig = aux;
		
	}	
	
}

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
			while (!LLISTA_final(*l) && !trobat) {
				if (e < read) {
					trobat = 1;
				}
				else {
					LLISTA_avanca (l);
					if (!LLISTA_final(*l))
						read = LLISTA_consulta(*l);
					else {
						trobat = 1;
					}
				}
			}
		}
		aux->e = e;
		aux->sig = l->pdi;
		aux->ant = l->pdi->ant;
		l->pdi->ant->sig = aux;
		l->pdi->ant = aux;	
	}	
}

void LLISTA_destrueix (Llista *l) {
	Node *aux;
	while (l->pri != NULL) {
		aux = l->pri;
		l->pri = l->pri->sig;
		free (aux);
	}
	l->ult = NULL;
	l->pdi = NULL;
}

void LLISTA_mostrarElements (Llista l) {
	int read = 0;

	LLISTA_vesInici (&l);
	printf ("List of numbers: ");
	while (!LLISTA_final(l)) {
		read = LLISTA_consulta(l);
		printf ("%d ", read);
		LLISTA_avanca(&l);
	}
}
