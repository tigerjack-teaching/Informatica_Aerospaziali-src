#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LUN 100

void dataLimite(const char nomefile[], float limCredito, char *dataRestituita) {

  /* Apertura file con l'elenco movimenti. */
  FILE *fp = fopen(nomefile, "r");
  if (fp == NULL) {
    return;
  }

  char iban[27 + 1], dataMovimento[10 + 1], segno;
  float importo, saldo;

  /* Leggiamo IBAN e saldo inziale. */
  fscanf(fp, "%s\n", iban);
  fscanf(fp, "%f\n", &saldo);

  /* Leggiamo tutte le linee contenenti i , fermandoci se il saldo parziale
     accumulato scende sotto il limite */
  while (feof(fp) == 0 && saldo >= limCredito) {
    /* Leggiamo i dati relativi a ciascun movimento, e li salviamo nelle
       variabili dedicate */
    fscanf(fp, "%s %f %c\n", dataMovimento, &importo, &segno);

    /* In base al segno del movimento, incrementiamo o decrementiamo il saldo
       della somma */
    if (segno == '+') {
      saldo += importo;
    } else {
      saldo -= importo;
    }
  }

  fclose(fp);

  /* Se usciti dal ciclo, il saldo accumulato è sceso sotto il limite, copiamo
     in `dataRestituita` la data del movimento che ha causato lo sforamento del
     limite, in modo da progagare questa informazione al main */
  if (saldo < limCredito) {
    strcpy(dataRestituita, dataMovimento);
  }

  return;
}

/* Struct che ci serve per modellare il tipo di dato che rappresenta il
 * movimento */
typedef struct mov {
  char data[10 + 1];
  float importo;
  char segno;
} t_movimento;

void leggiEstratto(const char nomefile[], t_movimento *movimenti, int *lung,
                   float *saldoIniziale) {

  char iban[27 + 1];
  t_movimento m;
  int cont = 0;

  /* Apertura del file */
  FILE *fp = fopen(nomefile, "r");
  if (!fp) {
    *lung = 0;
    *saldoIniziale = 0;
    return;
  }

  /* Prima lettura del file, identica a quella della funzione precedente, per
     contare il numero di movimenti nel file */
  fscanf(fp, "%s\n", iban);
  fscanf(fp, "%f\n", saldoIniziale);
  while (feof(fp) == 0) {
    fscanf(fp, "%s %f %c\n", m.data, &m.importo, &m.segno);
    cont += 1;
  }

  /* Se non abbiamo movimenti, chiudiamo il file e fermiamo l'esecuzione */
  (*lung) = cont;
  if (cont == 0) {
    fclose(fp);
    return;
  }

  /* Riposizioniamo la posizione di lettura del file all'inizio */
  rewind(fp);

  /* Rileggiamo la lista dei movimenti, e popoliamo l'array dei movimenti in
     memoria */
  fscanf(fp, "%s\n", iban);
  fscanf(fp, "%f\n", saldoIniziale);
  for (int i = 0; i < cont; i++) {
    fscanf(fp, "%s %f %c\n", m.data, &m.importo, &m.segno);
    movimenti[i] = m;
  }
  fclose(fp);
  return;
}

int numAnno(char data[]);
int numMese(char data[]);

/* Struct per modellare il bilancio mensile di entrata e uscita */
typedef struct t_entrateUscite {
  float totEntrate;
  float totUscite;
} t_bilancio;
typedef t_bilancio bilancioMensile[12];

void calcolaBilanciMensili(t_movimento *elenco, int lung, int anno,
                           t_bilancio ris[12]) {
  /* Inizializziamo l'array dei movimenti */
  for (int i = 0; i < 12; i++) {
    t_bilancio bilancioZero;
    bilancioZero.totEntrate = 0.0;
    bilancioZero.totUscite = 0.0;
    ris[i] = bilancioZero;
  }

  t_movimento m;
  /* Scorrendo l'elenco dei movimenti, estraiamo i movimenti */
  for (int i = 0; i < lung; i++) {
    m = elenco[i];

    /* Grazie alla funzione di supporto `numAnno`, che ci converte
       l'anno in intero, controlliamo se l'anno del movimento è quello di
       interesse */
    if (numAnno(m.data) == anno) {

      /* In base al segno del movimento, incrementiamo il campo corretto di
       * uscita/entrata */
      if (m.segno == '+') {
        /* Per accedere al bilancio del mese corretto, utilizziamo la funzione
           di supporto `numMese` che restituisce l'intero del mese
           corrispondente */
        ris[numMese(m.data) - 1].totEntrate += m.importo;
      } else {
        ris[numMese(m.data) - 1].totUscite += m.importo;
      }
    }
  }
}

/* Funzione di supporto che estrae dalla stringa rappresentante la data
   l'anno, e lo restituisce come intero */
int numAnno(char data[]) {
  char year[5] = {data[0], data[1], data[2], data[3], '\0'};
  return atoi(year);
}

/* Funzione di supporto che estrae dalla stringa rappresentante la data
   il mese, e lo restituisce come intero */
int numMese(char data[]) {
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
  // Punto 1
  const char *filename = "banca_estratto.txt";
  char risultato[MAX_LUN];
  dataLimite(filename, -500.00, risultato);
  fprintf(stderr, "%s", risultato);

  // Punto 2
  t_movimento movimenti[MAX_LUN];
  int lung;
  float saldoIniziale;
  leggiEstratto(filename, movimenti, &lung, &saldoIniziale);

  // Punto 3
  bilancioMensile bilanci;
  calcolaBilanciMensili(movimenti, lung, 2019, bilanci);
  for (int i = 0; i < 12; i++) {
    printf("\nMese %d:\n", i);
    printf("Entrate: %f, Uscite: %f", bilanci[i].totEntrate,
           bilanci[i].totUscite);
  }

  return 0;
}
