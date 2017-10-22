#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int divop(int a, int b) {
  int_least8_t sign = 1;
  int ret = 0;
  if (a < 0) {
    printf("%d", a);
    a = -a;
    printf("%d", a);
    sign = -sign;
  }
  if (b < 0) {
    b = -b;
    sign = -sign;
  }
  while (a > b) {
    a -= b;
    ret++;
  }
  return ret * sign;
}

int modop(int a, int b) {
  if (b == 0) {
    exit(EXIT_FAILURE);
  }
  return a - (a / b) * b;
}

int main() {
  int a = INT_MIN + 1;
  int b = 2;
  printf("mod(a,b) = %d\n", modop(a, b));
  printf("a%b = %d\n", a % b);
  printf("div(a,b) = %d\n", divop(a, b));
  printf("a/b = %d\n", a / b);
  return 0;
}
