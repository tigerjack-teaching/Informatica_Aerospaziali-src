/*
 * TAGS: string
 *
 * Si progetti un programma che acquisisca due stringhe da stdin. Si assuma che
 * ciascuna stringa rappresenti una parola. Il programma deve stabilire se le
 * due parole sono anagrammi, cioè se sono ottenibili l’una dall’altra tramite
 * una permutazione delle lettere che le compongono.
 *
 * Ad esempio le parole POLENTA e PENTOLA sono anagrammi. Si presti attenzione
 * al fatto che parole come TAPPO e PATTO non sono anagrammi, anche se ogni
 * lettera dell’una è contenuta nell’altra.
 *
 * TODO casa: chiedere le stringhe da standard input
 */
#include <stdio.h>
#define CARATTERI_ASCII 256
#define MAX_LUNG 100

int main() {
  /* Le stringhe potenzialmente anagrammi. */

  /* Potenzialmente qui c'e' una scanf per chiedere le stringhe all'utente*/
  char str1[MAX_LUNG] = "pentola";
  char str2[MAX_LUNG] = "polenta";

  /* Creiamo gli array contatori, dove memorizzeremo in ognuna delle */
  /* 256 posizioni, il numero di occorrenze dell'n-esimo carattere */
  /* (e useremo come indice, proprio il valore da 0 a 255 del carattere */
  /*  inteso come numerazione dei caratteri ASCII). */
  int contatore1[CARATTERI_ASCII] = {0};
  int contatore2[CARATTERI_ASCII] = {0};
  int i;

  /* Scorriamo le due stringhe, e per ogni carattere che troviamo, */
  /* aumentiamo nel corrispondente array contatore il valore che indica */
  /* le occorrenze di quel carattere. */
  for (i = 0; str1[i] && str2[i]; i++) {
    contatore1[str1[i]]++;
    contatore2[str2[i]]++;
  }

  /* Controlliamo se le due stringhe sono di diversa lunghezza. Se */
  /* lo sono, sicuramente le stringhe non saranno anagrammi. */
  if (str1[i] || str2[i]) {
    printf("Non sono anagrammi\n");
    return 0;
  }

  /* Controlliamo che i valori che abbiamo salvato negli array contatori */
  /* corrispondono. Se corrispondono, significa che le parole sono */
  /* anagrammi. Se anche solo una delle celle degli array contatori */
  /* non corrispondono, allora le parole non sono anagrammi. */
  for (i = 0; i < CARATTERI_ASCII; i++)
    if (contatore1[i] != contatore2[i]) {
      printf("Non sono anagrammi\n");
      return 0;
    }
  printf("Le stringhe sono anagrammi.\n");

  return 0;
}
