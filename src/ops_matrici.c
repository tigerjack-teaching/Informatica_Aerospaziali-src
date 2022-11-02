#include <stdio.h>

#define SIZE 3 // Size of the matrix

int main() {
  int A[SIZE][SIZE] = {
      {0, 1, 2},
      {3, 4, 5},
      {6, 7, 8},
  };                 // Matrice 1 inizializzata
  int B[SIZE][SIZE]; // Matrice 2
  int C[SIZE][SIZE]; // Matrice somma

  int row, col;

  printf("Inserisci gli elementi della matrice B di dimensioni 3x3: \n");
  for (row = 0; row < SIZE; row++) {
    for (col = 0; col < SIZE; col++) {
      scanf("%d", &B[row][col]);
    }
  }

  printf("\nMatrice A = \n");
  for (row = 0; row < SIZE; row++) {
    for (col = 0; col < SIZE; col++) {
      printf("%d ", A[row][col]);
    }
    printf("\n");
  }
  printf("\nMatrice B = \n");
  for (row = 0; row < SIZE; row++) {
    for (col = 0; col < SIZE; col++) {
      printf("%d ", B[row][col]);
    }
    printf("\n");
  }

  /*
   * Somma le matrici, risultato nella matrice C
   */
  for (row = 0; row < SIZE; row++) {
    for (col = 0; col < SIZE; col++) {
      /* C_ij = A_ij + B_ij */
      C[row][col] = A[row][col] + B[row][col];
    }
  }

  printf("\nSomma delle matrici A+B = \n");
  for (row = 0; row < SIZE; row++) {
    for (col = 0; col < SIZE; col++) {
      printf("%d ", C[row][col]);
    }
    printf("\n");
  }

  printf("\nMoltiplicazione delle matrici A*B = \n");
  // N.B.: stampa senza salvare la matrice!
  for (row = 0; row < SIZE; row++) {
    for (col = 0; col < SIZE; col++) {
      int somma = 0;
      int i = 0;
      for (i = 0; i < SIZE; i++) {
        somma += A[row][i] * B[i][col];
      }
      printf("%d ", somma);
    }
    printf("\n");
  }

  printf("\nTrasposta A = \n");
  for (col = 0; col < SIZE; col++) {
    for (row = 0; row < SIZE; row++) {
      printf("%d ", A[row][col]);
    }
    printf("\n");
  }

  return 0;
}
