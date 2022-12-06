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

typedef struct nodo_float_s {
  float valore;
  struct nodo_float_s *next;
} nodo_float_t;
typedef nodo_float_t *lista_float;

lista_prodotti_t leggi_da_file(char *nome_file) {
  lista_prodotti_t L = NULL;
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
    aux = (nodo_prodotto_t *)malloc(sizeof(nodo_prodotto_t));
    aux->prodotto = p;
    aux->next = L;
    L = aux;
  }
  fclose(fp);
  return L;
}

lista_prodotti_t inserisci_in_fondo(lista_prodotti_t testa, prodotto_t p) {
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

lista_prodotti_t leggi_da_file2(char *nome_file) {
  lista_prodotti_t L = NULL;
  FILE *fp = fopen(nome_file, "r");
  if (fp == NULL)
    fprintf(stderr, "Errore nell'apertura del file\n");
  else {
    prodotto_t p;
    nodo_prodotto_t *aux;
    while (!feof(fp)) {
      fscanf(fp, "%u %s %f\n", &p.codice, p.nome, &p.prezzo);
      L = inserisci_in_fondo(L, p);
    }
    fclose(fp);
  }
  return L;
}

void stampa_lista_prodotti_t(lista_prodotti_t L) {
  lista_prodotti_t ptr_corrente = L;
  while (ptr_corrente != NULL) {
    printf("Nodo codice: %d nome: %s prezzo: %f\n",
           ptr_corrente->prodotto.codice, ptr_corrente->prodotto.nome,
           ptr_corrente->prodotto.prezzo);
    ptr_corrente = ptr_corrente->next;
  }
}

void stampa_lista_float(lista_float L) {
  lista_float ptr_corrente = L;
  while (ptr_corrente != NULL) {
    printf("Nodo codice: %f\n", ptr_corrente->valore);
    ptr_corrente = ptr_corrente->next;
  }
}

lista_prodotti_t elimina_prodotti(lista_prodotti_t L, float prezzo_minimo) {
  lista_prodotti_t ptr_precedente = NULL, ptr_corrente = L, testa = L, temp;
  while (ptr_corrente != NULL) {
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

lista_float somma(lista_prodotti_t L) {
  lista_float testaListaFloat = NULL;
  nodo_float_t *ptr = NULL, *aux;
  float totaleCorrente = 0.0;
  while (L != NULL) {
    totaleCorrente += L->prodotto.prezzo;
    aux = (nodo_float_t *)malloc(sizeof(nodo_float_t));
    aux->valore = totaleCorrente;
    aux->next = NULL;
    if (ptr == NULL) {
      ptr = aux;
      testaListaFloat = aux;
    } else {
      ptr->next = aux;
      ptr = ptr->next;
    }
    L = L->next;
  }
  return testaListaFloat;
}

int main() {
  printf("\nLeggi 1 e stampa\n");
  lista_prodotti_t L = leggi_da_file("lista_prodotti_data.txt");
  stampa_lista_prodotti_t(L);

  printf("\nLeggi 2 e stampa\n");
  lista_prodotti_t L2 = leggi_da_file2("lista_prodotti_data.txt");
  stampa_lista_prodotti_t(L2);

  printf("\nElimina prodotto con prezzo inferiore a 4\n");
  L = elimina_prodotti(L, 4);
  stampa_lista_prodotti_t(L);

  printf("\nSomma prodotti\n");
  lista_float L3 = somma(L);
  stampa_lista_float(L3);

  return 0;
}
