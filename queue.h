#ifndef QUEUE_H
#define QUEUE_H
#include "linked_list.h"

struct Queue {
   struct List* List;
};

struct Queue* queue_create();
void queue_enqueue(struct Queue* queue, int value);
bool queue_dequeue(struct Queue* queue, int* result);
void queue_print(struct Queue* queue);
void queue_free(struct Queue* queue);

#endif