#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void header(){
  printf("**************************************************************\n");
  printf("********************** DADOS DO CLIENTE **********************\n");
  printf("**************************************************************\n\n\n\n");
}
void limpa(){
  system("clear");
}

void main(){
  setlocale(LC_ALL, "portuguese");

  struct client{
      char nome[50], endereco[50], estado[20];
      float salario;
      int codigo;
  } clientes[500];
      

  int i;
  for(i = 0; i < 2; i ++){
          limpa();
          header();
          printf("Nome      : ");
          gets(clientes[i].nome);
          fflush(stdin);
          
          limpa();
          header();
          printf("Endereco do %s      : ", clientes[i].nome);
          gets(clientes[i].endereco);
          fflush(stdin);

          limpa();
          header();
          printf("Estado do %s      : ", clientes[i].nome);
          gets(clientes[i].estado);
          fflush(stdin);

          limpa();
          header();
          printf("Salario do %s      : ", clientes[i].nome);
          scanf("%f", &clientes[i].salario);
          fflush(stdin);

          limpa();
          header();
          printf("Codigo do %s      : ", clientes[i].nome);
          scanf("%d", &clientes[i].codigo);
          fflush(stdin);
  }
int escolha;
      limpa();
      header();
      printf("==============Digite qual Cliente deseja saber as informações ==============\n");
    for(i = 0; i < 2; i++){
    printf("%d) %s\n", i+1, clientes[i].nome);
    }
    scanf("%d", &escolha);

  limpa();
  header();
  printf("Nome    :    %s\n", clientes[escolha - 1].nome);
  printf("Endereco    :    %s\n", clientes[escolha - 1].endereco);
  printf("Estado    :    %s\n", clientes[escolha - 1].estado);
  printf("Salario    :    %f\n", clientes[escolha - 1].salario);
  printf("Codigo    :    %d", clientes[escolha - 1].codigo);
} 