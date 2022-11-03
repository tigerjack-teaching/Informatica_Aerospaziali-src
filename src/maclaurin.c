/*
 * TAGS: function
 */
#include <stdio.h>
#define N 10

/*Dichiarazioni che ci permettono di rimandare la definizione del
corpo delle funzioni, pur permettendo di chiamarle nella funzione `ex`.*/
float potenza(float x, unsigned int exp);
unsigned int fattoriale(unsigned int n);

/* Funzione che calcola l'esponenziale con la serie di Maclaurin */
float ex(float x) {
  float somma = 0.0;
  int n;

  /*Il corpo della funzione è semplicemente l'implementazione
  della sommatoria data nella consegna. Ricorriamo ad altre
  due funzioni di supporto per cacolare ogni volta la potenza
  e il fattoriale necessari.*/
  for (n = 0; n < N; n++) {
    somma += potenza(x, n) / fattoriale(n);
  }
  return somma;
}

/* Funzione di supporto per calcolare la potenza. */
float potenza(float x, unsigned int exp) {
  float prodotto = 1.0;
  int i;
  for (i = 0; i < exp; i++) {
    prodotto = prodotto * x;
  }
  return prodotto;
}

/* Funzione di supporto per calcolare il fattoriale. */
unsigned int fattoriale(unsigned int n) {
  float prodotto = 1.0;
  while (n > 0) {
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
  risultato = ex(x);
  printf("Il risultato di exp(%f) e': %f\n", x, risultato);
  return 0;
}
