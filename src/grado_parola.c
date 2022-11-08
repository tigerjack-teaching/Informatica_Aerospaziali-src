/*
 *  Definiamo il grado minimo g e il grado massimo G di una
 *  parola P rispettivamente il minimo e il massimo numero di
 *  occorrenze delle lettere di P in P. G e g valgono convenzionalmente 0 per la
 *  parola vuota.
 *
 * Esempio
 *  ISTANBUL g=1, G=1  (tutte le lettere compaiono una sola volta )
 *  BOSFORO g=1, G=3 (B, S, F, R una sola volta, O tre volte)
 *  GALATASARAY g=1, G=5 (G, L, T, S, R, Y una
 *    volta, A cinque volte)
 *  MARMARA g=2, G=3 (M e R due volte, A tre volte)
 *
 *  Si scriva un programma che legga una stringa di lunghezza generica che
 *  rappresenta P, e calcola i gradi G e g, e li riporti su stdout.
 */
#include <stdio.h>
#include <string.h>
#define MAXLEN 10
int main() {
  char parola[MAXLEN + 1];
  int g, G, i, j, count, lun;
  printf("\n Inserire una parola: ");
  scanf("%10s", parola);
  lun = strlen(parola);
  g = lun;
  G = 0;
  for (i = 0; i < lun; i++) {
    count = 0;
    for (j = 0; j < lun; j++)
      if (parola[i] == parola[j])
        count++;

    if (count < g)
      g = count;
    if (count > G)
      G = count;
  }
  printf("\n g=%d, G=%d \n", g, G);
  return 0;
}
