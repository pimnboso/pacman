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
  prod[2].codigo = 2222;
  prod[2].estoque = 3;
  prod[2].preco =  3 ;

  strcpy(prod[3].nome, "Produto 4");
  prod[3].codigo = 4444;
  prod[3].estoque = 4;
  prod[3].preco =  4 ;

  limpa();
  int i = 0, end, pesq, contador = 0;
  do{
  limpa();
  printf("Bem vindo ao nosso mercadinho, digite o código de seu produto\n\nDigite sua resposta aqui ====> ");
  scanf("%d", &pesq);
    limpa();
     while(i < 4){
      if (pesq == prod[i].codigo){
      limpa();
      contador++;
      }
  limpa();
  i++;
  if(i == 4){
    printf("Foram encontrados %d produtos!!", contador);
  }
}
  //definir pesq depois da escolha do usuario gets(pesq);

  fflush(stdin);

    printf("\n\nDeseja finalizar o programa? \n1)Sim\n2)Não\n\nDigite sua resposta aqui ====> ");
    scanf("%d", &end);
    fflush(stdin);
    i = 0;
  }while(end == 2);
}