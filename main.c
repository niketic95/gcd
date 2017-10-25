/**
 * @file main.c
 * @brief Calculating the greatest common divisor using the euclidean algorithm and a software
 * implementation of the modulo operator.
 *
 * The Euclidean algorithm is based on the principle that the greatest common divisor of two numbers
 * does not change if the larger number is replaced by its difference with the smaller number.
 *
 * The version of the Euclidean algorithm described above  can take many subtraction steps to find the GCD
 * when one of the given numbers is much bigger than the other. A more efficient version of the algorithm
 * shortcuts these steps, instead replacing the larger of the two numbers by its remainder when divided by
 * the smaller of the two.
 *
 * The solution is based on the modulo implementation of the euclidean method, with a software implemented modulo
 * function. The program calculates the GCD of an array of numbers (signed or unsigned). The size of the array is
 * defined in the main file. Library files of the solution are MISRA C Compliant whilst the main.c file breaks
 * the MISRA-C:2004 20.9/R because printf and scanf from the stdio header are used.
 *
 *
 * @author Stefan Nicetin, RA188-2014
 * @date 23.10.2017.
 *
 * @bug No known bugs
 */


#include "gcd.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 100

int_least32_t main(void);


int_least32_t main(void)
{
	int_least32_t array[ ARRAY_SIZE ] = { 0 };
	int_least16_t  size;
	int_least16_t  index;

	do
	{
		printf( "Size of the array (min: 2, max: %" PRIdLEAST16 "):", ARRAY_SIZE );
		scanf( "%" SCNdLEAST16, &size );
	} while ( (size > ARRAY_SIZE) ||
				(size <= 1) );

	for ( index = 0; index < size; index++ )
	{
		printf( "Array[%" PRIdLEAST16 "] = ", index );
		scanf( "%" SCNdLEAST32, &array[index] );
	}
	printf( "GCD: { " );
	for ( index = 0; index < size; index++ )
	{
		printf( "%" PRIdLEAST32 " ", array[ index ] );
	}
	printf( "} = %" PRIuLEAST32 "\n", calculate_gcd( array, size) );
	return 0;
}
