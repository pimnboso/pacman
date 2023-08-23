#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
  setlocale(LC_ALL, "Portuguese");
  system("clear");
  int a, b, c , d, e, f;
  a = 10;
  b = 20;
  c = 30;
  d = 40;
  e = 50;
  f = 60;

  printf("O conteúdo da variável a é: %d       Ela está no endereço de memória 0x%X\n", a, &a);
  printf("O conteúdo da variável b é: %d       Ela está no endereço de memória 0x%X\n", b, &b);
  printf("O conteúdo da variável c é: %d       Ela está no endereço de memória 0x%X\n", c, &c);
  printf("O conteúdo da variável d é: %d       Ela está no endereço de memória 0x%X\n", d, &d);
  printf("O conteúdo da variável e é: %d       Ela está no endereço de memória 0x%X\n", e, &e);
  printf("O conteúdo da variável f é: %d       Ela está no endereço de memória 0x%X", f, &f);
  }