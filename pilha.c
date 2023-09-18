#define MAX 10
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void limpa(){
  system("clear");
}
void header(){
  limpa();
  printf("****************************\n");
  printf("******** MENU STACK ********\n");
  printf("****************************\n\n\n\n");
}

int st[MAX]; //stack
int top = -1;

void push(int st[], int val){
  if(top == MAX - 1){
    printf("Pilha está sobrecarregada, desempilhe um pouco!\n\n");
  }else{
    top++;
    st[top] = val;
  }
} //empilha

int pop(int st[]){
  if(top == -1){
    printf("Pilha vazia!\n\n");
  }
  else{
    st[top] = NULL;
    top--;
  }
} //desempilha

int continuar(){
  int choice;
  printf("\n\nDeseja continuar?\n1)Sim\n2)Não\n\nDigite aqui sua resposta ====> ");
  scanf("%d", &choice);
  if(choice == 2){
    exit(0);
  }
}

void display(int st[]){
  if(top == - 1){
    printf("\n\nPilha vazia!\n\n");
  }
  else{
  for(int i = top; i > -1; i--){
  printf("\n%d", st[i]);
  }
  }
} //mostra

void main(){
  int choice, val, continua;

  do{
    header();
    printf("1)Empilha\n2)Desempilha\n3)Display\n4)Encerrar programa\n\nDigite sua resposta aqui ====> ");
    scanf("%d", &choice);
    switch(choice){
      case 1:
      printf("\nDigite o valor que deseja empilhar no stack => ");
      scanf("%d",&val);
      push(st, val);
      break;

      case 2:
      pop(st);
      break;

      case 3:
      display(st);
      break;

      case 4:
      exit(0);
      break;
    }
    continua = continuar();
  }while((choice < 0) || (choice > 5) || (continua == 1));
}