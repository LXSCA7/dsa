#include "queue.h"
#include "linked_list.h"
#include <limits.h>

Queue* queue_create() {
   Queue* queue = (Queue*)malloc(sizeof(Queue));
   if (queue == NULL)
      exit(1);

   queue->List = list_create();
   return queue;
}

void queue_enqueue(Queue* queue, int value) {
   list_add_tail(queue->List, value);
}

bool queue_dequeue(Queue* queue, int* result) {
   if (queue->List->head == NULL || queue == NULL)
      return false;

   if (!list_get(queue->List, 0, result))
      return false;
   
   list_remove_head(queue->List);
   return true;
}

void queue_print(Queue* queue) {
   list_print(queue->List);
}

void queue_free(Queue* queue) {
   if (queue == NULL) return;
   list_free(queue->List);
   free(queue);
}