/*
 * TAGS: string
 *
 * Come assegnare un valore a una stringa dichiarata precedentemente?
 */
#include <stdio.h>
#include <string.h>
#define STR_LEN 200

int main(int argc, char *argv[]) {
  char str1[STR_LEN];
  for (int i = 0; i < STR_LEN; i++) {
    printf("%d %c\n", i, str1[i]);
  }
  printf("%s\n", str1);
  // ERROR
  /* str1 = "hola chic*"; */
  strcpy(str1, "Hola chich*");

  printf("%s\n", str1);
  return 0;
}
