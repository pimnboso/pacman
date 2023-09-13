#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
  // -============ NAO COLOCAR EM FUNÇAO =============-
  struct Ponto{
    char enderecoP[200];
    int data[3], periodo, caucao, agua, luz, iptu;
    float aluguel;
  };

  struct Banco{
    char nomebanco[100];
    int ag, conta;
  };

  struct Pessoas{
    char nome[100], endereco[200], email[100];
    int civil;
    int rg[4];
    int cpf[4];
    int telefone[2];
    struct Banco banco;
    struct Ponto ponto;
  } dadosP[50];

  int searchCadastro = 0 ;
  int i;
  // -============ NAO COLOCAR EM FUNÇAO =============-
void header(){
  printf("*********************************************************\n");
  printf("******************** FICHA CADASTRAL ********************\n");
  printf("*********************************************************\n\n\n\n");
}
void limpa(){
  system("clear");
}

void cadastro(){
  limpa();
  header();
  fflush(stdin);
  printf("Digite o nome do proprietário\n\nDigite sua resposta aqui ====> ");
  gets(dadosP[searchCadastro].nome);

  limpa();
  header();
  printf("Digite o endereço do proprietário\n\nDigite sua resposta aqui ====> ");
  gets(dadosP[searchCadastro].endereco);

  limpa();
  header();
  fflush(stdin);
  printf("Digite o estado civil do proprietário\n1)Solteiro\n2)Casado\n3)Viúvo\n4)Separado\n5)Divorciado\n\nDigite sua resposta aqui ====> ");
  scanf("%d", &dadosP[searchCadastro].civil);

  // -========CPF========-
  for(i = 0; i < 4; i++){
    limpa();
    header();
       if(i < 3){
          do{
         printf("Digite os 3 %dº números de seu cpf\n\nDigite sua resposta aqui ====> ", i+1);
         scanf("%d", &dadosP[searchCadastro].cpf[i]);
            }while((dadosP[searchCadastro].cpf[i] < 0) || (dadosP[searchCadastro].cpf[i] > 999));
       }

       if(i == 3){
          do{
         printf("Digite os 2 %dº números de seu cpf\n\nDigite sua resposta aqui ====> ", i+1);
         scanf("%d", &dadosP[searchCadastro].cpf[i]);
            }while((dadosP[searchCadastro].cpf[i] < 0) || (dadosP[searchCadastro].cpf[i] > 99));
       }
  }

  // -======== RG ========-
    for(i = 0; i < 4; i++){
    limpa();
    header();
    fflush(stdin);
         if(i == 0){
         do{
         printf("Digite os 2 %dº números de seu rg\n\nDigite sua resposta aqui ====> ", i+1);
         scanf("%d", &dadosP[searchCadastro].rg[i]);
            }while((dadosP[searchCadastro].rg[i] < 0) || (dadosP[searchCadastro].rg[i] > 99));
                   }
    
       if((i == 1) || (i == 2)){
          do{
         printf("Digite os 3 %dº números de seu rg\n\nDigite sua resposta aqui ====> ", i+1);
         scanf("%d", &dadosP[searchCadastro].rg[i]);
            }while((dadosP[searchCadastro].rg[i] < 0) || (dadosP[searchCadastro].rg[i] > 999));
       }

       if(i == 3){
          do{
         printf("Digite o último número de seu rg\n\nDigite sua resposta aqui ====> ", i+1);
         scanf("%d", &dadosP[searchCadastro].rg[i]);
            }while((dadosP[searchCadastro].rg[i] < 0) || (dadosP[searchCadastro].rg[i] > 9));
       }
  }

  for(i = 0; i < 2; i++){
    limpa();
    header();
    do{
    printf("Digite os 4 %dº números do telefone\n\nDigite sua resposta aqui ====> ", i+1);
    scanf("%d", &dadosP[searchCadastro].telefone[i]);
    }while((dadosP[searchCadastro].telefone[i] < 0) || (dadosP[searchCadastro].telefone[i] > 9999));
  }

  limpa();
  header();
  fflush(stdin);
  printf("Digite seu email\n\nDigite sua resposta aqui ====> ");
  gets(dadosP[searchCadastro].email);

  //-======== BANCO ========-
  limpa();
  header();
  printf("Digite o nome do seu banco\n\n Digite sua resposta aqui ====> ");
  gets(dadosP[searchCadastro].banco.nomebanco);

  limpa();
  header();
  fflush(stdin);
  printf("Digite sua conta bancária\n\n Digite sua reposta aqui ====> ");
  scanf("%d", &dadosP[searchCadastro].banco.conta);

  limpa();
  header();
  printf("Digite sua agência bancária\n\n Digite sua reposta aqui ====> ");
  scanf("%d", &dadosP[searchCadastro].banco.ag);


  // -======= PONTO A SER ALUGADO ========-
  limpa();
  header();
  fflush(stdin);
  printf("Digite o endereço do ponto a ser alugado\n\n Digite sua resposta aqui ====> ");
  gets(dadosP[searchCadastro].ponto.enderecoP);

  for(i = 0; i < 3; i++){
    limpa();
    header();
    fflush(stdin);
    if(i == 0){
      do{
      printf("Digite o dia de início do contrato\n\n Digite sua resposta aqui ====> ");
      scanf("%d", &dadosP[searchCadastro].ponto.data[i]);
      }while((dadosP[searchCadastro].ponto.data[i] > 31) || (dadosP[searchCadastro].ponto.data[i] < 1));
    }
    else if(i == 1){
      do{
      printf("Digite o mês de início do contrato\n\n Digite sua resposta aqui ====> ");
      scanf("%d", &dadosP[searchCadastro].ponto.data[i]);
      }while((dadosP[searchCadastro].ponto.data[i] > 12) || (dadosP[searchCadastro].ponto.data[i] < 1));
    }
    else{
      do{
      printf( "Digite o ano de início do contrato\n\n Digite sua resposta aqui ====> ");
      scanf("%d", &dadosP[searchCadastro].ponto.data[i]);
      }while(dadosP[searchCadastro].ponto.data[i] < 2023);
    }
  }
  limpa();
  header();
  do{
  printf("Digite o período de contrato OBS: em dias\n\nDigite sua resposta aqui ====> ");
  scanf("%d", &dadosP[searchCadastro].ponto.periodo);
  }while(dadosP[searchCadastro].ponto.periodo < 1);

  limpa();
  header();
  printf("Digite o valor do ponto\n\n Digite aqui sua resposta ====> ");
  scanf("%f", &dadosP[searchCadastro].ponto.aluguel);
  
  limpa();
  header();
  fflush(stdin);
  printf("Terá pagamento de caução? \n1) Sim\n2)Não\n\n Digite sua resposta aqui====> ");
  scanf("%d", &dadosP[searchCadastro].ponto.caucao);

  limpa();
  header();
  printf("Terá pagamento de água? \n1) Sim\n2)Não\n\n Digite sua resposta aqui====> ");
  scanf("%d", &dadosP[searchCadastro].ponto.agua);

  limpa();
  header();
  printf("Terá pagamento de luz? \n1) Sim\n2)Não\n\n Digite sua resposta aqui====> ");
  scanf("%d", &dadosP[searchCadastro].ponto.luz);

  limpa();
  header();
  printf("Terá pagamento de IPTU? \n1) Sim\n2)Não\n\n Digite sua resposta aqui====> ");
  scanf("%d", &dadosP[searchCadastro].ponto.iptu);

  searchCadastro++;
}
void alterar(){
  header();
  limpa();
  fflush(stdin);
  int escolhaC;
  int escolha;
  printf("Escolha o cadastro que deseja alterar\n\n");
  for(i = 0; i < searchCadastro; i++){
    printf("%d)%s", i+1, dadosP[i].nome);
  }
  printf("\n\nDigite sua resposta aqui ====> ");
  scanf("%d", &escolhaC);
  escolhaC = escolhaC - 1;
  
  header();
  limpa();
  printf("Digite qual opção deseja alterar");
  printf("1) Nome do proprietário \n2)Endereço do proprietário\n3)Estado Civil\n4)CPF\n5)RG\n6)Telefone\n7)Email\n8)Nome do banco\n9)Conta\n10)Agência\n11)Endereço do ponto\n12)Valor do aluguel\n13)Data de início\n14)Período do contrato");
  scanf("%d", &escolha);

  header();
  limpa();
  fflush(stdin);
  switch(escolha){
    case 1:
  printf("Digite o nome do proprietário\n\nDigite sua resposta aqui ====> ");
  gets(dadosP[escolhaC].nome);
  break;

  case 2:
  printf("Digite o endereço do proprietário\n\nDigite sua resposta aqui ====> ");
  gets(dadosP[escolhaC].endereco);
  break;

  case 3:
  printf("Digite o estado civil do proprietário\n1)Solteiro\n2)Casado\n3)Viúvo\n4)Separado\n5)Divorciado\n\nDigite sua resposta aqui ====> ");
  scanf("%d", &dadosP[escolhaC].civil);

  case 4:
    for(i = 0; i < 4; i++){
    limpa();
    header();
       if(i < 3){
          do{
         printf("Digite os 3 %dº números de seu cpf\n\nDigite sua resposta aqui ====> ", i+1);
         scanf("%d", &dadosP[escolhaC].cpf[i]);
            }while((dadosP[escolhaC].cpf[i] < 0) || (dadosP[escolhaC].cpf[i] > 999));
       }

       if(i == 3){
          do{
         printf("Digite os 2 %dº números de seu cpf\n\nDigite sua resposta aqui ====> ", i+1);
         scanf("%d", &dadosP[escolhaC].cpf[i]);
            }while((dadosP[escolhaC].cpf[i] < 0) || (dadosP[escolhaC].cpf[i] > 99));
       }
  }
  break;

  case 5:
      for(i = 0; i < 4; i++){
    limpa();
    header();
         if(i == 0){
         do{
         printf("Digite os 2 %dº números de seu rg\n\nDigite sua resposta aqui ====> ", i+1);
         scanf("%d", &dadosP[escolhaC].rg[i]);
            }while((dadosP[escolhaC].rg[i] < 0) || (dadosP[escolhaC].rg[i] > 99));
                   }
    
       if((i < 3) || (i > 0)){
          do{
         printf("Digite os 3 %dº números de seu rg\n\nDigite sua resposta aqui ====> ", i+1);
         scanf("%d", &dadosP[escolhaC].rg[i]);
            }while((dadosP[escolhaC].rg[i] < 0) || (dadosP[escolhaC].rg[i] > 999));
       }

       if(i == 3){
          do{
         printf("Digite o último número de seu rg\n\nDigite sua resposta aqui ====> ", i+1);
         scanf("%d", &dadosP[escolhaC].rg[i]);
            }while((dadosP[escolhaC].rg[i] < 0) || (dadosP[escolhaC].rg[i] > 9));
       }
  }
  break;

  case 6:
    for(i = 0; i < 2; i++){
    limpa();
    header();
    do{
    printf("Digite os 4 %dº números do telefone", i+1);
    scanf("%d", &dadosP[escolhaC].telefone[i]);
    }while((dadosP[escolhaC].telefone[i] < 0) || (dadosP[escolhaC].telefone[i] > 9999));
  }
  break;

  case 7:
  printf("Digite seu email\n\nDigite sua resposta aqui ====> ");
  gets(dadosP[escolhaC].email);
  break;

  case 8: 
  printf("Digite o nome do seu banco\n\n Digite sua resposta aqui ====> ");
  gets(dadosP[escolhaC].banco.nomebanco);
  break;

  case 9:
  printf("Digite sua conta bancária\n\n Digite sua reposta aqui ====> ");
  scanf("%d", &dadosP[escolhaC].banco.conta);
  break;

  case 10:
  printf("Digite sua agência bancária\n\n Digite sua reposta aqui ====> ");
  scanf("%d", &dadosP[escolhaC].banco.ag);
  break;

  case 11:
  printf("Digite o endereço do ponto a ser alugado\n\n Digite sua resposta aqui ====> ");
  gets(dadosP[searchCadastro].ponto.enderecoP);
  break;

  case 12:
  printf("Digite o valor do ponto\n\n Digite aqui sua resposta ====> ");
  scanf("%f", &dadosP[searchCadastro].ponto.aluguel);
  break;

  case 13:
  for(i = 0; i < 3; i++){
    limpa();
    header();
    if(i == 0){
      do{
      printf("Digite o dia de início do contrato\n\n Digite sua resposta aqui ====> ");
      scanf("%d", &dadosP[escolhaC].ponto.data[i]);
      }while((dadosP[escolhaC].ponto.data[i] > 31) || (dadosP[escolhaC].ponto.data[i] < 1));
    }
    else if(i == 1){
      do{
      printf("Digite o mês de início do contrato\n\n Digite sua resposta aqui ====> ");
      scanf("%d", &dadosP[escolhaC].ponto.data[i]);
      }while((dadosP[escolhaC].ponto.data[i] > 12) || (dadosP[escolhaC].ponto.data[i] < 1));
    }
    else{
      do{
      printf( "Digite o ano de início do contrato\n\n Digite sua resposta aqui ====> ");
      scanf("%d", &dadosP[escolhaC].ponto.data[i]);
      }while(dadosP[escolhaC].ponto.data[i] < 2023);
    }
  }
  break;

  case 14:
    do{
  printf("Digite o período de contrato OBS: em dias\n\nDigite sua resposta aqui ====> ");
  scanf("%d", &dadosP[escolhaC].ponto.periodo);
  }while(dadosP[escolhaC].ponto.periodo < 1);
  break;
  }
}
void consultar(){
  header();
  limpa();
  fflush(stdin);
  int escolhaC;
  int escolha;
  printf("Escolha o cadastro que deseja alterar\n\n");
  for(i = 0; i < searchCadastro; i++){
    printf("%d)%s", i+1, dadosP[i].nome);
  }
  printf("\n\nDigite sua resposta aqui ====> ");
  scanf("%d", &escolhaC);
  escolhaC = escolhaC - 1;

  header();
  limpa();
  printf("********** DADOS DO PROPRIETARIO **********\n\n");
  printf("Nome: %s\n", dadosP[escolhaC].nome);
  printf("Endereço: %s\n", dadosP[escolhaC].endereco);
  //1)Solteiro\n2)Casado\n3)Viúvo\n4)Separado\n5)Divorciado
  switch(dadosP[escolhaC].civil){
    case 1: 
    printf("Estado civil: Solteiro\n");
    break;

    case 2:
    printf("Estado civil: Casado\n");
    break;

    case 3:
    printf("Estado Civil: Viúvo\n");
    break;

    case 4:
    printf("Estado Civil: Separado\n");
    break;

    case 5:
    printf("Estado Civil: Divorciado\n");
    break;
  }

  printf("CPF: %d.%d.%d-%d\n", dadosP[escolhaC].cpf[0], dadosP[escolhaC].cpf[1], dadosP[escolhaC].cpf[2], dadosP[escolhaC].cpf[3]);
  printf("RG: %d.%d.%d-%d\n", dadosP[escolhaC].rg[0], dadosP[escolhaC].rg[1], dadosP[escolhaC].rg[2], dadosP[escolhaC].rg[3]);
  printf("Contato: %d-%d\n", dadosP[escolhaC].telefone[0], dadosP[escolhaC].telefone[1]);
  printf("Email: %s\n\n", dadosP[escolhaC].email);
  printf("************* DADOS BANCÁRIOS *************\n\n");
  printf("Nome do banco: %s\n", dadosP[escolhaC].banco.nomebanco);
  printf("Conta bancária: %d\n", dadosP[escolhaC].banco.conta);
  printf("Agência bancária: %d\n", dadosP[escolhaC].banco.ag);
  printf("************* DADOS DO PONTO **************\n\n");
  printf("Endereço do ponto: %s\n", dadosP[escolhaC].ponto.enderecoP);
  printf("Valor do aluguel: %f\n", dadosP[escolhaC].ponto.aluguel);
  printf("Data de início: %d/%d/%d\n", dadosP[escolhaC].ponto.data[0], dadosP[escolhaC].ponto.data[1], dadosP[escolhaC].ponto.data[2]);
  printf("Período do contrato: %d dias\n", dadosP[escolhaC].ponto.periodo);
  if(dadosP[escolhaC].ponto.caucao == 1){
    printf("Pagamento de caução: (X) Sim ( ) NÃO\n");
  }else{
    printf("Pagamento de caução: ( ) Sim (X) NÃO\n");
  }

  if(dadosP[escolhaC].ponto.agua == 1){
    printf("Pagamento de caução: (X) Sim ( ) NÃO\n");
  }else{
    printf("Pagamento de caução: ( ) Sim (X) NÃO\n");
  }

  if(dadosP[escolhaC].ponto.luz == 1){
    printf("Pagamento de caução: (X) Sim ( ) NÃO\n");
  }else{
    printf("Pagamento de caução: ( ) Sim (X) NÃO\n");
  }

  if(dadosP[escolhaC].ponto.iptu == 1){
    printf("Pagamento de caução: (X) Sim ( ) NÃO\n");
  }else{
    printf("Pagamento de caução: ( ) Sim (X) NÃO\n");
  }
}
void excluir() {
    int escolha;

    header();
    printf("Qual perfil você deseja excluir?\n");
    for (i = 0; i < searchCadastro; i++) {
        printf("%d) %s\n", i + 1, dadosP[i].nome);
    }

    printf("\n\nDigite aqui sua resposta ====> ");
    scanf("%d", &escolha);
    limpa();

    if (escolha >= 1 && escolha <= searchCadastro) {
        // Desloca os elementos para trás para preencher o espaço do elemento excluído
        for (i = escolha - 1; i < searchCadastro - 1; i++) {
            dadosP[i] = dadosP[i + 1];
        }

        searchCadastro--; // Decrementa a contagem de cadastros
        printf("Perfil excluído com sucesso.\n");
    } else {
        printf("Opção inválida. Nenhum perfil foi excluído.\n");
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