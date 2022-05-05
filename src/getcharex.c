#include <stdio.h>
int main(int argc, char *argv[]) {
  char c;
  unsigned num = 0;
  unsigned corretto = 1; // variabile Booleana

  printf("\nInserisci una seq. di char numerici da convertire in un numero"
         " decimale: ");

  /* c = getchar(); */
  /* while (c  != '\n' && corretto == 1) { */
    while ((c = getchar()) != '\n' && corretto == 1) {
      if (c >= '0' && c <= '9')
        num = 10 * num + ((int)c - (int)'0');
      else
        corretto = 0;
      /* c = getchar(); */
    }

    printf("\nLa sequenza di caratteri inserita ");

    if (corretto == 1)
      printf("ha codifica decimale: %d \n\n", num);
    else
      printf("\nNON puo' essere convertita in un numero intero! %d"
             "\n\n",
             num);
    return 0;
  };
