/*
 * Dato un numero positivo Q, scrivere la sua rappresentazione in binario
 * naturale, applicando il tradizionale algoritmo per divisioni successive
 *  • in questo esercizio l’output sarà da leggersi da destra a sinistra
 *  • indicare anche il minimo numero di bit utilizzato.
 *
 * Esempio
 * Q: 19 in notazione decimale
 * In binario naturale (invertito) codificato su 5 bit
 * Q : 11001   con 5 bit
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  /* Acquisiamo il numero. */
  unsigned N;
  do {
    printf("Inserisci un intero positivo\n");
    scanf("%u", &N);
  } while (N <= 0);
  printf("In binario: ");

  int i = 0;
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
