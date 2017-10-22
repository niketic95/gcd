#ifndef GCD_H
#define GCD_H

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint_fast16_t modop(uint_fast16_t a, uint_fast16_t b);
uint_fast16_t gcd(uint_fast16_t a, uint_fast16_t b);
uint_fast16_t find_gcd(uint_fast16_t arr[], uint_fast16_t n);
#endif // GCD_H
