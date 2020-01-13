#include <string.h>
#include <stdio.h>

int main () {
    char str[80] = "Raul Andrade; 4.5; 7";
    char nome[64];
    char* cursor;
    float p1, p2;
	double d;
    int i;
    for (cursor = str, i = 0; *cursor && *cursor != ';'; cursor++, i++)
        nome[i] = *cursor;
    nome[i+1]='\0';
    sscanf(cursor, ";%f;%f", &p1, &p2);
    printf("Nome: %s,\tP1 = %4.1f,\tP2 = %4.1f,\tMedia = %4.1f\n", nome, p1, p2, (p1 + p2)/2);
	printf("sizeof nome[64] = %d, sizeof float = %d, sizeof double = %d\n", sizeof nome, sizeof p1, sizeof d);
	printf("len(nome) = %d\n", strlen(nome));
	char ch;
    short sh;
    long li;
	long long int lli;
    float ff;
    double dd;
	long double ld;
    unsigned sz;
    sz = sizeof ch;
    printf("Tamanho do char = %d\n", sz);
    sz = sizeof sh;
    printf("Tamanho do short = %d\n", sz);
    sz = sizeof i;
    printf("Tamanho do int = %d\n", sz);
    sz = sizeof li;
    printf("Tamanho do long = %d\n", sz);
    sz = sizeof lli;
    printf("Tamanho do long long int = %d\n", sz);
    sz = sizeof ff;
    printf("Tamanho do float = %d\n", sz);
    sz = sizeof dd;
    printf("Tamanho do double = %d\n", sz);
    sz = sizeof ld;
    printf("Tamanho do long double = %d\n", sz);
    return(0);
}