#ifndef _LLISTA_H
#define _LLISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct N {
	int e;
	struct N *sig;
	struct N *ant;
} Node;

typedef struct {
	Node *pri;
	Node *ult;
	Node *pdi;
} Llista;

Llista LLISTA_crea();
void LLISTA_insertDavant (Llista *l, int e);
void LLISTA_insertDarrere (Llista *l, int e);
int LLISTA_consulta (Llista l);
void LLISTA_elimina (Llista *l);
void LLISTA_avanca (Llista *l);
void LLISTA_retrocedeix (Llista *l);
void LLISTA_vesInici (Llista *l);
void LLISTA_vesFinal (Llista *l);
int LLISTA_inici (Llista l);
int LLISTA_final (Llista l);
int LLISTA_buida (Llista l);
void LLISTA_destrueix (Llista *l);
void LLISTA_mostrarElements (Llista l);

#endif
