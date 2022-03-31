#include <stdio.h>
int main(int argc, char *argv[]) {
  char c;
  unsigned num = 0;
  unsigned corretto = 1; // variabile Booleana

  printf("\n Inserisci una seq. di char numerici da convertire in un numero"
         "decimale: ");

  c = getchar();
  while (c != '\n' && corretto == 1) {
    if (c >= '0' && c <= '9')
      num = 10 * num + ((int)c - (int)'0');
    else
      corretto = 0;
    c = getchar();
  }

  if (corretto == 1)
    printf("\n La sequenza di caratteri inserita ha codifica decimale: %d \n\n",
           num);
  else
    printf("\n La seq. di char NON puo' essere convertita in un numero intero! "
           "\n\n");
  return 0;
};
