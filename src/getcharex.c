/*
 * TAGS: getchar
 *
 * Si scriva un programma C che acquisendo una sequenza di caratteri numerici
 * (cioé ‘0’, ‘1’,...,’9’) terminata da ‘\n’ (invio), computi il numero intero
 * corrispondente memorizzandone il valore in una variabile di tipo int. Se un
 * carattere della sequenza sopra-menzionata non è un carattere numerico, il
 * programma deve segnalare l’errore con un messaggio a video appropriato.
 *
 * HINT: ASCII tables
 */
#include <stdio.h>
int main(int argc, char *argv[]) {
  char c;
  unsigned num = 0;
  unsigned corretto = 1; // variabile Booleana

  printf("\nInserisci una seq. di char numerici da convertire in un numero"
         " decimale: ");

  /* while ((c = getchar()) != '\n' && corretto == 1) { */
  c = getchar();
  while (c  != '\n' && corretto == 1) {
    if (c >= '0' && c <= '9')
      num = 10 * num + ((int)c - (int)'0');
    else
      corretto = 0;
    c = getchar();
  }

  printf("\nLa sequenza di caratteri inserita ");

  if (corretto == 1)
    printf("ha codifica decimale: %d \n\n", num);
  else
    printf("\nNON puo' essere convertita in un numero intero!");
    printf("\n Ho convertito fino a %d\n", num);
  return 0;
};
