#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
  // -============ NAO COLOCAR EM FUNÇAO =============-
  struct pessoas{
      char nome[120];
      char nacionalidade[120];
      char naturalidade[120];
      int nasc[3]; // armazena o dia, mes e ano de nascimento [0] dia [1] mes [2] ano
      int rg[4]; // armazena 4 seções do RG
      int cpf[4]; // armazena 4 seções do cpf
      char enderec[120]; // armazena o nome da rua
      int csNum; // numero da CASA
      char bairro[120], cidade[120], estado[120];
      int telefone[1]; // armazena os 4 primeiros numeros do telefone e os 4 ultimos
      float renda;
      int csPRouAL; // variavel booleana !!
      char empresa[120]; // nome da empresa
      int secao;
      int tempo; //tempo em dias
      int civil;
  } cadastros[500];

  int searchCadastro = 0;
  int i;
  // -============ NAO COLOCAR EM FUNÇAO =============-
void header(){
  printf("***********************************************************\n");
  printf("******************** SISTEMA CADASTRAL ********************\n");
  printf("***********************************************************\n\n\n\n");
}
void limpa(){
  system("clear");
}

void cadastro(){
  searchCadastro++;
  
  // pega o nome
  fflush(stdin);
  header();
  printf("Digite seu nome completo por gentileza.\n\nDigite sua resposta aqui ====> ");
  gets(cadastros[searchCadastro].nome);
  limpa();

  // nacionalidade
  fflush(stdin);
  header();
  printf("Digite sua nacionalidade. \n\nDigite sua resposta aqui ====> ");
  gets(cadastros[searchCadastro].nacionalidade);
  limpa();

  //naturalidade
  fflush(stdin);
  header();
  printf("Digite sua naturalidade. \n\nDigite sua resposta aqui ====> ");
  gets(cadastros[searchCadastro].naturalidade);
  limpa();

  //nascimento
  fflush(stdin);
  do{
  header();
  printf("Digite o dia de seu nascimento.\n\nDigite sua resposta aqui ====> ");
  scanf("%d", &cadastros[searchCadastro].nasc[0]);
  limpa();
  }while((cadastros[searchCadastro].nasc[0] < 1) || (cadastros[searchCadastro].nasc[0] > 31));

  //mes
  fflush(stdin);
   do{
  header();
  printf("Digite o mês de seu nascimento.\n\nDigite sua resposta aqui ====> ");
  scanf("%d", &cadastros[searchCadastro].nasc[1]);
  limpa();
  }while((cadastros[searchCadastro].nasc[1] < 1) || (cadastros[searchCadastro].nasc[1] > 12));

  //ano
  fflush(stdin);
    do{
  header();
  printf("Digite o ano de seu nascimento.\n\nDigite sua resposta aqui ====> ");
  scanf("%d", &cadastros[searchCadastro].nasc[0]);
  limpa();
  }while((cadastros[searchCadastro].nasc[0] < 1950) || (cadastros[searchCadastro].nasc[0] > 2023));



  //============== RG ==========//
  fflush(stdin);
  do{
    header();
    printf("Digite os 2 primeiros números de seu RG.\n\nDigite sua resposta aqui ====> ");
    scanf("%d", &cadastros[searchCadastro].rg[0]);
  }while((cadastros[searchCadastro].rg[0] < 0) || (cadastros[searchCadastro].rg[0] > 99));
  limpa();
  
  for(i = 1; i < 2; i++){
    do{
      header();
      printf("Digite os 3 %dº números de seu RG.\n\n Digite sua resposta aqui ====> ", i);
      scanf("%d", &cadastros[searchCadastro].rg[i]);
      limpa();
    }while((cadastros[searchCadastro].rg[i] < 0) || (cadastros[searchCadastro].rg[i]) > 999);
  }
  
  do{
  header();
  printf("Digite o último número de seu RG.\n\nDigite sua resposta aqui ====> ");
  scanf("%d", &cadastros[searchCadastro].rg[3]);
  limpa();
  }while((cadastros[searchCadastro].rg[3] < 0) || (cadastros[searchCadastro].rg[3] > 9));

  //-======== CPF ========-
  fflush(stdin);

  for(i = 0; i < 2; i++){
    do{
      header();
      printf("Digite os 3 %dº números de seu CPF.\n\n Digite sua resposta aqui ====> ", i+1);
      scanf("%d", &cadastros[searchCadastro].cpf[i]);
      limpa();
    }while((cadastros[searchCadastro].cpf[i] < 0) || (cadastros[searchCadastro].cpf[i] > 999));
  }
  
  do{
  header();
  printf("Digite os últimos números de seu CPF.\n\nDigite sua resposta aqui ====> ", i+1);
  scanf("%d", &cadastros[searchCadastro].cpf[3]);
  limpa();
  }while((cadastros[searchCadastro].cpf[3] < 0) || (cadastros[searchCadastro].cpf[3] > 99));

  // RUA
  fflush(stdin);
  header();
  printf("Digite o nome de sua rua.\n\nDigite sua resposta aqui ====> ");
  gets(cadastros[searchCadastro].enderec);
  limpa();

  // NUMERO DA CASA
  fflush(stdin);

  header();
  printf("Digite o número da sua casa.\n\nDigite sua resposta aqui ====> ");
  scanf("%d", &cadastros[searchCadastro].csNum);
  limpa();

  // Bairro
  fflush(stdin);
  header();
  printf("Digite o nome de seu bairro.\n\nDigite sua resposta aqui ====> ");
  gets(cadastros[searchCadastro].bairro);
  limpa();

  //Cidade
  fflush(stdin);
  header();
  printf("Digite o nome de sua cidade.\n\nDigite sua resposta aqui ====> ");
  gets(cadastros[searchCadastro].cidade);
  limpa();

  //Estado
  fflush(stdin);
  header();
  printf("Digite o nome de seu estado.\n\nDigite sua resposta aqui ====> ");
  gets(cadastros[searchCadastro].estado);
  limpa();

  // TELEFONE
  fflush(stdin);
  for(i = 0; i < 2; i++){
    do{
    header();
    printf("Digite os %dº números de seu telefone.\n\nDigite sua resposta aqui ====> ", i+1);
    scanf("%d", &cadastros[searchCadastro].telefone[i]);
    limpa();
    }while((cadastros[searchCadastro].telefone[i] < 0) || (cadastros[searchCadastro].telefone[i] > 9999));
  }

  //Casa própria ou alugada
  fflush(stdin);
  do{
    header(); 
    printf("Você possui: \n0)Casa Alugada\n1)Casa Própria\n\nDigite sua resposta aqui ====> ");
    scanf("%d", &cadastros[searchCadastro].csPRouAL);
    limpa();
  }while((cadastros[searchCadastro].csPRouAL < 0) || (cadastros[searchCadastro].csPRouAL > 1));

  // Nome empresa
  fflush(stdin);
  header();
  printf("Qual o nome da empresa que trabalha?\n\nDigite aqui sua resposta ====> ");
  gets(cadastros[searchCadastro].empresa);
  limpa();

  //Tempo que trabalha na empresa
  fflush(stdin);
  header();
  printf("Há quanto tempo trabalha na empresa %s? OBS: EM DIAS!!\n\nDigite aqui sua resposta ====> ", cadastros[searchCadastro].empresa);
  scanf("%d", &cadastros[searchCadastro].tempo);
  limpa();
  
  //seção
  fflush(stdin);
  header();
  printf("Qual sua seção?\n\nDigite sua resposta aqui ====> ");
  scanf("%d", &cadastros[searchCadastro].secao);
  limpa();

  // Renda mensal
  fflush(stdin);
  header();
  printf("Qual sua renda mensal?\n\nDigite sua resposta aqui ====> ");
  scanf("%f", &cadastros[searchCadastro].renda);
  limpa();

  //Estado civil
  fflush(stdin);
  do{
    header();
    printf("Qual seu estado civil?\n1)Casado(a)\n2)Solteiro(a)\n3)Viúvo(a)\n4)Separado\n5)Divorciado\n\nDigite sua resposta aqui ====> ");
    scanf("%d", &cadastros[searchCadastro].civil);
    limpa();
  }while((cadastros[searchCadastro].civil < 0) || (cadastros[searchCadastro].civil > 5));
}

void alterar(){
  int escolha;
  int escolhaAlt;
  
  header();
  printf("Qual perfil você deseja alterar?\n");
  for(i = 0; i < searchCadastro; i++){
    printf("%d) %s\n", i+1, cadastros[searchCadastro].nome);
  }
  printf("\n\nDigite aqui sua resposta ====> ");
  scanf("%d", &escolha);
  limpa();

  do{
  header();
  printf("Digite o que você quer alterar.");                                                                                                                //ZERA O TEMPO Q TRABALHA NA EMPRESA
  printf("\n1)Nome\n2) RG\n3)CPF\n4)Nacionalidade\n5)Naturalidade\n6)Data de nascimento\n7)Rua\n8)Bairro\n9)Número da casa\n10)Cidade\n11)Estado\n12)Telefone\n13)Nome da empresa em que trabalha\n14)Renda Mensal\n15)Estado Civil\n\n16)Sair\n\n\nDigite aqui sua resposta ====> ");
  scanf("%d", &escolhaAlt);
  limpa();
  }while((escolhaAlt < 1) || (escolhaAlt > 16));
  
  switch(escolhaAlt){
    case 1:
    header();
    printf("Novo nome desejado.\n\nDigite aqui sua resposta ====> ");
    gets(cadastros[escolha].nome);
    limpa();
    break;

    case 2:
    header();
    printf("Digite os dois primeiros números do novo RG desejado.\n\nDigite sua resposta aqui ====> ");
    scanf("%d", &cadastros[escolha].rg[0]);

    for(i = 1; i < 2; i++){
      do{
      limpa();
      header();
      printf("Digite os três %dº números do novo RG\n\nDigite sua resposta aqui ====> ");
      scanf("%d", &cadastros[escolha].rg[i]);
      }while((cadastros[escolha].rg[i] < 0) || (cadastros[searchCadastro].rg > 999));
      }

      do{
        limpa();
       header();
       printf("Digite o último número de seu novo RG.\n\nDigite aqui sua resposta ====> ");
       scanf("%d", &cadastros[escolha].rg[3]);
      }while((cadastros[escolha].rg[3] < 0) || (cadastros[escolha].rg > 9));

      break;

    case 3:
    
    header();
    for(i = 0; i < 2; i++){
      do{
      limpa();
      header();
      printf("Digite os três %dº números do novo CPF\n\nDigite sua resposta aqui ====> ");
      scanf("%d", &cadastros[escolha].cpf[i]);
      }while((cadastros[escolha].cpf[i] < 0) || (cadastros[searchCadastro].cpf[i] > 999));
      }

      do{
      limpa();
      header();
      printf("Digite os dois últimos números de seu novo CPF.\n\nDigite aqui sua resposta ====> ");
      scanf("%d", &cadastros[escolha].cpf[3]);
      }while((cadastros[escolha].cpf[3] < 0) || (cadastros[escolha].cpf[3] > 99));

      break;

      case 4:
      header();
      printf("Digite sua nova Nacionalidade.\n\nDigite sua resposta aqui ====> ");
      gets(cadastros[escolha].nacionalidade);
      limpa();
      break;

      case 5:
      header();
      printf("Digite sua nova Naturalidade.\n\nDigite sua resposta aqui ====> ");
      gets(cadastros[escolha].naturalidade);
      limpa();
      break;

      case 6:
      do{
      header();
      printf("Digite o novo dia de seu nascimento.\n\nDigite aqui sua resposta ====> ");
      scanf("%d", &cadastros[escolha].nasc[0]);
      limpa();
      }while((cadastros[escolha].nasc[0] < 1) || (cadastros[escolha].nasc[0] > 31));

      do{
      header();
      printf("Digite o novo mês de seu nascimento.\n\nDigite aqui sua resposta ====> ");
      scanf("%d", &cadastros[escolha].nasc[1]);
      limpa();
      }while((cadastros[escolha].nasc[1] < 1) || (cadastros[escolha].nasc[1] > 12));

      do{
      header();
      printf("Digite o novo ano de seu nascimento.\n\nDigite aqui sua resposta ====> ");
      scanf("%d", &cadastros[escolha].nasc[2]);
      limpa();
      }while((cadastros[escolha].nasc[2] < 1950) || (cadastros[escolha].nasc[2] > 2023));
      break;

      case 7:
      header();
      printf("Digite o nome da nova Rua\n\nDigite aqui sua resposta ====> ");
      gets(cadastros[escolha].enderec);
      limpa();
      break;

      case 8:
      header();
      printf("Digite o nome do novo Bairro\n\nDigite aqui sua resposta ====> ");
      gets(cadastros[escolha].bairro);
      limpa();
      break;

      case 9:
      header();
      printf("Digite o novo número da Casa\n\nDigite aqui sua resposta ====> ");
      scanf("%d", &cadastros[escolha].csNum);
      limpa();
      break;

      case 10:
      header();
      printf("Digite o nome da nova Cidade.\n\nDigite aqui sua resposta ====> ");
      gets(cadastros[escolha].cidade);
      limpa();
      break;

      case 11:
      header();
      printf("Digite o nome do seu novo Estado. \n\nDigite aqui sua resposta ====> ");
      gets(cadastros[escolha].cidade);
      limpa();
      break;

      case 12: 
      header();
      for(i = 0; i < 1; i++){
        do{
          printf("Digite os 4 %dº números de seu novo telefone.\n\nDigite aqui sua resposta ====> ");
          scanf("%d", &cadastros[escolha].telefone[i]);
        }while((cadastros[escolha].telefone[i] < 0) || (cadastros[escolha].telefone[i] > 9999));
      }
      limpa();
      break;

// empresa, renda e estado civil <==== escrevi pra lembrar pq minha mente ja ta falhando
      case 13:
      header();
      printf("Digite o nome da empresa que está trabalhando recentemente.\n\nDigite aqui sua resposta ====> ");
      gets(cadastros[escolha].empresa);
      cadastros[escolha].tempo = 0;
      limpa();
      break;

      case 14:
      header();
      printf("Digite sua nova renda mensal.\n\nDigite aqui sua resposta ====> ");
      scanf("%f",&cadastros[escolha].renda);
      limpa();
      break;

      case 15:
      do{
      header();
      printf("Digite seu novo estado civil.\n1)Casado(a)\n2)Solteiro(a)\n3)Viúvo(a)\n4)Separado\n5)Divorciado\n\nDigite aqui sua resposta ====> ");
      scanf("%d", cadastros[escolha].civil);
      limpa();
      }while((cadastros[escolha].civil < 1) || (cadastros[escolha].civil > 5));
      break;
    }
}

void excluir() {
    int escolha;
  
    header();
    printf("Qual perfil você deseja excluir?\n");
    for (i = 0; i < searchCadastro; i++) {
        printf("%d) %s\n", i+1, cadastros[i].nome);
    }

    printf("\n\nDigite aqui sua resposta ====> ");
    scanf("%d", &escolha);
    limpa();

    if (escolha >= 0 && escolha < searchCadastro) {
        // Desloca os elementos para trás para preencher o espaço do elemento excluído
        for (i = escolha; i < searchCadastro - 1; i++) {
            cadastros[i] = cadastros[i + 1];
        }

        searchCadastro--; // Decrementa a contagem de cadastros
        printf("Perfil excluído com sucesso.\n");
    }
}

void consultar(){
      int escolha;
  
    header();
    printf("Qual perfil você deseja consultar?\n");
    for (i = 0; i < searchCadastro; i++) {
        printf("%d) %s\n", i+1, cadastros[i].nome);
    }

    printf("\n\nDigite aqui sua resposta ====> ");
    scanf("%d", &escolha);
    limpa();

    header();
    printf("Nome: %s\n", cadastros[escolha].nome);
    printf("CPF: %d.%d.%d-%d\n", cadastros[escolha].cpf[0], cadastros[escolha].cpf[1], cadastros[escolha].cpf[2], cadastros[escolha].cpf[3]);
    printf("RG: %d.%d.%d-%d\n", cadastros[escolha].rg[0], cadastros[escolha].rg[1], cadastros[escolha].rg[2], cadastros[escolha].rg[3]);
    printf("Nacionalidade: %s\n", cadastros[escolha].nacionalidade);
    printf("Naturalidade: %s\n", cadastros[escolha].naturalidade);
    printf("Data Nascimento: %d/%d/%d\n", cadastros[escolha].nasc[0], cadastros[escolha].nasc[1], cadastros[escolha].nasc[2]);
    printf("Rua: %s\n", cadastros[escolha].enderec);
    printf("Bairro: %s\n", cadastros[escolha].bairro);
    printf("Número da casa: %dº", cadastros[escolha].csNum);
    printf("Cidade: %s\n", cadastros[escolha].cidade);
    printf("Estado: %s\n", cadastros[escolha].estado);
    if(cadastros[escolha].csPRouAL == 0){
      printf("Casa alugada\n");
    }else{
      printf("Casa Própria\n");
    }
    printf("Telefone: +55 %d-%d\n", cadastros[escolha].telefone);
    printf("Renda Mensal: %2.f\n", cadastros[escolha].renda);
    printf("Trabalha na empresa %s, a %d dias\n", cadastros[escolha].empresa, cadastros[escolha].tempo);
    printf("Seção: \n", cadastros[escolha].secao);
    //1)Casado(a)\n2)Solteiro(a)\n3)Viúvo(a)\n4)Separado\n5)Divorciado
    if(cadastros[escolha].civil == 1){
      printf("Estado Civil: Casado");
    }
    else if (cadastros[escolha].civil == 2){
      printf("Estado Civil: Solteiro");
    }
    else if (cadastros[escolha].civil == 3){
      printf("Estado Civil: Solteiro");
    }
    else if (cadastros[escolha].civil == 4){
      printf("Estado Civil: Separado");
    }
    else if (cadastros[escolha].civil == 5){
      printf("Estado Civil: Divorciado");
    }

}
void main(){
  setlocale(LC_ALL, "portuguese");
  limpa();
  header();
  int menu;
  int escolha;
  do{
  printf("Bem-vindo ao nosso sistema, o que deseja?\n1)Cadastrar\n2)Alterar Cadastro\n3)Consultar Cadastro\n4)Excluir Cadastro\n5)Encerrar programa\n\nDigite sua resposta aqui ====> ");
  scanf("%d", &menu);
  }while((menu < 1) || (menu > 5));

  switch(menu){
    case 1:
    limpa();
    cadastro();// <=== Se atente que NAO É "cadastros" e sim ===> CADASTROOOO
    limpa();
    header();
    printf("Deseja voltar ao menu principal?\n1)Sim\n2)Não\n\nDigite sua resposta aqui ====> ");
    scanf("%d", &escolha);

    if(escolha == 1){
      main();
    }
    break;
  
  case 2:
    limpa();
    alterar();
    limpa();
    header();
    printf("Deseja voltar ao menu principal?\n1)Sim\n2)Não\n\nDigite sua resposta aqui ====> ");
    scanf("%d", &escolha);

    if(escolha == 1){
      main();
    }
    break;

    case 3:
    limpa();
    consultar();
    printf("\n\nDeseja voltar ao menu principal?\n1)Sim\n2)Não\n\nDigite sua resposta aqui ====> ");
    scanf("%d", &escolha);
    if(escolha == 1){
      main();
    }
    break;

    case 4:
    limpa();
    excluir();
    limpa();
    header();
    printf("Deseja voltar ao menu principal?\n1)Sim\n2)Não\n\nDigite sua resposta aqui ====> ");
    scanf("%d", &escolha);
    if(escolha == 1){
      main();
    }
    break;
  }
  }