#include "gcd/gcd.h"

#define TYPE unsigned
int main() {
  TYPE a = UINT_MAX;
  TYPE b = 1;
  printf("mod(a,b) = %d\n", modop(a, b));
  printf("a % b = %d\n", a % b);
  printf("divop(a,b) = %d\n", divop(a, b));
  printf("a / b = %d\n", a / b);

  return 0;
}
