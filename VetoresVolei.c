#include <stdlib.h>
#include <locale.h>
#include <stdio.h>

void limpa() {
    system("clear");
}

int main() {
    setlocale(LC_ALL, "portuguese");

    int N;
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &N);
    limpa();

    char nomes[N][100];
    int S[N], B[N], A[N], S1[N], B1[N], A1[N];

    for (int i = 0; i < N; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%s", nomes[i]);
        limpa();

        printf("Saques realizados pelo %s: ", nomes[i]);
        scanf("%d", &S[i]);
        limpa();

        printf("Bloqueios realizados pelo %s: ", nomes[i]);
        scanf("%d", &B[i]);
        limpa();

        printf("Ataques realizados pelo %s: ", nomes[i]);
        scanf("%d", &A[i]);
        limpa();

        printf("Saques realizados com sucesso pelo %s: ", nomes[i]);
        scanf("%d", &S1[i]);
        limpa();

        printf("Bloqueios realizados com sucesso pelo %s: ", nomes[i]);
        scanf("%d", &B1[i]);
        limpa();

        printf("Ataques realizados com sucesso pelo %s: ", nomes[i]);
        scanf("%d", &A1[i]);
        limpa();
    }

    int totalS = 0, totalB = 0, totalA = 0;
    int totalS1 = 0, totalB1 = 0, totalA1 = 0;

    for (int i = 0; i < N; i++) {
        totalS += S[i];
        totalB += B[i];
        totalA += A[i];
        totalS1 += S1[i];
        totalB1 += B1[i];
        totalA1 += A1[i];
    }

    float percentualS = (totalS1 * 100.0) / totalS;
    float percentualB = (totalB1 * 100.0) / totalB;
    float percentualA = (totalA1 * 100.0) / totalA;

    printf("Percentual de saques: %.2f%%\n", percentualS);
    printf("Percentual de bloqueios: %.2f%%\n", percentualB);
    printf("Percentual de ataques: %.2f%%\n", percentualA);
}
