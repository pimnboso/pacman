#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h> //clock()

void limpa(){
  system("clear");
}

void main(){
  setlocale(LC_ALL, "Portuguese");
  int end;
  double tempo_gasto;

  do{
    clock_t inicio = clock();

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
      clock_t final = clock();
      tempo_gasto = (double)(final - inicio) / CLOCKS_PER_SEC;
      printf("\nO tempo gasto para a execução do programa é: %f segundos", tempo_gasto);

    printf("\n\nDeseja finalizar o programa?\n1)Sim\n2)Não\n\nDigite sua resposta aqui ====> ");
      scanf("%d", &end);
              }while(end == 2);
}