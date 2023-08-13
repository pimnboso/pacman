#include <stdlib.h>
#include <locale.h>
#include <stdio.h>

void limpa() {
    system("clear");
}

int main(){
  int i, X[20];
  setlocale(LC_ALL, "portuguese");

  for(i = 0; i < 20; i++){
  printf("Digite o %d° número: ", i);
  scanf("%d", &X[i]);
  limpa();
  }
  
  for(i = 0; i < 20; i++){
    if(X[i] == 0){
      X[i] = 1;
    }

    if(X[i] < 0){
      X[i] = 1;
    }
    printf("X[%d] = %d\n", i, X[i]);
  }
}