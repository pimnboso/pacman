#include <stdlib.h>
#include <locale.h>
#include <stdio.h>

void limpa() {
    system("clear");
}

int main(){
  int i;
  float J[100], A[100];

  for(i = 0; i < 100; i++){
    printf("Digite o %d° número: ", i+1);
    scanf("%f", &A[i]);
    limpa();
  }

  for(i = 0; i < 100; i++){
    if(A[i] < 10){
      J[i] = A[i];
    }
  }

  for(i = 0; i < 100; i++){
    if(J[i] != 0){
    printf("N[%d] = %2.f\n", i, J[i]);
    }
  }
}