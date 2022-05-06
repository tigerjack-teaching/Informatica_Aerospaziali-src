#include <stdio.h>
#define LUN_MAX 100
int main() {
  int v[LUN_MAX], i, n, k;

  // Acquisiamo un intero n, che rappresenta il numero di elementi da acquisire.
  do {
    printf("\nInserisci il numeri di elementi da acquisire (max %d)", LUN_MAX);
    scanf("%d", &n);
  } while ((n <= 0) || (n > LUN_MAX));

  /* Acquisimo gli elementi del vettore da ordinare. */
  printf("\nInserisci gli elementi del vettore: ");
  for (i = 0; i < n; ++i) {
    scanf("%d", &v[i]);
  }
  /* ... ometto codice lettura vettore ... */
  int min = v[0], max = v[0];
  for (i = 1; i < n; i++) {
    if (min > v[i])
      min = v[i];
    if (max < v[i])
      max = v[i];
  }
  int intervallo = 1; // uso una variabile indicatrice
  for (k = min + 1; k < max && intervallo == 1; k++) {
    for (i = 0; i < n && v[i] != k; i++)
      ;
    if (i == n)
      intervallo = 0;
  }
  if (intervallo == 1)
    printf(" \nL' insieme di numeri e' un Intervallo \n ");
  else
    printf(" \n L' insieme di numeri NON e' un Intervallo \n ");
  return 0;
}
