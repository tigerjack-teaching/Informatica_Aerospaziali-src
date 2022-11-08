/*
 * NOTE On the importance of limiting scanf chars.
 */
#include <stdio.h>
#include <string.h>
#define MAXLEN 10
int main() {
  int i;
  char parola[MAXLEN + 1];
  printf("\n Inserire una parola (max. %d characters): ", MAXLEN);
  scanf("%s", parola);
  for (i = 0; i < MAXLEN + 1; i++) {
    printf("%d\n", parola[i]);
  }
  printf("La string %s e' lunga %lu\n", parola, strlen(parola));
  return 0;
}
