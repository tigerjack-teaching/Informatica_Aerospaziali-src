#include <stdio.h>
#include <stdlib.h>

#define MAX_NOME 25
#define MAX_LINE_LEN 200

typedef struct {
  unsigned codice;
  char nome[MAX_NOME + 1];
  float prezzo;
} prodotto_t;

typedef struct nodo_prodotto_s {
  prodotto_t prodotto;
  struct nodo_prodotto_s *next;
} nodo_prodotto_t;
typedef nodo_prodotto_t *lista_prodotti_t;

lista_prodotti_t inserisci_in_testa(lista_prodotti_t testa, prodotto_t p) {
  /*
   * Inserisce in testa, restituendo la testa della lista
   */
  lista_prodotti_t punt, cur = testa;

  punt = (nodo_prodotto_t *)malloc(sizeof(nodo_prodotto_t));
  punt->prodotto = p;
  punt->next = testa;

  return punt;
}

lista_prodotti_t inserisci_in_fondo(lista_prodotti_t testa, prodotto_t p) {
  /*
   * Inserisce in fondo, restituendo la testa della lista
   */
  lista_prodotti_t punt, cur = testa;

  punt = (nodo_prodotto_t *)malloc(sizeof(nodo_prodotto_t));
  punt->next = NULL;
  punt->prodotto = p;

  if (testa == NULL) {
    return punt;
  }

  while (cur->next != NULL) {
    cur = cur->next;
  }
  cur->next = punt;

  return testa;
}

lista_prodotti_t leggi_da_file(char *nome_file, int in_testa) {
  lista_prodotti_t testa = NULL;
  FILE *fp = fopen(nome_file, "r");
  if (!fp) {
    fprintf(stderr, "Errore nell'apertura del file\n");
    exit(-1);
  }
  prodotto_t p;
  nodo_prodotto_t *aux;
  char buffer[MAX_LINE_LEN];
  while (fgets(buffer, sizeof(buffer), fp)) {
    sscanf(buffer, "%u %s %f\n", &p.codice, p.nome, &p.prezzo);
    if (in_testa) {
      testa = inserisci_in_testa(testa, p);
    } else {
      testa = inserisci_in_fondo(testa, p);
    }
  }
  fclose(fp);
  return testa;
}

void stampa_lista_prodotti_t(lista_prodotti_t testa) {
  lista_prodotti_t ptr_corrente = testa;
  while (ptr_corrente) {
    printf("Nodo codice: %d nome: %s prezzo: %f\n",
           ptr_corrente->prodotto.codice, ptr_corrente->prodotto.nome,
           ptr_corrente->prodotto.prezzo);
    ptr_corrente = ptr_corrente->next;
  }
}

lista_prodotti_t elimina_prodotti(lista_prodotti_t testa, float prezzo_minimo) {
  lista_prodotti_t ptr_precedente = NULL, ptr_corrente = testa, temp;
  while (ptr_corrente) {
    if (ptr_corrente->prodotto.prezzo < prezzo_minimo) {
      temp = ptr_corrente;
      if (ptr_precedente == NULL)
        testa = ptr_corrente->next;
      else
        ptr_precedente->next = ptr_corrente->next;
      ptr_corrente = ptr_corrente->next;
      free(temp);
    } else {
      ptr_precedente = ptr_corrente;
      ptr_corrente = ptr_corrente->next;
    }
  }
  return testa;
}

float somma(lista_prodotti_t testa) {
  float totale = 0.0;
  lista_prodotti_t curr = testa;
  while (curr != NULL) {
    totale += testa->prodotto.prezzo;
    curr = curr->next;
  }
  return totale;
}

int main() {
  printf("\nLeggi 1 e stampa\n");
  lista_prodotti_t L = leggi_da_file("lista_prodotti_data.txt", 1);
  stampa_lista_prodotti_t(L);

  printf("\nLeggi 2 e stampa\n");
  lista_prodotti_t L2 = leggi_da_file("lista_prodotti_data.txt", 0);
  stampa_lista_prodotti_t(L2);

  printf("\nElimina prodotto con prezzo inferiore a 4\n");
  L = elimina_prodotti(L, 4);
  stampa_lista_prodotti_t(L);

  printf("\nSomma prodotti %f\n", somma(L));
  return 0;
}
