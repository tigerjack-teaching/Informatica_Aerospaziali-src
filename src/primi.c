#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  unsigned n; // e' un intero senza segno

  // Acquisiamo il nostro intero
  printf("Inserisci un numero\n");
  // %u e' per trattare un intero senza segno. Cosa succede se provate ad
  // %inserire un numero negativo?
  scanf("%u", &n);
  /* printf("Hai inserito %x\n", n); */

  // Gestiamo il caso base.
  if (n == 0 || n == 1) {
    printf("Il numero %u non è primo\n", n);
    return 0;
  }

  // Inizializziamo X, che conterrà tutti i valori per i quali
  // andremo a tentare di dividere il numero N.
  unsigned x = 2;
  unsigned r;

  /*
    Eseguiamo il ciclo per ottenere il resto della divisione intera. Dovremo
    testare tutti i divisori da 2 fino ad N - 1 (esercizio a casa: possiamo
    fare meglio di cosi'?). Quando troviamo un divisore, interrompiamo il
    ciclo.
  */
  while (x < n) {
    r = n % x;
    if (r == 0) {
      printf("Il numero %u non è primo\n", n);
      printf("Puo' essere diviso per %u\n", x);
      return 0;
    }
    x++;
  }

  // Se siamo arrivati qui, non abbiamo trovato divisori
  printf("Il numero %d è primo\n", n);

  // Terminiamo l'esecuzione del programma.
  return 0;
}
