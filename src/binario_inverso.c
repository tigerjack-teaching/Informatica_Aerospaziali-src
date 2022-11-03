#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  /* Acquisiamo il numero. */
  unsigned N = 0;
  int i = 0;
  while (N <= 0) {
    printf("Inserisci un intero positivo\n");
    scanf("%u", &N);
  }
  printf("In binario: ");

  /* Procediamo per divisioni successive. i ci servirà solo per accumulare il */
  /* numero di bit necessari per la rappresentazione. */
  while (N > 0) {
    /* Stampiamo il resto della divisione intera. */
    printf("%u", (N % 2));

    /* Aggiorniamo il risultato della divisone intera (che ignora il resto). */
    N /= 2;
    i += 1;
  }
  printf("\n");
  printf("Numero di bit necessari: %u\n", i);
  return 0;
}
