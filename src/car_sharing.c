/***********************************************************
 * INTRODUZIONE
 **********************************************************
 * Vogliamo simulare il funzionamento di un'azienda di car sharing. Gli utenti
 * prelevano il veicolo da un punto qualsiasi all'interno della citta' e, al
 * termine del noleggio, lo riparcheggiano all'interno della stessa citta'.
 **********************************************************
 * DESCRIZIONE FILE CON I DATI
 **********************************************************
 * - File 1) car_sharing_noleggi.csv
 *   Informazioni sui noleggi effettuati dai clienti.
 *   ID_Cliente;ID_Via_Inizio;ID_Via_Fine;Minuti_Noleggio
 *
 *   Ogni riga successiva del file riporta le informazioni su un noleggio
 *   svolto dal cliente, i diversi valori sono separati da ; e i \r\n
 *   rappresentano i caratteri di a capo.
 *   + ID_Cliente e' un valore numerico che identifica univocamente
 *     il cliente che ha effettuato il noleggio,
 *   + ID_Via_Inizio e ID_Via_Fine sono valori numerici che identificano
 *     le vie in cui un noleggio inizia e finisce,
 *   + Minuti_Noleggio indica la durata in minuti del noleggio
 *
 * - File 2) car_sharing_vie.csv
 *   Il file contiene le distanze in km tra le vie della citta'.
 *   ID_via1;Via1;ID_via2;Via2;Distanza_metri
 *
 *   Ogni riga successiva del file contiene i dati di due vie e la loro distanza
 *   in metri (per ogni via e' riportato sia l'identificatore numerico sia il
 *   nome). In una riga, ogni volta che appare il nome di una via (ViaX...),
 *   appare sempre il corrispondente identificatore numerico (ID_viaX).
 *   ATTENZIONE, la distanza tra due vie e' presente un'unica volta nel file
 *   quindi se nel file e' presente ID_viaA;ViaA;ID_viaB;ViaB;Distanza allora
 *non e' presente una riga con ID_viaB;ViaB;ID_viaA;ViaA;Distanza o viceversa.
 *In ogni riga, i diversi valori sono separati da ; e i \r\n rappresentano i
 *   caratteri di a capo.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN_LINE 500
#define MAX_LEN_STRING 50
#define MAX_VIE 200
#define MAX_NOLEGGI 2000

/*
**********************************************************
* DESCRIZIONE DEL LAVORO DA SVOLGERE
**********************************************************
*/
typedef struct {
  /* Struttura contente la distanza tra le vie */
  unsigned id_via1;
  char via1[MAX_LEN_STRING];
  unsigned id_via2;
  char via2[MAX_LEN_STRING];
  float distanza;
} distanza_vie_t;

typedef struct {
  /* Struttura contente i dati sui noleggi */
  unsigned id_cliente;
  unsigned id_via_inizio;
  unsigned id_via_fine;
  unsigned minuti_noleggio;
} noleggio_t;

typedef struct {
  unsigned id_cliente;
  unsigned punti;
} cliente_t;

/*
 * Implementare le seguenti funzioni.
 */

/*
 * La funzione accetta come parametri il nome del file con i dati sulle distanze
 * tra le vie (File 2) e un array di puntatori a tipo distanza_vie_t. La
 * funzione dovra' memorizzare in array_vie i puntatori alle strutture contenti
 * la distanza tra le diverse vie.
 */
int leggi_vie(char *nome_file, distanza_vie_t *array_vie[], int n_vie);

/*
 * Stampa tutte le vie lette da file con leggi_vie()
 */
void stampa_vie(distanza_vie_t *array_vie[], int n_vie);

/*
 * I parametri idvia1 e idvia2 conterngono gli identificatori di due vie. Il
 * parametro distanza_vie_t e' invece l'array di puntatori popolato con
 * leggi_vie(). La funzione deve restituire la distanza tra le due vie. Se i
 * valori di idvia1 o idvia2 non sono presenti in array_vie, allora deve essere
 * restituito 100.0 come valore di distanza.
 */
float distanza_vie(int idvia1, int idvia2, distanza_vie_t **array_vie,
                   unsigned max_vie);

/*
 * Popola l'array noleggi con i puntatori ai dati contenuti nel file
 * nome_file_noleggi (File 1). Ogni cella di noleggi e' un puntatore a una
 * struttura noleggio_t.
 */
int leggi_dati_noleggi(char *nome_file_noleggi, noleggio_t *noleggi[],
                       unsigned max_noleggi);
/*
 * Dati i noleggi letti con la funzione leggi_dati_noleggi, calcola dei punti
 * bonus per gli utenti utilizzando la funziona calcola_bonus (data). Per ogni
 * cliente, memorizza poi il risultato in un file; ogni riga sara' formata da
 * id_cliente;punti
 */

int scrivi_punti_bonus(char *nome_file_clienti, noleggio_t *noleggi[],
                       unsigned n_noleggi);

  int leggi_vie(char *nome_file, distanza_vie_t **array_vie, int max_vie) {
    FILE *fp = fopen(nome_file, "r");
    if (!fp) {
      // controllo dꞌerrore su fopen
      fprintf(stderr, "\n Errore nellꞌ aprire il file!\n");
      exit(-1);
    }

    char line[MAX_LEN_LINE] = {0};
    const char *separator = ";";
    /* La prima linea contiene l'intestazione, possiamo ignorarla.*/
    fgets(line, MAX_LEN_LINE, fp);

    int i = 0;
    while (fgets(line, MAX_LEN_LINE, fp) != NULL) {
      distanza_vie_t *distanza =
          (distanza_vie_t *)malloc(sizeof(distanza_vie_t));

      /*
       * strtok trova la prima occorrenza del separatore, la sostituisce con
       * '\0' e restituisce un puntatore all'inizio della stringa. E.g.
       * strtok("ciao;mamma;guarda", ";") restituisce il puntatore a "c" e
       * sostituisce il primo ';' con '\0'.
       */
      char *ptr = strtok(line, separator);
      /* atoi converte da stringa a intero*/
      distanza->id_via1 = atoi(ptr);

      /*
       * Per la stringa successiva, usiamo NULL come primo parametro. In questo
       * modo strtok partira' dalla posizione successiva all'ultimo ";" trovato
       */
      ptr = strtok(NULL, separator);
      strcpy(distanza->via1, ptr);

      ptr = strtok(NULL, separator);
      distanza->id_via2 = atoi(ptr);

      ptr = strtok(NULL, separator);
      strcpy(distanza->via2, ptr);

      ptr = strtok(NULL, separator);
      distanza->distanza = atof(ptr);
      array_vie[i] = distanza;
      i++;
    }
    return i;
  }

  void stampa_vie(distanza_vie_t * *array_vie, int n_vie) {
    for (int i = 0; i < n_vie; i++) {
      distanza_vie_t *distanza = array_vie[i];
      printf("%d %s %d %s %f\n", distanza->id_via1, distanza->via1,
             distanza->id_via2, distanza->via2, distanza->distanza);
    }
  }

  float distanza_vie(int idvia1, int idvia2, distanza_vie_t **array_vie,
                     unsigned n_vie) {
    for (int i = 0; i < n_vie; i++) {
      if ((array_vie[i]->id_via1 == idvia1 && array_vie[i]->id_via2) ||
          (array_vie[i]->id_via2 == idvia1 && array_vie[i]->id_via1)) {
        return array_vie[i]->distanza;
      }
    }
    return 100.0;
  }

  int leggi_dati_noleggi(char *nome_file_noleggi, noleggio_t **noleggi,
                         unsigned max_noleggi) {
    /* TODO */
    return 0;
  }

  float calcolo_punti_bonus(float kms, unsigned minuti) {
    if (kms < 5) {
      return (int)kms;
    } else {
      return 3 * minuti;
    }
  }
  int scrivi_punti_bonus(char *nome_file_clienti, noleggio_t *noleggi[],
                         unsigned n_noleggi) {
    /* TODO */
    return 0.0;
  }
  /*       ########################################################## */

  int main(int argc, char *argv[]) {
    printf("Leggo tutte le vie\n");
    distanza_vie_t *vie[MAX_VIE];
    int n_vie = leggi_vie("car_sharing_vie.csv", vie, MAX_VIE);
    printf("Stampo tutte le vie\n");
    stampa_vie(vie, n_vie);

    printf("Calcolo distanza 0-1: ");
    float distanza = distanza_vie(0, 1, vie, n_vie);
    printf("%f\n", distanza);

    printf("Calcolo distanza 1-0 (nota ordine inverso, ma deve essere uguale a "
           "prima): ");
    distanza = distanza_vie(1, 0, vie, n_vie);
    printf("%f\n", distanza);

    noleggio_t *noleggi[MAX_NOLEGGI];
    printf("Leggo dati noleggi\n");
    int n_noleggi =
        leggi_dati_noleggi("car_sharing_noleggi.csv", noleggi, MAX_NOLEGGI);

    printf("Calcolo bonus\n");
    scrivi_punti_bonus("car_sharing_clienti.csv", noleggi, n_noleggi);

    return 0;
  }
