#include <stdio.h>
#include "linked_list.h"
#include "queue.h"

void list();
void queue();

int main() {
   list();
   queue();
}

void list() {
   printf("\nLinked list:\n");
   struct List* list = list_create();
   list_add_tail(list, 12);
   list_add_tail(list, 48);
   list_add_tail(list, 24);
   list_add_tail(list, 72);
   list_add_tail(list, 36);
   list_add_tail(list, 100);
   list_print(list);
   int result;
   list_get(list, 5, &result);
   printf("list[3] = %i\n", result);
   printf("list->length = %i\n", list->length);
   list_free(list);
}

void queue() {
   printf("\nQueue:\n");
   struct Queue* queue = queue_create();
   queue_enqueue(queue, 6);
   queue_enqueue(queue, 7);
   queue_enqueue(queue, 8);
   queue_enqueue(queue, 9);
   queue_enqueue(queue, 10);
   queue_print(queue);
   int number;
   if (!queue_dequeue(queue, &number)) {
      printf("cant dequeue");
      return;
   }
   queue_print(queue);
   queue_free(queue);
}