#include <stdio.h>
#include <stdlib.h>
#define NUM_GIUDICI 5
#define NUM_ATLETI 2
#define MAX_STRING 100

typedef float punteggi_tuffo[NUM_GIUDICI];

typedef struct {
  char nome[MAX_STRING];
  char cognome[MAX_STRING];
  char sesso;
  char nazionalita[MAX_STRING];
  float punteggio_finale;
} atleta;

typedef atleta gara[NUM_ATLETI];

// Funzione di supporto per calcolare il punteggio finale a partire
// da un array contenente i punteggi singoli e la difficoltà.
float calcola_punteggio(punteggi_tuffo voti, float diff) {
  float min = voti[0], max = voti[0], tot = 0;

  // Inizialiazzazione
  for (int i = 0; i < NUM_GIUDICI; i++) {

    // Ricerca minimo.
    if (voti[i] < min) {
      min = voti[i];
    }

    // Ricerca massimo.
    if (voti[i] > max)
      max = voti[i];

    // Somma punti.
    tot += voti[i];
  }

  // Eliminazione estremi.
  tot = tot - min - max;

  // Calcolo punteggio finale.
  return tot * diff;
}

void stampa_migliori(gara G) {
  float max_pf_donna = -1.0, max_pf_uomo = -1.0;
  int i, flag_miglior_donna = 0, flag_miglior_uomo = 0;

  // Ricerca del punteggio massimo per donne e uomini
  for (i = 0; i < NUM_ATLETI; i++) {
    if (G[i].sesso == 'f' && max_pf_donna < G[i].punteggio_finale)
      max_pf_donna = G[i].punteggio_finale;
    if (G[i].sesso == 'm' && max_pf_uomo < G[i].punteggio_finale)
      max_pf_uomo = G[i].punteggio_finale;
  }
  // Stampa dei migliori differenziati per uomo/donna.
  for (i = 0; i < NUM_ATLETI; i++) {
    if (G[i].sesso == 'f' && G[i].punteggio_finale == max_pf_donna) {
      flag_miglior_donna = 1;
      printf("\n Donna (Punteggio: %3.2f) – Nome: %s, Cognome: %s, "
             "Nazionalita: %s \n",
             G[i].punteggio_finale, G[i].nome, G[i].cognome, G[i].nazionalita);
    }
    if (G[i].sesso == 'm' && G[i].punteggio_finale == max_pf_uomo) {
      flag_miglior_uomo = 1;
      printf("\n Uomo (Punteggio: %3.2f) – Nome: %s, Cognome: %s, Nazionalita: "
             "%s \n",
             G[i].punteggio_finale, G[i].nome, G[i].cognome, G[i].nazionalita);
    }
  }

  // Controllo addizionale sull'aver trovato un atleta migliore per
  // uomini/donne.
  if (flag_miglior_donna == 0)
    printf("\n Nessuna donna ha ottenuto il punteggio massimo! \n");
  if (flag_miglior_uomo == 0)
    printf("\n Nessun uomo ha ottenuto il punteggio massimo! \n");
}

void acquisici(gara G) {
  int i, j;
  punteggi_tuffo voti;
  float difficolta;

  // Acquisiamo i dati anagrafici degli atleti.
  for (i = 0; i < NUM_ATLETI; i++) {
    printf("Inserisci nome\n");
    scanf("\n%s", G[i].nome);
    printf("Inserisci cognome\n");
    scanf("\n%s", G[i].cognome);
    printf("Inserisci sesso\n");
    scanf("\n%c", &G[i].sesso);
    printf("Inserisci nazionalita\n");
    scanf("\n%s", G[i].nazionalita);

    // Acquisiamo i voti dei giudici, e calcoliamo il punteggio finale
    // utilizzando la funzione di supporto.
    for (j = 0; j < NUM_GIUDICI; j++) {
      printf("Inserisci voto giudice %d\n", j);
      scanf("\n%f", &voti[j]);
    }
    printf("Inserisci difficoltà tuffo\n");
    scanf("\n%f", &difficolta);
    G[i].punteggio_finale = calcola_punteggio(voti, difficolta);
  }
}

int main() {
  int i, j;

  // Le seguenti variabili, hanno un tipo definito nelle precedenti `typedef`.
  gara G;

  // Acquisiamo i dati degli atleti da user input.
  acquisici(G);

  // Cerchiamo i migliori con la funzione di supporto.
  stampa_migliori(G);

  return 0;
}
