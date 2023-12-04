#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "headers/adt.h"
#include "headers/priority_queue.h"

#define STR_SIZE 1024

uint8_t menu();

int main(int argc, char** argv) {
	for(int i=1; i<argc; i++) {
		if(strcmp(argv[i], "test-info") == 0)
			tdd_info();
		else if(strcmp(argv[i], "test-node") == 0)
			tdd_node();
		else if(strcmp(argv[i], "test-priority-queue") == 0)
			tdd_priority_queue();
	}

	PriorityQueue* pq = construct_priority_queue();
	uint8_t opt;

	do {
		opt = menu();

		switch (opt) {
		case 1:
			printf("Inserindo um arquivo:\n");
			char fileName[STR_SIZE];
			uint8_t priority;

			do {
				printf("Digite um nome valido para o arquivo: ");
				setbuf(stdin, NULL);
				fgets(fileName, STR_SIZE, stdin);
			} while(strcmp(fileName, "") == 0);

			do {
				printf("Digite uma prioridade valida (positiva): ");
				scanf("%hhd", &priority);
			} while(priority < 0);

			Info* i = construct_info(fileName, priority);
			Node* n = construct_node(i, NULL);
			enqueue_priority_queue(pq, n);

			break;
		case 2:
			printf("Removendo proximo arquivo:\n");
			Node* file = dequeue_priority_queue(pq);
			print_node(file);
			printf("\n\n");
			break;
		case 3:
			printf("Fila atual:\n");
			print_priority_queue(pq);
			printf("\n\n");
			break;
		case 4:
			printf("Limpando a fila\n");
			clear_priority_queue(pq);
			break;
		case 0:
			printf("Saindo do programa.\n");
			break;
		default:
			printf("Erro inesperado");
			exit(1);
			break;
		}

		system("read -p \"Digite algo para continuar: \"");
		system("clear");
	} while(opt != 0);

	destruct_priority_queue(pq);

	printf("FIM FILA DE ARQUIVOS DE IMPRESSAO\n\n");
	return 0;
}

uint8_t menu() {
	uint8_t opt;

	do {
		printf("FILA DE ARQUIVOS DE IMPRESSAO\n\n");

		printf("1) Inserir arquivo na fila.\n");
		printf("2) Remover o proximo arquivo da fila.\n");
		printf("3) Mostrar a fila atual.\n");
		printf("4) Limpar a fila.\n");
		printf("0) Sair do programa.\n");

		printf("Digite sua opcao: ");
		setbuf(stdin, NULL);
		scanf("%hhd", &opt);
	} while(opt < 0 || opt > 4);

	return opt;
}
