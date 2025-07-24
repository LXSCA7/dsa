#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "queue.h"
#include "stack.h"

void list();
void queue();
void stack();

int main() {
   list();
   queue();
   stack();
}

void list() {
   printf("\nLinked list:\n");
   List* list = list_create();
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
   Queue* queue = queue_create();
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

void stack() {
   printf("\nStack:\n");
   Stack* stack = stack_create();
   if (stack == NULL) exit(4);
   for (int i = 0; i < 5; i++) {
      printf("%i\n", i);
      stack_push(stack, i);
   }

   list_print(stack->list);

   for (int j = 0; j < 5; j++) {
      int result;
      if (stack_pop(stack, &result))
         printf("Pos: %i = %i\n", j, result);
      else
         printf("vish n deu");
   }

   stack_free(stack);
}