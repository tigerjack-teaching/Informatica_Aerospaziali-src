/*
 * TAGS: string, function, pointer
 *
 * Implementazione di alcune funzione della libreria string.h, unite ad alcuni
 * funzioni ausiliari.
 *
 * TODO casa: implementare una funzione aggiuntiva per ordinare un array di
 * stringhe, utilizzando una delle tecniche di sorting viste durante le
 * esercitazioni e le funzioni di libreria qui definite.
 */
#include <stdio.h>
#define MAX_LUN 1000

/* TODO */
char *sort_strings(char **);

int strlen_(char *v) {
  int pos = 0;
  /* Simplify */
  while (*(v + pos) != '\0') {
    pos++;
  }
  return pos;
}

void strcpy_(char *str_dst, char *str_src) {
  int pos = 0;
  while (*(str_src + pos) != '\0') {
    *(str_dst + pos) = *(str_src + pos);
    pos++;
  }

  *(str_dst + pos) = '\0';

  return;
}

char *strcat_(char *str_dst, char *str_src) {
  int len_dst = strlen_(str_dst);
  int len_src = strlen_(str_src);

  if (len_dst + len_src > MAX_LUN) {
    printf("Spazio insufficiente per concatenare le stringhe");
  }

  /* + 1 perche' vogliamo anche copiare \0 */
  int i;
  for (i = 0; i < len_src + 1; i++) {
    *(str_dst + len_dst + i) = *(str_src + i);
  }
  return str_dst;
}

/* Questa implementazione non è esattamente compliant con la strcmp */
int strcmp_(char *stringa1, char *stringa2) {

  while (*stringa1 && *stringa2 && *stringa1 == *stringa2) {
    stringa1++;
    stringa2++;
  }

  return (int)*stringa1 - (int)*stringa2;
}

void strcmp_and_to_string(char *stringa1, char *stringa2) {
  int res = strcmp_(stringa1, stringa2);
  if (res == 0) {
    printf("Le stringhe %s e %s sono uguali\n", stringa1, stringa2);
  } else {
    char *prima, *dopo;
    if (res < 0) {
      prima = stringa1;
      dopo = stringa2;
    } else {
      prima = stringa2;
      dopo = stringa1;
    }
    printf("La stringa %s viene alfabeticamente prima di %s\n", prima, dopo);
  }
}

int main() {
  printf("*** Test 1 ***\n");
  strcmp_and_to_string("ciao", "ciao");
  strcmp_and_to_string("ciao", "mondo");
  strcmp_and_to_string("mondo", "ciao");
  printf("La stringa paperino e' lunga: %d\n", strlen_("paperino"));
  char str1[MAX_LUN] = "pippo";
  char str2[MAX_LUN] = "paperino";
  printf("La concatenazione di %s e %s e': %s\n", str1, str2,
         strcat_(str1, str2));
  printf(
      "Nota che abbiamo modificato la stringa di partenza, che ora vale %s\n",
      str1);

  printf("*** Test 2 ***\n");
  char stringa1[MAX_LUN], stringa2[MAX_LUN], stringa3[MAX_LUN];

  scanf("%s", stringa1);
  printf("La stringa e' lunga: %d\n", strlen_(stringa1));

  scanf("%s", stringa2);
  strcpy_(stringa1, stringa2);
  printf("La stringa copiata e': %s\n", stringa1);

  scanf("%s", stringa3);
  strcat_(stringa2, stringa3);
  printf("La stringa concatenata e': %s\n", stringa2);

  strcmp_and_to_string(stringa1, stringa2);
  strcmp_and_to_string(stringa1, stringa3);
  strcmp_and_to_string(stringa2, stringa3);

  return 0;
}
