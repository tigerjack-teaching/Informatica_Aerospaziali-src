/*
 * WIP
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 100
#define MAX_LINE 500
#define MAX_STUDENT 200
#define MAX_ASSIST 3
#define MAX_STRUTTURAT 2
#define MAX_CORSI 10

typedef struct {
  char nome[MAX_STRING];
  char cognome[MAX_STRING];
} persona_t;

typedef enum {
  STRUTTURAT,
  RICERC,
  STUD,
} tipo_immatricolata_e;

typedef struct {
  persona_t *persona;
  tipo_immatricolata_e tipo;
  char matricola[MAX_STRING];
} immatricolata_t;

typedef struct {
  char id[MAX_STRING];
  char nome[MAX_STRING];

  //
  immatricolata_t *prof[MAX_STRUTTURAT];
  int n_prof;
  //
  immatricolata_t *assistente[MAX_ASSIST];
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
    *immatricolati[(MAX_STUDENT + MAX_STRUTTURAT + MAX_ASSIST) * MAX_CORSI];
voto_t *voti[MAX_CORSI * MAX_STUDENT];
int n_corsi, n_voti, n_immatricolati;

tipo_immatricolata_e da_stringa_a_tipo(char *stringa);
void acquisisci_dati(char *filename_corsi, char *filename_immatricolati,
                     char *filename_voti);

corso_t *cerca_corso_per_nome(const char *nome_corso);
corso_t *cerca_corso_per_id(const char *id);
immatricolata_t *cerca_immatricolata_per_matricola(const char *matricola);

void stampa_immatricolati();
void stampa_corsi();
void stampa_dettagli_corso(const corso_t *corso);
void stampa_voti();
void stampa_media_corso(const corso_t *corso);

int main() {
  printf("Acquisisco dati file\n");
  acquisisci_dati("corsi_data.txt", "corsi_immatricolati.txt",
                  "corsi_voti.txt");
  stampa_immatricolati();
  stampa_corsi();

  /* TODO */
  /* stampa_voti(); */
  corso_t *corso = cerca_corso_per_nome("Fisica1");
  if (corso == NULL) {
    printf("Corso non trovato\n");
    return 0;
  }
  stampa_dettagli_corso(corso);

  /* TODO */
  /* stampa_media_corso(corso); */

  return 0;
}

tipo_immatricolata_e da_stringa_a_tipo(char *stringa) {
  if (strcmp(stringa, "strut") == 0) {
    return STRUTTURAT;
  } else if (strcmp(stringa, "ricerc") == 0) {
    return RICERC;
  } else if (strcmp(stringa, "studente") == 0) {
    return STUD;
  } else {
    fprintf(stderr, "Errore conversione stringa->tipo per %s\n", stringa);
    exit(-1);
  }
}

void stampa_immatricolati() {
  for (int i = 0; i < n_immatricolati; i++) {
    printf("%s %s %s\n", immatricolati[i]->matricola,
           immatricolati[i]->persona->cognome, immatricolati[i]->persona->nome);
  }
}

void stampa_corsi() {
  for (int i = 0; i < n_corsi; i++) {
    stampa_dettagli_corso(corsi[i]);
  }
}

void stampa_dettagli_corso(const corso_t *corso) {
  fprintf(stdout,
          "Corso {nome: %s, id: %s, n_prof: %d, n_assistenti: %d, "
          "n_studenti: %d}\n",
          corso->nome, corso->id, corso->n_prof, corso->n_assistenti,
          corso->n_studenti);
}

void acquisisci_dati_immatricolati(char *filename_immatricolati) {
  FILE *fp_imm = fopen(filename_immatricolati, "r");
  char buffer[MAX_LINE];
  char tipo[MAX_STRING], cognome[MAX_STRING], nome[MAX_STRING],
      matricola[MAX_STRING];

  while (fgets(buffer, MAX_LINE, fp_imm)) {
    int ret = sscanf(buffer, "%s %s %s %s\n", matricola, tipo, cognome, nome);
    /* printf("%d %s %s %s %s\n", ret, matricola, tipo, cognome, nome); */

    immatricolata_t *imm = (immatricolata_t *)malloc(sizeof(immatricolata_t));
    persona_t *persona = (persona_t *)malloc(sizeof(persona_t));

    strcpy(imm->matricola, matricola);
    strcpy(persona->cognome, cognome);
    strcpy(persona->nome, nome);
    imm->persona = persona;
    imm->tipo = da_stringa_a_tipo(tipo);
    immatricolati[n_immatricolati++] = imm;
  }
  fclose(fp_imm);
}

corso_t *cerca_corso_per_id(const char *id) {
  for (int i = 0; i < n_corsi; i++) {
    if (strcmp(corsi[i]->id, id)) {
      return corsi[i];
    }
  }
  return NULL;
}

corso_t *cerca_corso_per_nome(const char *nome) {
  for (int i = 0; i < n_corsi; i++) {
    if (!strcmp(corsi[i]->nome, nome)) {
      return corsi[i];
    }
  }
  return NULL;
}

immatricolata_t *cerca_immatricolata_per_matricola(const char *matricola) {
  for (int i = 0; i < n_immatricolati; i++) {
    if (!strcmp(immatricolati[i]->matricola, matricola)) {
      return immatricolati[i];
    }
  }
  return NULL;
}

void acquisisci_dati_corsi(char *filename_corsi) {
  FILE *fp = fopen(filename_corsi, "r");
  if (!fp) {
    fprintf(stderr, "Errore apertura file %s\n", filename_corsi);
    exit(-1);
  }
  char buffer[MAX_LINE];
  char ruolo[MAX_STRING], matricola[MAX_STRING];
  int intestazione = 0;
  corso_t *corso;
  immatricolata_t *imm;
  int ret;

  while (fgets(buffer, MAX_LINE, fp)) {
    /* printf("%d %s", intestazione, buffer); */
    if (strcmp(buffer, "****\n") == 0) {
      // nuovo corso
      corso = (corso_t *)malloc(sizeof(corso_t));
      corsi[n_corsi++] = corso;
      // alla prossima iterazione ho una intestazione
      intestazione = 1;
      continue;
    }
    if (intestazione) {
      intestazione = 0;
      ret = sscanf(buffer, "%s %s\n", corso->nome, corso->id);
      if (ret != 2) {
        fprintf(stderr, "Errore scanf intestazione %d\n", ret);
        exit(-1);
      }
      continue;
    }
    ret = sscanf(buffer, "%s %s\n", ruolo, matricola);
    if (ret != 2) {
      fprintf(stderr, "Errore scanf intestazione %d\n", ret);
      exit(-1);
    }
    imm = cerca_immatricolata_per_matricola(matricola);
    if (!imm) {
      fprintf(stderr, "Persona immatricolata con matricola %s non trovata\n",
              matricola);
      exit(-1);
    }
    if (!strcmp(ruolo, "titolare")) {
      corso->prof[corso->n_prof++] = imm;
    } else if (!strcmp(ruolo, "assist")) {
      corso->assistente[corso->n_assistenti++] = imm;
    } else if (!strcmp(ruolo, "studente")) {
      corso->studente[corso->n_studenti++] = imm;
    } else {
      fprintf(stderr, "Errore tipo %s\n", ruolo);
      exit(-1);
    }
  }
  fclose(fp);
}

void acquisisci_dati_voti(char *filename_voti) {}

void acquisisci_dati(char *filename_corsi, char *filename_immatricolati,
                     char *filename_voti) {

  acquisisci_dati_immatricolati(filename_immatricolati);
  acquisisci_dati_corsi(filename_corsi);
  acquisisci_dati_voti(filename_voti);
}
