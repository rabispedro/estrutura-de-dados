#include "./ponto.h"

typedef struct lista Lista;

Lista* constroi_lista();
void imprime_lista(Lista*);
int esta_vazia_lista(Lista*);
void adiciona_lista(Lista*, Ponto*);
void remove_por_nome_lista(Lista*, char*);
Ponto* pega_por_nome_lista(Lista*, char*);
int tamanho_lista(Lista*);
void destroi_lista(Lista*);
void teste_lista();
