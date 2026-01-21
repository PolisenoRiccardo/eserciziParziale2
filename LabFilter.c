#include <stdio.h>
#include <stdlib.h>

#define lunghezza 30
enum weekdays {MON, TUE, WED, THU, FRI, SAT, SUN};


struct student {
  char nome[lunghezza];
  int matricola;
  int voto_lab;
  enum weekdays giorno_lab;
};

int main(int argc, char *argv[]) {
  struct student studenti[2];

  

  for (int i = 0; i < 2; i++) {
    printf("Inserisci il nome: \n");
    fgets(studenti[i].nome, lunghezza-1, stdin);
    printf("Inserisci la matricola: \n");
    scanf("%d", studenti[i].matricola);
    printf("Inserisci il voto: \n");
    scanf("%d", studenti[i].voto_lab);
    printf("Inserisci il giorno del laboratorio: \n");
    scanf("%d", studenti[i].giorno_lab);
  }

  return 0;
}
