#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void limpa(){
  system("clear");
}

void main(){
  setlocale(LC_ALL, "Portuguese");
  int end;
  do{
  int numR[] = {1,2,3,4,5,6,7,8,9,10};
  int i, numU, found = 0;
  limpa();
  printf("Duvido você encontrar um dos números que tem no meu vetor\n\nDigite aqui ====> ");
  scanf("%d", &numU);

  for(i = 0; i < 10; i++){
    if (numU == numR[i]){
      found++;
  }
}

      if(found == 1){
        limpa();
        printf("\nAchei o número digitado");
      }
      else{
        printf("\nNumero não encontrado na pesquisa");
      }

      printf("\n\nDeseja finalizar o programa?\n1)Sim\n2)Não\n\nDigite sua resposta aqui ====> ");
      scanf("%d", &end);
              }while(end == 2);
}