#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Include the string.h header for strcpy
#include <locale.h>
#include <ctype.h>

void limpa() {
    system("clear");
}

void header() {
    printf("*******************************************\n");
    printf("************** JOGO DA FORCA **************\n");
    printf("*******************************************\n\n");
}


int main() {
    FILE* file;
    int i;
    file = fopen("/Users/gabrielfranciscorocha/Desktop/Faculdade/LINGUAGEM DE PROGRAMAÇÃO/respostas.txt", "r"); // Replace "file.txt" with your file path
    int lineCount = 0;
    char buffer[256];
    char texto[256]; // Buffer to read lines

    while (fgets(buffer, sizeof(buffer), file)) {
        lineCount++;
    }
    fclose(file);

    file = fopen("/Users/gabrielfranciscorocha/Desktop/Faculdade/LINGUAGEM DE PROGRAMAÇÃO/respostas.txt", "r");
    for(i = 0; i < 2; i++){
      fscanf(file, "%s", &texto);
    }
    fclose(file);

    int letraCount;

    for (int i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i])) {
            letraCount++;
        }
    }

    char letra[letraCount];

        for (int i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i])) {
            letra[i] = texto[i];
        }
    }
    printf("%s\n", texto);
    printf("%d\n", lineCount);
    printf("%d\n", letraCount);

    for(i = 0; i < 5; i++){
      printf("%c\n", letra[i]);
    }
}