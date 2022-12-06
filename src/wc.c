#include <stdio.h>

// Questa struct sarà utilizzata per ritornare come dati aggregati
// i valori calcolati dalla funzione `wc`
typedef struct ret_s {
  int linecount, wordcount, charcount;
} ret_t;

ret_t wc(const char *filename) {

  // Variabili per il file e il carattere che leggeremo di volta in volta.
  FILE *fp;
  char ch;

  // Flag che useremo per identificare molteplici spazi di seguito,
  // per evitare di incrementare erroneamente due volte il numero di parole.
  int flag = 1;

  // Inizializziamo i contatori della struct a 0
  ret_t ret;
  ret.linecount = 0;
  ret.wordcount = 0;
  ret.charcount = 0;

  // Apertura del file di testo in lettura.
  fp = fopen(filename, "r");
  if (!fp) {
    fprintf(stderr, "\n Errore nellꞌ aprire il file!\n ");
    return ret;
  }

  // Leggiamo il primo carattere.
  ch = getc(fp);

  // Questo ciclo andrà avanti a leggere i caratteri fino a che non raggiungiamo
  // la fine del file.
  while (!feof(fp)) {
    ret.charcount++;
    // Ricordiamoci di reimpostare la flag per contare le parole.
    if (ch != ' ' && ch != '\n') 
      flag = 0;
    
    // Ogni spazio e a capo da luogo ad una nuova parola. Controlliamo, grazie
    // alla flag, di ignorare eventuali spazi molteplici consecutivi.
    /* if ((ch == ' ' || ch == '\n') && !flag) { */
    else if (!flag) {
      ret.wordcount++;
      flag = 1;
      // Ogni carattere a capo incontrato nel file farà incrementare il numero
      // di righe.
    }
    if (ch == '\n')
      ret.linecount++;
    // Lettura del prossimo carattere.
    ch = getc(fp);
  }
  fclose(fp);
  return ret;
}

int main() {
  ret_t risultato;

  // Invochiamo la funzione `wc`, che ci restituisce la struct voluta.
  // Il file `test.txt` deve esistere nella cartella di esecuzione.
  risultato = wc("wc_lorem_ipsum.txt");

  // Stampiamo i valori trovati.
  printf("Lines: %d Words: %d Chars: %d\n", risultato.linecount,
         risultato.wordcount, risultato.charcount);
  return 0;
}
