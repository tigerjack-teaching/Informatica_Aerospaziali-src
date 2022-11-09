#include <stdio.h>
#define PUNTI_MASSIMI 10
#define DIMENSIONE 5

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
    int piano[DIMENSIONE][DIMENSIONE];

    /* Acquisiamo da tastiera una serie di coppie di coordinate
       per i punti che vogliamo rappresentare sul nostro piano. */
    printf("Inserisci il numero di punti da acqusire\n", &n);
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Inserisci coordinata x\n");
        scanf("%d", &punti[i].x);
        printf("Inserisci coordinata y\n");
        scanf("%d", &punti[i].y);
    }

    /* Per ogni punto acquisito, settiamo ad 1 la cella corrispondente
       nel piano cartesiano se il punto è presente. */
    for (i = 0; i < n; i++) {
        piano[punti[i].y][punti[i].x] = 1;
    }

    /* Stampiamo il nostro piano cartesiano. Partiamo dalle coordinate più
       "in alto". Per ogni riga, dovremo stampare la coordinata dell'asse Y,
       un divisiorio "|", e i punti rappresentati con una X se presenti. */
    for (i = DIMENSIONE - 1; i >= 0; i--) {
        printf("%d|", i);
        for (j = 0; j < DIMENSIONE; j++) {
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
    for (j = 0; j < DIMENSIONE; j++) {
        printf("- ");
    }

    /* Stampiamo le coordinate dell'asse X. */
    printf("\n  ");
    for (j = 0; j < DIMENSIONE; j++) {
        printf("%d ", j);
    }

    printf("\n");

    return 0;
}
