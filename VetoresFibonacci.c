#include <stdlib.h>
#include <locale.h>
#include <stdio.h>

void limpa() {
    system("clear");
}

unsigned long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    unsigned long long fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int main() {
    int T;
    setlocale(LC_ALL, "portuguese");

    printf("Digite a quantidade de testes que você deseja: ");
    scanf("%d", &T);
    limpa();

    unsigned long long fibo[T];
    int N[T];
    
    for (int i = 0; i < T; i++) {
      do{
        printf("Digite qual termo da série de Fibonacci você deseja saber: ");
        scanf("%d", &N[i]);
        }while((N[i] < 0) || (N[i] > 60));
    }
    limpa();
    
    for (int i = 0; i < T; i++) {
        unsigned long long result = fibonacci(N[i]);
        fibo[i] = result;

        printf("Fib(%d) = %llu\n", N[i], result);
    }

    return 0;
}
