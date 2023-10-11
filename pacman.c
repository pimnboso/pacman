/*----------
|••••••••|
|•••|••@•|
|•••--•••|    <==== MAPA
|••••••••|
----------*/

#include <stdlib.h>
#include <stdio.h>
int coluna;
int linha;
char** mapa;

void limpa(){
  system("clear");
}

int main(){
  FILE* arq;
  arq = fopen("/Users/gabrielfranciscorocha/Desktop/Faculdade/LINGUAGEM DE PROGRAMAÇÃO/mapa.txt", "r");
  
  if(arq == 0){
    limpa();
    printf("PALHAÇO NÃQO CONSEGUIU ABRI O ARQUIVO HAHAHAHAHHAHAHAHA");
    exit(1);
  }

  fscanf(arq, "%d %d", &linha, &coluna);

  mapa = malloc(sizeof(char*) * linha);
 
  limpa();
  for(int i = 0; i < 6; i++){
    fscanf(arq, "%s", mapa[i]);
}

  for(int i = 0; i < 6; i++){
    printf("%s\n", mapa[i]);
}
fclose(arq);
}