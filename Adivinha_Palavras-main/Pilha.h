/*
 * PILHA - REPRESENTACAO ENCADEADA
 */

typedef struct NoTag {
	int info;
	struct NoTag *link;
} no;

no *inicializaPilha(no *L) {
	return NULL;
}

void imprimePilha(no *L) {
	no *P;
	P = L;	
	
	printf("\n Imprime Itens da Pilha: \n");	
	while(P != NULL) {
		printf(" %d ", P->info);	
		P = P->link;
	}
	printf("\n");
}

no *PUSH(no *L, int x) {
	no *N;

	N = (no *) malloc (sizeof(no));
	N->info = x;

    N->link = L;
	
	L = N;
	return (L);
}


no *POP(no *L, int *n) {
	no *AUX;

	if (L != NULL) {
		*n = L->info;
		AUX = L;
		L = L->link;
		free(AUX);
	}
	else{
		*n = 0;
	}
	return (L);
}

int verificaSeVazia_Pilha(no *L) {
	if (L == NULL)
		return 1;
	else
		return 0;
}


