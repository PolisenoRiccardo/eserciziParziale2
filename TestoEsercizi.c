

/*
========================================
ESERCIZIO 1: Focus su malloc, calloc, realloc

Scrivere un programma che:

1) Chiede all'utente un numero n (dimensione iniziale di un array di int).
2) Alloca dinamicamente un array A di n interi usando malloc.
   - Chiede all'utente di inserire i n valori.
   - Stampa i valori inseriti.

3) Chiede all'utente un numero m (dimensione di un secondo array).
4) Alloca dinamicamente un array B di m interi usando calloc.
   - Prima di modificarlo:
       * stampa i valori di B per mostrare che sono inizializzati a 0.
   - Poi chiede all'utente di inserire dei valori su alcune posizioni,
     e ristampa B.

5) Chiede all'utente una nuova dimensione k per l'array A.
6) Usa realloc per ridimensionare A da n a k:
   - Se k > n:
       * chiede all'utente di inserire i valori delle nuove posizioni
         (da n a k-1).
   - Stampa il nuovo contenuto di A (di dimensione k).

7) Libera tutta la memoria allocata (A e B).

========================================
OBIETTIVO DIDATTICO

- RECAP:

  malloc:
    * alloca memoria NON inizializzata
    * il contenuto iniziale è indeterminato (non va usato prima di assegnare)

  calloc:
    * alloca memoria e la inizializza a 0 (tutti i bit a 0)
    * per un array di int, inizialmente tutti gli elementi sono 0

  realloc:
    * cambia dimensione di un blocco già allocato (più grande o più piccolo)
    * mantiene il contenuto esistente (fino alla minima dimensione tra vecchia e nuova)
    * può restituire un puntatore diverso da quello originale (non bisogna usare più quello vecchio)

========================================
ESEMPIO (ESECUZIONE TIPO)

  n = 3
  Inserisci A[0], A[1], A[2] = 10, 20, 30
  -> A: 10 20 30

  m = 4
  calloc crea B = [0, 0, 0, 0]
  (stampando si vedono 0 0 0 0)
  poi utente modifica B[1] = 5, B[3] = 8
  -> B: 0 5 0 8

  k = 5  (ingrandiamo A)
  realloc mantiene i primi 3 valori (10,20,30),
  poi l'utente inserisce A[3] = 40, A[4] = 50
  -> A: 10 20 30 40 50

========================================

*/

/*
========================================
ESERCIZIO

Scrivere un programma in C che:

1) Chiede all'utente:
   - un intero n = numero di righe
   - un intero m = numero di colonne
   - un intero c = valore massimo dei numeri casuali

2) Alloca dinamicamente una matrice di interi di dimensioni n x m
   (usare int** e malloc).

3) Riempie la matrice con valori interi casuali compresi tra 1 e c (inclusi).
   Suggerimento: usare la funzione rand() della libreria stdlib
   e l'operatore modulo %, ad esempio:
       valore = rand() % c + 1;

4) Stampa a video la matrice generata.

5) Libera tutta la memoria allocata dinamicamente.

Nota:
   Usare srand(time(NULL)) all'inizio del main per inizializzare
   il generatore di numeri casuali, in modo che ad ogni esecuzione
   i numeri siano diversi.

========================================
STRATEGIA

1) Leggere n, m, c da tastiera.
   - Controllare che n > 0, m > 0, c > 0.
   - In caso contrario, terminare con un messaggio di errore.

2) Allocare dinamicamente la matrice:
   - usare una funzione:
        int** allocMatrix(int rows, int cols);
   - dentro la funzione:
       a) allocare un int** di dimensione rows (vettore di puntatori)
       b) per ogni riga i, allocare un int* di dimensione cols

3) Scrivere una funzione:
       void fillRandomMatrix(int **mat, int rows, int cols, int maxVal);
   - per ogni posizione (i,j):
       mat[i][j] = rand() % maxVal + 1;

4) Scrivere una funzione per stampare la matrice:
       void printMatrix(int **mat, int rows, int cols);

5) Alla fine, usare una funzione:
       void freeMatrix(int **mat, int rows);
   - che libera prima ogni riga e poi il vettore di puntatori.

========================================
ESEMPIO (ESECUZIONE TIPO)

Supponiamo che l'utente inserisca:

   n = 3, m = 4, c = 6

Il programma potrebbe generare (in modo casuale) una matrice come:

   2  6  1  3
   4  5  2  2
   6  1  3  4

Ogni numero è compreso tra 1 e 6 (estremi inclusi).

Ogni volta che si esegue il programma, i numeri possono cambiare
perché sono generati in modo casuale.

========================================
*/

/*
========================================
ESERCIZIO 2: Costruzione matrice casuale m x n (malloc + int**)

Scrivere un programma in C che:

1) Chiede all'utente:
   - un intero n = numero di righe
   - un intero m = numero di colonne
   - un intero c = valore massimo dei numeri casuali

2) Alloca dinamicamente una matrice di interi di dimensioni n x m
   (usare int** e malloc).

3) Riempie la matrice con valori interi casuali compresi tra 1 e c (inclusi).
   Suggerimento: usare la funzione rand() della libreria stdlib
   e l'operatore modulo %, ad esempio:
       valore = rand() % c + 1;

4) Stampa a video la matrice generata.

5) Libera tutta la memoria allocata dinamicamente.

Nota:
   Usare srand(time(NULL)) all'inizio del main per inizializzare
   il generatore di numeri casuali, in modo che ad ogni esecuzione
   i numeri siano diversi.

========================================
STRATEGIA

1) Leggere n, m, c da tastiera.
   - Controllare che n > 0, m > 0, c > 0.
   - In caso contrario, terminare con un messaggio di errore.

2) Allocare dinamicamente la matrice:
   - usare una funzione:
        int** allocMatrix(int rows, int cols);
   - dentro la funzione:
       a) allocare un int** di dimensione rows (vettore di puntatori)
       b) per ogni riga i, allocare un int* di dimensione cols

3) Scrivere una funzione:
       void fillRandomMatrix(int **mat, int rows, int cols, int maxVal);
   - per ogni posizione (i,j):
       mat[i][j] = rand() % maxVal + 1;

4) Scrivere una funzione per stampare la matrice:
       void printMatrix(int **mat, int rows, int cols);

5) Alla fine, usare una funzione:
       void freeMatrix(int **mat, int rows);
   - che libera prima ogni riga e poi il vettore di puntatori.

========================================
ESEMPIO (ESECUZIONE TIPO)

Supponiamo che l'utente inserisca:

   n = 3, m = 4, c = 6

Il programma potrebbe generare (in modo casuale) una matrice come:

   2  6  1  3
   4  5  2  2
   6  1  3  4

Ogni numero è compreso tra 1 e 6 (estremi inclusi).

Ogni volta che si esegue il programma, i numeri possono cambiare
perché sono generati in modo casuale.

========================================
*/

/*
========================================
ESERCIZIO

Scrivere un programma in C che:

1) Chiede all'utente le dimensioni di due matrici:
   - Matrice A di dimensioni r1 x c1
   - Matrice B di dimensioni r2 x c2

2) Alloca dinamicamente le due matrici A e B usando malloc.
   (Si possono usare int** e allocare prima il vettore di puntatori alle righe,
    poi ogni riga separatamente.)

3) Controlla se le matrici sono compatibili per la moltiplicazione:
   la moltiplicazione A (r1 x c1) * B (r2 x c2) è possibile solo se c1 == r2.

4) Se sono compatibili:
   - Alloca dinamicamente anche la matrice risultato C di dimensioni r1 x c2
   - Chiede all'utente gli elementi di A
   - Chiede all'utente gli elementi di B
   - Calcola C = A * B
   - Stampa A, B e C in forma matriciale.

5) Libera tutta la memoria allocata dinamicamente (A, B, C).

========================================
STRATEGIA

1) Leggere da tastiera r1, c1, r2, c2.
2) Controllare se c1 == r2:
   - Se NO -> stampare un messaggio di errore e terminare il programma.
3) Creare una funzione per:
   - allocare una matrice int** della dimensione richiesta
   - liberare la matrice
   - leggere i valori di una matrice da tastiera
   - stampare una matrice
4) Creare una funzione per la moltiplicazione:
   - Parametri: A, r1, c1, B, r2, c2, C
   - Implementare la formula:
       C[i][j] = somma per k da 0 a c1-1 di A[i][k] * B[k][j]
5) Alla fine, ricordarsi di chiamare la funzione che libera la memoria.


/*
========================================
ESERCIZIO 3 : moltiplicazionni matrici (malloc + int**)

Scrivere un programma in C che:

1) Chiede all'utente le dimensioni di due matrici:
   - Matrice A di dimensioni r1 x c1
   - Matrice B di dimensioni r2 x c2

2) Alloca dinamicamente le due matrici A e B usando malloc.
   (Si possono usare int** e allocare prima il vettore di puntatori alle righe,
    poi ogni riga separatamente.)

3) Controlla se le matrici sono compatibili per la moltiplicazione:
   la moltiplicazione A (r1 x c1) * B (r2 x c2) è possibile solo se c1 == r2.

4) Se sono compatibili:
   - Alloca dinamicamente anche la matrice risultato C di dimensioni r1 x c2
   - Chiede all'utente gli elementi di A
   - Chiede all'utente gli elementi di B
   - Calcola C = A * B
   - Stampa A, B e C in forma matriciale.

5) Libera tutta la memoria allocata dinamicamente (A, B, C).

========================================
STRATEGIA

1) Leggere da tastiera r1, c1, r2, c2.
2) Controllare se c1 == r2:
   - Se NO -> stampare un messaggio di errore e terminare il programma.
3) Creare una funzione per:
   - allocare una matrice int** della dimensione richiesta
   - liberare la matrice
   - leggere i valori di una matrice da tastiera
   - stampare una matrice
4) Creare una funzione per la moltiplicazione:
   - Parametri: A, r1, c1, B, r2, c2, C
   - Implementare la formula:
       C[i][j] = somma per k da 0 a c1-1 di A[i][k] * B[k][j]
5) Alla fine, ricordarsi di chiamare la funzione che libera la memoria.

========================================
ESEMPIO (ESECUZIONE TIPO)

Input utente:
   r1 = 2, c1 = 3
   r2 = 3, c2 = 2

   Matrice A (2x3):
     1 2 3
     4 5 6

   Matrice B (3x2):
     7  8
     9 10
    11 12

Risultato C (2x2) = A * B:

  C[0][0] = 1*7 + 2*9 + 3*11  = 58
  C[0][1] = 1*8 + 2*10 + 3*12 = 64
  C[1][0] = 4*7 + 5*9 + 6*11  = 139
  C[1][1] = 4*8 + 5*10 + 6*12 = 154

Output:

   Matrice A:
   1   2   3
   4   5   6

   Matrice B:
   7   8
   9  10
  11  12

   Matrice C = A * B:
   58   64
   139  154

========================================
*/

/*
========================================
GIOCO: CACCIA AL TESORO CON MALLOC

Descrizione:

1) L'utente sceglie:
   - numero di righe (R)
   - numero di colonne (C)
   - numero massimo di tentativi (T)

2) Il programma alloca dinamicamente una matrice (chiamiamola 
"mappa del tesoro" R x C
   (una matrice di int con malloc) che rappresenta le celle in cui abbiamo
   già cercato il tesoro.

3) Il programma sceglie in modo casuale la posizione di un tesoro
   (rTesoro, cTesoro) all'interno della griglia.

4) Ad ogni turno:
   - stampa la griglia con:
        '.' = cella non ancora provata
        'X' = cella già provata (sbagliata)
        (il tesoro non si vede finché non viene trovato)
   - chiede all'utente una coppia (r, c)
     (indice di riga e colonna, partendo da 1)
   - se (r, c) è la posizione del tesoro -> vince il giocatore
   - altrimenti segna la cella come provata e decrementa i tentativi

5) Il gioco termina se:
   - il giocatore trova il tesoro -> messaggio di vittoria
   - finiscono i tentativi -> messaggio di sconfitta
     e si rivela la posizione del tesoro.

6) Alla fine, la memoria dinamica usata per la mappa viene liberata con free.

========================================
STRATEGIA

- Usare una matrice dinamica int**:
    int **mappa;

  dove:
    mappa[i][j] = 0  -> cella mai provata
    mappa[i][j] = 1  -> cella già provata

- Passi principali:

  1) Leggere R, C, T con scanf.
  2) Allocare mappa con una funzione:
         int** allocMatrix(int rows, int cols);
  3) Inizializzare mappa a 0.
  4) Generare posizione tesoro:
         rTesoro = rand() % R;
         cTesoro = rand() % C;
     (indici da 0 a R-1 e 0 a C-1)
  5) Ciclo while con tentativi > 0:
         - stampare griglia (senza mostrare il tesoro)
         - leggere r, c in formato "utente" (da 1 a R, da 1 a C)
         - convertire a indici "interni" (r-1, c-1)
         - controllare se già provata -> avvertire l'utente
         - controllare se è la posizione del tesoro
  6) A fine gioco, usare una funzione freeMatrix per liberare la memoria.

========================================
ESEMPIO (ESECUZIONE TIPO)

Supponiamo:
   R = 3, C = 4, T = 5

La griglia (vista dall'utente) ha celle numerate:

   (1,1) (1,2) (1,3) (1,4)
   (2,1) (2,2) (2,3) (2,4)
   (3,1) (3,2) (3,3) (3,4)

Il tesoro (scelto a caso) è in (2,3).

Possibile partita:

Tentativo 1: utente inserisce (1,1) -> sbaglia
Tentativo 2: (3,4) -> sbaglia
Tentativo 3: (2,3) -> trova il tesoro -> vince

========================================
*/


/*
========================================
ESERCIZIO: liste

Scrivere un programma in C che:

1) Definisce una lista concatenata di interi usando una struct Nodo:
       struct Nodo {
           int valore;
           struct Nodo *next;
       };

2) L'utente inserisce:
   - un intero n = numero di elementi da inserire nella lista
   - poi n interi (anche negativi o zero)

3) Per ogni valore letto, il programma:
   - crea dinamicamente un nuovo nodo (con malloc)
   - inserisce il nodo in coda alla lista (alla fine)

4) A partire dalla lista costruita, il programma deve:
   - stampare tutti gli elementi della lista in ordine
   - calcolare e stampare:
        a) il numero totale di elementi
        b) la somma di tutti gli elementi
        c) il valore massimo presente nella lista

5) Alla fine, il programma deve liberare tutta la memoria
   usata dalla lista (free di tutti i nodi).

========================================
STRATEGIA

1) Definire la struct Nodo:
       typedef struct Nodo {
           int valore;
           struct Nodo *next;
       } Nodo;

2) Tenere un puntatore alla testa della lista:
       Nodo *head = NULL;

   e, per inserire in coda in modo efficiente, mantenere anche
   un puntatore alla coda:
       Nodo *tail = NULL;

3) Scrivere una funzione:
       Nodo* creaNodo(int valore);
   che:
       - usa malloc(sizeof(Nodo))
       - assegna valore al campo valore
       - mette next a NULL
       - restituisce il puntatore al nuovo nodo

4) Inserimento in coda:
   Se la lista è vuota (head == NULL):
       - sia head che tail devono puntare al nuovo nodo
   Altrimenti:
       - tail->next = nuovoNodo;
       - tail = nuovoNodo;

5) Per stampare, sommare e cercare il massimo:
   - usare un puntatore temporaneo p che parte da head
   - scorrere la lista con un while (p != NULL)
   - ad ogni nodo:
       - stampare p->valore
       - aggiornare somma, conteggio, massimo
       - passare al nodo successivo: p = p->next

6) Per liberare la lista:
   - scorrere di nuovo con un puntatore temporaneo,
     salvando il prossimo nodo prima di fare free:
         Nodo *p = head;
         while (p != NULL) {
             Nodo *next = p->next;
             free(p);
             p = next;
         }

========================================
ESEMPIO (ESECUZIONE TIPO)

Input utente:
   n = 5
   valori:  3  -1  7  0  4

Lista: 3 -> -1 -> 7 -> 0 -> 4 -> NULL

Output atteso:
   Lista: 3 -1 7 0 4
   Numero di elementi: 5
   Somma degli elementi: 13
   Valore massimo: 7

========================================
*/