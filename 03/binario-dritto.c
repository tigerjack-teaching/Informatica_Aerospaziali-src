#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  unsigned N = 0;

  // Acquisizione dell'input.
  while (N <= 0) {
    printf("Inserisci un intero positivo\n");
    scanf("%u", &N);
  }

  // Precalcoliamo, su una copia ausiliaria di N (in modo da non distruggere N),
  // il numero di bit che ci serviranno per rappresentare N.
  unsigned b = 0;
  unsigned Naux = N;
  while (Naux > 0) {
    Naux /= 2;
    b += 1;
  }

  printf("Numero di bit necessari per rappresentare %d: %d\n", N, b);
  printf("La codifica è: ");

  // L'idea è la seguente: per stampare la rappresentazione in binario già
  // invertita, procediamo (grazie alla conoscenza del numero di bit che ci
  // serviranno per rappresentare il numero), ad effettuare il metodo di
  // divisioni successive per ogni bit, ogni volta fermandoci al bit per il
  // quale vogliamo calcolare il resto della divisione intera, e stampandone
  // quindi l'output. Ovviamente, ad ogni iterazione di questo ciclo esterno, il
  // ciclo interno dovra arrestarsi ad uno step prima.
  unsigned i = b;
  while (i > 0) {

    // Ad ogni iterazione del ciclo esterno, ripristiniamo il valore iniziale di
    // N (le iterazioni precedenti avranno distrutto il valore).
    Naux = N;

    // Questo ciclo interno, procederà ad effettuare le divisioni successive
    // ignorando il resto, per tutti i bit precedenti a quello che ci
    // interessano.
    unsigned j = 0;
    while (j < i - 1) {
      Naux /= 2;
      j += 1;
    }

    // Stampo il resto della divisione del bit che mi interessa rappresentare.
    printf("%u", Naux % 2);
    i -= 1;
  }
  printf("\n");

  // Terminiamo l'esecuzione del programma.
  return 0;
}
