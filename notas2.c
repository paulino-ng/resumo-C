#include <string.h>
#include <stdio.h>

int main () {
    char str[80] = "Raul Andrade; 4.5; 7";
    char nome[64];
    char* cursor;
    float p1, p2;
    int i;
    for (cursor = str, i = 0; *cursor && *cursor != ';'; cursor++, i++)
        nome[i] = *cursor;
    nome[i+1]='\0';
    sscanf(cursor, ";%f", &p1);
    // avanca o cursor de um em um ate o fim da linha ou ate um ;
    // observe que o cursor atualmente está no primeiro ;, a inicializacao eh pula-lo
    for ( cursor++ ; *cursor && *cursor != ';'; cursor++) ;
    sscanf(cursor, ";%f", &p2);
    printf("Nome: %s,\tP1 = %4.1f,\tP2 = %4.1f\n", nome, p1, p2);
    return(0);
}