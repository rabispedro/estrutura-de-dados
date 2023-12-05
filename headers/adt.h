#ifndef ADT_H
#define ADT_H

#include <stdint.h>

#define STR_SIZE 1 << 10

struct info {
	char file[STR_SIZE];
	uint8_t priority;
} typedef Info;

Info* construct_info(char* file, uint8_t priority);
void destruct_info(Info* info);
void print_info(Info* info);
void tdd_info();

struct node {
	Info* value;
	struct node* next;
} typedef Node;

Node* construct_node(Info* value, Node* next);
void destruct_node(Node* node);
void print_node(Node* node);
void tdd_node();

#endif
