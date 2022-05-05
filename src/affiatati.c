#include <stdio.h>

int main() {
  int i, j, somma, prodotto;
  int unita1, unita2, decine1, decine2;

  // La struttura principale della soluzione è composta da un doppio
  // ciclo di iterazione. L'idea è quella di avere due variabili i e j,
  // che iterano su tutti i valori possibili a due cifre decimali
  // (quindi tra 0 e 99 compresi), e ad ogni iterazione controlla il
  // criterio per i numeri affiatati. Notare che la variabile j ad ogni
  // iterazione del ciclo esterno, viene inizializzata al valore di "i",
  // e non a 0. Questo per non effettuare il doppio confronto (se ho già
  // controllato 2 e 5, sarà inutile controllare 5 e 2).
  for (i = 0; i < 100; i++) {
    for (j = i; j < 100; j++) {

      // La somma è facile da calcolare.
      somma = i + j;

      // Estraiamo la cifra delle unità e delle decine, utilizzando
      // la divisione in modulo.
      unita1 = i % 10;
      unita2 = j % 10;
      decine1 = i / 10 % 10;
      decine2 = j / 10 % 10;

      // Controlliamo, se le decine dopo la trasformaziono sono equivalenti
      // a 0, significa che il numero era a singola cifra. Settimo la cifra
      // delle decine a 1, per non intaccare il prodotto calcolato sotto.
      if (decine1 == 0) {
        decine1 = 1;
      }
      if (decine2 == 0) {
        decine2 = 1;
      }

      // Questa versione commentata, sebbene più compatta non tiene in conto
      // i numeri a singola cifra.
      // prodotto = (i % 10) * (i / 10 % 10) * (j % 10) * (j / 10 % 10);

      // Calcolo del prodotto usando le variabili intermedie calcolate
      // sopra.
      prodotto = unita1 * unita2 * decine1 * decine2;

      // Se la somma è uguale al prodotto, stampiamo i numeri affiatati.
      // Questa versione stampa anche i numeri autoaffini, come esercizio
      // modificarla per eliminare questa possibilità.
      if (somma == prodotto) {
        printf("%d e %d sono affini!\n", i, j);
      }
    }
  }

  return 0;
}
