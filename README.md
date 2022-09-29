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

Example
```bash
gcc -o somma.out somma.c
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
## Lez. 02
**Intro C e costrutto if**

* [Confronto](src/confronto.c)
* [Media](src/media.c)
* [Pari/Dispari](src/dis_pari.c)
* [Massimo/Minimo](src/max_min.c)
* [Intersezione rette](src/intersezione.c)

## Lez. 03
**Costrutti iterazione**
<!-- * [Confronto ripetuto](src/confronto_ripetuto.c) -->
<!-- * [Media](src/media_var.c) -->
<!-- * [Fibonacci](src/fibonacci.c) -->
<!-- * [Numeri primi](src/primi.c) -->
<!-- * [Conversione in binario invertita](src/binario_inverso.c) -->
<!-- * [Conversione in binario dritta - alternativa 1](src/binario_dritto.c) -->
<!-- * [Conversione in binario dritta - alternativa 2](src/binario_dritto2.c) -->

**Altri**
<!-- * [Quadrato](src/quadrato.c) -->
<!-- * [Numeri triangolari](src/triangolari.c) -->

## Lez. 04
**Stringhe, array, struct, typedef**
<!-- * [String2int con getchar](src/getchar_ex.c) -->
<!-- * [Sequenze pari](src/sequenze.c) -->
<!-- * [Numeri affiatati](src/affiatati.c) -->
<!-- * [Stima pi greco ](src/pi_monte_carlo.c) -->
<!-- * [Bubble sort](src/bubble_sort.c) -->

<!-- **Altri** -->
<!-- * [Insertion sort](src/insertion_sort.c) -->
<!-- * [Selection sort](src/selection_sort.c) -->
<!-- * [Stampa tabelline](src/tabelline.c) -->
<!-- * [Gioco tris](src/tris.c) -->


## Lez. 05
**Stringhe, array, struct, typedef**
<!-- * [Parole intarsiate](src/parole_intarsiate.c) -->
<!-- * [Parole intarsiate2](src/parole_intarsiate2.c) -->
<!-- * [Coppie](src/coppie.c) -->
<!-- * [Conteggio caratteri](src/conteggio_caratteri.c) -->
<!-- * [Intervallo valori](src/intervallo_valori.c) -->
<!-- * [Moda sequenza](src/moda.c) -->
<!-- * [Anagrammi](src/anagrammi.c) -->

## Lez. 06
**Funzioni**
<!-- * [MacLaurin](src/maclaurin.c) -->
<!-- * [Quadrato vettore](src/quadrato-vettore.c) -->
<!-- * [Parole hertziane](src/hertziane.c) -->
<!-- **Struct** -->
<!-- * [Scadenze](src/scadenze.c) -->
<!-- * [Puntatori e const](src/pointers_const.c) -->
<!-- * [Fight game](src/fight_game.c) -->
<!-- a -->
<!-- * [Stringhe libreria](src/stringhe-libreria.c) -->
<!-- * [Cerniera](src/cerniera.c) -->
<!-- * [Plane manager](src/plane_manager_stack.c) -->
<!-- <\!-- * [Tuffi](src/tuffi.c) -\-> -->

## Lez. 07
**File**

# Per categoria
Lista incrementale: ogni sottosezione presuppone la conoscenza della sezione precedente

## Intro
* [Media](src/media.c)
* [Intersezione rette](src/intersezione.c)

## Costrutti selezione e iterazione
* [Confronto](src/confronto.c)
* [Pari/Dispari](src/dis_pari.c)
* [Massimo/Minimo](src/max_min.c)

## Vettori
* [Parole intarsiate](src/parole_intarsiate.c)
* [Parole intarsiate2](src/parole_intarsiate2.c)
* [Coppie](src/coppie.c)
* [Conteggio caratteri](src/conteggio_caratteri.c)
* [Intervallo valori](src/intervallo_valori.c)
* [Moda sequenza](src/moda.c)
## Manipolazione stringhe
<!-- * [Stringhe libreria](src/stringhe-libreria.c) -->
* [Parole intarsiate](src/parole_intarsiate.c)
* [Parole intarsiate2](src/parole_intarsiate2.c)
* [Conteggio caratteri](src/conteggio_caratteri.c)
## Puntatori
* [Puntatori e const](src/pointers_const.c)
* [Stringhe libreria](src/stringhe-libreria.c)
## Struct e typedef
* [Scadenze](src/scadenze.c)
* [Tuffi](src/tuffi.c)
* [Fight game](src/fight_game.c)
* [Plane manager](src/plane_manager.c)
## Funzioni
* [Anagrammi](src/anagrammi.c)
* [Parole hertziane](src/hertziane.c)
* [Stringhe libreria](src/stringhe-libreria.c)
* [Quadrato vettore](src/quadrato-vettore.c)
* [MacLaurin](src/maclaurin.c)
## File

