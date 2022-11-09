# About
Codice sorgente per il corso di Informatica per Aerospaziali.

# Istruzioni
## Compilazione ed esecuzione ##
Per compilare i file eseguire

```bash
gcc -o <nome_eseguibile> <nome_file>.c
```

dove ``<nome_eseguibile>`` è il nome dell'eseguibile (scelto a piacere, a.out di
default) e ``<nome_file>.c`` è il nome del file sorgente.

Nel nostro corso, aderiamo all'ANSI C, ragion per cui aggiungiamo due altri flag in fase di compilazione: `-ansi` e `-pedantic`.

Example
```bash
gcc -ansi -pedantic -o somma.out somma.c
```

Per eseguire, su Linux ``./<nome_eseguibile>``

Example
```bash
./somma.out
```

## Librerie esterne ##
Supponiamo di avere un file esterno `libreria.h` (interfaccia) con corrispondente implementazione `libreria.c`.
Bisogna prima compilare la libreria
```gcc -o libreria.o -c libreria.c```

e quindi compilare il file principale (contenente il `main`), linkando il file di libreria

```gcc somma.out libreria.o```

Informazioni aggiuntive [qui](https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_C_libraries.html)

# A.Y. 2022-23
## Ese. 02
**Intro C e costrutto if**
* [Confronto](src/confronto.c)
* [Media](src/media.c)
* [Pari/Dispari](src/dis_pari.c)
* [Massimo/Minimo tra 3 numeri](src/max_min.c)
* [Intersezione rette](src/intersezione.c)

**Costrutto iterazione while**
* [Confronto ripetuto](src/confronto_ripetuto.c)
* [Media](src/media_var.c)
* [Quadrato](src/quadrato.c)


## Lez. XX
**Esercizi visti a lezione**
* [Numeri triangolari](src/triangolari.c)
* [Conversione in binario invertita](src/binario_inverso.c)
* [Conversione in binario dritta - alternativa 1](src/binario_dritto.c)
* [Conversione in binario dritta - alternativa 2](src/binario_dritto2.c)
* [String2int con getchar](src/getcharex.c)


## Ese. 03
**Costrutti iterazione**
* [Numeri primi](src/primi.c)
* [Fibonacci](src/fibonacci.c)
* [Sequenze pari](src/sequenze.c)
* [Numeri affiatati](src/affiatati.c)

**Array**
* [Coppie](src/coppie.c)
* [Bubble sort](src/bubble_sort.c)

**Vari**
* [Stima pi greco](src/pi_monte_carlo.c)


## Ese. 04
**Array mono/multi-dimensionali, stringhe, struct typedef**
* [Massimo e minimo di un array](src/min_max_array.c)
* [Secondo valore più grande array](src/second_largest_array.c)
* [Massimo e minimo di un array, con struct](src/min_max_array_struct.c)
* [Selection sort](src/selection_sort.c)

* [Stampa tabelline](src/tabelline.c)
* [Operazioni matrici](src/ops_matrici.c)

* [Parole intarsiate1](src/parole_intarsiate1.c)
* [Parole intarsiate2](src/parole_intarsiate2.c)

* [Scadenze](src/scadenze.c)

**Vari**
* [Gioco tris](src/tris.c)
* [Sizeof array](src/array_size.c)

## Ese. 05
**Recap**
* [Stringhe](src/str_ex.c)
* [String smashing](src/string_smashing.c)

**Array mono/multi-dimensionali, stringhe, struct typedef**
* [Insertion sort](src/insertion_sort.c)
* [Grado parola](src/grado_parola.c)
* [Intervallo valori](src/intervallo_valori.c)
* [Moda sequenza](src/moda.c)
* [Pseudo-social](src/social.c)
* [Pseudo-social](src/social2.c)
* [Cartesiano](src/cartesiano.c)
* [Anagrammi](src/anagrammi_wout_functions.c)


## Ese. 06
**Funzioni**
<!-- * [Tuffi](src/tuffi.c) -->
<!-- * [MacLaurin](src/maclaurin.c) -->
<!-- * [Quadrato vettore](src/quadrato-vettore.c) -->
<!-- * [Parole hertziane](src/hertziane.c) -->
<!-- * [Cerniera](src/cerniera.c) -->
<!-- * [Puntatori e const](src/pointers_const.c) -->
<!-- * [Plane manager](src/plane_manager_stack.c) -->
<!-- * [Fight game](src/fight_game.c) -->

## Ese. 07
**File**

# Per categoria
Lista incrementale: ogni sottosezione presuppone la conoscenza della sezione precedente

## Intro
* [Media](src/media.c)
* [Intersezione rette](src/intersezione.c)
* [Confronto](src/confronto.c)

## Costrutti selezione e iterazione
* [Pari/Dispari](src/dis_pari.c)
* [Stampa tabelline](src/tabelline.c)
* [Massimo/Minimo](src/max_min.c)
* [Confronto ripetuto](src/confronto_ripetuto.c)
* [Media](src/media_var.c)
* [Quadrato](src/quadrato.c)
* [Numeri triangolari](src/triangolari.c)
* [Numeri primi](src/primi.c)
* [Fibonacci](src/fibonacci.c)
* [Sequenze pari](src/sequenze.c)
* [Numeri affiatati](src/affiatati.c)
* [Stima pi greco](src/pi_monte_carlo.c)

* [Conversione in binario invertita](src/binario_inverso.c)
* [Conversione in binario dritta - alternativa 1](src/binario_dritto.c)
* [Conversione in binario dritta - alternativa 2](src/binario_dritto2.c)

* [Char2int con getchar](src/getcharex.c)

## Array
### 1D
* [Massimo e minimo di un array](src/min_max_array.c)
* [Secondo valore più grande array](src/second_largest_array.c)
* [Coppie](src/coppie.c)
* [Intervallo valori](src/intervallo_valori.c)
* [Moda sequenza](src/moda.c)

### 2D
* [Gioco tris](src/tris.c)
* [Operazioni matrici](src/ops_matrici.c)
* [Sizeof array](src/array_size.c)
* [Forecast](src/forecast.c)

### Ordinamento
* [Bubble sort](src/bubble_sort.c)
* [Insertion sort](src/insertion_sort.c)
* [Selection sort](src/selection_sort.c)

## Manipolazione stringhe
* [Parole intarsiate](src/parole_intarsiate.c)
* [Parole intarsiate2](src/parole_intarsiate2.c)
* [Conteggio caratteri](src/grado_parola.c)
* [Stringhe](src/str_ex.c)
* [String smashing](src/string_smashing.c)
* [Anagrammi](src/anagrammi_wout_functions.c)

## Struct e typedef
* [Massimo e minimo di un array, con struct](src/min_max_array_struct.c)
* [Scadenze](src/scadenze.c)
* [Pseudo-social](src/social.c)
* [Pseudo-social](src/social2.c)
* [Cartesiano](src/cartesiano.c)

## Funzioni
* [Anagrammi](src/anagrammi.c)
* [Cerniera](src/cerniera.c)
* [Parole hertziane](src/hertziane.c)
* [Stringhe libreria](src/stringhe-libreria.c)
* [Quadrato vettore](src/quadrato-vettore.c)
* [MacLaurin](src/maclaurin.c)

### + Struct
* [Tuffi](src/tuffi.c)
* [Fight game](src/fight_game.c)
* [Plane manager](src/plane_manager_stack.c)
* [Plane manager](src/plane_manager_heap.c)

<!-- ## File -->

<!-- ## Puntatori -->
<!-- * [Stringhe libreria](src/stringhe_libreria_pointers.c) -->
<!-- * [Puntatori e const](src/pointers_const.c) -->
