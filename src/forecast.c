/*
 * TAGS: multid-array
 * 
 * Salva la temperatura di 2 citta' nel corso della settimana in un array 2D
 */
#include <stdio.h>
const int CITY = 2;
const int WEEK = 7;
int main() {
  int temperature[CITY][WEEK];

  for (int i = 0; i < CITY; ++i) {
    for (int j = 0; j < WEEK; ++j) {
      printf("Citta' %d, Giorno %d: ", i + 1, j + 1);
      scanf("%d", &temperature[i][j]);
    }
  }
  for (int i = 0; i < CITY; ++i) {
    for (int j = 0; j < WEEK; ++j) {
      printf("City %d, Day %d = %d\n", i + 1, j + 1, temperature[i][j]);
    }
  }
  return 0;
}
