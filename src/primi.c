/*
 * Scrivere un programma che dato in input un numero intero X > 0, verifica se X
 * e' primo
 */
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
  printf("bit: %b\n", n); // N.B.: solo da GNU C > 2.35

  // Gestiamo il caso base.
  if (n == 0 || n == 1) {
    printf("Il numero %u non è primo\n", n);
  } else {
    // Inizializziamo X, che conterrà tutti i valori per i quali
    // andremo a tentare di dividere il numero N.
    unsigned i;
    unsigned r;

    /*
      Eseguiamo il ciclo per ottenere il resto della divisione intera. Dovremo
      testare tutti i divisori da 2 fino ad n - 1 (esercizio a casa: possiamo
      fare meglio di cosi'?). Quando troviamo un divisore, interrompiamo il
      ciclo.
    */
    if (n % 2 == 0) {
printf("Il numero %u e' pari\n", n);
    } else {
      for (i = 3; i < n / 2; i += 2) {
        /* for (i = 3; i * i < n; i += 2) { */
        r = n % i;
        if (r == 0) {
          printf("Il numero %u non è primo\n", n);
          printf("Puo' essere diviso per %u\n", i);
          return 0;
        }
      }
    }

    // Se siamo arrivati qui, non abbiamo trovato divisori
    printf("Il numero %d è primo\n", n);

    // Terminiamo l'esecuzione del programma.
  }
  return 0;
}
