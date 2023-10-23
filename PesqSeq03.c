#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void limpa(){
  system("clear");
}

int main(){
  setlocale(LC_ALL, "Portuguese");
  struct produtos{
    char nome[50];
    int codigo, estoque;
    float preco;
  } prod[4];

  //DEFININDO
  strcpy(prod[0].nome, "Produto 1");
  prod[0].codigo = 1111;
  prod[0].estoque = 1;
  prod[0].preco =  1 ;

  strcpy(prod[1].nome, "Produto 2");
  prod[1].codigo = 2222;
  prod[1].estoque = 2;
  prod[1].preco =  2 ;

  strcpy(prod[2].nome, "Produto 3");
  prod[2].codigo = 3333;
  prod[2].estoque = 3;
  prod[2].preco =  3 ;

  strcpy(prod[3].nome, "Produto 4");
  prod[3].codigo = 4444;
  prod[3].estoque = 4;
  prod[3].preco =  4 ;

  limpa();
  int i, end;
  char pesq[50];
  do{
  limpa();
  printf("Bem vindo ao nosso mercadinho, digite o produto que você deseja encontrar\n\nDigite sua resposta aqui ====> ");
  gets(pesq);

  fflush(stdin);

  for(i = 0; i < 4; i++){
    if (strcmp(pesq , prod[i].nome) == 0){
      limpa();
      printf("Produto encontrado!!!");
      printf("\n\nNome:     %s", prod[i].nome);
      printf("\nCódigo do produto:     %d", prod[i].codigo);
      printf("\nPreço do produto:     %f", prod[i].preco);
      printf("\nQuantidade em estoque do produto:     %d", prod[i].estoque);
      break; // nunca fazer isso
  }
  else{
    printf("Produto não encontrado");
  }
}
    printf("\nDeseja finalizar o programa? \n1)Sim\n2)Não\n\nDigite sua resposta aqui ====> ");
    scanf("%d", &end);
    fflush(stdin);
  }while(end == 2);
}