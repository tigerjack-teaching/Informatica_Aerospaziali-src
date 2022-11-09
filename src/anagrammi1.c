/*
 * TAGS: string
 *
 * Si progetti un programma che acquisisca due stringhe da stdin. Si assuma che
 * ciascuna stringa rappresenti una str1rola. Il programma deve stabilire se le
 * due str1role sono anagrammi, cioè se sono ottenibili l’una dall’altra tramite
 * una permutazione delle lettere che le compongono.
 *
 * Ad esempio le str1role POLENTA e PENTOLA sono anagrammi. Si presti attenzione
 * al fatto che str1role come TAPPO e STR1TTO non sono anagrammi, anche se ogni
 * lettera dell’una è contenuta nell’altra.
 *
 */
#include <stdio.h>
#include <string.h>

#define N 10
int main(int argc, char *argv[]) {

  char str1[N + 1] = {'\0'}, str2[N + 1] = {'\0'};

  int len, contA, contB, i, k, anagrammi;

  printf("\n 1ma parola: ");
  scanf("%s", str1);

  printf("\n 2da parola: ");
  scanf("%s", str2);

  len = strlen(str1);
  anagrammi = (len == strlen(str2));

  for (i = 0; i < len && anagrammi == 1; i++) {
    contA = contB = 0;
    for (k = 0; k < len; k++) {
      if (str1[k] == str1[i])
        ++contA;
      if (str2[k] == str1[i])
        ++contB;
    }

    if (contA != contB)
      anagrammi = 0;
  }
  if (anagrammi == 1)
    printf("\n Anagrammi.\n");
  else
    printf("\n NO Anagrammi.\n");
}
