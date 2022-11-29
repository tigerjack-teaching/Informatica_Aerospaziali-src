/*
 * TAGS: functions, pointers

 * Due parole 'a' e 'b' sono Hertziane se entrambe sono leggibili anche
 * oscillando durante la lettura dei caratteri tra di esse. Ad esempio, le
 * parole `tigre` e `fiera` possono entrambe essere lette partendo dal primo
 * carattere di ciascuna, e oscillando poi sui caratteri dell'altra.

 * Nella situazione descritta sopra, parliamo di parole direttamente Hertziane,
 * ma possiamo anche avere parole inversamente Hertziane, dove la lettura
 * comincia dalla prima lettera della parola opposta. `Fiera` e `Fresa` sono
 * esempi di parole inversamente Hertziane.
 */
#include <stdio.h>
#define MAX_LUNG 100

/* Funzione di supporto. Restituisce:
 * - 0 se le parole non sono hertziane,
 * - 1 se le parole sono direttamente hertziane
 * - 2 se le parolo sono inversamente hertziane
 * - 3 se sono sia direttamente che inversamente hertziane
 */
int hertziane(char *str1, char *str2) {
  int direttamente, inversamente;

  /* Scorriamo le due stringhe, fermandoci quando incontriamo (in una o
   * entrambe) il carattere '\0'. In pratica, controlliamo se le due stringhe
   * sono di uguale lunghezza.
   */
  int i;
  for (i = 0; *(str1 + i) && *(str2 + i); i++) {
  }
  if (*(str1 + i) || *(str2 + i))
    return 0;

  /* Controlliamo se le stringhe sono direttamente hertziane. Vero fino a prova
     contraria.*/
  direttamente = 1;
  int j;
  for (j = 1; j < i && direttamente; j += 2) {
    if (*(str1 + j) != *(str2 + j))
      direttamente = 0;
  }

  /* Controlliamo se le stringhe sono inversamente hertziane. */
  inversamente = 1;
  for (j = 0; *(str1 + j) && inversamente; j += 2) {
    if (*(str1 + j) != *(str2 + j))
      inversamente = 0;
  }

  /* Restituiamo un valore appropriato in base alla situazione in cui siamo. */
  if (direttamente && inversamente) {
    return 3;
  } else if (direttamente) {
    return 1;
  } else if (inversamente) {
    return 2;
  } else {
    return 0;
  }
}

int main() {
  /* Le stringhe potenzialmente hertziane. */

  char strs1[][MAX_LUNG] = {"ciao", "tigre", "fiera", "fiera"};
  char strs2[][MAX_LUNG] = {"mondo", "fiera", "fresa", "fiera"};

  /* Chiamamiamo la funzione hertziana, che restituirà `1` se le parole  sono
   * anagrammi, o `0` se non lo sono. */
  int i;
  for (i = 0; i < 4; i++) {
    printf("Le stringhe %s e %s ", strs1[i], strs2[i]);
    switch (hertziane(strs1[i], strs2[i])) {
    case 0:
      printf("non sono parole hertziane.\n");
      break;
    case 1:
      printf("sono parole direttamente hertziane\n");
      break;
    case 2:
      printf("sono parole inversamente hertziane\n");
      break;
    case 3:
      printf("sono parole sia direttamente che inversamente "
             "hertziane\n");
      break;
    default:
      printf("ERRORE\n");
      break;
    }
  }
  return 0;
}
