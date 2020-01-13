/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Pang
 *
 * Created on 13 July 2019, 19:57
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    printf("Alo, Mamae!\n");
    printf("De-me um numero inteiro: ");
    int n;
    scanf("%d", &n);
    printf("O numero lido foi: %d\n", n);
    fflush(stdout);
    printf("De-me um numero real: ");
    float f;
    scanf("%f", &f);
    printf("O numero lido foi: %f\n", f);
    fflush(stdout);
    return (EXIT_SUCCESS);
}

