#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 20
// forza la scanf ad acquisire sempre al piu' 20 char
#define FORMAT_STRING "%20s"

int main() {
  char str1[MAX_LENGTH + 1] = {'\0'}, str2[MAX_LENGTH + 1] = {'\0'}, c;
  printf("\n 1ma parola: ");
  scanf("%s", str1);
  printf("\n 2da parola: ");
  scanf("%s", str2);
  int pos, k, n1 = strlen(str1), n2 = strlen(str2);
  if (n1 <= n2) { // se la condizione e' falsa, str1 non e' intarsiata in str2
    pos = 0;
    for (k = 0; k < n2 && pos < n1; ++k)
      if (str2[k] == str1[pos])
        pos += 1;

    if (pos == n1)
      printf("\n La 1ma parola e' intarsiata nella 2da! ");
    else
      printf("\n La 1ma parola NON e' intarsiata nella 2da! ");
  } else
    printf("\n Errore nelle lunghezze delle parole! ");
  return 0;
}
