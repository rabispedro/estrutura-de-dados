#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "./headers/lista.h"
#include"./headers/ponto.h"

struct lista {
	Ponto* valor;
	Lista* proximo;
};

Lista* constroi_lista() {
	Lista* li = (Lista*) malloc(sizeof(Lista));

	if (li != NULL) {
		li->valor = NULL;
		li->proximo = NULL;
	}

	return li;
}

void imprime_lista(Lista* li) {
	printf("Lista %p:\n", li);

	if(esta_vazia_lista(li) == 0) {
		Lista* temp = li->proximo;

		while(temp != NULL) {
			printf("\t");
			imprime_ponto(temp->valor);
			temp = temp->proximo;
		}
	}

	printf("\n");
}

int esta_vazia_lista(Lista* li) {
	return (li->proximo == NULL ? 1 : 0);
}

void adiciona_lista(Lista* li, Ponto* p) {
	Lista* temp = li;

	while(temp->proximo != NULL) {
		temp = temp->proximo;
	}

	Lista* elemento = constroi_lista();
	elemento->valor = p;
	temp->proximo = elemento;
}

void remove_por_nome_lista(Lista* li, char* nome) {
	if(esta_vazia_lista(li) == 0) {
		Lista* temp = li->proximo;
		Lista* anterior;
		
		if(e_igual_ponto(temp->valor, nome)) {
			anterior = temp->proximo;
			li->proximo = anterior;

			temp->proximo = NULL;
			destroi_ponto(temp->valor);
		} else {
			while(temp != NULL && e_igual_ponto(temp->valor, nome) == 0) {
				anterior = temp;
				temp = temp->proximo;
			}

			if(temp != NULL) {
				anterior->proximo = temp->proximo;
				temp->proximo = NULL;
				destroi_ponto(temp->valor);
			}
		}
	}
}

Ponto* pega_por_nome_lista(Lista* li, char* nome) {
	if(esta_vazia_lista(li) == 0) {
		Lista* temp = li->proximo;
		while(temp != NULL && e_igual_ponto(temp->valor, nome) == 0) {
			temp = temp->proximo;
		}

		return temp->valor;
	}

	return NULL;
}

int tamanho_lista(Lista* li) {
	int tamanho=0;

	if(esta_vazia_lista(li) == 0) {
		Lista* temp = li->proximo;

		while(temp != NULL) {
			tamanho++;
			temp = temp->proximo;
		}
	}

	return tamanho;
}

void destroi_lista(Lista* li) {
	if(esta_vazia_lista(li) == 0) {
		Lista* temp = li->proximo;
		Lista* anterior;
		while(temp != NULL) {
			anterior = temp;
			temp = temp->proximo;

			destroi_ponto(anterior->valor);
			anterior->proximo = NULL;
			free(anterior);
		}
	}

	li->proximo = NULL;
	free(li);
}

void teste_lista() {
	//	Given	| Assume
	Ponto* p1 = constroi_ponto("P1", 1.0, 0.1);
	Ponto* p2 = constroi_ponto("P2", 2.0, 0.2);
	Ponto* p3 = constroi_ponto("P3", 3.0, 0.3);
	Ponto* p4 = constroi_ponto("P4", 4.0, 0.4);
	Ponto* p5 = constroi_ponto("P5", 5.0, 0.5);

	Lista* li = constroi_lista();

	//	When	| Act
	imprime_lista(li);
	printf("Lista vazia: %d\n", esta_vazia_lista(li));
	printf("Tamanho lista: %d\n", tamanho_lista(li));

	adiciona_lista(li, p4);
	adiciona_lista(li, p2);
	adiciona_lista(li, p5);
	adiciona_lista(li, p3);
	adiciona_lista(li, p1);

	imprime_lista(li);
	printf("Lista vazia: %d\n", esta_vazia_lista(li));
	printf("Tamanho lista: %d\n", tamanho_lista(li));

	remove_por_nome_lista(li, "P5");
	remove_por_nome_lista(li, "P8");
	remove_por_nome_lista(li, "P1");
	remove_por_nome_lista(li, "P4");

	imprime_lista(li);
	printf("Lista vazia: %d\n", esta_vazia_lista(li));
	printf("Tamanho lista: %d\n", tamanho_lista(li));

	Ponto* pontoAcessado = pega_por_nome_lista(li, "P2");
	printf("Elemento %s:\n\t", "P2");
	imprime_ponto(pontoAcessado);
	printf("\n");



	//	Then	| Assert
	// assert(no->proximo == NULL);

	printf("Todos os testes de Lista passaram!!!\n");

	destroi_lista(li);
	imprime_lista(li);
}
