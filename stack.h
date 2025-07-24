#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"


typedef struct {
    List* list;
}Stack;

Stack* stack_create();
void stack_push(Stack* stack, int value);
bool stack_pop(Stack* stack, int* result);
void stack_free(Stack* stack);

#endif