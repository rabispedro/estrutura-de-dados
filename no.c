#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

#include"./headers/ponto.h"
#include"./headers/no.h"

struct no {
	Ponto* valor;
	No* proximo;
};

No* constroi_no(Ponto* p) {
	No* no = (No*) malloc(sizeof(No));

	if (no != NULL) {
		no->valor = p;
		no->proximo = NULL;
	}

	return no;
}

void imprime_no(No* no) {
	printf("No:\n\t");
	imprime_ponto(no->valor);
	printf("\tProximo: %p\n", no->proximo);
}

void destroi_no(No* no) {
	no->proximo = NULL;
	destroi_ponto(no->valor);

	free(no);
}

void teste_no() {
	//	Given	| Assume
	Ponto* p = constroi_ponto("Teste", 0.0, 0.0);
	No* no = constroi_no(p);

	//	When	| Act
	imprime_no(no);

	//	Then	| Assert
	assert(no->proximo == NULL);

	printf("Todos os testes de No passaram!!!\n");

	destroi_no(no);
}
