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
 *  Potrebbe esserci più di un valore che rappresenta la Moda; stamparne solo
 *  uno!
 *
 */
#include <stdio.h>

#define M 5

int main() {
  int num_ripetizioni[M] = {0};
  int valore;

  int max_indice = 0;
  int max_ripetizioni = num_ripetizioni[max_indice];
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
      } else {
        n_val++;
        wrong_val = 0;
      }
    } while (wrong_val);
    num_ripetizioni[valore - 1] += 1;
    if (num_ripetizioni[valore - 1] > max_ripetizioni) {
      max_indice = valore - 1;
      max_ripetizioni = num_ripetizioni[max_indice];
    }
  } while (valore != 0);

  printf("Con %d occorrenze il valore della moda e': %d", max_ripetizioni,
         max_indice + 1);
  return 0;
}
