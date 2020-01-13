#include <stdio.h>
#include <string.h>
int main() {
  char nome[80];
  float p1, p2;
  printf("Nome do aluno: ");
  fgets(nome, 80, stdin);
  nome[strlen(nome)-1] = '\0';
  printf("Nota P1 = ");
  scanf("%f", &p1);
  printf("Nota P2 = ");
  scanf("%f", &p2);
  printf("O aluno: %s, com P1 = %5.2f e P2 = %5.2f ficou com média %4.1f\n",
         nome, p1, p2, (p1 + p2)/2);
}