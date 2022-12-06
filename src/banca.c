#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LUN 100

/* Struct che ci serve per modellare il tipo di dato che rappresenta il
 * movimento */
typedef struct mov {
  char data[10 + 1];
  float importo;
  char segno;
} movimento_t;

int num_anno(char data[]);
int num_mese(char data[]);

void data_limite(const char nomefile[], float lim_credito,
                 char *data_restituita) {
  /*
   * Legge il file e si ferma quando il saldo scende sotto il limite,
   * restituendo la data in cui tale limite e' stato sforato.
   */

  /* Apertura file con l'elenco movimenti. */
  FILE *fp = fopen(nomefile, "r");
  if (!fp) {
    fprintf(stderr, "Errore nell'apertura del file\n");
    exit(-1);
  }

  char iban[27 + 1], data_movimento[10 + 1], segno;
  float importo, saldo;

  /* Leggiamo IBAN e saldo inziale. */
  fscanf(fp, "%s\n", iban);
  fscanf(fp, "%f\n", &saldo);

  /* Leggiamo tutte le linee, fermandoci se il saldo parziale
     accumulato scende sotto il limite */

  /* Leggiamo i dati relativi a ciascun movimento, e li salviamo nelle
   * variabili dedicate */
  /* fscanf restituisce EOF se ci sono stati errori; altrimenti, restituisce il
     numero di assegnamenti corretti.*/
  int ret = fscanf(fp, "%s %f %c\n", data_movimento, &importo, &segno);
  while (ret == 3 && saldo >= lim_credito) {
    /* N.B. La \n e' fondamentale per segnalare correttamente EOF (e quindi
     * evitare di leggere l'ultima riga 2 volte) */

    /* In base al segno del movimento, incrementiamo o decrementiamo il
     * saldo della somma */
    if (segno == '+') {
      saldo += importo;
    } else {
      saldo -= importo;
    }
    ret = fscanf(fp, "%s %f %c\n", data_movimento, &importo, &segno);
  }
  fclose(fp);

  if (ret == EOF) {
    printf("Correttamente raggiunto EOF\n");
  } else {
    printf("Assegnati solo %d item\n", ret);
  }
  /* Se usciti dal ciclo per EOF, il saldo accumulato è sceso sotto il limite,
   * copiamo in `data_restituita` la data del movimento che ha causato lo
   * sforamento del limite, in modo da progagare questa informazione al
   * main */
  if (saldo < lim_credito) {
    strcpy(data_restituita, data_movimento);
  }
  return;
}

void leggi_estratto(const char nomefile[], movimento_t *movimenti, int *lung,
                    float *saldo_iniziale, float *saldo_finale) {

  /*
   * Legge il file e memorizza tutti i dati nella struttura movimenti. lung
   * conterrra', alla fine della funzione, il numero di movimenti.
   * saldo_iniziale e finale conterrano, risp., saldo_iniziale e finale.
   */

  char iban[27 + 1];
  movimento_t m;
  int cont = 0;

  /* Apertura del file */
  FILE *fp = fopen(nomefile, "r");
  if (!fp) {
    fprintf(stderr, "Errore lettura file\n");
    exit(-1);
  }

  /* Prima lettura del file, identica a quella della funzione precedente, per
   * contare il numero di movimenti nel file */
  fscanf(fp, "%s\n", iban);
  fscanf(fp, "%f\n", saldo_iniziale);

  int ret = fscanf(fp, "%s %f %c\n", m.data, &m.importo, &m.segno);
  while (ret == 3) {
    cont++;
    ret = fscanf(fp, "%s %f %c\n", m.data, &m.importo, &m.segno);
  }
  /* Andrebbero gestiti anche qui i valori di ret.*/

  /* Se non abbiamo movimenti, chiudiamo il file e fermiamo l'esecuzione */
  (*lung) = cont;
  *saldo_finale = *saldo_iniziale;
  if (cont == 0) {
    fclose(fp);
    return;
  }

  /* Riposizioniamo la posizione di lettura del file all'inizio */
  rewind(fp);

  /* Rileggiamo la lista dei movimenti, e popoliamo l'array dei movimenti in
     memoria */
  fscanf(fp, "%s\n", iban);
  fscanf(fp, "%f\n", saldo_iniziale);
  for (int i = 0; i < cont; i++) {
    fscanf(fp, "%s %f %c\n", m.data, &m.importo, &m.segno);
    if (m.segno == '+') {
      *saldo_finale += m.importo;
    } else {
      *saldo_finale -= m.importo;
    }
    movimenti[i] = m;
  }
  fclose(fp);
  return;
}

/* Struct per modellare il bilancio mensile di entrata e uscita */
typedef struct t_entrateUscite {
  float tot_entrate;
  float tot_uscite;
} t_bilancio;
typedef t_bilancio bilancio_mensile[12];

void calcola_bilanci_mensili(movimento_t *elenco, int lung, int anno,
                             t_bilancio ris[12]) {
  /*
   * Dato un anno e la lista movimenti, stampa entrate/uscite per ogni mese.
   */

  /* Inizializziamo l'array dei movimenti */
  for (int i = 0; i < 12; i++) {
    t_bilancio bilancio_zero;
    bilancio_zero.tot_entrate = 0.0;
    bilancio_zero.tot_uscite = 0.0;
    ris[i] = bilancio_zero;
  }

  movimento_t m;
  /* Scorrendo l'elenco dei movimenti, estraiamo i movimenti */
  for (int i = 0; i < lung; i++) {
    m = elenco[i];

    /* Grazie alla funzione di supporto `num_anno`, che ci converte
       l'anno in intero, controlliamo se l'anno del movimento è quello di
       interesse */
    if (num_anno(m.data) == anno) {

      /* In base al segno del movimento, incrementiamo il campo corretto di
       * uscita/entrata */
      if (m.segno == '+') {
        /* Per accedere al bilancio del mese corretto, utilizziamo la funzione
           di supporto `num_mese` che restituisce l'intero del mese
           corrispondente */
        ris[num_mese(m.data) - 1].tot_entrate += m.importo;
      } else {
        ris[num_mese(m.data) - 1].tot_uscite += m.importo;
      }
    }
  }
}

/* Funzione di supporto che estrae dalla stringa rappresentante la data
   l'anno, e lo restituisce come intero */
int num_anno(char data[]) {
  char year[5] = {data[0], data[1], data[2], data[3], '\0'};
  return atoi(year);
}

/* Funzione di supporto che estrae dalla stringa rappresentante la data
   il mese, e lo restituisce come intero */
int num_mese(char data[]) {
  char month[3] = {'\0'};
  if (data[5] == '0') {
    month[0] = data[6];
  } else {
    month[0] = data[5];
    month[1] = data[6];
  }
  return atoi(month);
}

int main() {
  fprintf(stdout, "Prendo data in cui sono sceso sotto i 500\n");
  const char *filename = "banca_estratto.txt";
  char risultato[MAX_LUN];
  data_limite(filename, -500.00, risultato);
  fprintf(stdout, "Sono sceso sotto il limite in data %s\n", risultato);

  fprintf(stdout, "Leggo tutti i movimenti\n");
  movimento_t movimenti[MAX_LUN];
  int lung;
  float saldo_iniziale, saldo_finale;
  leggi_estratto(filename, movimenti, &lung, &saldo_iniziale, &saldo_finale);
  printf("Ho letto %d movimenti, saldo iniziale: %f, finale: %f\n", lung,
         saldo_iniziale, saldo_finale);

  printf("Calcolo il bilancio del 2019\n");
  bilancio_mensile bilanci;
  calcola_bilanci_mensili(movimenti, lung, 2019, bilanci);
  for (int i = 0; i < 12; i++) {
    printf("\nMese %d:\n", i + 1);
    printf("Entrate: %f, Uscite: %f", bilanci[i].tot_entrate,
           bilanci[i].tot_uscite);
  }
  return 0;
}
