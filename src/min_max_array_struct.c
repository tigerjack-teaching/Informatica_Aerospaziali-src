/*
 * TAGS: array, struct, typedef
 *
 * Trova il massimo e il minimo di un array, memorizzando tali valori in una
 * struct.
 *
 * TODO Classe. Utilizzare typedef con struct.
 */
#include <limits.h>
#include <stdio.h>
#define SIZE 10

struct Coppia {
  int min;
  int max;
};

int main(int argc, char *argv[]) {
  int numbers[SIZE] = {5, 1, 6, 10, 2, 3, 6, 50, -7, 4};

  struct Coppia minmax;
  minmax.min = INT_MAX;
  minmax.max = INT_MIN;

  int i;
  for (i = 0; i < SIZE; i++) {
    if (numbers[i] > minmax.max) {
      minmax.max = numbers[i];
    } else if (numbers[i] < minmax.min) {
      minmax.min = numbers[i];
    }
  }
  printf("Max %d, Min %d\n", minmax.max, minmax.min);

  return 0;
}
