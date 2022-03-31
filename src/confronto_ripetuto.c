#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int A, B;
  printf("Inserisci il primo intero positivo\n");
  scanf("%d", &A);
  printf("Inserisci il secondo intero positivo\n");
  scanf("%d", &B);

  while (A != B) {
    if (A > B) {
      printf("A maggiore di B\n");
    } else {
      printf("A minore di B\n");
    }
    printf("Inserisci il primo intero positivo\n");
    scanf("%d", &A);
    printf("Inserisci il secondo intero positivo\n");
    scanf("%d", &B);
  }
  printf("A uguale a B, FINE\n");
  return 0;
}
