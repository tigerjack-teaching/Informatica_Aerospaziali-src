#include <stdio.h>

int main(int argc, char *argv[]) {

  int N;
  int b = 0;
  int Naux = N;
  int pos_val;
  /* Acquisizione dell'input. */
  do {
    printf("Inserisci un intero positivo\n");
    scanf("%u", &N);
  } while (N <= 0);

  while (Naux > 0) {
    Naux /= 2;
    b += 1;
  }
  printf("Numero di bit necessari per rappresentare %d: %d\n", N, b);
  printf("La codifica è: ");

  /* L'esponente maggiore */
  /* unsigned exp = b-1; */
  do {
    b -= 1;
    /* E' equivalente a 2^b */
    pos_val = 1 << b;

    if (N > 0 && N - pos_val >= 0) {
      printf("1");
      N -= pos_val;
    } else
      printf("0");
  } while (b > 0);
  printf("\n");

  return 0;
}
