int main(int argc, char *argv[]) {
  int a = 5, b = 10, c = 15;

  int const *foo; // puntatore a constant int, equivalente a const  * int
  foo = &a;       // assegno a foo l'indirizzo della variabile a

  // *foo = 6;
  /*
   * Statement illegale, non posso cambiare il valore puntato da
   * *foo (cioè a). Il compilatore genera un errore
   */

  foo = &b; // il puntatore stesso però può essere cambiato

  int *const bar = &c; // constant pointer to int
  /*
   * Nota che in questo caso è il puntatore stesso ad essere immutabile. Per
   * questo motivo non possiamo far altro che inizializzarlo al momento della
   * sua dichiarazione
   */

  *bar = 16; // il valore puntato da bar (cioè c) può essere modificato

  // bar = &a;
  /* non è possibile cambiare il valore di bar (ovvero l'indirizzo
     in esso contenuto) */

  int const *const baz = &c; // constant pointer to int
  /*
   * Il più restrittivo, non possiamo cambiare né il puntatore né il valore
   * della cella a cui punta
   */

  return 0;
}
