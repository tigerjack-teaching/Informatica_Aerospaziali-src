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
  int num_ripetizioni[M] = {0};
  int valore;
  int maxRipetizioni = 0;
  int wrong_val = 0;
  int n_val = 0;

  /* Ciclo do-while per prendere in input valori finche' utente inserisce 0 */
  do {
    /* Ciclo do-while per prendere in input valori corretti */
    do {
      if (wrong_val) {
        printf("Il valore inserito deve essere compreso tra 0 e %d", M);
      }
      printf("\n");
      printf("valore %d = ", n_val);
      scanf("%d", &valore);

      if (valore < 0 || valore > M) {
        wrong_val = 1;
      }
      else {
        n_val++;
        wrong_val = 0;
      }
    } while (wrong_val);
    
    printf("Aggiorno vettore ripetizioni\n");
    num_ripetizioni[valore - 1] += 1;
    if (num_ripetizioni[valore - 1] > maxRipetizioni)
      maxRipetizioni = num_ripetizioni[valore - 1];
  } while (valore != 0);
  printf("Con %d occorrenze il/i valore/i della moda e'/sono:", maxRipetizioni);
  for (int i = 0; i < M; i++) {
    if (num_ripetizioni[i] == maxRipetizioni) {
      printf("%d ", i + 1);
    }
  }
  printf("\n");

  /* Stampa finale, non richiesta dalla traccia, ma utile ai fini della
   * comprensione della soluzione.
   */
  for (int i = 0; i < M; i++) {
    printf("%d:%d; ", i + 1, num_ripetizioni[i]);
  }
  printf("\n");

  return 0;
}
