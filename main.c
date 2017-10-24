/**
  * @file main.c
  * @brief Racunanje najveceg zajednickog delioca primenom euklidovog algoritma bez operatora deljenja
  * i ostatka pri deljenju
  *
  * Euklidov algoritam je zasnovan na principu da se najveci zajednicki delioc dva broja ne menja
  * ako se veci broj zameni sa njegovom razlikom sa manjim brojem. Mada takvo resenje je ne efikasno
  * ako su jedan od brojeva mnogo veci od drugog. Efikasnija verzija euklidovog algoritma je da
  * umesto razlike veceg broja zamenimo sa ostatkom pri deljenju i algoritam se zavrsava dok ostatak
  * ne bude 0.
  *
  * Implementacija resenja se zasniva na efikasnijoj verziji euklidovog algoritma, sa softverski
  * implementiranom funkcijom koja racuna ostatak pri deljenju. Program mora da racuna NZD za niz
  * podataka, tako sto sukcesivno primenjuje euklidov algoritam nad nizom. Program radi samo sa neoznacenim
  * brojevima zbog bitwise implementacije racunanja modula. Program mora da radi nad nizom podataka,
  * tako je u main funkciji definisana duzina niza koju korisnik moze da menja, korisnik unosi
  * podatke u niz za koje ce biti izracunat najveci zajednicki delilac.
  *
  * @author Stefan Nicetin, RA188-2014
  * @date 23.10.2017.
  *
  * @bug No known bugs
  */
#include "gcd/gcd.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
int main() {
  uint_least32_t array[ARRAY_SIZE] = {0};
  int_least16_t size;
  int_least16_t index;
  do {
    printf("Size of the array (min: 2, max: %" PRIdLEAST16 "):", ARRAY_SIZE);
	scanf("%" SCNdLEAST16, &size);
  } while (size > 20 || size <= 1);

  for (index = 0; index < size; index++) {
	printf("Array[%" PRIdLEAST32 "] = ", index);
	scanf("%" SCNuLEAST32, (array + index));
    printf("\n");
  }
  printf("GCD: { ");
  for (index = 0; index < size; index++) {
	printf("%" PRIdLEAST32" ", array[index]);
  }

  printf("} = %" PRIdLEAST32 "\n", calculate_gcd(array, size));
  return 0;
}
