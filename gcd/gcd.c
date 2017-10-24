/** @file gcd.c
 *  @brief Implementacija najmanjeg zajednickog delioca
 *
 *  Implementacija potrebnih oepratora i implementacija najveceg zajednickog delioca
 * 	pomocu euklidovog algoritma.
 *
 *  @author Stefan M. Nicetin
 *  @bug No known bugs
 */

#include "gcd.h"
#include <stdlib.h>

uint_least32_t modop( uint_least32_t a, uint_least32_t b )
{
	uint_least32_t temp		   = 1;
	uint_least64_t denominator = b;

	/* Eliminisanje deljenja sa nulom */
	if( denominator == 0 )
	{
		exit( EXIT_FAILURE );
	}

	/* Moguce ubrzanje za velike brojeve */
	if( a == denominator )
	{
		return 0;
	}

	/* Pomeranje imenioca na krajnje levu stranu brojioca gde temp prati poziciju cifre*/
	while( denominator <= a )
	{
		denominator <<= 1;
		temp <<= 1;
	}

	/* Dok se ne dodje do zadnje cifre*/
	while( temp > 1 )
	{
		denominator >>= 1;
		temp >>= 1;

		if( a >= denominator )
		{
			a -= denominator;
		}
	}

	return a;
}

uint_least32_t gcd( uint_least32_t a, uint_least32_t b )
{
	uint_least32_t r;

	if( a == 0
			|| b == 0 )
	{
		return a + b;
	}
	r = modop( a, b );
	while( r != 0 )
	{
		a = b;
		b = r;
		r = modop( a, b );
	}
	return b;
}

uint_least32_t calculate_gcd( const uint_least32_t arr[], const int_least16_t n )
{
	uint_least32_t res = arr[ 0 ];
	int_least16_t  i;
	for( i = 1; i < n; i++ )
	{
		res = gcd( arr[ i ], res );
	}
	return res;
}
