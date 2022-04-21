#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int A, B;

  do {
    printf("Inserisci il primo intero positivo\n");
    scanf("%d", &A);
    printf("Inserisci il secondo intero positivo\n");
    scanf("%d", &B);
    if (A > B) {
      printf("A maggiore di B\n");
    } else if (A<B) {
      printf("A minore di B\n");
    } else {
      printf("A uguale a B, uscita\n");
    }
  } while (A != B);
  return 0;
}
