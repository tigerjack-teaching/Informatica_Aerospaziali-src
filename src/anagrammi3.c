/*
 * TAGS: string, function, pointer
 *
 * Modifica di anagrammi2, con uso di funzioni e puntatori.
 *
 * Si progetti un programma che acquisisca due stringhe da stdin. Si assuma che
 * ciascuna stringa rappresenti una str1rola. Il programma deve stabilire se le
 * due str1role sono anagrammi, cioè se sono ottenibili l’una dall’altra tramite
 * una permutazione delle lettere che le compongono.
 *
 * Ad esempio le stringhe POLENTA e PENTOLA sono anagrammi. Si presti attenzione
 * al fatto che str1role come TAPPO e PATTO non sono anagrammi, anche se ogni
 * lettera dell’una è contenuta nell’altra.
 */
#include <stdio.h>
#define CARATTERI_ASCII 256
#define MAX_LUNG 100

/* La funzione di supporto. */
int anagramma(char *str1, char *str2) {
  /* Creiamo gli array contatori, dove memorizzeremo in ognuna delle */
  /* 256 posizioni, il numero di occorrenze dell'n-esimo carattere */
  /* (e useremo come indice, proprio il valore da 0 a 255 del carattere */
  /*  inteso come numerazione dei caratteri ASCII). */
  int contatore1[CARATTERI_ASCII] = {0};
  int contatore2[CARATTERI_ASCII] = {0};

  /* Scorriamo le due stringhe, e per ogni carattere che troviamo, */
  /* aumentiamo nel corrispondente array contatore il valore che indica */
  /* le occorrenze di quel carattere. */
  int i;
  for (i = 0; *(str1 + i) && *(str2 + i); i++) {
    contatore1[*(str1 + i)]++;
    contatore2[*(str2 + i)]++;
  }

  /* Controlliamo se le due stringhe sono di diversa lunghezza. Se lo sono,
   * sicuramente le stringhe non saranno anagrammi.
   */
  if (*(str1 + i) || *(str2 + i))
    return 0;

  /* Controlliamo i valori che abbiamo salvato negli array contatori 
   * corrispondono. Se corrispondono, significa che le parole sono 
   * anagrammi. Se anche solo una delle celle degli array contatori 
   * non corrispondono, allora le parole non sono anagrammi.
   */
  for (i = 0; i < CARATTERI_ASCII; i++)
    if (contatore1[i] != contatore2[i])
      return 0;
  return 1;
}

int main() {
  /* Le stringhe potenzialmente anagrammi. */
  char str1[MAX_LUNG] = "prese";
  char str2[MAX_LUNG] = "serpe";

  /* Chiamamiamo la funzione anagramma, che restituirà `1` se le parole sono anagrammi, o `0` se non lo sono. */
  if (anagramma(str1, str2))
    printf("Le stringhe sono anagrammi.\n");
  else
    printf("Le stringhe non sono anagrammi.\n");

  return 0;
}
