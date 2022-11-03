/*
 * TAGS: float
 *
 * TODO classe. Prova con input 11.6 e 7.3. Cosa succede nell'output?
 */
#include <stdio.h>
int main(int argc, char *argv[]) {
  float A, B, Y;
  printf("Inserisci A\n");
  scanf("%f", &A);
  printf("Inserisci B\n");
  scanf("%f", &B);

  Y = (A + B)/2;

  printf("Media = %f\n", Y);

  return 0;
}
