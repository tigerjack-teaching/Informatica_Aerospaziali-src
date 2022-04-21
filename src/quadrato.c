#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  unsigned n;
  // Procediamo all'acquisizione del numero.

  do {
    printf("Inserisci un numero\n");
    scanf("%u", &n);
  } while (n <= 0);

  // Procediamo con il sommare i primi n numeri dispari, per calcolare il
  // quadrato del numero n. Praticamente, quello che vogliamo fare è,
  // facendo iterare i da 0 a n - 1, elencare tutti i numeri dispari usando
  // la forma: 2*i + 1 == i + i + 1, e accumularli nel nostro accumulatore.
  unsigned accum = 0;

  while ( n > 0) {
    accum += n + n - 1;
    n--;
  }

  // Stampiamo il risultato.
  printf("Il quadrato del numero %d è %d\n", n, accum);

  // Terminiamo l'esecuzione del programma.
  return 0;
}
