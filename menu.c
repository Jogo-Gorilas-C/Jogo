#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "menu.h"
#include "console.h"

void menu(char* player1, char* player2, int pontuacao, int pontuacao1, int pontuacao2, int score1, int score2, int posicao_macaco1, int posicao_macaco2, char Rank[3][10], int pontos[3], int pontuacao_final1, int pontuacao_final2){
int x = 0;
while(opcao != 1){
    clear();
    imprimir_em((LIMITE / 2) - 2, 2, "MENU");
    imprimir_em(1 , 13, "1 - JOGAR");
    imprimir_em(1 , 15, "2 - DIFICULDADE");
    imprimir_em(1 , 17, "3 - RANKING");
    imprimir_em(1 , 19, "5 - SAIR");
    imprimir_em(LIMITE - 35, 49, "ALUNOS:");
    imprimir_em(LIMITE - 35, 50, "Arthur Marcelino Batista da Silva");
    imprimir_em(LIMITE - 35, 51, "Luan Rubens Saraiva Barroso");
    imprimir_em(LIMITE - 35, 52, "Lucas Cesar da Silva\n");
    scanf("%d", &opcao);
    if(opcao == 1){
        clear();
        imprimir_em((LIMITE / 2) - 6, 2, "JOGADORES");
        imprimir_em(1, 3, "Digite nome do primeiro jogador: ");
        scanf("%s", &player1);
        imprimir_em(1, 6, "Digite nome do primeiro jogador: ");
        scanf("%s", &player2);
        if(x == 0 || x == 2){
            jogo(1, 0, esquerda, player1, player2, pontuacao, pontuacao1, pontuacao2, score1, score2, posicao_macaco1, posicao_macaco2);
        } else if (x == 1) {
            jogo(1, 1, esquerda, player1, player2, pontuacao, pontuacao1, pontuacao2, score1, score2, posicao_macaco1, posicao_macaco2);
        } else if (x == 3) {
            jogo(0, 0, esquerda, player1, player2, pontuacao, pontuacao1, pontuacao2, score1, score2, posicao_macaco1, posicao_macaco2);
        }
    } else if (opcao == 2){
        int x = dificuldade();
    } else if (opcao == 3){
        ranking(Rank, pontos);
    } else if(opcao == 4){
    clear();
    imprimir_em((LIMITE / 2) - 7, 15, "Obrigado por jogar!");
    sleep(3);
    exit(0);
    }
}
