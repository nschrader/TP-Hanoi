#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

Stack* newStack() {
  Stack *stack = malloc(sizeof(Stack));
  stack->i = 0;
  stack->next = NULL;
  return stack;
}

Stack* push(Stack* stack, int i) {
  if(stack == NULL) {
    stack = newStack();
    stack->i = i;
    return stack;
  } else {
    Stack* next = newStack();
    next->i = i;
    next->next = stack;
    return next;
  }
}

Stack* pop(Stack *stack, int* i) {
  Stack* next = NULL;
  if(stack == NULL) {
    fprintf(stderr,"Cannot pop: Empty stack");
    exit(EXIT_FAILURE);
  } else {
    *i = stack->i;
    next = stack->next;
    free(stack);
  }
  return next;
}

void printStack(Stack* stack) {
  if (stack != NULL) {
    for (Stack* tmp = stack; tmp != NULL; tmp = tmp->next) {
      printf("%d\n", tmp->i);
    }
  }
}
