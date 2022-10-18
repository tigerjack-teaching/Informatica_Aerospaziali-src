#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  float x;
  // Ex. 0
  // Qual e' l'output del seguente codice?
  x = 1.0/10.0;
  printf("%.100f\n", x);
  // Questo e' la causa del fallimento del missile Patriot durante la prima
  // guerra del golfo (google Patriot Missile failure)
  printf("****\n");

  /* // Ex. 1 */
  /* // Qual e' l'output del seguente codice? */
  /* x = 1 + 1e28 - 1e28; */
  /* printf("%.100f\n", x); */
  /* printf("****\n"); */

  /* // Ex. 2 */
  /* // E di questo? */
  /* x = 1e28 - 1e28 + 1; */
  /* printf("%.100f\n", x); */
  /* printf("****\n"); */

  /* // Ex. 2 */
  /* // E di questo? */
  /* x = 0.001 + 10.1; */
  /* printf("%.100f\n", x); */
  /* printf("****\n"); */

  /* // Ex. 2 */
  /* // Cosa stampiamo qui */
  /* for (x = 0.0; x != 10.0; x+=0.1) { */
  /*   printf("."); */
  /* } */
  /* printf("\n%.100f\n", x); */
  /* printf("****\n"); */

  return 0;
}
