#include <stdio.h>

#include "hanoi.h"

void hanoi(int n, Stack** src, Stack** aux, Stack** dst) {
  int i;
  if (n > 0) {
    hanoi(n-1, src, dst, aux);
    *src = pop(*src, &i);
    *dst = push(*dst, i);
    hanoi(n-1, aux, src, dst);
  }
}

#define printNChars(n, c) for(int _i = 0; _i < n; _i++, putchar(c))
#define N_STACKS 3
#define OFFSET 5

typedef struct _StackInfo {
  Stack* stack;
  int n;
} StackInfo;

static int exploreDepth(Stack* stack) {
  int i = 0;
  while (stack != NULL) {
    stack = stack->next;
    i++;
  }
  return i;
}

static void printEmptySlot(int n) {
  printNChars(n, ' ');
  putchar('|');
  printNChars(n + OFFSET, ' ');
}

static void printSlot(int n, int i) {
  printNChars(n - i, ' ');
  printNChars(i, '=');
  putchar('|');
  printNChars(i, '=');
  printNChars(n - i, ' ');
  printNChars(OFFSET, ' ');
}

void printStacks(int n, Stack* left, Stack* middle, Stack* right) {
  StackInfo stacks[N_STACKS] = {
    { left, exploreDepth(left) },
    { middle, exploreDepth(middle) },
    { right, exploreDepth(right) }
  };

  for (int r = n; r > 0; r--) {
    for (int c = 0; c < N_STACKS; c++) {
      if (stacks[c].n >= r) {
        printSlot(n, stacks[c].stack->i);
        stacks[c].stack = stacks[c].stack->next;
        stacks[c].n--;
      } else {
        printEmptySlot(n);
      }
    }
    putchar('\n');
  }
  printNChars(3*(2*n+OFFSET+1), '-');
  putchar('\n');
}
