#include <stdio.h>

int main() {

  /* Dichiariamo e inizializziamo lo stato del gioco, come
     matrice di char. */
  char tris[3][3] = {{' ', 'X', 'O'}, {'X', 'O', 'X'}, {'O', 'X', 'O'}};

  int i, j;

  int somma_X_diag = 0, somma_O_diag = 0;
  int somma_X_diag_2 = 0, somma_O_diag_2 = 0;

  /* Stampiamo lo stato del tris. */
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%c ", tris[i][j]);
    }
    printf("\n");
  }

  for (i = 0; i < 3; i++) {
    int somma_X_riga = 0, somma_O_riga = 0;
    int somma_X_colonna = 0, somma_O_colonna = 0;

    for (j = 0; j < 3; j++) {
      /* Ad i fissata, raccogliamo nelle apposite variabili,
         il numero di X e O presenti su tutte le colonne della
         i-esima riga (j sta iterando). */
      if (tris[i][j] == 'X') {
        somma_X_riga++;
      }
      if (tris[i][j] == 'O') {
        somma_O_riga++;
      }

      /* Ad i fissata, raccogliamo nelle apposite variabili,
         il numero di X e O presenti su tutte le righe della
         j-esima colonna (j sta iterando). */
      if (tris[j][i] == 'X') {
        somma_X_colonna++;
      }
      if (tris[j][i] == 'O') {
        somma_O_colonna++;
      }
    }

    /* Raccogliamo il numero di X e O presenti sulla diagonale
       principale e secondaria. Notare come per le diagionali,
       ci basti iterare su di un solo indice 1. */
    if (tris[i][i] == 'X') {
      somma_X_diag++;
    }
    if (tris[i][i] == 'O') {
      somma_O_diag++;
    }
    if (tris[i][2 - i] == 'X') {
      somma_X_diag_2++;
    }
    if (tris[i][2 - i] == 'O') {
      somma_O_diag_2++;
    }

    /* Controlliamo se la somma su una colonna o riga, o su una delle due
       diagonali ha raggiunto il valore necessario per la vittoria. In questo
       caso, stampiamo un messaggio indicante la cosa. */
    if (somma_X_riga == 3 || somma_X_colonna == 3 || somma_X_diag == 3 ||
        somma_X_diag_2 == 3) {
      printf("X vince.\n");
      break;
    }
    if (somma_O_riga == 3 || somma_O_colonna == 3 || somma_O_diag == 3 ||
        somma_O_diag_2 == 3) {
      printf("O vince.\n");
      break;
    }
  }
  return 0;
}
