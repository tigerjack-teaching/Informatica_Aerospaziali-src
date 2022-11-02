#include <limits.h>
#include <stdio.h>
#define SIZE 10

int main(int argc, char *argv[]) {
  int numbers[SIZE] = {5, 1, 6, 10, 2, 3, 6, 50, -7, 4};

  int max1 = INT_MIN;
  int max2 = INT_MIN;

  int i;
  for (i = 0; i < SIZE; i++) {
    if (numbers[i] > max1) {
      max2 = max1;
      max1 = numbers[i];
    }
  }

  printf("Max1 %d, Max2 %d\n", max1, max2);

  return 0;
}
