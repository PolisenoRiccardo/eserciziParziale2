#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
  int valore;
  struct Nodo* next;
} nodo;

nodo* creaNodo(int valore) {
  nodo* nuovoNodo = malloc(sizeof(nodo));
  nuovoNodo->valore = valore; // grazie loto
  nuovoNodo->next = NULL;
  return nuovoNodo;
}

nodo* aggiungiNodo(nodo* tail, int val) {
  nodo* nuovoNodo = creaNodo(val);
  if (tail != NULL) tail->next = nuovoNodo;
  return nuovoNodo;
}

int main(void) {
  srand(67);
  nodo* tail = creaNodo(rand() % 10);
  printf("Lista: [ ");
  for (int i = 0; i < 20; i++) {
    tail = aggiungiNodo(tail, rand()%10);
  }
  
  printf("]\n");
  
  // Restituire il valore più grande in quella lista. Se la lista è vuota restituire -1
   

  return 0;
}
