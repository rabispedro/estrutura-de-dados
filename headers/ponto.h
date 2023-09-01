#define TAMANHO_NOME 256

typedef struct ponto Ponto;

Ponto* constroi_ponto(char*, double, double);
void imprime_ponto(Ponto*);
double distancia_pontos(Ponto*, Ponto*);
void destroi_ponto(Ponto*);
int e_igual_ponto(Ponto*, char*);
void teste_ponto();
