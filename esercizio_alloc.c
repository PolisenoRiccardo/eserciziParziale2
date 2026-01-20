#include <stdio.h>
#include <stdlib.h>

int main() {
// Dimensione array A n
  int n;
  printf("Inserisci la dimensione dell'array A: ");
  scanf("%d", &n);
  int * arrayA = malloc(sizeof(int)*n);
  for (int i = 0; i < n; i++) {
    int newVal;
    printf("Inserisci il %d-esimo valore", i);
    scanf("%d", &newVal);
    arrayA[i] = newVal;
  }

  printf("Array A: [");
  for (int i = 0; i < n; i++) {
    printf(" %d", arrayA[i]);
  }
  printf(" ]\n");

  // Dimensione array B m
  int m;
  printf("Inserisci la dimensione dell'array B: ");
  scanf("%d", &m);
  int * arrayB = calloc(m, sizeof(int));
  printf("Array B: [");
  for (int i = 0; i < m; i++) {
    printf(" %d", arrayB[i]);
  }
  printf(" ]");

  putchar('\n');
  printf("Inserisci un valore: ");
  scanf("%d", &arrayB[0]);
  putchar('\n');
  printf("Inserisci un altro valore: ");
  scanf("%d", &arrayB[2]);
  putchar('\n');
  printf("Array B: [");
  for (int i = 0; i < m; i++) {
    printf(" %d", arrayB[i]);
  }
  printf(" ]\n");
  
  // Il ritorno dell'array A e k
  int k; // Nuova dimensione dell'array
  printf("Inserisci una nuova dimesione per l'Array A: ");
  scanf("%d", &k);
  arrayA = realloc(arrayA ,sizeof(int)*k);
  if (k > n) {
    for (int i = n; i < k-1; i++) {
      int newVal;
      printf("Inserisci il %d-esimo valore", i);
      scanf("%d", &newVal);
      arrayA[i] = newVal;
    }
  }
    
  printf("Array A: [");
  for (int i = 0; i < k; i++) {
    printf(" %d", arrayA[i]);
  }
  printf(" ]\n");
  
  free(arrayA);
  free(arrayB);

  return 0;
}
