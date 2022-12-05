#include <stdio.h>

#define BUF_LEN 1024
int cesare_encrypt(const char *plain, const char *encoded);
/* TODO */
int cesare_decrypt(const char *encoded, const char *plain);

int cesare_encrypt(const char *plain, const char *encoded) {
  int i;
  FILE *fin;
  FILE *fout;

  /* Buffer temporaneo dove leggeremo una porzione del file
   * di input per fare lo shift dei caratteri.
   */
  char buffer[BUF_LEN];

  /* Apertura dei file di input e output */
  if (!(fin = fopen(plain, "r"))) {
    printf("Error opening input file \n");
    return 1;
  }

  if (!(fout = fopen(encoded, "w"))) {
    fclose(fin);
    printf("Error opening output file \n");
    return 1;
  }

  /* Leggiamo una riga dal file di input e  la copiamo nella stringa buffer */
  fgets(buffer, BUF_LEN, fin);
  /* Leggiamo fino a che non raggiungiamo la fine del file. */
  while (!feof(fin)) {
    for (i = 0; buffer[i] != '\0'; i++) {

      /* Controlliamo che il carattere sia un carattere stampabile
         dell'alfabeto */
      if ((buffer[i] >= 'a' && buffer[i] <= 'z') ||
          (buffer[i] >= 'A' && buffer[i] <= 'Z')) {

        /* Effettuiamo lo shift. */
        buffer[i] = buffer[i] + 3;

        /* Se il carattere non è più compreso nell'intervallo dei caratteri
           alfabetici, dobbiamo riportalo nell'intervallo giusto sottraendo
           un numero uguale ai caratteri dell'alfabeto. */
        if (!((buffer[i] >= 'a' && buffer[i] <= 'z') ||
              (buffer[i] >= 'A' && buffer[i] <= 'Z')))
          buffer[i] = buffer[i] + 'a' - 'z';
      }
    }
    /* Scriviamo il buffer sul file di output. */
    fputs(buffer, fout);
    /* ... e sullo standard output */
    fputs(buffer, stdout);

    /* Leggiamo un'altra riga. */
    fgets(buffer, BUF_LEN, fin);
  }
  fclose(fin);
  fclose(fout);
  return 0;
  }

  int main() {

    /* Definiamo i nomi dei file di input e output-> */
    const char *input = "cesare_decrypted.txt";
    const char *output = "cesare_encrypted.txt";

    /* Invochiamo la funzione che effettua la cifratura. */
    cesare_encrypt(input, output);
    /* Fine */
    printf("Output (crittato) salvato su %s\n", output);

    return 0;
  }
