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
	uint_least32_t temp	   = 1u;
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
			temp <<= 1;
		}
		/* Until all digits are finished */
		while( temp > 1u )
		{
			denominator >>= 1u;
			temp >>= 1u;

			if( a >= denominator )
			{
				a += (~denominator)+1u;
			}
		}
	}
	return a;
}


uint_least32_t gcd( uint_least32_t a, uint_least32_t b)
{
	uint_least32_t r;

	if( (a == 0u)
			||(b == 0u) )
	{
		b+=a;
	}else{
		r = modop(a,b);
		while( r != 0u )
		{
			a = b;
			b = r;
			r = modop(a,b);
		}
	}
	return b;
}

uint_least32_t calculate_gcd( const uint_least32_t arr[], const int_least16_t n )
{
	uint_least32_t res = arr[ 0 ];
	int_least16_t  i;

	for( i = 1; i < n; i++ )
	{
		res = gcd( arr[ i ], res);
	}
	return res;
}
