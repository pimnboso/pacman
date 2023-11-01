#define VAZIO '.'
#define PAREDE_V '|'
#define PAREDE_H '-'
#define CHARACTER '@'
#define GHOST 'G'
#define BUFF 'P'

struct mapa{
  int colunas;
  int linhas;
  char** m;
};

typedef struct mapa MAPA;


void abrir_arquivo();
void leitor();