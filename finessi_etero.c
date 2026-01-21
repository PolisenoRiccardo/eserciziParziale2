#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  printf("1: %s,2: %s", argv[0], argv[1]);
  
  printf("%ld", strlen(argv[1]));
  return 0;
}
