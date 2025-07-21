#include "queue.h"
#include "linked_list.h"
#include <limits.h>

struct Queue* queue_create() {
   struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
   if (queue == NULL)
      exit(1);

   queue->List = list_create();
   return queue;
}

void queue_enqueue(struct Queue* queue, int value) {
   list_add_tail(queue->List, value);
}

bool queue_dequeue(struct Queue* queue, int* result) {
   if (queue->List->head == NULL || queue == NULL)
      return false;

   if (!list_get(queue->List, 0, result))
      return false;
   
   list_remove_head(queue->List);
   return true;
}

void queue_print(struct Queue* queue) {
   list_print(queue->List);
}

void queue_free(struct Queue* queue) {
   list_free(queue->List);
   free(queue);
}