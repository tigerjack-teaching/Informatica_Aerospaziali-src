#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LUNG_PAROLA 50

int cercaIndice(char c, char str[]);
int cerniera(char prima[], char seconda[]);

int main() {
  char primaParola[MAX_LUNG_PAROLA + 1] = {'\0'};
  char secondaParola[MAX_LUNG_PAROLA + 1] = {'\0'};
  printf("\n Programma di valutazione della cerniera tra due parole \n");
  printf("\n Inserisci la 1ma parola: ");
  scanf("%s", primaParola);
  printf("\n Inserisci la 2da parola: ");
  scanf("%s", secondaParola);
  int lung = cerniera(primaParola, secondaParola);
  if (lung < 0) {
    printf("\n La cerniera NON e' possibile! \n");
    return 1;
  }
  if (lung == strlen(primaParola) && lung == strlen(secondaParola)) {
    printf("\n La cerniera e' la stringa vuota! \n");
  } else {
    printf("\n La cerniera e': ");
    for (int i = lung; i < strlen(primaParola); i++)
      printf("%c", primaParola[i]);
    for (int i = 0; i < strlen(secondaParola) - lung; i++)
      printf("%c", secondaParola[i]);
    printf("\n");
  }
  return 0;
} // end main

int cercaIndice(char c, char str[]) {
  int idx = strlen(str) - 1;
  while (idx >= 0 && c != str[idx]) {
    idx = idx - 1;
  }
  return idx;
} // end cercaIndice

// Assumendo di fare la cerniera considerando
// prefissi e suffissi SENZA ripetizioni di caratteri.
int cerniera(char prima[], char seconda[]) {
  int idxSuffisso = cercaIndice(prima[0], seconda);
  if (idxSuffisso < 0)
    return -1;
  int lung = strlen(seconda) - idxSuffisso;
  int flag = 1;
  for (int i = 1; i < lung && flag == 1; i++)
    if (prima[i] != seconda[idxSuffisso + i])
      flag = 0;
  if (flag == 0)
    return -1;
  return lung;
} // end cerniera

// Soluzione generale (NON RICHIESTA)– senza far uso di ...cercaIndice(...)
int cerniera2(char prima[], char seconda[]) {
  int idxSeconda = strlen(seconda) - 1;
  if (idxSeconda < 0)
    return -1;
  int riconoscimento_iniziato_su_prima, idxPrima, lung = 0;
  riconoscimento_iniziato_su_prima = idxPrima = strlen(prima) - 1;
  while (idxPrima >= 0 && idxSeconda >= 0) {
    if (prima[idxPrima] == seconda[idxSeconda]) {
      if (lung == 0) // fase di inizio riconoscimento
        riconoscimento_iniziato_su_prima = idxPrima;
      lung++;
      idxPrima--;
      idxSeconda--;
    } else {
      idxSeconda = strlen(seconda) - 1;
      idxPrima = riconoscimento_iniziato_su_prima - 1;
      riconoscimento_iniziato_su_prima = idxPrima;
      lung = 0;
    } // end 1mo-if-else
  }   // end while
  if (lung == 0)
    return -1;
  else
    return lung;
} // end cerniera
