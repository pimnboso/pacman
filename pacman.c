#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "mapa.h" 

XY position;
int teste = 0;

int main() {
  bool end = false;
  int i, j;

  limpa();
  abrir_arquivo();
  leitor();

  for(i = 0; i < matriz.linhas; i++) {
    for(j = 0; j < matriz.colunas; j++) {
      if(matriz.m[i][j] == CHARACTER) {
        position.x = i;
        position.y = j;
      }
    }
  }

  char tecla;
  int antx, anty;

  do {
    limpa();
    desenhar_map();
    scanf("%c", &tecla);
    antx = position.x;
    anty = position.y;

    switch (tecla) {
      case ESQ: // esquerda
          position.y--;
        break;

      case DIR: // direita
          position.y++;
        break;

      case CIM: // cima
          position.x--;
        break;

      case BAI: // baixo
          position.x++;
        break;
    }

    matriz.m[antx][anty] = " ";
    matriz.m[position.x][position.y] = CHARACTER;

    if (teste == 1) {
      end = true;
    }
  } while (!end);

  liberar_memory();
  return 0;
}
