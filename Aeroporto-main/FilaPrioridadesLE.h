#include <malloc.h>
#include <stdlib.h>

typedef struct node {
    int info;
    int prior;
    struct node *link;
} no;

no *inicializaFP(no *L)
{
    L = NULL;
    return L;
}

no *insereFP(no *L, int valor, int prior)
{
    no *N, *P, *ANT;

    N = (no *) malloc(sizeof(no));
    N->info = valor;
    N->prior = prior;

    if (L == NULL) {
        L = N;
        N->link = NULL;
    }
    else {
        P = L;

        while ((P != NULL) && (prior >= P->prior)) {
            ANT = P;
            P = P->link;
        }
        if (P == L) {
            N->link = L;
            L = N;
        }
        else {
            ANT->link = N;
            N->link = P;
        }
    }
    return L;
}

no *removeFP(no *L, int *n, int * prior) {
	no *AUX;

	if (L != NULL) {
		*n = L->info;
		*prior = L->prior; 
		AUX = L;
		L = L->link;
		delete AUX;
	}
	return L;
}

no *insereFilaChegada(no *L, int data, int prior) {
	no *P, *N;

	N = (no *) malloc (sizeof(no)); 
	N->info = data; 
	N->prior = prior; 
	N->link = NULL; 
	 
	if (L == NULL){ 
		L = N;
	}
	else { 
		P = L;	
	
		while(P->link != NULL) {
			P = P->link;
		}
		P->link = N;
	} 
	return L;
}

int verificaSeVazia(no *L) {
	if (L == NULL)
		return 1;
	else
		return 0;
}

void exibe(no *L) {
    no *P = L;

    while (P != NULL) {
        printf("\n");
        printf("Prioridade: %d - Aviao: %d", P->prior, P->info);
        P = P->link;
    }
}