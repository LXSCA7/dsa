#include "stack.h"
#include "linked_list.h"

Stack* stack_create() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    if (stack == NULL) 
        return NULL;
  
    stack->list = list_create();
    if (stack->list == NULL) {
        free(stack);
        return NULL;
    }

    return stack;
}

void stack_push(Stack* stack, int value) {
    if (stack == NULL || stack->list == NULL)
        return;

    list_add_head(stack->list, value);
}

bool stack_pop(Stack* stack, int* result) {
    if (stack == NULL || stack->list == NULL || stack->list->head == NULL)
        return false;

    if (!list_get(stack->list, 0, result))
        return false;

    list_remove_head(stack->list);
    return true;
}

void stack_free(Stack* stack) {
    if (stack == NULL) return;
    list_free(stack->list);
    free(stack);
}