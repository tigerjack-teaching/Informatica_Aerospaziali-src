/*
 * Scrivere un programma che dato in input un numero intero N > 0, stampi i
 * primi N numeri di fibonacci
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  // Dichiariamo e acquisiamo il nostro N
  unsigned n;
  printf("Inserisci un numero\n");
  scanf("%u", &n);

  // Controlliamo che il valore in input sia positivo, altrimenti terminiamo.
  if (n <= 0) {
    printf("Il valore inserito non è positivo\n");
    return 0;
  }

  int prev1, prev2, cur;

  // Stampa del primo numero della serie di Fibonacci.
  printf("0 ");

  // Volevamo solo il primo numero? Se si, terminiamo.
  if (n == 1) {
    return 0;
  }

  // Stampa del secondo numero della serie.
  printf("1 ");

  // nelle slide, prev1=a, prev2=b, cur=c
  prev1 = 0;
  prev2 = 1;

  // Questo ciclo, verrà eseguito n - 2 volte, perché i
  // primi due numeri della serie sono già stati stampati sopra.
  while (n > 2) {
    // Calcoliamo l'n-esimo numero della serie di Fibonacci e lo stampiamo.
    cur = prev1 + prev2;
    printf("%u ", cur);

    // Aggiorniamo le variabili che contengono i precedenti due valori della
    // serie di Fibonacci
    prev1 = prev2;
    prev2 = cur;
    n--;
  }
  printf("\n");

  // Terminiamo l'esecuzione del programma.
  return 0;
}
