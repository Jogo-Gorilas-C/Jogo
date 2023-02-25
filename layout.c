#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "layout.h"
#include "console.h"


void turnos(esquerda){
if(esquerda == 1){
   POSICAO = LIMITE/200;
   return 0;
}
else {
   POSICAO = LIMITE-15;
   return 1;
}
}

void layout(int coordenada, int distancia, int esquerda, char player1[10], char player2[10], int pontuacao1, int pontuacao2, int posicao_macaco1, int posicao_macaco2, int score1, int score2){
posicao_macaco = 1 + rand() % 60;
posicao_macaco2 = 140 + rand()% 60;
if(coordenada == 1){
    if(distancia == 1){
        while(score 1 > 0 && score2 > 0){
            esquerda = turnos(esquerda);
            init(LIMITE_VERT);
            imprimir_em(1,1, player1);
            imprimir_em((LIMITE / 2) - 10, LIMITE_VERT-2, "VIDA");
            imprimir_em(LIMITE - 17, 1, player2);
            imprimir_em( 1, 2, "Pontuação:");
            imprimir_em(LIMITE - 17, 2, "Pontuação:");
            imprimir_em((LIMITE / 2) - 8, 1, "Distância:");
            imprimir_em(posicao_macaco1, LIMITE_VERT - 5, "O");
            imprimir_em(posicao_macaco2, LIMITE_VERT - 5, "O");
            imprimir_em(POSICAO, LIMITE_VERT - 2, "Angulo: ")
            scanf("%d", &ang); //falta colocar em rad(talvez não precise)
            imprimir_em(POSICAO, LIMITE_VERT - 1, "Velocidade: ");
            scanf("f", &vel);
            return posicao_macaco1, posicao_macaco2, ang, vel, score1, score2;
        }
        if(score1 == 0){
            clear();
            imprimir_em(LIMITE/2 - 7, 15, player2);
            printf(" Venceu!");
            sleep(3);
            pontuacao_final1 = pontuacao1;
            pontuacao_final2 = pontuacao2;
            //ordenador_rank();
            //menu();
        }
        else if(score2 == 0){
            clear();
            imprimir_em(LIMITE/2 - 7, 15, player1);
            printf(" Venceu!");
            sleep(3);
            pontuacao_final1 = pontuacao1;
            pontuacao_final2 = pontuacao2;
            //ordenador_rank();
            //menu();
        }
        }
        else{}
    }
}
