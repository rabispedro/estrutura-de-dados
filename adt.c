#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "headers/adt.h"

Info* construct_info(char* file, const uint8_t priority) {
	Info* info = (Info*) malloc(sizeof(Info));

	if(info != NULL) {
		strcpy(info->file, file);
		info->priority = priority;
	}

	return info;
}

void destruct_info(Info* info) {
	if(info == NULL)
		return;

	strcpy(info->file, "");
	free(info);
	info = NULL;
}

void print_info(Info* info) {
	if(info == NULL)
		return;

	printf("Info@%p = [file: %s, priority: %u]", info, info->file, info->priority);
}

void tdd_info() {
	Info* i1 = construct_info("Arquivo X\0", 0);

	assert(i1 != NULL);
	assert(strcmp(i1->file,  "Arquivo X") == 0);
	assert(i1->priority == 0);

	print_info(i1);
	printf("\n");

	destruct_info(i1);
}

Node* construct_node(Info* value, Node* next) {
	Node* node = (Node*) malloc(sizeof(Node));

	if(node != NULL) {
		node->value = value;
		node->next = next;
	}

	return node;
}

void destruct_node(Node* node) {
	if(node == NULL)
		return;

	node->next = NULL;
	destruct_info(node->value);
	node->value = NULL;
	free(node);
	node = NULL;
}

void print_node(Node* node) {
	if(node == NULL)
		return;

	printf("Node@%p = [value: [", node);
	print_info(node->value);
	printf("], next: %p]", node->next);
}

void tdd_node() {
	Info* i1 = construct_info("Arquivo X\0", 0);
	Info* i2 = construct_info("X File\0", 10);
	Info* i3 = construct_info("Arquivinho Chizinho\0", 2);

	Node* n1 = construct_node(i1, NULL);
	Node* n2 = construct_node(i2, NULL);
	Node* n3 = construct_node(i3, NULL);

	assert(n1 != NULL);
	assert(n1->value != NULL);
	assert(strcmp(n1->value->file, "Arquivo X\0")  == 0);
	assert(n1->value->priority == 0);
	assert(n1->next == NULL);

	assert(n2 != NULL);
	assert(n2->value != NULL);
	assert(n2->value->priority == 10);
	assert(n2->next == NULL);

	assert(n3 != NULL);
	assert(n3->value != NULL);
	assert(n3->value->priority == 2);
	assert(n3->next == NULL);

	n1->next = n2;
	n2->next = n3;

	assert(n1->next == n2);
	assert(n2->next == n3);
	assert(n1->next->next == n3);

	print_node(n1);
	printf("\n");
	print_node(n2);
	printf("\n");
	print_node(n3);
	printf("\n");

	destruct_node(n1);
	destruct_node(n2);
	destruct_node(n3);
}
