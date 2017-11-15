#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "stack.h"
#include "hanoi.h"

#define N 9

/**
 * @mainpage
 * Petit programme de test utilisant le module hanoi et le module pile
 */

static Stack* initHanoiStack() {
  Stack* stack = NULL;
  for (int i=N; i>0; i--) {
      stack = push(stack, i);
  }
  return stack;
}

static void printTestHeader(char* name, int n, Stack* src, Stack* aux, Stack* dst) {
  printf("*********** Test %s ***********\n", name);
  printf("Set up a Hanoi stack of size %d\n\n", N);
  printStacks(N, src, aux, dst);
}

static void printTestFooter(int n, Stack* src, Stack* aux, Stack* dst) {
  printf("Executed hanoi(%d)\n\n", n);
  printStacks(N, src, aux, dst);
  puts("\n");
}

static void testNormal() {
  Stack* src = initHanoiStack();
  Stack* aux = NULL;
  Stack* dst = NULL;

  printTestHeader("Normal", N, src, aux, dst);
  hanoi(N, &src, &aux, &dst);
  printTestFooter(N, src, aux, dst);
}

static void testAnormal() {
  Stack* src = initHanoiStack();
  Stack* aux = NULL;
  Stack* dst = push(NULL, 5);

  printTestHeader("Anormal", 4, src, aux, dst);
  hanoi(4, &src, &aux, &dst);
  printTestFooter(4, src, aux, dst);
}

static void testFailure() {
  Stack* src = initHanoiStack();
  Stack* aux = NULL;
  Stack* dst = push(NULL, 1);

  printTestHeader("Failure", N, src, aux, dst);
  printf("Should fail while pushing\n");
  hanoi(N, &src, &aux, &dst);
  assert(false); //Should not arrive here
}

int main() {
  testNormal();
  testAnormal();
  testFailure();
  return EXIT_SUCCESS;
}
