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
			l.pri->sig = l.ult;
			l.pri->ant = NULL;
			l.ult->ant = l.pri;
			l.ult->sig = NULL;
			l.pdi = l.ult;
		}
	}

	return l;
}

void LLISTA_insertDavant (Llista *l, int e) {
	
}

void LLISTA_insertDarrere (Llista *l, int e) {

}

int LLISTA_consulta (Llista l) {

}

void LLISTA_elimina (Llista *l) {

}

void LLISTA_avanca (Llista *l) {

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


