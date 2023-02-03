#include <stdio.h>
#include <stdlib.h>
#include "console.h"

#define LIMITE 156
#define LIMITE_VERT 40


void clear() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void imprimir_em(int x, int y, char *texto) { // imprimir um texto em alguma posição da tela
    printf("\033[%d;%dH", y, x); // move o cursor para a posição (x, y)
    printf("%s", texto); // exibe o texto na tela
    fflush(stdout); // força o buffer de saída a ser esvaziado
}

void init(int lines){
int k;
for(k=1;k<=lines;k++){
    printf("\n");
    }
fflush(stdout);
}
