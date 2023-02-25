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

void reset(int x, int y, int lines, int columns) {
    printf("\033[%d;%dH", y, x);  // move o cursor para a posição (x, y)
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            printf(" ");  // escreve um espaço em branco na posição atual
        }
        printf("\033[1B");  // move o cursor para baixo
        printf("\033[%dD", columns);  // move o cursor de volta para a esquerda
    }
    printf("\033[%d;%dH", y, x);  // move o cursor de volta para a posição inicial
}
