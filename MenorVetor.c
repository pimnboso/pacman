#include <stdlib.h>
#include <locale.h>
#include <stdio.h>

void limpa() {
    system("clear");
}

int main() {
    setlocale(LC_ALL, "portuguese");

    int N;
    
    do {
        printf("Digite a quantidade de elementos que deseja (OBS: o número deve ser maior que 1 e menor que 1000): ");
        scanf("%d", &N);
        limpa();
    } while (N < 1 || N > 1000);

    int X[N];
    
    for (int i = 0; i < N; i++) {
        printf("Agora digite o %d° número: ", i + 1);
        scanf("%d", &X[i]);
        limpa();
    }

    int menor = X[0];
    int casa = 0;

    for (int i = 1; i < N; i++) {
        if (X[i] < menor) {
            menor = X[i];
            casa = i;
        }
    }

    printf("O menor valor é: %d\nA casa do número é: %d\n", menor, casa + 1);
}
