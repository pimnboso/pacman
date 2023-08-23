#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
  setlocale(LC_ALL, "Portuguese");
  int inteiro = 90;
  int *ptr_int;

  char charac[] = "salve";
  char *ptr_char;

  double dobro = 10.0;
  double *ptr_double;

  ptr_int = &inteiro;
  ptr_double = &dobro;
  ptr_char = &charac;

  system("clear");
  printf("O endereço de char é: %p\n", &charac);
  printf("O endereço de int é: %p\n", &inteiro);
  printf("O endereço de double é: %p\n\n", &dobro);

  printf("O endereço de *char é: %p\n", &ptr_char);
  printf("O endereço de *int é: %p\n", &ptr_int);
  printf("O endereço de *double é: %p\n\n", &ptr_double);

  printf("O valor de char é: %s\n", charac);
  printf("O valor de int é: %d\n", inteiro);
  printf("O valor de double é: %lf\n\n", dobro);

  printf("O valor apontado por ptr_char é: %s\n", *ptr_char);
  printf("O valor apontado por ptr_int é: %d\n", *ptr_int);
  printf("O valor apontado por ptr_double é: %lf\n\n", *ptr_double);

  printf("O tamanho da variável char é: %lu bytes\n", sizeof(charac));
  printf("O tamanho da variável int é: %lu bytes\n", sizeof(inteiro));
  printf("O tamanho da variável double é: %lu bytes\n\n", sizeof(dobro));

  printf("O tamanho da variável *char é: %lu bytes\n", sizeof(ptr_char));
  printf("O tamanho da variável *int é: %lu bytes\n", sizeof(ptr_int));
  printf("O tamanho da variável *double é: %lu bytes\n", sizeof(ptr_double));
}
