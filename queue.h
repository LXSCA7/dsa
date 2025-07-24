#ifndef QUEUE_H
#define QUEUE_H
#include "linked_list.h"

typedef struct {
   List* List;
}Queue;

Queue* queue_create();
void queue_enqueue(Queue* queue, int value);
bool queue_dequeue(Queue* queue, int* result);
void queue_print(Queue* queue);
void queue_free(Queue* queue);

#endif