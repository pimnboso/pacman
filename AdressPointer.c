#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
  setlocale(LC_ALL, "Portuguese");
  int m;
  int n;
  int o;

  int *ptr_m;
  int *ptr_n;
  int *ptr_o;

  ptr_m = &m;

  printf("O valor de m é 10\nO valor de n é 1\nO valor de o é 0\n\n");
  printf("Z armazena o endereço de m: %d\n", &ptr_m);
  printf("Z armazena o endereço de m: 0x%X\n", &ptr_m);
  printf("Z armazena o valor de m: %d\n\n", ptr_m);

  printf("&m é o endereço de m: %d\n", &m);
  printf("&m é o endereço de m: %X\n\n", &m);

  printf("&m é o endereço de m: %d\n", &n);
  printf("&m é o endereço de m: %X\n\n", &n);

  printf("&m é o endereço de m: %d\n", &o);
  printf("&m é o endereço de m: %X\n\n", &o);

  printf("&m é o endereço de m: %d\n", &ptr_m);
  printf("&m é o endereço de m: %X", &ptr_m);
  } 