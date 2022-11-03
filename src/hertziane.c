#include <stdio.h>
#define MAX_LUNG 100

/* La funzione di supporto. */
int hertziane(char *str1, char *str2) {
  int i, j;
  int direttamente, inversamente;

  /*Scorriamo le due stringhe, e per ogni carattere che troviamo,
  aumentiamo nel corrispondente array contatore il valore che indica
  le occorrenze di quel carattere.*/
  for (i = 0; *(str1 + i) && *(str2 + i); i++) {
  }

  /* Controlliamo se le due stringhe sono di diversa lunghezza. Se
     lo sono, sicuramente le stringhe non saranno hertziane.*/
  if (*(str1 + i) || *(str2 + i))
    return 0;

  /* Controlliamo se le stringhe sono direttamente hertziane. */
  direttamente = 1;
  for (j = 1; j < i; j += 2) {
    if (*(str1 + j) != *(str2 + j)) {
      direttamente = 0;
    }
  }

  /* Controlliamo se le stringhe sono inversamente hertziane. */
  inversamente = 1;
  for (j = 0; *(str1 + j); j += 2) {
    if (*(str1 + j) != *(str2 + j)) {
      inversamente = 0;
    }
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
  char str1[MAX_LUNG] = "tigre";
  char str2[MAX_LUNG] = "fiera";

  /* Chiamamiamo la funzione hertziana, che restituirà `1` se le parole  sono
   * anagrammi, o `0` se non lo sono. */
  switch (hertziane(str1, str2)) {
  case 0:
    printf("Le stringhe non sono parole hertziane.\n");
    break;
  case 1:
    printf("Le stringhe sono parole direttamente hertziane\n");
    break;
  case 2:
    printf("Le stringhe sono parole inversamente hertziane\n");
    break;
  case 3:
    printf("Le stringhe sono parole sia direttamente che inversamente "
           "hertziane\n");
    break;
  default:
    printf("Situazione non possibile\n");
    break;
  }
  return 0;
}
