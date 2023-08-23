#include <stdio.h>
#include <locale.h>

void funcao1(int valor_de_x) {
int x;
int *ptrx;

ptrx = &x;
x = valor_de_x;
printf("O valor de x é: %d\n", x);
printf("O endereço de x é: %X\n\n", &ptrx);
// imprima o endereço e o valor de x aqui
}
void funcao2(int aux) {
int y;
int *ptry;

ptry = &y;
printf("O valor de Y é: %d\n", y);
printf("O endereço de y é: %X", &ptry);
// imprima o endereço e o valor de y aqui 
}
void main(){
setlocale(LC_ALL, "portuguese");
funcao1(7);
funcao2(11); 
}