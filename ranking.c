#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ranking.h"
#include "console.h"

void ranking(char Rank[][10], int pontos[]) {
    int voltar_menu = 1;
    int i;
    while (voltar_menu != 0) {
        clear();
        imprimir_em((LIMITE / 2) - 6, 2, "RANKING");
        for (i = 0; i < 3; i++) {
            printf("\033[%d;%dH", 15 + i, LIMITE / 2 - 8);
            printf("%d - %s : %d\n", i + 1, Rank[i], pontos[i]);
            fflush(stdout);
        }
        imprimir_em(1, LIMITE_VERT - 4, "0 - VOLTAR\n");
        scanf("%d", &voltar_menu);
    }
}


void ordenador_rank(char Rank[][10], int pontos[], int pontuacao_final1, int pontuacao_final2, char player1[], char player2[]) {
    int i = 0, j = 0;
    while (i == 0) {
        if (pontuacao_final1 > pontos[0]) {
            char ord_rank[10], ord_pontos[10];
            strcpy(ord_rank, rank[0]);
            sprintf(ord_pontos, "%d", pontos[0]);
            strcpy(rank[0], player1);
            sprintf(pontos[0], "%d", pontuacao_final1);
            strcpy(rank[2], rank[1]);
            sprintf(pontos[2], "%d", pontos[1]);
            strcpy(rank[1], ord_rank);
            sprintf(pontos[1], "%s", ord_pontos);
        }
        else if (pontuacao_final1 > pontos[1]) {
            char ord_rank[10], ord_pontos[10];
            strcpy(ord_rank, rank[1]);
            sprintf(ord_pontos, "%d", pontos[1]);
            strcpy(rank[1], player1);
            sprintf(pontos[1], "%d", pontuacao_final1);
            strcpy(rank[2], ord_rank);
            sprintf(pontos[2], "%s", ord_pontos);
        }
        else if (pontuacao_final1 > pontos[2]) {
            strcpy(rank[2], player1);
            sprintf(pontos[2], "%d", pontuacao_final1);
        }
        i++;
    }
    while (j == 0) {
        if (pontuacao_final2 > pontos[0]) {
            char ord_rank[10], ord_pontos[10];
            strcpy(ord_rank, rank[0]);
            sprintf(ord_pontos, "%d", pontos[0]);
            strcpy(rank[0], player2);
            sprintf(pontos[0], "%d", pontuacao_final2);
            strcpy(rank[2], rank[1]);
            sprintf(pontos[2], "%d", pontos[1]);
            strcpy(rank[1], ord_rank);
            sprintf(pontos[1], "%s", ord_pontos);
        }
        else if (pontuacao_final2 > pontos[1]) {
            char ord_rank[10], ord_pontos[10];
            strcpy(ord_rank, rank[1]);
            sprintf(ord_pontos, "%d", pontos[1]);
            strcpy(rank[1], player2);
            sprintf(pontos[1], "%d", pontuacao_final2);
            strcpy(rank[2], ord_rank);
            sprintf(pontos[2], "%s", ord_pontos);
        }
        else if (pontuacao_final2 > pontos[2]) {
            strcpy(rank[2], player2);
            sprintf(pontos[2], "%d", pontuacao_final2);
        }
        j++;
    }
}
