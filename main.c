/* 
 * File:   main.c
 * Author: Pang
 * Descricao: testa Aluno
 * Created on 27 November 2019, 16:05
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _aluno {
    char nome[80];
    long matr;
    float av1, av2, media;
} Aluno;

int leUsuario(Aluno*);
void imprime(Aluno*);
float mediaAv1(Aluno**);
float mediaAv2(Aluno**);
int leArquivo(Aluno*, FILE*);
void escreveArquivo(Aluno*, FILE*);
  
#define MAX_LINHA 128
/*
 * Este programa testa as funções para manipular Aluno.
 */
int main(int argc, char** argv) {
    Aluno *pAl = (Aluno*) malloc(sizeof(Aluno));
    Aluno *als[10];
    als[0] = pAl;
    als[1] = pAl;
    als[2] = NULL;
    leUsuario(pAl);
    imprime(pAl);
    printf("Media av1 = %5.1f\n", mediaAv1(als));
    printf("Media av2 = %5.1f\n", mediaAv2(als));
//    FILE *outf = fopen("test.txt", "w");
//    escreveArquivo(pAl,outf);
//    fclose(outf);
    printf("Read al2\n");
    Aluno *pAl2 = (Aluno*) malloc(sizeof(Aluno));
    FILE *inf = fopen("test.txt", "r");
    leArquivo(pAl2, inf);
    imprime(pAl2);
    fclose(inf);
    free(pAl2);
    free(pAl);
    return (EXIT_SUCCESS);
}

int leUsuario(Aluno *pAl) {
    printf("Nome: ");
    fgets(pAl->nome, 80, stdin);
    if (strlen(pAl->nome) <= 1) return 0;
    pAl->nome[strlen(pAl->nome) - 1] = '\0';
    printf("Numero de matricula: ");
    scanf("%ld", &(pAl->matr));
    printf("Nota da avaliacao 1: ");
    scanf("%f", &(pAl->av1));
    printf("Nota da avaliacao 2: ");
    scanf("%f", &(pAl->av2));
    char lixo[80];
    fgets(lixo,80,stdin);
    pAl->media = (pAl->av1 + 2 * pAl->av2)/3;
    return 1;
}
void imprime(Aluno *pAl) {
    printf("%s;%ld;%4.1f;%4.1f;%4.1f\n",
            pAl->nome, pAl->matr, pAl->av1,
            pAl->av2, pAl->media);
}
float mediaAv1(Aluno** als) {
    int i;
    int len = sizeof als/sizeof(Aluno*);
    float acc = 0.0F;
    for (i = 0; (i<len) && als[i]; i++) {
        acc += als[i]->av1;
    }
    return acc / i;
}
float mediaAv2(Aluno** als) {
    int i;
    int len = sizeof als/sizeof(Aluno*);
    float acc = 0.0F;
    for (i = 0; (i<len) && als[i]; i++) {
        acc += als[i]->av2;
    }
    return acc / i;
}
int leArquivo(Aluno *pAl, FILE *inputf) {
    char linha[MAX_LINHA];
    if (!fgets(linha,MAX_LINHA,inputf))
        return 0;
    if (strlen(linha) < 4) return 0;
    char *cursor = linha;
    int i;
    for (i=0; (i<MAX_LINHA) && *cursor &&
            (*cursor != ';'); i++, cursor++)
        pAl->nome[i] = *cursor;
    pAl->nome[i] = '\0';
    sscanf(cursor,";%d;%f;%f",&(pAl->matr),
            &(pAl->av1),&(pAl->av2));
    pAl->media = (pAl->av1 + 2*pAl->av2)/3;
    return 1;}
void escreveArquivo(Aluno *pAl, FILE *outf) {
    fprintf(outf,"%s;%ld;%4.1f;%4.1f\n",
            pAl->nome,pAl->matr,pAl->av1,
            pAl->av2);
}

