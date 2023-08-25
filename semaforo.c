#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    int i, cont = 1;
    char *cor[] = {"Verde", "Amarelo", "Vermelho"}, *ligadoDesligado[] = {"Desligado", "Desligado", "Desligado"};
    
    do {
        for (i = 0; i < 3; i++) {
            // Ligando a cor atual e desligando as outras
            for (int j = 0; j < 3; j++) {
                if (j == i) {
                    ligadoDesligado[j] = "Ligado";
                } else {
                    ligadoDesligado[j] = "Desligado";
                }
            }
            
            printf("A cor %s está %s!\n", cor[0], ligadoDesligado[0]);
            printf("A cor %s está %s!\n", cor[1], ligadoDesligado[1]);
            printf("A cor %s está %s!\n", cor[2], ligadoDesligado[2]);
            
            sleep(5);
            system("clear");
        }
    } while (cont != 0);

    return 0;
}
