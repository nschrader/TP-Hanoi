#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "hanoi.h"

#define N 9

/**
 * @mainpage
 * Petit programme de test utilisant le module hanoi et le module pile
 */

Stack* src = NULL;
Stack* aux = NULL;
Stack* dst = NULL;

static Stack* initHanoiStack() {
  Stack* stack = NULL;
  for (int i=N; i>0; i--) {
      stack = push(stack, i);
  }
  return stack;
}

static void printStacks() {
  printStack(src);
  printStack(aux);
  printStack(dst);
}

int main() {
  printf("/********** Test Numéro 1 *************\n");
  printf("Après mise en place d'un Hanoi de taille %d\n", N);
  src = initHanoiStack();
  printStacks();
  printf("Après execution de hanoi(%d)\n", N);
  hanoi(N, src, aux, dst);
  printStacks();

  printf("/********** Test Numéro 2 *************\n");
  printf("Après mise en place d'un Hanoi de taille %d\n", 4);
  src = dst;
  dst = push(NULL, 5);
  printStacks();
  printf("Après execution de hanoi(%d)\n", 4);
  hanoi(4, src, aux, dst);
  printStacks();

  printf("/*********** Test Erreur **************\n");
  hanoi(4, src, aux, dst);
  printf("Ne devrait pas arriver ici\n");

  return EXIT_SUCCESS;
}
