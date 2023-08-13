#include <stdlib.h>
#include <locale.h>
#include <stdio.h>

void limpa(){
  system("clear");
}

int main(){
  int i, Vetor[19];

  for(i = 1; i <= 20 ; i++){
    printf("Digite o %d° número desejado: ", i);
    scanf("%d", &Vetor[i]);
    limpa();
  }

  for(i = 0; i < 20; i++){
    printf("N[%d] = %d\n", i, Vetor[20 - i]);
  }
}