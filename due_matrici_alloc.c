#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** allocMatrix(int rows, int cols) {
  int** matrice = malloc(rows*sizeof(int*));
  for (int i = 0; i < rows; i++) {
    matrice[i] = malloc(sizeof(int)*cols);
  }
  return matrice;
}

void printMatrix(int **mat, int rows, int cols) { 
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf(" %d", mat[i][j]);
    }
    putchar('\n');
  }
}

void freeMatrix(int **mat, int rows) {
  for (int i = 0; i < rows; i++) {
      free(mat[i]);
  }
  free(mat);
}

void fillMatrix(int** mat, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("Inserisci il valore per la cella %d-%d",i, j);
      scanf("%d",&mat[i][j]);
    }
  }
}


void moltMatrix(int** matriceA, int** matriceB,int** matriceC, int r1, int c1, int c2) {
  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c2; j++) {
      matriceC[i][j] = 0;
      for (int k = 0; k < c1; k++) {
         matriceC[i][j] += matriceA[i][k] * matriceB[k][j];
      }
    }
  }
}

int main() {
  int r1;
  int c1;
  int r2;
  int c2;

  printf("A) Inserisci il numero di righe: \n");
  scanf("%d", &r1);
  printf("A) Inserisci il numero di colonne: \n");
  scanf("%d", &c1);
  printf("B) Inserisci il numero di righe: \n");
  scanf("%d", &r2);
  printf("B) Inserisci il numero di colonne: \n");
  scanf("%d", &c2);
  
  if (c1 != r2) {
    printf("Erroraccio mi spiaz.");
    return 65;
  }

  int** matriceA = allocMatrix(r1, c1);
  int** matriceB = allocMatrix(r2, c2);
  int** matriceC = allocMatrix(r1, c2);

  fillMatrix(matriceA, r1, c1);
  fillMatrix(matriceB, r2, c2);

  moltMatrix(matriceA, matriceB, matriceC, r1, c1, c2);


  printf("Matrice A: \n");
  printMatrix(matriceA, r1, c1);
  printf("Matrice B: \n");
  printMatrix(matriceB, r2, c2);
  printf("Matrice C: \n");
  printMatrix(matriceC, r1, c2);
  
  freeMatrix(matriceA, r1);
  freeMatrix(matriceB, r2);
  freeMatrix(matriceC, r1);

  return 0;
}
