#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <time.h>

void limpa(){
system("clear");
}


int main(){
    setlocale(LC_ALL, "portuguese");
    //Apresentação do jogo
    limpa();
    int dificuldade;
    int continua;
    int segundos = time();

    srand(segundos);
    int numeroGigante = rand();
    int numeroSecreto = numeroGigante % 100;

    do{
    printf("Bem-Vindo ao jogo da adivinhação\n");
    printf("**********************************\n");
    printf("Selecione a dificuldade do jogo:\n1 - Fácil (10 Tentativas)\n2 - Médio (7 Tentativas)\n3 - Difícil (3 Tentativas)\n");
    scanf("%d", &dificuldade);
    limpa();
    int tentativas;
    /* No fácil os pontos vão de 10 a 1
    1o tentativa = 10
    2o tentativa = 9
    3o tentativa = 8
    4o tentativa = 7
    5o tentativa = 6
    6o tentativa = 5
    7o tentativa = 4
    8o tentativa = 3
    9o tentativa = 2
    10o tentativa = 1
    */

   /* No médio os pontos vão de 70 a 10
    1o tentativa = 70
    2o tentativa = 60
    3o tentativa = 50
    4o tentativa = 40
    5o tentativa = 30
    6o tentativa = 20
    7o tentativa = 10
    */

      /* No médio os pontos vão de 70 a 10
    1o tentativa = 100
    2o tentativa = 75
    3o tentativa = 50
    */
    if(dificuldade == 1){
        tentativas = 10;
    }
    else if(dificuldade == 2){
        tentativas = 7;
    }
    else{
        tentativas = 3;
    }

        int pontos;
        //variavel que armazena a tentativa do jogador
        int chute;
        printf("Estou pensando num número! Adivinha qual?\n");

    for(int tentativa = 1; tentativa <= tentativas; tentativa++){
        scanf("%d", &chute);
    if(chute == numeroSecreto){
        limpa();
        if(dificuldade == 1){
            pontos = (11 - tentativa);
        }else if(dificuldade == 2){
            pontos = (80 - (tentativa * 10));
        }
        else{
            pontos = (125 - (tentativa * 25));
        }
        printf("Parabéns você acertou na tentativa %d, e fez %d pontos!\n", tentativa, pontos);
        tentativa = tentativas;
    }
    else{
        limpa();
        printf("Você errou... tente novamente.\n");
        }
}
        printf("\n\nDigite 0 para encerrar o jogo, e 1 para continuar.\n");
        scanf("%d", &continua);
    } while(continua != 0);
}