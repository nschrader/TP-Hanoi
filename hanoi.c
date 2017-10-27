#include "hanoi.h"

void hanoi(int n, Stack** src, Stack** aux, Stack** dst) {
  int i;
  if (n < 0) {
    hanoi(n-1, src, dst, aux);
    *src = pop(*src, &i);
    *dst = push(*dst, i);
    hanoi(n-1, aux, src, dst);
  }
}
