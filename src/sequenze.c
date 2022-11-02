/*
 * Implementare un programma che legge una sequenza (di lunghezza arbitraria) di
 * interi _positivi_ terminata dal valore 0, e al termine della sequenza, stampa
 * quante terne di numeri _consecutivi_, _diversi tra loro_ e _pari_, sono
 * contenute nella sequenza.
 */
#include <stdio.h>
#include <stdlib.h>

int main() {

  // Numero di terne incontrate
  unsigned contatore = 0;

  /* Queste variabili, ci serviranno rispettivamente per poter memorizzare ad
   * ogni istante gli ultimi 3 elementi inseriti della sequenza. La loro
   * inizializzazione, con un valore che non soddisfa i criteri della condizione
   * controllata all'unsignederno del ciclo, è fondamentale per non effettuare
   * conteggi sbagliati (provare ad inizializzare con 2, e vedere cosa succede
   * usando il debugger).
   */
  unsigned prev1 = 1;
  unsigned prev2 = 1;
  unsigned cur = 1;
  // Useremo questa variabile come un booleano, per memorizzare
  unsigned short cond1, cond2, cond3;
  // Il ciclo continua fintantochè il valore inserito è diverso da 0.
  // Grazie al fatto che i valori sono stati inizializzati a numeri iden
  while (cur != 0) {

    // Calcoliamo la condizione che deve avverarsi affinchè siamo in
    // presenza di una sequenza di numeri nel sequenza inserita, che soddisfa
    // il criterio espresso. Per una maggiore leggibilità, calcoliamo tutte
    // le sottocondizioni una riga per volta, e mettiamo il tutto in "and"

    // tutti positivi
    cond1 = (prev2 >= 0 && prev1 >= 0 && cur > 0);
    // diversi tra loro
    cond2 = !(prev2 == prev1 || prev2 == cur || prev1 == cur);
    // tutti pari
    cond3 = (prev2 % 2 == 0 && prev1 % 2 == 0 && cur % 2 == 0);
    if (cond1 && cond2 && cond3) {
      // Se la condizione è soddisfatta, stampiamo la terna e aumentiamo il
      // contatore.
      contatore++;
      printf("Ho trovato la terna: %d %d %d\n", prev2, prev1, cur);
    }

    // Riassegnamento delle variabili contenenti i valori precedenti, e
    // ascquisizione del valore corrente (attenzione all'ordine delle
    // operazioni, ricordarsi che il C è sequenziale).
    prev2 = prev1;
    prev1 = cur;
    scanf("%d", &cur);
  }

  // Stampa finale del numero di terne trovato.
  printf("Ho trovato %d terne", contatore);
  return 0;
}
