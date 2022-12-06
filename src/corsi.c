/*
 * WIP
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 100
#define MAX_LINE 1000
#define MAX_STUDENT 200
#define MAX_ASSISTENT 2
#define MAX_PROF 2
#define MAX_CORSI 20

typedef struct {
  char nome[MAX_STRING];
  char cognome[MAX_STRING];
} persona_t;

typedef enum {
  PROF,
  ASS,
  STUD,
} tipo_imm_e;

typedef struct {
  persona_t *persona;
  tipo_imm_e tipo;
  char matricola[MAX_STRING];
} immatricolata_t;

typedef struct {
  char id[MAX_STRING];
  char nome[MAX_STRING];

  //
  immatricolata_t *prof[MAX_PROF];
  int n_prof;
  //
  immatricolata_t *assistente[MAX_ASSISTENT];
  int n_assistenti;
  //
  immatricolata_t *studente[MAX_STUDENT];
  int n_studenti;
} corso_t;

typedef struct {
  immatricolata_t *studente;
  unsigned voto;
} voto_t;

corso_t *corsi[MAX_CORSI];
immatricolata_t
    *immatricolati[(MAX_STUDENT + MAX_PROF + MAX_ASSISTENT) * MAX_CORSI];
voto_t *voti[MAX_CORSI * MAX_STUDENT];
int n_corsi, n_voti, n_immatricolati;

tipo_imm_e da_stringa_a_tipo(char *stringa);
void acquisisci_dati(char *filename_corsi, char *filename_immatricolati,
                     char *filename_voti);

corso_t *cerca_corso_per_nome(const char *nome_corso);
corso_t *cerca_corso_per_id(const char *id);
immatricolata_t *cerca_immatricolata_per_matricola(const char *matricola);

void stampa_dettagli_corso(const corso_t *corso);
void stampa_media_corso(const corso_t *corso);

int main() {
  acquisisci_dati("corsi_data.txt", "corsi_immatricolati.txt",
                  "corsi_voti.txt");

  corso_t *corso = cerca_corso_per_nome("Informatica per Aerospaziali");
  stampa_media_corso(corso);

  return 0;
}

tipo_imm_e da_stringa_a_tipo(char *stringa) {
  if (strcmp(stringa, "prof") == 0) {
    return PROF;
  } else if (strcmp(stringa, "ass") == 0) {
    return ASS;
  } else if (strcmp(stringa, "studente") == 0) {
    return STUD;
  } else {
    fprintf(stderr, "Erorre conversione stringa->tipo\n");
    exit(-1);
  }
}

void acquisisci_dati_immatricolati(char *filename_immatricolati) {
  FILE *fp_imm = fopen(filename_immatricolati, "r");
  char buffer[MAX_LINE];
  while (fgets(buffer, strlen(buffer), fp_imm)) {
    char tipo[MAX_STRING], cognome[MAX_STRING], nome[MAX_STRING],
        matricola[MAX_STRING];
    immatricolata_t *imm = (immatricolata_t *)malloc(sizeof(immatricolata_t));
    persona_t *persona = (persona_t *)malloc(sizeof(persona_t));
    sscanf(buffer, "%s %s %s %s\n", matricola, tipo, cognome, nome);
    strcpy(imm->matricola, matricola);
    strcpy(persona->cognome, cognome);
    strcpy(persona->nome, nome);
    imm->persona = persona;
    imm->tipo = da_stringa_a_tipo(tipo);
  }
}

corso_t *cerca_corso_per_id(const char *id) {
  for (int i = 0; i < n_corsi; i++) {
    if (strcmp(corsi[i]->id, id)) {
      return corsi[i];
    }
  }
  return NULL;
}
immatricolata_t *cerca_immatricolata_per_matricola(const char *matricola) {

  for (int i = 0; i < n_immatricolati; i++) {
    if (strcmp(immatricolati[i]->matricola, matricola)) {
      return immatricolati[i];
    }
  }
  return NULL;
}

void acquisisci_dati_corsi(char *filename_corsi) {
  FILE *fp = fopen(filename_corsi, "r");
  char buffer[MAX_LINE];
  int intestazione = 0;
  corso_t *corso;
  while (fgets(buffer, strlen(buffer), fp)) {
    if (strcmp(buffer, "****") == 0) {
      // nuovo corso
      corso = (corso_t *)malloc(sizeof(corso_t));
      // alla prossima iterazione ho una intestazione
      intestazione = 1;
      continue;
    }
    if (intestazione) {
      sscanf(buffer, "%s %s\n", corso->nome, corso->id);
      intestazione = 0;
      continue;
    }
    char ruolo[MAX_STRING], matricola[MAX_STRING];
    sscanf(buffer, "%s %s\n", ruolo, matricola);
    if (strcmp(ruolo, "prof")) {
      immatricolata_t *prof = cerca_immatricolata_per_matricola(matricola);
      corso->prof[corso->n_prof] = prof;
      corso->n_prof++;
    } else if (strcmp(ruolo, "ass")) {
      ;
    } else {
      // error
      ;
    }
  }
}

void acquisisci_dati_voti(char *filename_voti) {}

void acquisisci_dati(char *filename_corsi, char *filename_immatricolati,
                     char *filename_voti) {

  acquisisci_dati_immatricolati(filename_immatricolati);
  acquisisci_dati_corsi(filename_corsi);
  acquisisci_dati_voti(filename_voti);
}
