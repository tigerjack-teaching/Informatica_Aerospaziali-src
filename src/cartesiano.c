/*
 * Implementare un programma C che legge da tastiera un numero intero N (1 ≤ N ≤
 * 10), e sucessivamente legge N coppie di interi >= 0 rappresentanti
 * ciascuna le coordinate di un punto (x,y) su di un piano cartesiano 5X5. Si
 * stampi poi il piano cartesiano rappresentando i punti con una X.
 *
 * TODO casa: modificare l'esercizio in modo da gestire anche interi negativi
 */
#include <stdio.h>
#define PUNTI_MASSIMI 10
#define X_DIMENSIONE 10
#define Y_DIMENSIONE 5

/* Definiamo la struct che useremo per memorizzare un punto
   sul piano cartesiano. */
struct point {
    int x;
    int y;
};

int main() {
    int n, i, j;

    /* Vettore di struct che conterranno i punti. */
    struct point punti[PUNTI_MASSIMI];

    /* Matrice per rappresentare il piano cartesiano. Se in posizione i j
       troviamo un 1, significa che quel punto è presente sul piano cartesiano
       con quelle coordinate. */
    int piano[Y_DIMENSIONE][X_DIMENSIONE];

    /* Acquisiamo da tastiera una serie di coppie di coordinate
       per i punti che vogliamo rappresentare sul nostro piano. */
    printf("Inserisci il numero di punti da acqusire (MAX %d)\n", PUNTI_MASSIMI);
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      printf("Inserisci coordinata x (MAX %d)\n", X_DIMENSIONE - 1);
      scanf("%d", &punti[i].x);
      printf("Inserisci coordinata y (MAX %d)\n", Y_DIMENSIONE - 1);
      scanf("%d", &punti[i].y);
      /* Per ogni punto acquisito, settiamo ad 1 la cella corrispondente
         nel piano cartesiano se il punto è presente. */
      piano[punti[i].y][punti[i].x] = 1;
    }
    printf("\n");

    /* Stampiamo il nostro piano cartesiano. Partiamo dalle coordinate più
       "in alto". Per ogni riga, dovremo stampare la coordinata dell'asse Y,
       un divisorio "|", e i punti rappresentati con una X se presenti. */
    for (i = Y_DIMENSIONE - 1; i >= 0; i--) {
        printf("%d|", i);
        for (j = 0; j < X_DIMENSIONE; j++) {
            if (piano[i][j] == 1) {
                printf("X ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    /* Stampiamo la divisione con l'asse X */
    printf("  ");
    for (j = 0; j < X_DIMENSIONE; j++) {
        printf("- ");
    }

    /* Stampiamo le coordinate dell'asse Y. */
    printf("\n  ");
    for (j = 0; j < X_DIMENSIONE; j++) {
        printf("%d ", j);
    }

    printf("\n");

    return 0;
}
