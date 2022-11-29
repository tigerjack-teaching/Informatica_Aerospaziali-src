/*
 * TAGS: function
 *
 * Implementare il calcolo dell'esponenziale e^x tramite l'uso della serie di
 * MacLaurin, facendo uso estensivo dei sottoprogrammi
 * e^{x} = (x^0)/(0!) + (x^1)(1!) + (x^2)(2!) + ...
 *
 * HINT: usare due funzioni: _potenza_ e _fattoriale_
 */
#include <stdio.h>

#define ORDER 15

/*
 * Dichiarazioni che ci permettono di rimandare la definizione del
 * corpo delle funzioni, pur permettendo di chiamarle nella funzione `ex`.
*/
unsigned potenza(unsigned, unsigned);
unsigned fattoriale(unsigned);

/* Funzione che calcola l'esponenziale con la serie di Maclaurin */
float ex(unsigned x, unsigned order) {
  float somma = 0.0;

  /*Il corpo della funzione è semplicemente l'implementazione
  della sommatoria data nella consegna. Ricorriamo ad altre
  due funzioni di supporto per cacolare ogni volta la potenza
  e il fattoriale necessari.*/
  unsigned n;
  for (n = 0; n < order; n++) {
    somma += (float) potenza(x, n) / fattoriale(n);
    printf("+ %d / %d = %f\n", potenza(x, n), fattoriale(n), somma);
  }
  return somma;
}

/* Funzione di supporto per calcolare la potenza. */
unsigned potenza(unsigned x, unsigned int exp) {
  unsigned prodotto = 1;
  int i;
  for (i = 0; i < exp; i++) {
    prodotto = prodotto * x;
  }
  return prodotto;
}

/* Funzione di supporto per calcolare il fattoriale. */
unsigned int fattoriale(unsigned int n) {
  unsigned prodotto = 1;
  while (n > 1) {
    prodotto *= n;
    n--;
  }
  return prodotto;
}

int main() {
  float x, risultato;
  scanf("%f", &x);

  /*Nella funzione main, oltre ad acquisire e stampare il valore, ci limitiamo
  ad invocare la funzione ex che calcolerà l'esponenziale con la serie di
  Maclaurin.*/
  risultato = ex(x, ORDER);
  printf("Il risultato di exp(%f) e': %f\n", x, risultato);
  return 0;
}
