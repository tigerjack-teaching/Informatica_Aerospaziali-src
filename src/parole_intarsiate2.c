/*
 * TAGS: string, getchar, typedef
 *
 * Continua parole_intarsiate1.c
 *
 * Modificare il programma precedente per determinare se la prima stringa
 * corrisponde a una parola che è intarsiata nella seconda stringa, riportando a
 * video un messaggio appropriato sia in caso affermativo sia in caso contrario.
 * Per semplicità si considerino i caratteri alfabetici maiuscoli distinti dai
 * caratteri alfabetici minuscoli.
 *
 * ADDITIONAL: usare una typedef per le stringhe con lunghezza fissata.
 *
 * Esempi: fate, fantasie  -> intarsiata
 *         nomi, encomio   -> intarsiata
 *         encomio, nomi   -> NON intarsiata
 *         volo, tavolozza -> intarsiata
 *         rime, primiera  -> intarsiata
 *         ago,  apologo   -> intarsiata
 */
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 20
// forza la scanf ad acquisire sempre al piu' 20 char
#define FORMAT_STRING "%20s"

typedef char stringa_t [MAX_LENGTH + 1];

int main() {
  stringa_t str1, str2;
  char c;
  printf("\n Prima parola (con al piu' %d caratteri) str1: ", MAX_LENGTH);
  scanf(FORMAT_STRING, str1);
  do {
    c = getchar();
  } while (c != EOF && c != '\n'); // consuma eventuali char oltre il
                                   // 20-esimo rimasti sul nastro della
                                   // tastiera
  printf("\n Seconda parola (con al piu' %d caratteri) str2: ", MAX_LENGTH);
  scanf(FORMAT_STRING, str2);
  while ((c = getchar()) != EOF && c != '\n')
    ;

  int n1 = strlen(str1); // var. per la lunghezza della seconda parola.
  int n2 = strlen(str2); // var. per la lunghezza della seconda parola.
  printf("Parola 1: %s, Parola 2: %s", str1, str2);

  if (n1 > n2) {
    // se la condizione e' vera, str1 ovviamente non puo' essere intarsiata in
    // str2
    printf("\n Non intarsiate, n1 piu' lunga di n2");
    return 0;
  }

  int pos = 0;
  int k;
  for (k = 0; k < n2 && pos < n1; ++k)
    if (str2[k] == str1[pos])
      pos += 1;

  if (pos == n1)
    printf("\n La 1ma parola e' intarsiata nella 2da! ");
  else
    printf("\n La 1ma parola NON e' intarsiata nella 2da! ");
  return 0;
}
