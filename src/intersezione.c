/*
 * Trovare l'intersezione tra due rette
 */
#include <stdio.h>

int main(int argc, char *argv[]) {
  /*
   * L'idea e' che le rette siano rappresentate in maniera esplicita, come
   * y1 = ax + b, y2 = cx + d. All'utente chiediamo i coefficienti a, b, c e d.
   */
  float a, b, c, d;
  float x, y;
  printf("y1 = ax + b");
  printf("\na: ");
  scanf("%f", &a);
  printf("\nb: ");
  scanf("%f", &b);
  printf("y2 = cx + d");
  printf("\nc: ");
  scanf("%f", &c);
  printf("\nd: ");
  scanf("%f", &d);

  if (a == c) {
    printf("Rette parallele\n");
    return -1;
  }

  x = (d - b) / (a - c);
  y = a * x + b;

  printf("\nL'intersezione tra");
  printf("\ny = %f x + %f", a, b);
  printf("\ne");
  printf("\ny = %f x + %f", c, d);
  /* printf("\n")'' */
  printf("\ne' x = %f, y = %f\n", x, y);

  return 0;
}
