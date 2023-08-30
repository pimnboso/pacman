#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>

void header() {
    printf("*******************************************\n");
    printf("************** JOGO DA FORCA **************\n");
    printf("*******************************************\n\n\n\n");
}

void limpa() {
    system("clear");
}

void AddForca(){
     header();

    FILE* file;
    int i;
    file = fopen("/Users/gabrielfranciscorocha/Desktop/Faculdade/LINGUAGEM DE PROGRAMAÇÃO/respostas.txt", "a");
    char texto[256];
    fflush(stdin);
    printf("Qual palavra você deseja adicionar?\n\n\nDigite aqui sua resposta ====> ");
    scanf("%s", texto);

    fprintf(file, "\n%s", texto);
    fclose(file);
}

void ExcForca(){
 header();

    FILE* file;
    int i;
    file = fopen("/Users/gabrielfranciscorocha/Desktop/Faculdade/LINGUAGEM DE PROGRAMAÇÃO/respostas.txt", "r");
    int lineCount = 0;
    char buffer[256];
    char texto[256];
    int escolhaApagar;

    while (fgets(buffer, sizeof(buffer), file)) { 
        lineCount++;
    }
    fclose(file);

    printf("Qual deseja apagar?\n\n\n");

    file = fopen("/Users/gabrielfranciscorocha/Desktop/Faculdade/LINGUAGEM DE PROGRAMAÇÃO/respostas.txt", "r");

    for (i = 0; i < lineCount; i++) {
        fscanf(file, "\n%s", texto);
        printf("%d) %s\n", i+1, texto);
    }
    fclose(file);

    printf("\nDigite sua resposta aqui ====> ");
    scanf("%d", &escolhaApagar);
    
    file = fopen("/Users/gabrielfranciscorocha/Desktop/Faculdade/LINGUAGEM DE PROGRAMAÇÃO/respostas.txt", "r");
    
    FILE* tempFile = fopen("/Users/gabrielfranciscorocha/Desktop/Faculdade/LINGUAGEM DE PROGRAMAÇÃO/temp.txt", "w");

    for (i = 0; i < lineCount; i++) {
        fgets(texto, sizeof(texto), file);
        if (i != escolhaApagar - 1) {
            fprintf(tempFile, "%s", texto);
        }
    }

    fclose(file);
    fclose(tempFile);
    
    remove("/Users/gabrielfranciscorocha/Desktop/Faculdade/LINGUAGEM DE PROGRAMAÇÃO/respostas.txt");
    rename("/Users/gabrielfranciscorocha/Desktop/Faculdade/LINGUAGEM DE PROGRAMAÇÃO/temp.txt", "/Users/gabrielfranciscorocha/Desktop/Faculdade/LINGUAGEM DE PROGRAMAÇÃO/respostas.txt");
}

void AltForca() {
    header();

    FILE* file;
    int i;
    file = fopen("/Users/gabrielfranciscorocha/Desktop/Faculdade/LINGUAGEM DE PROGRAMAÇÃO/respostas.txt", "r");
    int lineCount = 0;
    char buffer[256];
    char texto[256];
    char novoTexto[256];
    int escolhaAlt;

    while (fgets(buffer, sizeof(buffer), file)) { 
        lineCount++;
    }
    fclose(file);

    printf("Qual deseja alterar?\n\n\n");

    file = fopen("/Users/gabrielfranciscorocha/Desktop/Faculdade/LINGUAGEM DE PROGRAMAÇÃO/respostas.txt", "r");

    for (i = 0; i < lineCount; i++) {
        fscanf(file, "\n%s", texto);
        printf("%d) %s\n", i+1, texto);
    }
    fclose(file);
    printf("\nDigite aqui sua resposta ====> ");
    scanf("%d", &escolhaAlt);

    limpa();
    header();
    printf("Por qual palavra deseja substituir?\n\n\nDigite aqui ====> ");
    scanf("%s", novoTexto);

    file = fopen("/Users/gabrielfranciscorocha/Desktop/Faculdade/LINGUAGEM DE PROGRAMAÇÃO/respostas.txt", "r");
    
    FILE* tempFile = fopen("/Users/gabrielfranciscorocha/Desktop/Faculdade/LINGUAGEM DE PROGRAMAÇÃO/temp.txt", "w");

    for (i = 0; i < lineCount; i++) {
        fgets(texto, sizeof(texto), file);
        if (i == escolhaAlt - 1) {
            fprintf(tempFile, "%s\n", novoTexto);
        } else {
            fprintf(tempFile, "%s", texto);
        }
    }

    fclose(file);
    fclose(tempFile);
    
    //apaga o arquivo temp que armazenou o texto que desejamos e passa para as respostas!!
    remove("/Users/gabrielfranciscorocha/Desktop/Faculdade/LINGUAGEM DE PROGRAMAÇÃO/respostas.txt");
    rename("/Users/gabrielfranciscorocha/Desktop/Faculdade/LINGUAGEM DE PROGRAMAÇÃO/temp.txt", "/Users/gabrielfranciscorocha/Desktop/Faculdade/LINGUAGEM DE PROGRAMAÇÃO/respostas.txt");
}

void logicalForca() {

    FILE* file;
    int i;
    file = fopen("/Users/gabrielfranciscorocha/Desktop/Faculdade/LINGUAGEM DE PROGRAMAÇÃO/respostas.txt", "r");
    int lineCount = 0;
    char buffer[256];
    char texto[256];
    while (fgets(buffer, sizeof(buffer), file)) { 
        lineCount++;
    }
    fclose(file);

    srand(time(NULL));
    int PalavraRand = rand();
    int PalavraRandScan = PalavraRand % lineCount;
    PalavraRandScan++;

    file = fopen("/Users/gabrielfranciscorocha/Desktop/Faculdade/LINGUAGEM DE PROGRAMAÇÃO/respostas.txt", "r");
    for(i = 0; i < PalavraRandScan; i++){
        fscanf(file, "%s", texto);
    }
    fclose(file);

    int letraCount = 0;
    for (i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i])) {
            letraCount++;
        }
    }

    char letra[256];
    int letraIndex = 0;

    for (i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i])) {
            letra[letraIndex] = texto[i];
            letraIndex++;
        }
    }

    printf("Palavra selecionada: %s\n", texto);

    limpa();

    int acertos = 0;
    char LetrasQueAcertou[256];
    char LetrasQueErrou[256];

    for (i = 0; i < letraCount; i++) {
        LetrasQueAcertou[i] = '_';
    }

        for (i = 0; i < 7; i++) {
        LetrasQueErrou[i] = '_';
    }
    LetrasQueAcertou[letraCount] = '\0';
    LetrasQueErrou[letraCount] = '\0';
    int contadorErro = 0;
    int erros = 0;
    char letrasEscolhidas[26]; // Array para armazenar as letras escolhidas
    int letrasEscolhidasCount = 0;
    int contadorCorpo = 0;
    int contadorCorpo2 = 0;
    do {
        /*
    corpo[1] = "O";
    corpo[2] = "O\n/";
    corpo[3] = "O\n/|";
    corpo[4] = ("O\n/|%c", 167); <===== ideia descartada
    corpo[5] = ("O\n/|%c\n|", 167);
    corpo[6] = ("O\n/|%c\n|\n/", 167);
    corpo[7] = ("O\n/|%c\n|\n/%c", 167, 167);*/
                        if(contadorCorpo2 == 0){
                       header();
                       printf(" -------------\n");
                       printf(" |           |\n");
                       printf(" |            \n");
                       printf(" |            \n");
                       printf(" |            \n");
                       printf(" |            \n");
                       printf("---           \n");
                        }


        char EscolhaLetra;
        fflush(stdin);
        printf("\nDigite sua resposta aqui ===>  ");
        scanf(" %c", &EscolhaLetra);

        // Verificar se a letra já foi escolhida antes
        int letraRepetida = 0;
        for (i = 0; i < letrasEscolhidasCount; i++) {
            if (tolower(EscolhaLetra) == letrasEscolhidas[i]) {
                letraRepetida = 1;
                break;
            }
        }
        //to lower transforma todos os caracteres em minúsculos.
        // a exclamação serve para negar o resultado
        
        if (!letraRepetida) {
            letrasEscolhidas[letrasEscolhidasCount] = tolower(EscolhaLetra);
            letrasEscolhidasCount++;

            int acertou = 0;

            for (i = 0; i < letraCount; i++) {
                if (tolower(EscolhaLetra) == tolower(letra[i])) {
                    LetrasQueAcertou[i] = letra[i];
                    acertou = 1;
                    acertos++;
                }
            }

            if (!acertou) {
                LetrasQueErrou[contadorErro++] = EscolhaLetra;
                erros++;
                contadorCorpo++;
            }
        }
        limpa();
        header();
        // desenho
                if(contadorCorpo == 0){
                       printf(" -------------\n");
                       printf(" |           |\n");
                       printf(" |            \n");
                       printf(" |            \n");
                       printf(" |            \n");
                       printf(" |            \n");
                       printf("---           \n\n\n");
                }
                else if(contadorCorpo == 1){
                       printf(" -------------\n");
                       printf(" |           |\n");
                       printf(" |           O\n");
                       printf(" |            \n");
                       printf(" |            \n");
                       printf(" |            \n");
                       printf("---           \n\n\n");
                                         }
                  else if(contadorCorpo == 2){
                       printf(" -------------\n");
                       printf(" |           |\n");
                       printf(" |           O\n");
                       printf(" |           |\n");
                       printf(" |            \n");
                       printf(" |            \n");
                       printf("---           \n\n\n");
                                         }
                  else if(contadorCorpo == 3){
                       printf(" -------------\n");
                       printf(" |           |\n");
                       printf(" |           O\n");
                       printf(" |          /|\n");
                       printf(" |            \n");
                       printf(" |            \n");
                       printf("---           \n\n\n");
                                         }
                  else if(contadorCorpo == 4){
                       printf(" -------------\n");
                       printf(" |           |\n");
                       printf(" |           O\n");
                       printf(" |          /|\\\n");
                       printf(" |            \n");
                       printf(" |            \n");
                       printf("---           \n\n\n");
                                         }
                  else if(contadorCorpo == 5){
                       printf(" -------------\n");
                       printf(" |           |\n");
                       printf(" |           O\n");
                       printf(" |          /|\\\n");
                       printf(" |           |\n");
                       printf(" |            \n");
                       printf("---           \n\n\n");
                                         }
                  else if(contadorCorpo == 6){
                       printf(" -------------\n");
                       printf(" |           |\n");
                       printf(" |           O\n");
                       printf(" |          /|\\\n");
                       printf(" |           |\n");
                       printf(" |          / \n");
                       printf("---           \n\n\n");
                                         }
                  else if(contadorCorpo == 7){
                       printf(" -------------\n");
                       printf(" |           |\n");
                       printf(" |           O\n");
                       printf(" |          /|\\\n");
                       printf(" |           |\n");
                       printf(" |          / \\\n");
                       printf("---           \n\n\n");
                                         }
        contadorCorpo2++;
        printf("Letras que errou: %s\n\n", LetrasQueErrou);
        printf("%s\n", LetrasQueAcertou);
    }while (erros < 7 && acertos < letraCount);
}

int main() {
    setlocale(LC_ALL, "portuguese");
    limpa();
    header();
    int menu;
    int escolha;
    do{
    printf("1)Jogar\n2)Alterar Palavra\n3)Excluir Palavra\n4)Adicionar Palavra\n5)Sair\n\n\nDigite sua resposta aqui ====> ");
    scanf("%d", &menu);

    switch(menu){
    case 1:
        limpa();
        logicalForca();
        limpa();
        header();
        printf("Deseja voltar para o menu principal?\n1)Sim\n2)Não\n\n\nDigite sua resposta aqui ====> ");
                 scanf("%d", &escolha);
                 if(escolha == 1){
                 main();
                 }
                 break;
    
    case 2:
        limpa();
        AltForca();
        limpa();
        header();

            printf("Deseja voltar para o menu principal?\n1)Sim\n2)Não\n\n\nDigite sua resposta aqui ====> ");
            scanf("%d", &escolha);
                if(escolha == 1){
                  main();
                 }
        break;

    case 3:
    limpa();
    ExcForca();
    limpa();
    header();
            printf("Deseja voltar para o menu principal?\n1)Sim\n2)Não\n\n\nDigite sua resposta aqui ====> ");
            scanf("%d", &escolha);
                if(escolha == 1){
                  main();
                 }
        break;

    case 4:
    limpa();
    AddForca();
    limpa();
    header();
            printf("Deseja voltar para o menu principal?\n1)Sim\n2)Não\n\n\nDigite sua resposta aqui ====> ");
            scanf("%d", &escolha);
                if(escolha == 1){
                  main();
                 }
        break;
    }
    
} while((escolha < 1) || (escolha > 5));
}
