/*
 * Scrivere un programma che stimi il valore di $\pi$, utilizzando il metodo di
 * Monte Carlo.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definiamo la precisione per i valori di x e y.
#define INTERVAL 10000

int main()
{
	int interval, i;
	double rand_x, rand_y, origin_dist, pi;
	int circle_points = 0, square_points = 0;

  // Inizializzazione, deve essere chiamata solo una volta
	srand(time(NULL));

	// Total Random numbers generated = possible x
	// values * possible y values
	for (i = 0; i < (INTERVAL * INTERVAL); i++) {
    // rand() genera un numero intero tra 0 e RAND_MAX
    rand_x = (double)(rand() % (INTERVAL + 1)) / INTERVAL;
    rand_y = (double)(rand() % (INTERVAL + 1)) / INTERVAL;

    // Distanza di (x, y) dall'origine
    origin_dist = rand_x * rand_x + rand_y * rand_y;

    // Controllo se la
    // distanza dall'origine e' minore di 1 per capire se il punto e'
    // all'interno del cerchio
    if (origin_dist <= 1)
      circle_points++;

    // Total number of points generated
    square_points++;

    // estimated pi after this iteration
    pi = (double)(4 * circle_points) / square_points;
    printf("Stima : %f\n", pi);

    // For visual understanding (Optional)
    /* cout << rand_x << " " << rand_y << " " << circle_points */
    /* 	<< " " << square_points << " - " << pi << endl << endl; */

	}

	// Final Estimated Value
  printf("Stima finale di pi %f\n", pi);

	return 0;
}
