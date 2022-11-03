/*
 * Trovare il massimo e il minimo tra tre numeri.
 *
 * TODO Casa. Come fare il check su rette parallele?
 */
#include <stdio.h>

int main(int argc, char *argv[]) {
  float x, y, z;
  printf("Primo numero: ");
  scanf("%f", &x);
  printf("\nSecondo numero: ");
  scanf("%f", &y);
  printf("\nTerzo numero: ");
  scanf("%f", &z);

  if (x < y) {
    if (y < z) {
      printf("\nmin = %f", x);
      printf("\nmax = %f", z);
    } else { /* x<y, y>=z */
      if (x < z) {
        printf("\nmin = %f", x);
        printf("\nmax = %f", y);
      }
      else { /* x<y, y>=z, x>=z*/
        printf("\nmin = %f", z);
        printf("\nmax = %f", y);
      }
    }
  } else { /* x >= y */
    if (y > z) {
      printf("\nmin = %f", z);
      printf("\nmax = %f", x);
    } else { /* x >= y, y <= z*/
      if (x < z) {
        printf("\nmin = %f", y);
        printf("\nmax = %f", z);
      }
      else {
        printf("\nmin = %f", y);
        printf("\nmax = %f", x);
      }
    }
  }

  return 0;
}
