#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int A, B;
  printf("Inserisci il primo intero positivo\n");
  scanf("%d", &A);
  printf("Inserisci il secondo intero positivo\n");
  scanf("%d", &B);
  if (A == B) {
    printf("A uguale a B\n");
  }
  else if (A > B) {
    printf("A maggiore di B\n");
  }
  else {
    printf("A minore di B\n");
  }
  printf("FINE\n");
  return 0;
}
