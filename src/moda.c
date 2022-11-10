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
 *  Potrebbe esserci più di un valore che rappresenta la Moda; stamparli tutti.
 *
 * TODO casa: Provare a pensare ad una possibile ottimizzazione nel caso in cui
 * ci interessi stampare solo un valore della moda.
 */
#include <stdio.h>

#define M 5

int main() {
  int numeroRipetizioni[M] = {0};
  int valore;
  int maxRipetizioni = 0;
  do {
    do {
      printf("\n valore = ");
      scanf("%d", &valore);
    } while (valore < 0 || valore > M);
    numeroRipetizioni[valore - 1] += 1;
    if (numeroRipetizioni[valore - 1] > maxRipetizioni)
      maxRipetizioni = numeroRipetizioni[valore - 1];
  } while (valore != 0);
  printf("Con %d occorrenze il/i valore/i della moda e'/sono:", maxRipetizioni);
  for (int i = 0; i < M; i++) {
    if (numeroRipetizioni[i] == maxRipetizioni) {
      printf("%d ", i + 1);
    }
  }

  // Stampa finale, non richiesta dalla traccia, ma utile ai fini della
  // comprensione della soluzione
  for (int i = 0; i < M; i++) {
    printf("%d:%d; ", i + 1, numeroRipetizioni[i]);
  }
  printf("\n");

  return 0;
}
