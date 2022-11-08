/*
 * Scrivere un programma che legge un vettore di $N$ numeri interi (dove $N$
 * rappresenta una costante definita dal programmatore) e riporta a video 1 se
 * l’insieme rappresentato contiene valori che possono essere considerati come
 * numeri facenti parte di un intervallo (anche se alcuni numeri sono
 * duplicati), e 0 altrimenti.
 *
 *  - N = 3, V[] = {4, 5, 6}          -> 1
 *  - N = 3, V[] = {4, 5, 5}          -> 1
 *  - N = 5, V[] = {-2, 0, 1, -3, -1} -> 1
 *  - N = 4, V[] = {0, 3, 0, 1}       -> 0 (manca 2)
 *  - N = 4, V[] = {0, 3, -1, 1}      -> 0 (manca 2)
 *
 * TODO casa: Il problema puo' essere risolto anche utilizzando uno degli algoritmi di
 * sorting.
 */
#include <stdio.h>
#define LUN_MAX 100
int main() {
  int v[LUN_MAX], i, n, k;
  int intervallo;
  int min, max;

  /* Acquisiamo un intero n, che rappresenta il numero di elementi da acquisire. */
  do {
    printf("\nInserisci il numeri di elementi da acquisire (max %d)", LUN_MAX);
    scanf("%d", &n);
  } while ((n <= 0) || (n > LUN_MAX));

  /* Acquisimo gli elementi del vettore da ordinare. */
  printf("\nInserisci gli elementi del vettore: ");
  for (i = 0; i < n; ++i) {
    scanf("%d", &v[i]);
  }
  printf("Il vettore e': [");
  for (i = 0; i < n; i++) {
    printf("%d", v[i]);
  }
  printf("]\n");

  min = v[0], max = v[0];
  for (i = 1; i < n; i++) {
    if (min > v[i])
      min = v[i];
    if (max < v[i])
      max = v[i];
  }
  intervallo = 1;
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
