#include <stdio.h>
#include "linked_list.h"

struct Node* node_create(int value);

struct Node* node_create(int value) {
   struct Node* node = (struct Node*)malloc(sizeof(struct Node));
   if (node == NULL)
      exit(2);
   node->value = value;
   node->next = NULL;
   return node;
}

List* list_create() {
   List* list = (List*)malloc(sizeof(List));
   if (list == NULL)
      exit(1);

   list->head = NULL;
   list->tail = NULL;
   list->length = 0;

   return list;
}

void list_add_tail(List* list, int value) {
   struct Node* node = node_create(value);
   if (list->head == NULL) {
      list->head = node;
      list->tail = node;
      list->length++;
      return;
   }
   
   list->tail->next = node;
   list->tail = node;
   list->length++;
}

void list_add_head(List* list, int value) {
   if (list->head == NULL) {
      list_add_tail(list, value);
      return;
   }

   struct Node* node = node_create(value);
   node->next = list->head;
   list->head = node;
   list->length++;
}

void list_print(List* list) {
   struct Node* current = list->head;
   while (current != NULL) {
      printf("%i", current->value);
      current = current->next;
      if (current != NULL)
         printf(" -> ");
   }
   
   printf("\n");
}

void list_free(List* list) {
   struct Node* current = list->head;
   while (current != NULL) {
      struct Node* next = current->next;
      free(current);
      current = next;
   }

   free(list);
}

void list_add_position(List* list, int position, int value) {
   if (position < 0 || position > list->length) {
      return;
   }
   
   if (position == 0) {
      list_add_head(list, value);
      return;
   }

   if (position == list->length) {
      list_add_tail(list, value);
      return;
   }

   struct Node* new_node = node_create(value);
   struct Node* previous_node = list->head;
   for (int i = 0; i < position-1; i++) {
      previous_node = previous_node->next;
   }
   struct Node* actual_node = previous_node->next;
  
   previous_node->next = new_node;
   new_node->next = actual_node;
   list->length++;
}

bool list_get(List* list, int position, int* result) {
   if (list->head == NULL || position < 0 || position >= list->length)
      return false;
   
   struct Node* node = list->head;
   if (position == 0) {
      *result = node->value;
      return true;
   }
   
   if (position == list->length-1) {
      *result = list->tail->value;
      return true;
   }

   for (int i = 0; i < position; i++)
      node = node->next;

   *result = node->value;
   return false;
}

void list_remove_head(List* list) {
   if (list == NULL || list->head == NULL)
      return;

   struct Node* node_to_remove = list->head;
   
   list->head = list->head->next;
   list->length--;

   if (list->head == NULL)
      list->tail = NULL;

   free(node_to_remove);
}

void list_remove_tail(List* list) {
   if (list == NULL || list->tail == NULL)
      return;

   list->length--;

   if (list->head == list->tail) {
      free(list->head);
      list->head = NULL;
      list->tail = NULL;

      return;
   }

   struct Node* penultimate_node = list->head;
   while (penultimate_node->next != list->tail)
      penultimate_node = penultimate_node->next;
    
   free(penultimate_node->next);
   list->tail = penultimate_node;
   penultimate_node->next = NULL;
}