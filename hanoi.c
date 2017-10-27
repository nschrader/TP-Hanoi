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

#define newStackIfNull(x) ((x == NULL) ? newStack() : x)
#define printNChars(n, c) for(int _i = 0; _i < n; _i++, putc(c, stdout))
#define N_STACKS 3
#define OFFSET 5

void printStacks(int n, Stack* left, Stack* middle, Stack* right) {
  Stack* stacks[N_STACKS] = {
    newStackIfNull(left),
    newStackIfNull(middle),
    newStackIfNull(right)
  };

  for (int r = 1; r <= n; r++) {
    for (int c = 0; c < N_STACKS; c++) {
      if (stacks[c]->i == r) {
        printNChars(n - r, ' ');
        printNChars(r, '=');
        putc('|', stdout);
        printNChars(r, '=');
        printNChars(n - r, ' ');
        printNChars(OFFSET, ' ');
        stacks[c] = newStackIfNull(stacks[c]->next);
      } else {
        printNChars(n, ' ');
        putc('|', stdout);
        printNChars(n + OFFSET, ' ');
      }
    }
    putc('\n', stdout);
  }
  printNChars(3*(2*n+OFFSET+1), '-');
  putc('\n', stdout);
}
