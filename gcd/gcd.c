/** @file gcd.c
 *  @brief Implementation of the Greatest common divisor
 *
 *  Implementation of the needed operator and the implementation of the greatest common divisor
 *  using the euclids algorithm
 *
 *  @author Stefan M. Nicetin
 *  @bug No known bugs
 */

#include "gcd.h"

uint_least32_t modop( uint_least32_t a, uint_least32_t b)
{
	uint_least64_t digit_pos = 1u;
	uint_least64_t denominator = b;
	/* Divide by zero will return 0*/
	if(denominator == 0u)
	{
		a = 0u;
	}else{
		/* Shifting the denominator to the left while temporary tracks the digit position */
		while( denominator <= a )
		{
			denominator <<= 1;
			digit_pos <<= 1;
		}
		/* Until all digits are finished */
		while( digit_pos > 1u )
		{
			denominator >>= 1u;
			digit_pos >>= 1u;

			if( a >= denominator )
			{
				a -= denominator;
			}
		}
	}
	return a;
}


uint_least32_t gcd( int_least32_t a, int_least32_t b)
{
	uint_least32_t r;
	uint_least32_t op1 = (uint_least32_t)a;
	uint_least32_t op2 = (uint_least32_t)b;
	if(a < 0)
	{
		/* Multiplication by -1 or unary use of the - sign breaks MISRA-C:2004 12.9/R so bitwise conversion is used*/
		op1 = ~op1 + 1u;
	}
	if(b < 0)
	{
		/* Multiplication by -1 or unary use of the - sign breaks MISRA-C:2004 12.9/R  rule so bitwise conversion is used*/
		op2 = ~op2 + 1u;
	}
	if( (op1 == 0u)
			||(op2 == 0u) )
	{
		op2+=op1;
	}else{
		r = modop(op1,op2);
		while( r != 0u )
		{
			op1 = op2;
			op2 = r;
			r = modop(op1,op2);
		}
	}
	return op2;
}

uint_least32_t calculate_gcd( const int_least32_t arr[], const int_least16_t n )
{
	uint_least32_t res = arr[ 0 ];
	int_least16_t i;
	if ( arr[ 0 ] < 0 )
	{
		res = ~res + 1u;
	}

	for( i = 1; i < n; i++ )
	{
		res = gcd( arr[ i ], (int_least32_t)res);
	}
	return res;
}
