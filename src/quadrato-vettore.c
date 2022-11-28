/*
 * TAGS: function
 *
 * Implementare un sottoprogramma che, preso in input un vettore di interi,
 * rimpiazzi ogni intero originalmente contenuto con il suo quadrato.
 */
#include <stdio.h>

#define N_ELEMS 5

/* Funzione di supporto che calcola una potenza di un numero. */
int potenza(int n, int exp) {
  int risultato = 1;
  int i;
  for (i = 0; i < exp; i++) {
    risultato = risultato * n;
  }
  return risultato;
}

/* Funzione di supporto che effettua il quadrato. */
void vec_mul_const(int v[], int n_elem, int const_mult) {
  /* Per ogni elemento del vettore, invochiamo la funzione di supporto e */
  /* riassegniamo l'elemento. Ricordiamoci che grazie al fatto che la funzione */
  /* riceve l'indirizzo del primo elemento dell'array nello scope del `main`, la */
  /* modifica verrà effettuata direttamente nell'array dichiarato nel `main`. */
  int i;
  for (i = 0; i < n_elem; i++) {
    v[i] = potenza(v[i], const_mult);
  }

  /* In una funzione che restituisce `void`, il `return` è facoltativo. */
  return;
}

int main() {
  int i;
  /* Il vettore è dichiarato nello scope della funzione `main`. */
  /* In questo caso è giá inizializzato per comoditá, ma ovviamente */
  /* i valori potrebbero essere acquisiti da standard input. */
  int v[N_ELEMS] = {1, 2, 3, 4, 5};

  /* Invochiamo la funzione che ci calcolerà il quadrato per ogni */
  /* elemento. Ricordiamoci che dobbiamo anche passare la dimensione. */
  /* del vettore se vogliamo che la nostra funzione di supporto sia */
  /* in grado di gestire vettori di lunghezza arbitraria. */
  vec_mul_const(v, N_ELEMS, 2);

  for (i = 0; i < N_ELEMS; i++) {
    printf("%d ", v[i]);
  }
  return 0;
}
