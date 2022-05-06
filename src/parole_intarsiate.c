#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 20
#define FORMAT_STRING "%20s" // forza scanf ad acquisire sempre al piu' 20 char

int main() {
  char str1[MAX_LENGTH + 1] = {'\0'}, str2[MAX_LENGTH + 1] = {'\0'};
  int c;

  printf("\n Prima parola (con al piu' %d caratteri) str1: ", MAX_LENGTH);
  scanf(FORMAT_STRING, str1);
  do {
    c = getchar();
  } while (c != EOF && c != '\n'); // consuma eventuali char oltre il
                                   // 20-esimo rimasti sul nastro della
                                   // tastiera
  printf("\n Seconda parola (con al piu' %d caratteri) str2: ", MAX_LENGTH);
  scanf(FORMAT_STRING, str2);
  while ((c = getchar()) != EOF && c != '\n')
    ;
  int n2 = strlen(str2), // var. per la lunghezza della seconda parola.
      foundChar,         // var. booleana indicatrice della condizione di aver
                         //      individuato un carattere nella seconda parola.
      pos;               // var. per tener traccia la della posizione nella 2nda
                         //      parola dove e' stato trovato un carattere.
  foundChar = 0;
  for (int k = 0; k < n2 && foundChar == 0; ++k) {
    if (str2[k] == str1[0]) {
      foundChar = 1;
      pos = k;
    }
  }
  if (foundChar == 1) {
    printf("\n La posizione della prima occorrenza della lettera");
    printf("\n \'%c\' nella seconda parola e': %d", str1[0], pos);
  } else
    printf("\n La 2da parola non contiene la lettera \'%c\'! ", str1[0]);
  return 0;
}
