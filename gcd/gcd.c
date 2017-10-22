#include "gcd.h"
TYPE divop(TYPE a, TYPE b) {
  int_least8_t sign = 1;
  TYPE ret = 0;
  if (b == 0) {
    exit(EXIT_FAILURE);
  }

  if (b < 0 && a < 0) {
    if (b < a) {
      return 0;
    }
  }
  if (b < 0 && a > 0) {
    if (b < -a) {
      return 0;
    }
  }
  if (b > 0 && a < 0) {
    if (-b < a) {
      return 0;
    }
  }
  if (b > 0 && a > 0) {
    if (b > a) {
      return 0;
    }
  }

  if (b < 0) {
    sign = -sign;
  }
  if (a < 0) {
    sign = -sign;
    while (ret * b > a) {
      ret += sign;
    }
    if (ret * b != a) {
      ret -= sign;
    }
  } else {
    while (ret * b < a) {
      ret += sign;
    }
    if (ret * b != a) {
      ret -= sign;
    }
  }
  return ret;
}

TYPE modop(TYPE a, TYPE b) {
  if (b == 0) {
    exit(EXIT_FAILURE);
  }
  return a - divop(a, b) * b;
}
