#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void limpa(){
    system("clear");
} // só para não se perder no código

void main(){
    int x, i;
    setlocale(LC_ALL, "portuguese");

    do{
    printf("Escolha um número entre 1 e 50: ");
    scanf("%d", &x);
    limpa();

    }while((x < 1) || (x > 50));

    for(i = 0; i <= 10; i++){
        printf("n[%d] = %d\n", i, x);
        x = x * 2;
    }
}