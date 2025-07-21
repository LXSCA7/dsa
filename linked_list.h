#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdbool.h>
#include <stdlib.h>

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
void list_add_tail(struct List* list, int value);
void list_add_head(struct List* list, int value);
void list_print(struct List* list);
void list_free(struct List* list);
bool list_get(struct List* list, int position, int* result);
void list_add_position(struct List* list, int position, int value);
void list_remove_head(struct List* list);
void list_remove_tail(struct List* list);

#endif