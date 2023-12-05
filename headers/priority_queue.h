#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdint.h>

#include "adt.h"

struct priority_queue {
	uint32_t size;
	Node* first;
	Node* last;
} typedef PriorityQueue;

PriorityQueue* construct_priority_queue();
void destruct_priority_queue(PriorityQueue* pq);
uint8_t is_empty_priority_queue(PriorityQueue* pq);
uint32_t size_priority_queue(PriorityQueue* pq);
void enqueue_priority_queue(PriorityQueue* pq, Node* node);
Node* dequeue_priority_queue(PriorityQueue* pq);
void clear_priority_queue(PriorityQueue* pq);
void print_priority_queue(PriorityQueue* pq);
void tdd_priority_queue();

#endif
