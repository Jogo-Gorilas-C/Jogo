#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "console.h"

int main(int argc, char *argv[]){

//Variáveis
#define LIMITE 156
#define LIMITE_VERT 40
#define PONTOS_ACERTO 100
#define PONTOS_ERRO 1

float POSICAO;
int continuar;
int opcao = 0;
int x = 2;
int score1 = 2;
int score2 = 2;
int esquerda = 1;
char macaco[1];
strcpy(macaco, "O");
char player1[10];
strcpy(player1, "player1\0");
char player2[10];
strcpy(player2, "player2\0");
int pontuacao1 = 0;
int pontuacao2 = 0;
int pontuacao = 0;
int pontuacao_final1 = 0;
int pontuacao_final2 = 0;
int posicao_macaco1 = 0;
int posicao_macaco2 = 0;
char Rank[3][10] = {"player1\0","player2\0","player3\0"};
int pontos[3] = {0, 0, 0};



#TUTORIAL

void tutorial(char *player1, char *player2, int pontuacao, int pontuacao1, int pontuacao2, int score1, int score2, int posicao_macaco1, int posicao_macaco2, char rank[3][10], int pontos[3], int pontuacao_final1, int pontuacao_final2) {
    clear();
    imprimir_em((LIMITE / 2) - 4, 2, "Tutorial");
    imprimir_em((LIMITE / 2) - 44, 10, "Os jogadores devem informar os seguintes valores: ângulo(em graus) e velocidade(em m/s)");
    imprimir_em(1, LIMITE_VERT-4, "0 - PULAR TUTORIAL \n1 - CONTINUAR\n");
    scanf("%d", &continuar);
    system("pause");
    if(continuar == 1){
        clear();
        imprimir_em((LIMITE / 2) - 4, 2, "Tutorial");
        imprimir_em((LIMITE / 2) - 33, 10, "Lançamento falho: -1 ponto        Lançamento certeiro: +100 pontos");
        imprimir_em(1, LIMITE_VERT-4, "0 - PULAR TUTORIAL \n1 - CONTINUAR\n");
        scanf("%d", &continuar);
        if(continuar == 1){
            clear();
            imprimir_linha(1, "=");
            imprimir_em((LIMITE / 2) - 4, 2, "Tutorial");
            imprimir_em((LIMITE / 2) - 41, 10, "Cada jogador possui 2 vidas, vence o jogador que acabar com as vidas do adversário");
            imprimir_linha(3, "=");
            imprimir_em(1, LIMITE_VERT-4, "1 - CONTINUAR\n");
            scanf("%d", &continuar);
            if(continuar == 1){
                clear();
                            }
            else{
                clear();
            }
        }
        else{
            clear();
        }
    }
    else{
        clear();
    }
}


#RANKING

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


#MENU

void menu(char* player1, char* player2, int pontuacao, int pontuacao1, int pontuacao2, int score1, int score2, int posicao_macaco1, int posicao_macaco2, char rank[3][10], int pontos[3], int pontuacao_final1, int pontuacao_final2){
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


#DIFICULDADE

int dificuldade(){
clear();
imprima_em((LIMITE / 2) - 15, 2, "ESCOLHA A DIFICULDADE DO JOGO:");
imprima_em((LIMITE / 2) - 25, 5, "1 - FÁCIL : distância entre os macacos é mostrada");
imprima_em((LIMITE / 2) - 25, 8, "2 - MÉDIO : as posições dos macacos é mostrada");
imprima_em((LIMITE / 2) - 25, 11, "3 - DIFÍCIL : distância  e posição não são mostrados\n");
scanf("%d", &x);
}

return 0;
}
}
