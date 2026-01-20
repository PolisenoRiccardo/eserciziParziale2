#include <stdio.h>
#include <stdlib.h>

int allocMatrix(int rows, int cols) {
  int** matrice = malloc(rows*sizeof(int*));
  for (int i = 0; i < rows; i++) {
    matrice[i] = malloc(sizeof(int)*cols);
  }
  return matrice;
}

void fillRandomMatrix(int **mat, int rows, int cols, int maxVal) {
  int valore;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      valore = rand() % maxVal + 1;
      mat[i][j] = valore;
    }
  }
}

void printMatrix(int **mat, int rows, int cols) { 
  int valore;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d", mat[i][j]);
    }
  }
}

int main() {

  srand(time(NULL));

  int n; // Numero di righe
  int m; // Numero di colonne
  int c; // Valore Massimo 

  printf("Inserisci il numero di righe: ");
  scanf("%d", &n);
  printf("\nInserisci il numero di colonne: ");
  scanf("%d", &m);
  printf("\nInserisci il numero massimo: ");
  scanf("%d", &c);

  int** matrice1 = allocMatrix(n, m);
  
  fillRandomMatrix(matrice1, n, m, c);
  
  int** matrice = malloc(n*m*c);

  return 0;
}
