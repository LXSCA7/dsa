#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
   int value;
   struct Node* next;
};

struct List {
   struct Node* head;
   struct Node* tail;
   int length;
};

struct List* list_create();
void list_add(struct List* list, int value);
void list_add_head(struct List* list, int value);
void list_print(struct List* list);
void list_free(struct List* list);
bool list_get(struct List* list, int position, int* result);

struct Node* node_create(int value);

int main() {
   struct List* list = list_create();
   list_add(list, 12);
   list_add(list, 48);
   list_add(list, 24);
   list_add(list, 72);
   list_add(list, 36);
   list_add(list, 100);
   list_print(list);
   int result;
   list_get(list, 6, &result);
   printf("list[3] = %i\n", result);
   printf("list->length = %i\n", list->length);
   list_free(list);
}

struct Node* node_create(int value) {
   struct Node* node = (struct Node*)malloc(sizeof(struct Node));
   if (node == NULL)
      exit(2);
   node->value = value;
   node->next = NULL;
   return node;
}

struct List* list_create() {
   struct List* list = (struct List*)malloc(sizeof(struct List));
   if (list == NULL)
      exit(1);

   list->head = NULL;
   list->tail = NULL;
   list->length = 0;

   return list;
}

void list_add(struct List* list, int value) {
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

void list_add_head(struct List* list, int value) {
   if (list->head == NULL) {
      list_add(list, value);
      return;
   }

   struct Node* node = node_create(value);
   node->next = list->head;
   list->head = node;
   list->length++;
}

void list_print(struct List* list) {
   struct Node* current = list->head;
   while (current != NULL) {
      printf("%i", current->value);
      current = current->next;
      if (current != NULL)
         printf(" -> ");
   }
   
   printf("\n");
}

void list_free(struct List* list) {
   struct Node* current = list->head;
   while (current != NULL) {
      struct Node* next = current->next;
      free(current);
      current = next;
   }

   free(list);
}

void list_add_position(struct List* list, int position, int value) {
   if (position == 0) {
      list_add_head(list, value);
      return;
   }

   if (position == list->length) {
      list_add(list, value);
   }
}

bool list_get(struct List* list, int position, int* result) {
   if (list->head == NULL || position < 0 || position > list->length)
      return false;
   
   struct Node* node = list->head;
   if (position == 0) {
      *result = node->value;
      return true;
   }
   
   if (position == list->length) {
      *result = list->tail->value;
      return true;
   }

   for (int i = 0; i < position; i++)
      node = node->next;

   *result = node->value;
   return false;
}