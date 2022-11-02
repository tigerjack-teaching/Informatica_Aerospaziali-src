/*
 * Implementare un programma che stampa, fornendo in output una formattazione
 * ragionevole, le tabelline dei numeri dall'1 al 9. Si richiede, in
 * particolare, di stampare l'output andando a capo alla fine della tabellina di
 * ogni numero, e di allineare verticalmente le varie linee delle tabelline.
 */
#include <stdio.h>

int main(int argc, char *argv[]) {
  // Utilizziamo due variabili contatore per contenere il moltiplicando e il
  // moltiplicatore.
  int i, j;

  for (i = 1; i <= 10; i++) {
    // Stampiamo il nome della tabellina.
    printf("Tabellina del %.2d:", i);
    for (j = 1; j <= 10; j++) {
      // Stampiamo i numeri componenti la tabellina.
      printf(" %3d", i * j);
    }

    // Andiamo a capo alla fine di ogni tabellina di un
    // numero.
    printf("\n");
  }
}
