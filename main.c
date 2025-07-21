#include <stdio.h>
#include "linked_list.h"

int main() {
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