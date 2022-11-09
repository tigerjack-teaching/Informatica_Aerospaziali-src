/*
 * TAGS: string
 *
 * Implementare un programma C che presa in input una frase composta da piu`
 * parole, separate da spazi, ne stampi in output la versione dove, PER OGNI
 * PAROLA, la stampa dei suoi caratteri e` invertita.
 *
 * N.B.: non vogliamo stampare l'intera frase al contrario!
 */
#include <stdio.h>
#define LUN_STRINGA 50

int main() {
  int inizio_parola, i, j;
  char stringa[LUN_STRINGA + 1];

  /* Acquisiamo da tastiera una stringa. Nella format string, escludiamo
     solo il carattere "a capo", in modo da poter acquisire anche gli
     spazi separanti le diverse parole. */
  printf("Inserisci una sequenza di parole separate da spazio: ");
  scanf("%[^\n]s", stringa);

  /* La variabile inizio_parola, conterrà l'indice dell'inizio dell'ultima
     parola trovata. Ovviamente all'inizio del programma, sará inizializzata
     a 0. */
  inizio_parola = 0;

  /* Useremo invece la variabile i, come indice per iterarare sul nostro
     array di char. */
  i = 0;

  /* Ci fermiamo in corrispondenza del terminatore della stringa. */
  while (stringa[i] != '\0') {

    /* Il carattere spazio, viene da noi utilizzato come separatore tra parole,
     */
    if (stringa[i] == ' ') {
      /* Con questo secondo ciclo, ogni qualvolta troviamo uno spazio,
         stampiamo al contrario tutti i caratteri della parola precedente. */
      for (j = i - 1; j >= inizio_parola; j--) {
        printf("%c", stringa[j]);
      }

      /* Aggiustiamo l'indice che punta all'inizio dell'ultima parola
         trovata. */
      inizio_parola = i + 1;
      printf(" ");
    }
    i++;
  }

  /* Ciclo aggiuntivo che gestisce l'ultima parola, dato che non troveremo
     uno spazio dopo l'ultima parola, ma il terminatore di stringa '\0'. */
  for (j = i - 1; j >= inizio_parola; j--) {
    printf("%c", stringa[j]);
  }

  printf("\n");
  return 0;
}
