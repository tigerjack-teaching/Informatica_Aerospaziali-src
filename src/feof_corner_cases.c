/*
 * TAGS: file
 *
 * Esempio sull'uso di feof con fscanf, fgets
 *
 * Note:
 * char *fgets(char *str, int n, FILE *stream)
 * Restituisce la stessa stringa memorizzata in str in caso di successo.
 * Se incontra EOF && nessun carattere è stato letto, restituisce NULL
 *
 * int fscanf(FILE *stream, const char *format, ...)
 * Restituisce il numero di item di input riconosciuti con successo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *fp = fopen("lista_prodotti_data.txt", "r");
  char buf[100];

  int i = 0;
  char *ret;
  while (!feof(fp)) {
    ret = fgets(buf, sizeof(buf), fp);
    printf("Line %4d\nret %sbuf %s", i, ret, buf);
    printf("****");
    i++;
  }
  fclose(fp);
}
