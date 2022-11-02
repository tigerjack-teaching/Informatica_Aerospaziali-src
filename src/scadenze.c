/*
 * TAGS: string, struct, enum
 *
 * Gestione del frigorifero
 */
#include <stdio.h>
#define LUN_MAX 100  /* lunghezza nome */
#define N_PROD_MAX 2 /* numero prodotti */

struct Data {
  unsigned short giorno;
  unsigned short mese;
  unsigned short anno;
};

struct Prodotto {
  char nome[LUN_MAX];
  struct Data scadenza;
};

enum Flag { NON_SCADUTO, SCADUTO, SCADE_OGGI };

int main() {
  struct Prodotto frigo[N_PROD_MAX];
  struct Data controllo;
  int i;
  enum Flag flag;
  char c;

  /* Acquisiamo i prodotti. */
  for (i = 0; i < N_PROD_MAX; i++) {
    printf("\nInserisci il nome del prodotto: ");
    scanf("%s", frigo[i].nome);
    do {
      /* Acquisiamo la data. */
      printf("\nInserisci la data di scadenza (futura) di %s (GG-MM-AAAA) ",
             frigo[i].nome);
      scanf("%hu-%hu-%hu", &frigo[i].scadenza.giorno, &frigo[i].scadenza.mese,
            &frigo[i].scadenza.anno);
      printf("Inserito %s, scadenza %hu-%hu-%hu", frigo[i].nome,
             frigo[i].scadenza.giorno, frigo[i].scadenza.mese,
             frigo[i].scadenza.anno);

    } while (frigo[i].scadenza.giorno <= 0 || frigo[i].scadenza.giorno > 31 ||
             frigo[i].scadenza.mese <= 0 || frigo[i].scadenza.mese > 12 ||
             frigo[i].scadenza.anno < 2022);
    /* Consumiamo eventuali altri char rimanenti */
    do {
      c = getchar();
    } while (c != EOF && c != '\n'); 
  }

  /* Acquisiamo la data per la quale vogliamo controllare la scadenza. */
  do {
    printf("\nInserisci la data a cui controllare la scadenza ");
    scanf("%hu-%hu-%hu [GG-MM-AAAA]", &controllo.giorno, &controllo.mese, &controllo.anno);
  } while (controllo.giorno <= 0 || controllo.giorno > 31 ||
           controllo.mese <= 0 || controllo.mese > 12);

  /* Effettuiamo il controllo per ogni prodotto che abbiamo salvato. */
  for (i = 0; i < N_PROD_MAX; ++i) {
    /* flag -1 -> scaduto
    flag 1 -> buono
    flag 0 -> scade oggi */
    if (frigo[i].scadenza.anno > controllo.anno)
      flag = NON_SCADUTO;
    else if (frigo[i].scadenza.anno < controllo.anno)
      flag = SCADUTO;
    else if (frigo[i].scadenza.mese > controllo.mese)
      flag = NON_SCADUTO;
    else if (frigo[i].scadenza.mese < controllo.mese)
      flag = SCADUTO;
    else if (frigo[i].scadenza.giorno > controllo.giorno)
      flag = NON_SCADUTO;
    else if (frigo[i].scadenza.giorno < controllo.giorno)
      flag = SCADUTO;
    else
      flag = SCADE_OGGI;

    /* Utilizzando lo stato della flag, stampiamo l'informazione sulla scadenza.
     */
    switch (flag) {
    case SCADUTO:
      printf("\nIl prodotto %s sará scaduto alla data %hu-%hu-%hu.",
             frigo[i].nome, controllo.giorno, controllo.mese, controllo.anno);
      break;
    case NON_SCADUTO:
      printf("\nIl prodotto %s non sará scaduto alla data %hu-%hu-%hu.",
             frigo[i].nome, controllo.giorno, controllo.mese, controllo.anno);
      break;
    case SCADE_OGGI:
      printf("\nIl prodotto %s scadrà esattamente in quella data.",
             frigo[i].nome);
      break;
    }
  }

  return 0;
}
