/*
 * TAGS: array
 *
 * Trova il massimo e il minimo di un array.
 *
 * TODO Casa. Modificare l'esercizio in modo tale da leggere una sequenza di
 * interi da utente.
 *
 * TODO Classe. Modificare l'esercizio in modo tale da utilizzare INT_MIN e
 * INT_MAX della libreria <limits.h>
 */
#include <stdio.h>
/* #include <limits.h> */
#define SIZE 10

int main(int argc, char *argv[]) {
  int numbers[SIZE] = {5, 1, 6, 10, 2, 3, 6, 50, -7, 4};

  int max = numbers[0];
  int min = numbers[0];
  int i;
  for (i = 0; i < SIZE; i++) {
    if (numbers[i] > max) {
      max = numbers[i];
    }
    else if (numbers[i] < min) {
      min = numbers[i];
    }
  }
  printf("Max %d, Min %d\n", max, min);

  return 0;
}
