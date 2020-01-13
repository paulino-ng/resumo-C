/*
 * forca.c - jogo da forca sem forca
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// algumas variaveis globais
char *palavras[] = { "absolutismo", "totalitarismo", "inconstitucionalista",
            "oba", "oca", "asa", "aba", "tab", "ola", "ada" };
int nb_palavras = (int) (sizeof palavras)/sizeof(char*);
const int MAX_CHUTES = 6;

void forca(void) {
  char palavra[32];
  strncpy(palavra, palavras[rand() % nb_palavras], 32);
  char mostra[64];
  int i;
  for (i = 0; i < strlen(palavra); i++) {
    mostra[2*i] = '_';
    mostra[2*i + 1] = ' ';
  }
  mostra[2*i] = '\0';
  printf("Adivinhe a palavra: %s\n", mostra);
  int chutes = 0;
  int acertos = 0;
  char chs[26];
  chs[0] = '\0';
  while (chutes < MAX_CHUTES) {
    char ch;
    printf("Chute uma letra: ");
    scanf("%c", &ch);
    char lixo[80];
    fgets(lixo,80,stdin);  // para ler o fim de linha, salto de linha
    if (index(chs, ch)) {
      printf("%c jah foi chutada\n", ch);
      continue;
    }
    else {
      chs[i = strlen(chs)] = ch;
      chs[i+1] = '\0';
    }
    int acertou = 0;
    char *pos = palavra;
    while ((pos = index(pos, ch)) != NULL) {
      i = pos - palavra;
      mostra[2*i] = ch;
      acertos++;
      acertou = 1;
      pos++;
    }
    if (! acertou) {
      chutes++;
      printf("'%c' nao aparece na palavra\n", ch);
    }
    else
      printf("%s\n", mostra);
    if (acertos == strlen(palavra)) break;
  }
  if (acertos == strlen(palavra)) printf("Parabens!\n");
  else 
    printf("Voce foi enforcado\n");
}

int main() {
  srand(time(NULL));
  printf("sizeof palavras = %d\n", nb_palavras);
  forca();
  return 0;
}
