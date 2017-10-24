/** @file gcd.h
 *  @brief Prototipovi za dinamicku biblioteku
 *
 * Ova datoteka sadrzi deklaracije funkcija koje se koriste za racunanje najveceg zajednickog
 * delioca
 *
 *  @author Stefan M. Nicetin
 *  @bug No known bugs
 *
 */

#ifndef GCD_H
#define GCD_H

#include <stdint.h>

/** @brief Racuna ostatak pri deljenju
 *
 * 	Ako je imenilac jednak 0 iz programa sa izadje
 * 	Modop je vecinom realizovan pomocu bitskih operacija zbog fokusa na brzinu izvrsavanja
 *  funkcije. Zbog moguce pojave overflow-a pri shiftovanju za mnogo vece vrednosti, vrednost
 *  imenioca mora da bude smestena u promenljivu koja ima vecu velicinu nego tip imenioca.
 *
 * @param Operandi za racunaje ostatka (a%b)
 * @return Ostatak pri deljenju
 */
uint_least32_t modop( uint_least32_t a, uint_least32_t b );

/** @brief Racuna najveci zajednicki delilac
 *
 *  Iterativno resenje najveceg zajednickog delioca uz specijalan slucaj za nulte vrednosti.
 *  Zato sto vrednosti NZD su uvek ne negativne povratna vrednost je neoznacen ceo broj.
 *  Parametri su takodje neoznaceni zbog nacina implementacije ostatka pri deljenju.
 *
 * @param Operandi od kojih se racuna NZD
 * @return NZD
 */
uint_least32_t gcd( uint_least32_t a, uint_least32_t b );

/** @brief Racuna najveci zajednicki delilac za niz ne oznacenih vrednosti
 *
 * Prelazi kroz ceo niz i sukcesivno primenjuje gcd.
 *
 * @param Niz i njegova duzina na kojeg ce se primeniti gcd
 * @return NZD za ceo niz
 */
uint_least32_t calculate_gcd( const uint_least32_t arr[], const int_least16_t n );
#endif  // GCD_H
