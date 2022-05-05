#include <stdio.h>
#define LUN_MAX 100

int main(int argc, char *argv[]) {
  int i, j, n, aux;
  int sentinella;
  int V[LUN_MAX];

  /* Acquisiamo un intero n, che rappresenta il numero di elementi da acquisire.
   */
  do {
    printf("\nInserisci il numeri di elementi da acquisire (max %d)", LUN_MAX);
    scanf("%d", &n);
  } while ((n <= 0) || (n > LUN_MAX));

  /* Acquisimo gli elementi del vettore da ordinare. */
  printf("\nInserisci gli elementi del vettore: ");
  for (i = 0; i < n; ++i) {
    scanf("%d", &V[i]);
  }

  /* Per l'algoritmo di bubble sort, non basta una semplice passata di scambi,
     ma nel caso peggiore bisogna iterare sul vettore n - 1 volte. */
  for (i = 0; i < n; i++) {
    sentinella = 1;

    /* Iteriamo su tutte le coppie presenti nel vettore, e scambiamo gli
       elementi adiacenti se non rispettano l'ordinamento. */
    for (j = 0; j < n - 1; j++) {
      if (V[j] > V[j + 1]) {
        aux = V[j + 1];
        V[j + 1] = V[j];
        V[j] = aux;

        /* Se facciamo almeno uno scambio in una iterazione, lo segnaliamo
           nella nostra variabile sentinella. */
        sentinella = 0;
      }
    }

    /* Se la sentinella è ancora ad 1, significa che nella iterazione "esterna"
       corrente, non è stato effettuato alcuno scambio tra valori adiacenti.
       Questo significa che il vettore è già ordinato, e iterazioni successive
       non attueranno sicuramente nessun cambiamento. */
    if (sentinella == 1) {
      break;
    }
  }

  printf("\nStato finale del vettore: ");
  for (i = 0; i < n; i++)
    printf("%d", V[i]);

  return 0;
}
