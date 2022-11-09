/*
 *
 *  Viene definito numero triangolare, un numero costituito dalla somma dei
 *  primi interi positivi N, per un certo N. Implementare un programma che,
 *  letto un intero da user input, stabilisce se il numero è un numero
 *  triangolare.
 *
 * Esempio
 * Q = 10 è un numero triangolare in quanto Q = 1 + 2 + 3 + 4, da cui N=4.
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int i, N, S;

  /* Procediamo all'acquisizione del numero. */
  do {
    printf("Inserisci un numero maggiore di 0");
    scanf("%d", &N);
  } while (N <= 0);

  /* Continuiamo a sottrarre, dal numero N di partenza, tutti i numeri interi
     incrementali, che sono di volta in volta memorizzati nella variabile i. Per
     preservare il numero inserito originalmente, facciamo una copia di N in
     S. */
  S = N;
  i = 0;
  while (S > 0) {
    i = i + 1;
    S = S - i;
  }

  /* In base al valore di uscita di S alla fine del ciclo, possiamo stabilire se
   il numero è triangolare o meno.*/
  if (S == 0) {
    printf("\n %d è equivalente alla somma dei primi %d numeri positivi\n", N,
           i);
  } else {
    printf("\n Il numero %d non è un numero triangolare\n", N);
  }

  return 0;
}
