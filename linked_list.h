#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
   int value;
   struct Node* next;
};

typedef struct {
   struct Node* head;
   struct Node* tail;
   int length;
}List;

List* list_create();
void list_add_tail(List* list, int value);
void list_add_head(List* list, int value);
void list_print(List* list);
void list_free(List* list);
bool list_get(List* list, int position, int* result);
void list_add_position(List* list, int position, int value);
void list_remove_head(List* list);
void list_remove_tail(List* list);

#endif