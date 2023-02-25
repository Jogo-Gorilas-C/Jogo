#include <stdio.h>
#include <stdlib.h>
#include "dificuldade.h"
#include "console.h"

int dificuldade(){
clear();
imprima_em((LIMITE / 2) - 15, 2, "ESCOLHA A DIFICULDADE DO JOGO:");
imprima_em((LIMITE / 2) - 25, 5, "1 - FÁCIL : distância entre os macacos é mostrada");
imprima_em((LIMITE / 2) - 25, 8, "2 - MÉDIO : as posições dos macacos é mostrada");
imprima_em((LIMITE / 2) - 25, 11, "3 - DIFÍCIL : distância  e posição não são mostrados\n");
scanf("%d", &x);
}
