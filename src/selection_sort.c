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
    min = i;
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
