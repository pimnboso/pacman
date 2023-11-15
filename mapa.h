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

struct mapa{
  int colunas;
  int linhas;
  char** m;
};

typedef struct mapa MAPA;

struct posicao{
  int x;
  int y;
};

typedef struct posicao XY;

FILE* arq; // fiz a variável do arquivo ficar global
MAPA matriz; // a da matriz também

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
  //lê as coordenadas do arquivo
  fscanf(arq, "%d %d", &matriz.linhas, &matriz.colunas);

  matriz.m = (char**)malloc(sizeof(char*) * matriz.linhas);
  
  for (int i = 0; i < matriz.linhas; i++) {
    matriz.m[i] = (char*)malloc(sizeof(char) * (matriz.colunas + 1));
    fscanf(arq, "%s", matriz.m[i]);
  }
}


void desenhar_map(){
    for (int i = 0; i < matriz.linhas; i++) {
    printf("%s\n", matriz.m[i]);
  }

  fclose(arq);
}


void liberar_memory(){
    // Libere a memória alocada
  for (int i = 0; i < matriz.linhas; i++) {
    free(matriz.m[i]);
  }
  free(matriz.m);
}