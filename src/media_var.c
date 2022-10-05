#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  float somma = 0;
  int n = 0;
  float x;
  printf("Inserisci un numero\n");
  scanf("%f", &x);

  while (x != 0) {
    somma += x;
    n += 1;
    printf("Inserisci un numero\n");
    scanf("%f", &x);
  }

  if (n == 0) {
    printf("Nessun numero inserito, media 0 \n");
  } else {
    printf("Media = %f\n", somma / n);
  }

  return 0;
}
