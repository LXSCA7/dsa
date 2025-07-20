#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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

#endif