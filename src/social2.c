/*
 * TAGS: struct, strings
 *
 * Variante social.c
 * Chiedere all'utente un nickname e stampare I NICKNAME dei suoi amici.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UTENTI 200
#define MAX_AMICI 200
#define LUN_NOME 50

typedef struct {
  char nome[LUN_NOME], cognome[LUN_NOME];
  char nickname[LUN_NOME];
  unsigned int id;               // identificatore univoco
  unsigned int num_amici;        // numero di amici
  unsigned int amici[MAX_AMICI]; // array con gli id degli amici
} t_utente;

typedef t_utente t_rete_sociale[MAX_UTENTI]; // array di utenti

int main() {
  t_utente utente1 = {.nome = "pippo",
                      .cognome = "pippo",
                      .nickname = "goofy",
                      .id = 1,
                      .num_amici = 2,
                      .amici = {2, 3}};
  t_utente utente2 = {.nome = "paperino",
                      .cognome = "paperino",
                      .nickname = "quack",
                      .id = 2,
                      .num_amici = 2,
                      .amici = {1, 3}};
  t_utente utente3 = {.nome = "topolino",
                      .cognome = "topolino",
                      .nickname = "mickey",
                      .id = 3,
                      .num_amici = 2,
                      .amici = {2, 3}};
  t_rete_sociale rete = {utente1, utente2, utente3};

  char nickname[LUN_NOME];
  unsigned short trovato = 0;
  printf("Inserisci nickname ");
  scanf("%s", nickname);

  // Itero per cercare il nickname inserito dall'utente
  for (int i = 0; i < 3 && !trovato; i++) {
    t_utente utente_cur = rete[i];
    // NOTE Show shortcut here
    if (strcmp(utente_cur.nickname, nickname) == 0) {
      trovato = 1;
      printf("Utente %s trovata\n", nickname);
      // Itero sugli id degli amici
      for (unsigned j = 0; j < utente_cur.num_amici; j++) {
        unsigned short trovato_amico = 0;
        unsigned short id_amico_utente_cur = utente_cur.amici[j];
        /// Itero sulla rete per cercare l'utente con quell'id
        for (unsigned k = 0; k < 3 && !trovato_amico; k++) {
          t_utente utente_cur_interno = rete[k];
          if (utente_cur_interno.id == id_amico_utente_cur) {
            trovato_amico = 1;
            printf("Nickname amico: %s\n", utente_cur_interno.nickname);
          }
        }
      }
    }
  }
  if (!trovato) {
    printf("Utente non trovato");
  }
  printf("\n");
}
