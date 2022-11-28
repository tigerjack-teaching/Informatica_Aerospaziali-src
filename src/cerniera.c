/*
 * TAGS: functions
 *
 * In enigmistica la cerniera è uno schema per cui, date due parole, si ottiene
 * una terza parola scartando il medesimo gruppo di lettere (e nel medesimo
 * ordine) dalla testa (prefisso) della prima parola e dalla coda (suffisso)
 * della seconda parola, unendo infine i caratteri rimasti ordinatamente nella
 * prima e nella seconda
 *
 * ES. Date ABCDEF e GHABC, scartando ABC da entrambe otteniamo la loro cerniera
 *  DEFGH
 */
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
    int i;
    for (i = lung; i < strlen(primaParola); i++)
      printf("%c", primaParola[i]);
    for (i = 0; i < strlen(secondaParola) - lung; i++)
      printf("%c", secondaParola[i]);
    printf("\n");
  }
  return 0;
}

int cercaIndice(char c, char str[]) {
  int idx = strlen(str) - 1;
  while (idx >= 0 && c != str[idx]) {
    idx = idx - 1;
  }
  return idx;
}

/*
 * Assumendo di fare la cerniera considerando prefissi e suffissi SENZA
 * ripetizioni di caratteri.
 */
int cerniera(char prima[], char seconda[]) {
  int idxSuffisso = cercaIndice(prima[0], seconda);
  if (idxSuffisso < 0)
    return -1;
  int lung = strlen(seconda) - idxSuffisso;
  int flag = 1;
  int i;
  for (i = 1; i < lung && flag == 1; i++)
    if (prima[i] != seconda[idxSuffisso + i])
      flag = 0;
  if (flag == 0)
    return -1;
  return lung;
}

/* Soluzione generale (NON RICHIESTA)– senza far uso di ...cercaIndice(...) */
int cerniera2(char prima[], char seconda[]) {
  int idxSeconda = strlen(seconda) - 1;
  if (idxSeconda < 0)
    return -1;
  int riconoscimento_iniziato_su_prima, idxPrima, lung = 0;
  riconoscimento_iniziato_su_prima = idxPrima = strlen(prima) - 1;
  while (idxPrima >= 0 && idxSeconda >= 0) {
    if (prima[idxPrima] == seconda[idxSeconda]) {
      /* fase di inizio riconoscimento */
      if (lung == 0) 
        riconoscimento_iniziato_su_prima = idxPrima;
      lung++;
      idxPrima--;
      idxSeconda--;
    } else {
      idxSeconda = strlen(seconda) - 1;
      idxPrima = riconoscimento_iniziato_su_prima - 1;
      riconoscimento_iniziato_su_prima = idxPrima;
      lung = 0;
    }
  }
  if (lung == 0)
    return -1;
  else
    return lung;
}
