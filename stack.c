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
    if (i > stack->i) {
      fprintf(stderr,"Cannot push: Wrong order\n");
      exit(EXIT_FAILURE);
    } else {
      Stack* next = newStack();
      next->i = i;
      next->next = stack;
      return next;
    }
  }
}

Stack* pop(Stack *stack, int* i) {
  Stack* next = NULL;
  if(stack == NULL) {
    fprintf(stderr,"Cannot pop: Empty stack\n");
    exit(EXIT_FAILURE);
  } else {
    *i = stack->i;
    next = stack->next;
    free(stack);
  }
  return next;
}
