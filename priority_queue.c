#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "headers/priority_queue.h"

PriorityQueue* construct_priority_queue() {
	PriorityQueue* pq = (PriorityQueue*) malloc(sizeof(PriorityQueue));

	if(pq != NULL) {
		pq->size = 0;
		pq->first = NULL;
		pq->last = NULL;
	}

	return pq;
}

void destruct_priority_queue(PriorityQueue* pq) {
	if(pq == NULL)
		return;

	clear_priority_queue(pq);

	free(pq->first);
	pq->first = NULL;
	free(pq->last);
	pq->last = NULL;
	free(pq);
	pq = NULL;
}

uint8_t is_empty_priority_queue(PriorityQueue* pq) {
	return (uint8_t) pq->size == 0;
}

uint32_t size_priority_queue(PriorityQueue* pq) {
	return pq->size;
}

void enqueue_priority_queue(PriorityQueue* pq, Node* node) {
	if(pq == NULL)
		return;

	if(is_empty_priority_queue(pq)) {
		pq->size++;
		node->next = NULL;
		pq->first = node;
		pq->last = node;
		return;
	}

	pq->size++;
	Node* aux = pq->first;

	if(node->value->priority < aux->value->priority) {
		node->next = aux;
		pq->first = node;
		return;
	}


	while(aux->next != NULL && node->value->priority >= aux->next->value->priority)
		aux = aux->next;

	if(aux->next == NULL) {
		node->next = NULL;
		aux->next = node;
		pq->last = node;
		return;
	}

	node->next = aux->next;
	aux->next = node;
}

Node* dequeue_priority_queue(PriorityQueue* pq) {
	if(pq == NULL || is_empty_priority_queue(pq))
		return NULL;

	Node* aux = pq->first;
	pq->first = pq->first->next;
	aux->next = NULL;
	pq->size--;

	if(is_empty_priority_queue(pq))
		pq->last = NULL;

	return aux;
}

void clear_priority_queue(PriorityQueue* pq) {
	if(pq == NULL)
		return;
	
	if(!is_empty_priority_queue(pq)) {
		Node* aux = pq->first;
		Node* preAux = aux;
		while(aux != NULL) {
			aux = aux->next;
			destruct_node(preAux);
			preAux = aux;
		}
	}

	pq->first = NULL;
	pq->last = NULL;
	pq->size = 0;
}

void print_priority_queue(PriorityQueue* pq) {
	if(pq == NULL)
		return;

	printf("PriorityQueue@%p = [\n", pq);
	Node* aux = pq->first;
	while(aux != NULL) {
		printf("\t");
		print_node(aux);
		printf(",\n");
		aux = aux->next;
	}
	printf("], size: %u, first: %p, last: %p]", pq->size, pq->first, pq->last);
}


void tdd_priority_queue() {
	printf("\t\tPriority Queue Tests\n");
	PriorityQueue* pq1 = construct_priority_queue();

	assert(pq1 != NULL);
	assert(pq1->first == NULL);
	assert(pq1->last == NULL);
	assert(pq1->size == 0);

	assert(is_empty_priority_queue(pq1) == 1);
	assert(size_priority_queue(pq1) == 0);

	print_priority_queue(pq1);
	printf("\n");

	Info* i1 = construct_info("Test Admin File\0", 0);
	Info* i2 = construct_info("Test Employee File\0", 0);
	Info* i3 = construct_info("Test Chief File\0", 1);
	Info* i4 = construct_info("Test Manager File\0", 2);

	Node* n1 = construct_node(i1, NULL);
	Node* n2 = construct_node(i2, NULL);
	Node* n3 = construct_node(i3, NULL);
	Node* n4 = construct_node(i4, NULL);

	assert(is_empty_priority_queue(pq1) == 1);
	assert(size_priority_queue(pq1) == 0);

	enqueue_priority_queue(pq1, n3);
	enqueue_priority_queue(pq1, n2);
	enqueue_priority_queue(pq1, n4);
	enqueue_priority_queue(pq1, n1);

	print_priority_queue(pq1);
	printf("\n");

	assert(size_priority_queue(pq1) == 4);

	Node* aux = dequeue_priority_queue(pq1);

	printf("Dequeued: ");
	print_node(aux);
	printf("\n");

	aux = dequeue_priority_queue(pq1);

	printf("Dequeued: ");
	print_node(aux);
	printf("\n");

	assert(size_priority_queue(pq1) == 2);

	aux = dequeue_priority_queue(pq1);

	printf("Dequeued: ");
	print_node(aux);
	printf("\n");

	aux = dequeue_priority_queue(pq1);

	printf("Dequeued: ");
	print_node(aux);
	printf("\n");

	assert(size_priority_queue(pq1) == 0);
	assert(pq1->first == NULL);
	assert(pq1->last == NULL);

	enqueue_priority_queue(pq1, n3);
	enqueue_priority_queue(pq1, n2);
	enqueue_priority_queue(pq1, n4);
	enqueue_priority_queue(pq1, n1);

	assert(size_priority_queue(pq1) == 4);

	clear_priority_queue(pq1);

	assert(size_priority_queue(pq1) == 0);
	assert(pq1->first == NULL);
	assert(pq1->last == NULL);

	print_priority_queue(pq1);
	printf("\n");

	destruct_priority_queue(pq1);
	printf("\n\n");
}
