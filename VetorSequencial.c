#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void limpa(){
    system("clear");
} // só para não se perder no código

void main(){
    int x, n , i;
    do{
    printf("Digite o número do vetor, que seja maior que 2 e menor que 50: ");
    scanf("%d", &x);
    limpa();
    }
    while((x < 2) || (x > 50));
    n = 0;

    for(i = 0; i <= 1000; i++){
        printf("N[%d] = %d\n", i, n);
        n++;
        if(n == x){
            n = 0;
        }
}}