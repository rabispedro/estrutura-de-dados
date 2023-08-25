#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>

#include"./headers/ponto.h"

struct ponto {
	double x, y;
};

Ponto* constroi_ponto(double x, double y) {
	Ponto* p = (Ponto*) malloc(sizeof(Ponto));

	if (p != NULL) {
		p->x = x;
		p->y = y;
	}

	return p;
}

void imprime_ponto(Ponto* p) {
	printf("Ponto: (%4.3lf, %4.3lf)\n", p->x, p->y);
}

double distancia_pontos(Ponto* p1, Ponto* p2) {
	return sqrt(pow((p1->x - p2->x), 2) + pow((p1->y - p2->y), 2));
}

void destroi_ponto(Ponto* p) {
	free(p);
}

void teste_ponto() {
	//	Given	| Assume
	Ponto* p1 = constroi_ponto(0.0, 0.0);
	Ponto* p2 = constroi_ponto(1.0, 0.0);

	//	When	| Act
	imprime_ponto(p1);
	imprime_ponto(p2);

	//	Then	| Assert
	assert(distancia_pontos(p1, p2) >= 0.0);
	assert(distancia_pontos(p1, p2) == 1.0);
	assert(distancia_pontos(p1, p2) == distancia_pontos(p2, p1));
	assert(distancia_pontos(p1, p1) == 0.0);
	assert(distancia_pontos(p2, p2) == 0.0);

	printf("Todos os testes de Ponto passaram!!!\n");

	destroi_ponto(p1);
	destroi_ponto(p2);
}
