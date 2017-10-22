#include "gcd/gcd.h"

int main() {
  uint_fast16_t a = UINT_FAST16_MAX;
  uint_fast16_t b = UINT_FAST16_MAX;
  int_fast16_t i = 0;
  printf("%lu\n", modop(UINT_FAST16_MAX, 2));
  // printf("%lu\n", gcd(2, 10));
  // uint_fast16_t arr[] = {1024, 128, 256};
  // printf("%lu\n", find_gcd(arr, 4));
  return 0;
}
