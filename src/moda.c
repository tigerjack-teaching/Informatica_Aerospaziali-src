#include <stdio.h>

#define M 5

int main() {
  int numeroRipetizioni[M + 1] = {0}, i, valore, maxRipetizioni;
  do {
    do {
      printf("\n valore = ");
      scanf("%d", &valore);
    } while (valore < 0 || valore > M);
    numeroRipetizioni[valore] += 1;
  } while (valore != 0);
  maxRipetizioni = numeroRipetizioni[1];
  for (i = 2; i <= M; i++)
    if (numeroRipetizioni[i] > maxRipetizioni)
      maxRipetizioni = numeroRipetizioni[i];
  printf("Con %d occorrenze il valore della moda e' :", maxRipetizioni);

  for (i = 1; i <= M; i++)
    if (numeroRipetizioni[i] == maxRipetizioni)
      printf("%d ", i);

  return 0;
}
