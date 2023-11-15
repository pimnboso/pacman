#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "mapa.h" 

XY position;
XY ghost_pos;
int old_ghost_posx, old_ghost_posy;
int new_ghostx, new_ghosty;
bool end = false;

int teste = 0;

int can_move(){
  int newx, newy;
  newx = position.x;
  newy = position.y;
   if(matriz.m[newx][newy] == PAREDE_V){
    return 0;
   }
   else if(matriz.m[newx][newy] == PAREDE_H){
    return 0;
   }
   return 1;
}

int ghost_can_move(){
  new_ghostx = ghost_pos.x;
  new_ghosty = ghost_pos.y;
   if(matriz.m[new_ghostx][new_ghosty] == PAREDE_V){
    return 0;
   }
   else if(matriz.m[new_ghostx][new_ghosty] == PAREDE_H){
    return 0;
   }
   else if(matriz.m[new_ghostx][new_ghosty] == GHOST){
    return 0;
   }
   else if(matriz.m[new_ghostx][new_ghosty] == BUFF){
    return 0;
   }
   else if(matriz.m[new_ghostx][new_ghosty] == CHARACTER){
    end = true;
    printf("VOCê morreu!!");
   }
   return 1;
}

void fantasma(){
  for (int i = 0; i < matriz.linhas; i++){
    for(int j = 0; j < matriz.colunas; j++){
      if(matriz.m[i][j] == GHOST){
        ghost_pos.x = i;
        ghost_pos.y = j;
      }
    }
  }
}

void rand_ghost(){
  srand(time(0));
  int rand_g = rand() % 4;
  
  old_ghost_posx = ghost_pos.x;
  old_ghost_posy = ghost_pos.y;

  switch (rand_g){
    case 0: // esquerda
    ghost_pos.y--;
    if(ghost_can_move() == 0){
      ghost_pos.y++;
    }
    break;

    case 1: // direita
    ghost_pos.y++;
    if(ghost_can_move() == 0){
      ghost_pos.y--;
    }
    break;

    case 2: // cima
    ghost_pos.x++;
        if(ghost_can_move() == 0){
        ghost_pos.x--;
        }
    break;

    case 3: // baixo
    ghost_pos.x--;
    if(ghost_can_move() == 0){
      ghost_pos.x++;
    }
    break;
  }
}


int main() {
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
  fantasma();

  char tecla;
  int antx, anty;
  do {
    limpa();
    desenhar_map();
    scanf("%c", &tecla);

    // Salve as coordenadas atuais
    antx = position.x;
    anty = position.y;

    switch (tecla) {
      case ESQ: // esquerda
        position.y--;
        if (can_move() == 0) {
          position.y++;
        }
        break;

      case DIR: // direita
        position.y++;
        if (can_move() == 0) {
          position.y--;
        }
        break;

      case CIM: // cima
        position.x--;
        if (can_move() == 0) {
          position.x++;
        }
        break;

      case BAI: // baixo
        position.x++;
        if (can_move() == 0) {
          position.x--;
        }
        break;
    }

    matriz.m[antx][anty] = VAZIO;
    matriz.m[position.x][position.y] = CHARACTER;
    matriz.m[old_ghost_posx][old_ghost_posy] = VAZIO;
    matriz.m[ghost_pos.x][ghost_pos.y] = GHOST; 
    rand_ghost();
  } while (!end);

  liberar_memory();
  return 0;
}
