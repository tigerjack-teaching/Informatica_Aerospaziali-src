#include <stdio.h>
#include <string.h>
#define MAXLEN 10
int main() {
  char parola[MAXLEN + 1];
  int g, G, i, j, count, lun;
  printf("\n Inserire una parola: ");
  scanf("%s", parola);
  lun = strlen(parola);
  g = lun;
  G = 0;
  for (i = 0; i < lun; i++) {
    count = 0;
    for (j = 0; j < lun; j++)
      if (parola[i] == parola[j])
        count++;

    if (count < g)
      g = count;
    if (count > G)
      G = count;
  }
  printf("\n g=%d, G=%d \n", g, G);
  return 0;
}
