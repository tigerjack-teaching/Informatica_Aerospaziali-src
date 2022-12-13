/*
 * TAGS: malloc, realloc
 *
 * TODO: implementare stessa funzione senza usare la realloc
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  ptr = (char *)realloc(ptr, 40);
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
