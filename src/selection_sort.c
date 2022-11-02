/*
 * TAGS: array, sort
 *
 * Ordinare un array utilizzando l'algoritmo di selection sort
 *
 * Concettualmente, consideriamo l'array di input diviso in due parti: una
 * ordinata (a sx) e una non ordinata (a dx). L'algoritmo cerca il minimo nella
 * parte non ordinata e lo inserisce in coda alla parte ordinata.
 *
 * Esempio: [64, 25, 12]
 * Step 1 -> ordinata [], non ordinata [64, 25, 12]
 *           Cerco minimo -> 12
 *           Inserisco in coda a ordinata
 * Step 2 -> ord: [12], non-ord: [64, 25]
 *           Cerco minimo -> 25
 *           Inserisco in coda a ordinata
 * Step 3 -> ord: [12, 25], non-ord: [64]
 *           Cerco minimo -> 25
 *           Inserisco in coda a ordinata
 * Step 4 -> ord: [12, 25, 64], non-ord: []
 *
 * HINT: scambia min con posizione corrente.
 */
#include <stdio.h>
#define LUN_MAX 100

int main() {
  int i, j, n, min, temp;
  int V[LUN_MAX];

  // Acquisiamo un intero n, che rappresenta il numero di elementi da acquisire.
  do {
    printf("\nInserisci il numeri di elementi da acquisire (max %d)", LUN_MAX);
    scanf("%d", &n);
  } while ((n <= 0) || (n > LUN_MAX));

  /* Acquisimo gli elementi del vettore da ordinare. */
  printf("\nInserisci gli elementi del vettore: ");
  for (i = 0; i < n; ++i) {
    scanf("%d", &V[i]);
  }

  for (i = 0; i < n - 1; i++) {
    min = i; // posizione del minimo
    for (j = i + 1; j < n; j++)
      if (V[j] < V[min])
        min = j;

    temp = V[min];
    V[min] = V[i];
    V[i] = temp;
  }

  printf("\nStato finale del vettore: ");
  for (i = 0; i < n; i++)
    printf("%d ", V[i]);

  return 0;
}
