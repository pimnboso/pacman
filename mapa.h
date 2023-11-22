#include <stdio.h>
#include <stdlib.h>

#define VAZIO ' '
#define PAREDE_V '|'
#define PAREDE_H '-'
#define CHARACTER '@'
#define GHOST 'G'
#define BUFF 'P'
#define ESQ 'A'
#define DIR 'D'
#define CIM 'W'
#define BAI 'S'

struct mapa {
  int colunas;
  int linhas;
  char** m;
};

typedef struct mapa MAPA;

struct posicao {
  int x;
  int y;
};

typedef struct posicao XY;

FILE* arq;
MAPA matriz;

void limpa() {
  system("clear");
}

void abrir_arquivo() {
  arq = fopen("/Users/gabrielfranciscorocha/Desktop/Faculdade/LINGUAGEM DE PROGRAMAÇÃO/PacmanProject/mapa.txt", "r");
  if (arq == NULL) {
    limpa();
    printf("Não foi possível abrir o arquivo.\n");
    exit(1);
  }
}

void leitor() {
  //lê as coordenadas do arquivo
  fscanf(arq, "%d %d", &matriz.linhas, &matriz.colunas);

  matriz.m = (char**)malloc(sizeof(char*) * matriz.linhas);

  for (int i = 0; i < matriz.linhas; i++) {
    matriz.m[i] = (char*)malloc(sizeof(char) * (matriz.colunas + 1));
    fscanf(arq, "%s", matriz.m[i]);
  }
}

void draw_part(char draw[4][7], int parte) {
  printf("%s", draw[parte]);
}

char draw_wall[4][7] = {
  {"......"},
  {"......"},
  {"......"},
  {"......"}
};

char draw_ghost[4][7] = {
  {" .-.  "},
  {"| oo| "},
  {"|   | "},
  {"`---' "}
};

char draw_null[4][7] = {
  {'      '},
  {'      '},
  {'      '},
  {'      '}
};

char draw_pill[4][7] = {
  {".---. "},
  {"|   | "},
  {"|   | "},
  {"\\-/  "}
};

char draw_hero[4][7] = {
  {" .--. "},
  {"/ _.-'"},
  {"\\  '-."},
  {" '--' "}
};

void desenhar_map() {
  for (int i = 0; i < matriz.linhas; i++) {
    for (int parte = 0; parte < 4; parte++) {
      for (int j = 0; j < matriz.colunas; j++) {
        switch (matriz.m[i][j]) {
          case GHOST:
            draw_part(draw_ghost, parte);
            break;

          case PAREDE_H:
          case PAREDE_V:
            draw_part(draw_wall, parte);
            break;

          case CHARACTER:
            draw_part(draw_hero, parte);
            break;

          case VAZIO:
          draw_part(draw_null, parte);
          break;
        }
      }
      printf("\n"); // Adicionei uma quebra de linha ao final de cada linha do mapa
    }
  }
}

void liberar_memory() {
  // Libere a memória alocada
  for (int i = 0; i < matriz.linhas; i++) {
    free(matriz.m[i]);
  }
  free(matriz.m);
}
