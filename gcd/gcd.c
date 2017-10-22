#include "gcd.h"

uint_fast16_t modop(uint_fast16_t a, uint_fast16_t b) {
  if (b == 0) {
    exit(EXIT_FAILURE);
  }
  uint_fast16_t modulo = a;
  while (modulo >= b) {
    modulo -= b;
  }
  return modulo;
}

uint_fast16_t gcd(uint_fast16_t a, uint_fast16_t b) {
  uint_fast16_t r;
  if (a == 0 || b == 0) {
    return 0;
  }
  r = modop(a, b);
  while (r != 0) {
    a = b;
    b = r;
    r = modop(a, b);
  }
  return b;
}

uint_fast16_t find_gcd(uint_fast16_t arr[], uint_fast16_t n) {
  uint_fast16_t res = arr[0];
  int_least16_t i;
  for (i = 1; i < n; i++) {
    res = gcd(arr[i], res);
  }
  return res;
}
