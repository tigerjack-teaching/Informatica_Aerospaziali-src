#include <stdio.h>
#define LUN_MAX 100

int main() {
  int i, j, n;
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

  for (i = 1; i < n; i++) {
    int temp = V[i];
    j = i - 1;
    while (j >= 0 && temp <= V[j]) {
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
