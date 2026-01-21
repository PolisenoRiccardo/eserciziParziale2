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

void printList(nodo* head) {
  printf("Lista: [ ");
  nodo* cursore = head;
  while (cursore != NULL) {
    printf("%d ", cursore->valore); // grazie finessi
    cursore = cursore->next;
  }
  printf("]\n");
}

int listMax(nodo* head) {
  int max = head->valore;
  nodo *cursore = head;
  while (cursore != NULL) {
       if (cursore->valore > max) max = cursore->valore;
       cursore = cursore->next;
  }
  return max;
}

void listDuplica(nodo* head) {
  nodo *cursore = head;
  while (cursore != NULL) {
    nodo* nuovoNodo = creaNodo(cursore->valore); // duplico il nodo
    nuovoNodo->next = cursore->next; // rendiamo il vecchio next, il next di quello nuovo
    cursore->next = nuovoNodo; 
    cursore = nuovoNodo->next;
  }
}

void delete_duplicate(nodo* head) {
  nodo *cursore = head;
  nodo* previous = NULL;
  while (cursore != NULL) {
    nodo* cocco = head;
    while (cocco->next != NULL) {
      if (cursore->valore == cocco->valore && 
          cursore->next != cocco->next) {
        previous->next = cocco->next;
        free(cocco);
      } else {
        previous = cocco;
        cocco = cocco->next;
      }
    }
    cursore = cursore->next;
  }
  return;
}

int main(void) {
  srand(67);
  nodo* tail = creaNodo(rand() % 100);
  nodo* head = tail;
  printf("Lista: [ ");
  for (int i = 0; i < 20; i++) {
    tail = aggiungiNodo(tail, rand()%100);
  }
  nodo* cursore = head;
  while (cursore != NULL) {
    printf("%d ", cursore->valore); // grazie finessi
    cursore = cursore->next;
  }
  printf("]\n");

  printf("Valore head: %d\n", head->valore);
  printf("Valore tail: %d\n", tail->valore);
  
  // Restituire il valore più grande in quella lista. Se la lista è vuota restituire -1
  printf("Val Max: %d\n", listMax(head));

  // Duplicare ogni nodo nella lista inserendo lo stesso nodo subito dopo il nodo originale.
  listDuplica(head);
  printList(head);
  
  // Cancellare la prima istanza di un duplicato nella lista data
  delete_duplicate(head);
  printList(head);

  return 0;
}
