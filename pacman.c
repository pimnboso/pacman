#include <stdlib.h>
#include <stdio.h>
#include "mapa.h" 

FILE* arq;
MAPA matriz;

void limpa() {
  system("clear");
}

void abrir_arquivo() {
  arq = fopen("/Users/gabrielfranciscorocha/Desktop/Faculdade/LINGUAGEM DE PROGRAMAÇÃO/mapa.txt", "r");
  if (arq == NULL) {
    limpa();
    printf("Não foi possível abrir o arquivo.\n");
    exit(1);
  }
}

void leitor() {
  fscanf(arq, "%d %d", &matriz.linhas, &matriz.colunas);

  matriz.m = (char**)malloc(sizeof(char*) * matriz.linhas);
  
  for (int i = 0; i < matriz.linhas; i++) {
    matriz.m[i] = (char*)malloc(sizeof(char) * (matriz.colunas + 1));
    fscanf(arq, "%s", matriz.m[i]);
  }
}

int main() {
  limpa();
  abrir_arquivo();
  leitor();

  for (int i = 0; i < matriz.linhas; i++) {
    printf("%s\n", matriz.m[i]);
  }

  fclose(arq);

  // Libere a memória alocada
  for (int i = 0; i < matriz.linhas; i++) {
    free(matriz.m[i]);
  }
  free(matriz.m);

  return 0;
}
