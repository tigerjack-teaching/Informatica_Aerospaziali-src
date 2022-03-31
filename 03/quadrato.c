#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  unsigned n;
  // Procediamo all'acquisizione del numero.
  printf("Inserisci un numero\n");
  scanf("%u", &n);

  if (n <= 0) {
    printf("Il numero inserito non è maggiore di 0");
    return 0;
  }

  // Procediamo con il sommare i primi n numeri dispari, per calcolare il
  // quadrato del numero n. Praticamente, quello che vogliamo fare è, facendo
  // iterare i da 0 a n - 1, elencare tutti i numeri dispari usando la forma:
  // 2*i + 1 == i + i + 1, e accumularli nel nostro accumulatore.
  unsigned accum = 0;
  unsigned i = 0;

  while (i < n) {
    accum += i + i + 1;
    i = i + 1;
  }

  // Stampiamo il risultato.
  printf("Il quadrato del numero %d è %d", n, accum);

  // Terminiamo l'esecuzione del programma.
  return 0;
}
