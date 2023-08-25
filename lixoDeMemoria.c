#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
  setlocale(LC_ALL, "portuguese");
  system("clear");
  int a[100];
  int i;

  for(i = 0; i < 100; i++){
    printf("Vetor [%d] = %d\n", i, a[i]);
  }

  printf("\n\n\n\n\n");

  for(i = 0; i < 100; i++){
    a[i] = 30;
    printf("Vetor [%d] = %d\n", i, a[i]);
  }
}