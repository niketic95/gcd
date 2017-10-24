/** @file gcd.h
 *  @brief Declarations for greatest common divisor (GCD)
 *
 * This file contains function declarations which are used for calculating the greatest
 * common divisor
 *
 *  @author Stefan M. Nicetin
 *  @bug No known bugs
 *
 */

#ifndef GCD_H_
#define GCD_H_

#include <stdint.h>

/** @brief Calculates remainder of two numbers
 *
 *  @note When denominator is 0 this function returns its numerator because
 *  gcd(2,0) = 2 (2 Divides both 0 and 2) but 2%0 is undefined behavior.
 *
 *  @details the modulo operator is implemented using bitwise operations so it can be
 *  executed as fast as possible. Because of possible overflow occurring when the denominator
 *  is a really big number, the denominator is stored inside a bigger type.
 *
 * @param Modulo operands (a%b)
 * @return Remainder (Excluding when the denominator is 0)
 */
uint_least32_t modop( uint_least32_t a, uint_least32_t b);

/** @brief Calculates the greatest common divisor (GCD)
 *
 *   @details Iterative solution for calculating the GCD with special cases for 0
 *  since the output of GCD is always non negative the return value is an unsigned number
 *
 * @param Operands for which the GCD is calculated
 * @return GCD
 */
uint_least32_t gcd( uint_least32_t a, uint_least32_t b);

/** @brief Calculates GCD on a array of numbers
 *
 * Function iterates over array applying GCD
 *
 * @param Input array and its length
 * @return GCD of an array of nubmers
 */
uint_least32_t calculate_gcd( const uint_least32_t arr[], const int_least16_t n);

#endif /* GCD_H_ */
