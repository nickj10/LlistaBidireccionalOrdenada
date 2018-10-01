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

}

void LLISTA_vesInici (Llista *l) {

}

void LLISTA_vesFinal (Llista *l) {

}

int LLISTA_inici (Llista l) {

}

int LLISTA_final (Llista l) {
	
}

int LLISTA_buida (Llista l) {

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


