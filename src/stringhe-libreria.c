#include <stdio.h>
#define MAX_LUN 1000

int strlen_(char *v) {
  int pos = 0;
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

void strcat_(char *str_dst, char *str_src) {

  int len_1 = strlen_(str_dst);
  int len_2 = strlen_(str_src);

  int i;

  if (len_1 + len_2 > MAX_LUN) {
    printf("Spazio insufficiente per concatenare le stringhe");
  }

  for (i = 0; i < len_2; i++) {
    *(str_dst + len_1 + i) = *(str_src + i);
  }
}

// Questa implementazione non è esattamente compliant con la strcmp
int strcmp_(char *stringa1, char *stringa2) {

  int i = 0;
  while (*stringa1 != '\0' && *stringa2 != '\0' && *stringa1 == *stringa2) {
    stringa1++;
    stringa2++;
  }

  return (int)*stringa1 - (int)*stringa2;
}

int main() {

  char stringa[MAX_LUN];

  scanf("%s", stringa);

  printf("La stringa e' lunga: %d\n", strlen_(stringa));

  char stringa2[MAX_LUN];
  scanf("%s", stringa2);

  strcpy_(stringa, stringa2);

  printf("La stringa copiata e': %s\n", stringa);

  char stringa3[MAX_LUN];
  scanf("%s", stringa3);

  strcat_(stringa2, stringa3);

  printf("La stringa e': %s\n", stringa2);

  if (strcmp_("ciao", "ciao") == 0)
    printf("La stringa A e' uguale\n");

  if (strcmp_("ciao", "ciao1") == 0)
    printf("La stringa B e' uguale\n");

  if (strcmp_("cxao", "ciao") == 0)
    printf("La stringa C e' uguale\n");

  return 0;
}
