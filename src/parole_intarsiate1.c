/*
 * TAGS: string, getchar
 *
 * Date due parole, definiamo la prima parola come un intarsio della seconda, se
 * le sue lettere sono presenti anche nella seconda parola nella stessa sequenza
 * di lettura (da sinistra a destra), ma non necessariamente in posizioni
 * contigue.
 *
 * A. Srivere un programma che acquisisca due stringhe e riporti a video la
 * posizione della prima occorrenza della lettera iniziale della prima parola
 * nella seconda parola (nel senso di lettura da sinistra a destra); oppure un
 * messaggio appropriato, nel caso in cui la lettera iniziale della prima parola
 * non appaia nella seconda.
 *
 *
 * Esempi: fate, fantasie  -> 0
 *         nomi, encomio   -> 1
 *         volo, tavolozza -> 2
 *         rime, primiera  -> 1
 *         ago,  apologo   -> 0
 *         banane, lamponi -> Non contenuta
 */
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 20
/* forza scanf ad acquisire sempre al piu' 20 char */
#define FORMAT_STRING "%20s"

int main() {
  char str1[MAX_LENGTH + 1] = {'\0'}, str2[MAX_LENGTH + 1] = {'\0'};
  char c;        /*  */
  int k,         /* for loop variable */
      n2,        /* var. per la lunghezza della seconda parola.*/
      foundChar, /* var. booleana indicatrice della condizione di aver
                    individuato un carattere nella seconda
                    parola.*/
      pos;       /* var. per tener traccia della posizione nella 2nda
                    parola dove e' stato trovato un carattere.*/

  printf("\n Prima parola (con al piu' %d caratteri) str1: ", MAX_LENGTH);
  scanf(FORMAT_STRING, str1);
  do {
    /* consuma eventuali char oltre il 20-esimo rimasti sul nastro della */
    /* tastiera */
    c = getchar();
  } while (c != EOF && c != '\n');

  printf("\n Seconda parola (con al piu' %d caratteri) str2: ", MAX_LENGTH);
  scanf(FORMAT_STRING, str2);
  while ((c = getchar()) != EOF && c != '\n')
    ;
  n2 = strlen(str2);
  foundChar = 0;
  for (k = 0; k < n2 && foundChar == 0; ++k) {
    if (str2[k] == str1[0]) {
      foundChar = 1;
      pos = k;
    }
  }
  if (foundChar == 1) {
    printf("\n La posizione della prima occorrenza della lettera");
    printf("\n \'%c\' nella seconda parola e': %d", str1[0], pos);
  } else
    printf("\n La 2da parola non contiene la lettera \'%c\'! ", str1[0]);
  return 0;
}
