#ifndef GCD_H
#define GCD_H

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef TYPE
#define TYPE int_fast16_t
#endif

TYPE divop(TYPE a, TYPE b);
TYPE modop(TYPE a, TYPE b);

#endif // GCD_H
