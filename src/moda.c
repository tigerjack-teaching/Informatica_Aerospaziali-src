/*
 *  Si codifichi un programma C che legge da stdin una sequenza (di lunghezza
 *  arbitraria) di interi positivi, ciascuno dei quali con un valore compreso
 *  nell’intervallo 1...M (M arbitrariamente scelto dal programmatore).
 *  L’acquisizione della sequenza termina inserendo il valore 0. Il programma
 *  deve visualizzare sullo schermo (stdout) un messaggio che riporta la Moda
 *  della sequenza di valori inserita.
 *
 *  La Moda è il valore più popolare della sequenza, cioé quello che compare il
 *  maggior numero di volte.
 *
 *  Potrebbe esserci più di un valore che rappresenta la Moda
 */
#include <stdio.h>

#define M 5

int main() {
  int numeroRipetizioni[M + 1] = {0}, i, valore, maxRipetizioni;
  for (i = 0; i < M; i++)
    printf("%d\n", numeroRipetizioni[i]);

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
