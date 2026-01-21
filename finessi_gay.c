#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define lunghezza 20 

enum weekdays {mon, tue, wed, thur, fri, sat, sun, errore};

typedef struct Student {
    char Nome[lunghezza];
    int Matricola;
    int VotoLab;
    enum weekdays GiornoLab;
} Student;

// Funzione per convertire la stringa argv in enum
enum weekdays stringToEnum(char *str) {
    for(int i = 0; str[i]; i++) str[i] = tolower(str[i]); // Rende tutto minuscolo
    
    if (strcmp(str, "mon") == 0 || strcmp(str, "monday") == 0) return mon;
    if (strcmp(str, "tue") == 0 || strcmp(str, "tuesday") == 0) return tue;
    if (strcmp(str, "wed") == 0 || strcmp(str, "wednesday") == 0) return wed;
    if (strcmp(str, "thur") == 0 || strcmp(str, "thursday") == 0) return thur;
    if (strcmp(str, "fri") == 0 || strcmp(str, "friday") == 0) return fri;
    if (strcmp(str, "sat") == 0 || strcmp(str, "saturday") == 0) return sat;
    if (strcmp(str, "sun") == 0 || strcmp(str, "sunday") == 0) return sun;
    return errore;
}

void stampaStudenti(Student studenti[]) {
  for (int i = 0; i < 2; i++) {
    printf("%s\n", studenti[i].Nome);
    printf("%d\n", studenti[i].Matricola);
    printf("%d\n", studenti[i].VotoLab);
    printf("%d\n", studenti[i].GiornoLab);
  } 

}

int main(int argc, char *argv[]) {
    // Controllo se sono stati passati i 2 argomenti richiesti (+1 per il nome del programma)
    if (argc < 3) {
        printf("Utilizzo: %s <GIORNO> <MIN_VOTO>\n", argv[0]);
        return 1;
    }

    // Leggiamo i parametri da riga di comando
    enum weekdays giornoCercato = stringToEnum(argv[1]);
    int votoMinimo = atoi(argv[2]); // Converte stringa in intero

    if (giornoCercato == errore) {
        printf("Giorno non valido!\n");
        return 1;
    }

    Student studenti[2]; // Ridotto a 2 per brevità nei test
    
    for(int i = 0; i < 2; i++) {
        printf("\n--- Studente %d ---\n", i + 1);
        printf("Nome: ");
        scanf("%s", studenti[i].Nome); // Usiamo scanf per semplicità qui
        printf("Matricola: ");
        scanf("%d", &studenti[i].Matricola);
        printf("Voto: ");
        scanf("%d", &studenti[i].VotoLab);
        printf("Giorno (0-6, dove 0=Mon): ");
        scanf("%d", (int*)&studenti[i].GiornoLab);
    }

    // Filtriamo i risultati in base ai parametri argv
    printf("\n--- Risultati Filtro (Giorno: %s, Voto Min: %d) ---\n", argv[1], votoMinimo);
    for(int i = 0; i < 3; i++) {
        if (studenti[i].GiornoLab == giornoCercato && studenti[i].VotoLab >= votoMinimo) {
            printf("Ammesso: %s (Voto: %d)\n", studenti[i].Nome, studenti[i].VotoLab);
        }
    }

    stampaStudenti(studenti);

    while (getchar() != '\n');

    char studente1[20];
    printf("Inserisci lo studente:");
    fgets(studente1, sizeof(studente1), stdin);
    printf("Nome Studente: %s, Lunghezza Pene: %d", studente1, strlen(studente1)-1);
   

    return 0;
}
