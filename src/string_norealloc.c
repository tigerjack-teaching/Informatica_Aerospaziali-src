/*
 * TAGS: malloc
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *realloc_chars(char* str_v, int n_chars_v, int n_chars_new) {
  char *str_n = (char *)malloc(sizeof(n_chars_v + n_chars_new) * sizeof(char));
  if (!str_n) {
    fprintf(stderr, "Impossibile allocare memoria\n");
    return NULL;
  }
  for (int i = 0; i < n_chars_v; i++ ) {
    str_n[i] = str_v[i];
  }
  free(str_v);
  return str_n;
}

int main() {
  char *ptr;
  ptr = (char *)malloc(20);
  if (!ptr) {
    fprintf(stderr, "Impossibile allocare memoria\n");
    return -1;
  }
  strcpy(ptr, "La programmazione C");
  printf(" %s,  Indirizzo = %p\n", ptr, ptr);

  // Aggiungiamo memoria a blocchi già allocati
  ptr = (char *)realloc_chars(ptr, 20, 40);
  if (!ptr) {
    fprintf(stderr, "Impossibile (re)allocare memoria\n");
    return -1;
  }
  strcat(ptr, " è super divertente");
  // Nota come la stringa stampata contiene anche la precedente, i.e. realloc
  // copia la memoria precedente nella nuova
  printf(" %s,  Indirizzo = %p\n", ptr, ptr);
  free(ptr);
  return 0;
}
