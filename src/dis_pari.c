/*
 * Stabilire se numero e' pari o dispari
 */
#include <stdio.h>

int main(int argc, char *argv[]) {
  int x;

  printf("Inserisci un intero positivo\n");
  scanf("%d", &x);

  printf("%f e': ", x);
  if (x % 2 == 0) {
    printf("pari");
  }
  else {
    printf("dispari");
  }
  printf("\n");

  return 0;
}
