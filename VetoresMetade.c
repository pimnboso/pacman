#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void limpa(){
    system("clear");
} // só para não se perder no código

void main(){
    int i;
    float x;
    setlocale(LC_ALL, "portuguese");

    do{
    printf("Escolha um número entre 1 e 50: ");
    scanf("%f", &x);
    limpa();

    }while(x < 2);

    for(i = 0; i < 99; i++){
        printf("n[%d] = %.4f\n", i, x);
        x = x / 2;
    }
}