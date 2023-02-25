#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "jogo.h"
#include "console.h"

void jogo(float coordenada, float distancia, bool esquerda, char player1[], char player2[], int pontuacao[], int pontuacao1, int pontuacao2, int score1, int score2, float posicao_macaco1, float posicao_macaco2) {

    float grv = 10;
    float altura = LIMITE_VERT - 4 - (((vel*vel)*(sin(ang)*sin(ang)))/(2*grv));
    float alcance = ((vel*vel)*sin(2*ang))/grv + posicao_macaco1;

    typedef struct {
        int x;
        int y;
        int ativa;
        int traj_A;
        int traj_B;
    } Banana;

    // Criação do vetor de bananas
    Banana bananas[1] = { {0, 0, 0, 0, 0} };

    while (score1 > 0 && score2 > 0) {
        esquerda, acertou, score1, score2 = trajetoria(bananas, posicao_macaco1, posicao_macaco2, altura, esquerda, score1, score2);
        sleep(1);

        if (esquerda == 0) {
            if (acertou == 1) {
                pontuacao += PONTOS_ACERTO;
                pontuacao1 += pontuacao;
                score2--;
                pontuacao = 0;
            } else {
                pontuacao -= PONTOS_ERRO;
                pontuacao1 += pontuacao;
                pontuacao = 0;
            }
        } else {
            if (acertou == 1) {
                pontuacao += PONTOS_ACERTO;
                pontuacao2 += pontuacao;
                score1--;
                pontuacao = 0;
            } else {
                pontuacao -= PONTOS_ERRO;
                pontuacao2 += pontuacao;
                pontuacao = 0;
            }
        }

        posicao_macaco1, posicao_macaco2, ang, vel, score1, score2 = layout(coordenada, distancia, esquerda, player1, player2, pontuacao1, pontuacao2, posicao_macaco1, posicao_macaco2, score1, score2);

        if (esquerda == 1) {
            altura = LIMITE_VERT - 4 - (((vel*vel)*(sin(ang)*sin(ang)))/(2*grv));
            alcance = ((vel*vel)*sin(2*ang))/grv + posicao_macaco1;
        } else {
            altura = LIMITE_VERT - 4 - (((vel*vel)*(sin(ang)*sin(ang)))/(2*grv));
            alcance = ((vel*vel)*sin(2*ang))/grv + posicao_macaco1;
        }

        sleep(0.1);
    }
}
