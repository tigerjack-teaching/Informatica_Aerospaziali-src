#include <stdio.h>
#define N 10
int main() {
  int dati[N], i, j;

  for (i = 0; i < N; ++i) {
    printf("\n numero %d: ", i + 1);
    scanf("%d", &dati[i]);
  }

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (dati[i] == 2 * dati[j] && dati[i] != 0) // Evita (0, 0)
        printf(" (%d, %d) ", dati[i], dati[j]);
    }
  }
  return 0;
}
