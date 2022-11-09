/*
 * TAGS: array, sort
 *
 * Implementare un programma che preso un vettore di interi, ordini i suoi
 * elementi in ordine crescente, utilizzando la tecnica dell'insertion sort.
 *
 * ESEMPIO:
 *
 * STEP 1: arr[] = {12, _11_, 13, 5, 6}
 *   - comparo 11 con 12 -> posizioni sbagliate -> swap
 *   - stop (non ci sono altre posizioni precedenti)

 * STEP 2: arr[] = {11 | _12_, 13, 5, 6}
 *   - comparo 13 con 12 -> ok -> stop -> {11, 12| 13, 5, 6}
 *
 * STEP 3: arr[] = {11, 12| _13_, 5, 6}
 *   - comparo 5 con 13 -> swap -> {11, 12| 5, 13, 6}
 *   - comparo 5 con 12 -> swap -> {11, 5, 12| 13, 6}
 *   - comparo 5 con 11 -> swap -> {5, 11, 12| 13, 6}
 *   - stop
 *
 * STEP 4: arr[] = {5, 11, 12| 13 _6_}
 *   - comparo 6 con 13 -> swap -> {5, 11, 12| _6_, 13}
 *   - comparo 6 con 12 -> swap -> {5, 11, _6_, 12| 13}
 *   - comparo 6 con 11 -> swap -> {5, _6_, 11, 12| 13}
 *   - comparo 6 con 5 -> no swap -> stop
 */
#include <stdio.h>
#define LUN_MAX 100

int main() {
  int i, j, n;
  int V[LUN_MAX];

  /* Acquisiamo un intero n, che rappresenta il numero di elementi da
     acquisire. */
  do {
    printf("\nInserisci il numeri di elementi da acquisire (max %d)", LUN_MAX);
    scanf("%d", &n);
  } while ((n <= 0) || (n > LUN_MAX));

  /* Acquisiamo gli elementi del vettore da ordinare. */
  printf("\nInserisci gli elementi del vettore: ");
  for (i = 0; i < n; ++i) {
    scanf("%d", &V[i]);
  }

  for (i = 1; i < n; i++) {
    int temp = V[i];
    for (j = i - 1; j >= 0 && temp <= V[j]; j++) {
      V[j + 1] = V[j];
      j = j - 1;
    }
    V[j + 1] = temp;
  }

  printf("\nStato finale del vettore: ");
  for (i = 0; i < n; i++)
    printf("%d ", V[i]);

  return 0;
}
