/*
 * TAGS: array
 *
 * Trova il secondo numero piu' grande in un array non ordinato
 */
#include <limits.h>
#include <stdio.h>
#define SIZE 10

int main(int argc, char *argv[]) {
  int numbers[SIZE] = {15, 12, 14, 10, 2, 3, 6, 10, -7, 4};

  int max1 = INT_MIN;
  int max2 = INT_MIN;

  int i;
  for (i = 0; i < SIZE; i++) {
    if (numbers[i] > max1) {
      max2 = max1;
      max1 = numbers[i];
    }
    else if (numbers[i] > max2 && numbers[i] < max1) {
      max2 = numbers[i];
    }
  }

  printf("Max1 %d, Max2 %d\n", max1, max2);

  return 0;
}
