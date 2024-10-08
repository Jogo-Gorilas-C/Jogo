#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#include "console.h"

//VARIÁVEIS
#define LIMITE 156
#define LIMITE_VERT 40
#define PONTOS_ACERTO 100
#define PONTOS_ERRO 1

float POSICAO;
float radianos;
int tam_bananas = 5;
int graus;
int vel;
int continuar;
int acertou;
int opcao = 0;
int x = 2;
int score1 = 2;
int score2 = 2;
int esquerda = 1;
char player1[12];
char player2[12];
int pontuacao1 = 0;
int pontuacao2 = 0;
int pontuacao = 0;
int pontuacao_final1 = 0;
int pontuacao_final2 = 0;
int posicao_macaco1 = 0;
int posicao_macaco2 = 0;
char Rank[3][10] = {"player1\0","player2\0","player3\0"};
int pontos[3] = {0, 0, 0};



//DEFININDO AS FUNÇÕES

void menu(char* player1, char* player2, int pontuacao, int pontuacao1, int pontuacao2, int score1, int score2, int posicao_macaco1, int posicao_macaco2, char Rank[3][10], int pontos[3], int pontuacao_final1, int pontuacao_final2);

void jogo(float coordenada, float distancia, int esquerda, char player1[], char player2[], int pontuacao[], int pontuacao1, int pontuacao2, int score1, int score2, float posicao_macaco1, float posicao_macaco2);

double layout(int coordenada, int distancia, int esquerda, char player1[10], char player2[10], int pontuacao1, int pontuacao2, int posicao_macaco1, int posicao_macaco2, int score1, int score2);

void turnos(esquerda);

int dificuldade();

void ranking(char Rank[][10], int pontos[]);

void ordenador_rank(char Rank[][10], int pontos[], int pontuacao_final1, int pontuacao_final2, char player1[], char player2[]);

void clear();

void imprimir_em(int x, int y, char *texto);

void reset(int x, int y, int lines, int columns);


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

//TUTORIAL
void tutorial() {
    clear();
    imprimir_em((LIMITE / 2) - 4, 2, "Tutorial");
    imprimir_em((LIMITE / 2) - 44, 10, "Os jogadores devem informar os seguintes valores: ângulo(em graus) e velocidade(em m/s)");
    imprimir_em(1, LIMITE_VERT-4, "0 - PULAR TUTORIAL \n1 - CONTINUAR\n");
    scanf("%d", &continuar);
    if(continuar == 1){
        clear();
        imprimir_em((LIMITE / 2) - 4, 2, "Tutorial");
        imprimir_em((LIMITE / 2) - 33, 10, "Lançamento falho: -1 ponto        Lançamento certeiro: +100 pontos");
        imprimir_em(1, LIMITE_VERT-4, "0 - PULAR TUTORIAL \n1 - CONTINUAR\n");
        scanf("%d", &continuar);
        if(continuar == 1){
            clear();
            imprimir_em((LIMITE / 2) - 4, 2, "Tutorial");
            imprimir_em((LIMITE / 2) - 41, 10, "Cada jogador possui 2 vidas, vence o jogador que acabar com as vidas do adversário");
            imprimir_em(1, LIMITE_VERT-4, "1 - CONTINUAR\n");
            scanf("%d", &continuar);
            if(continuar == 1){
                clear();
                menu(player1, player2, pontuacao, pontuacao1, pontuacao2, score1, score2, posicao_macaco1, posicao_macaco2, Rank[3][10], pontos[3], pontuacao_final1, pontuacao_final2);
                }
            else{
                clear();
                menu(player1, player2, pontuacao, pontuacao1, pontuacao2, score1, score2, posicao_macaco1, posicao_macaco2, Rank[3][10], pontos[3], pontuacao_final1, pontuacao_final2);
                }
        }
        else{
            clear();
            menu(player1, player2, pontuacao, pontuacao1, pontuacao2, score1, score2, posicao_macaco1, posicao_macaco2, Rank[3][10], pontos[3], pontuacao_final1, pontuacao_final2);
        }
    }
    else{
        clear();
        menu(player1, player2, pontuacao, pontuacao1, pontuacao2, score1, score2, posicao_macaco1, posicao_macaco2, Rank[3][10], pontos[3], pontuacao_final1, pontuacao_final2);
        }
}



//MENU
void menu(char* player1, char* player2, int pontuacao, int pontuacao1, int pontuacao2, int score1, int score2, int posicao_macaco1, int posicao_macaco2, char Rank[3][10], int pontos[3], int pontuacao_final1, int pontuacao_final2){
int x = 0;
while(opcao != 1){
    clear();
    imprimir_em((LIMITE / 2) - 2, 2, "MENU");
    imprimir_em(1 , 13, "1 - JOGAR");
    imprimir_em(1 , 15, "2 - DIFICULDADE");
    imprimir_em(1 , 17, "3 - RANKING");
    imprimir_em(1 , 19, "4 - SAIR");
    imprimir_em(LIMITE - 35, 29, "ALUNOS:");
    imprimir_em(LIMITE - 35, 30, "Arthur Marcelino Batista da Silva");
    imprimir_em(LIMITE - 35, 31, "Luan Rubens Saraiva Barroso");
    imprimir_em(LIMITE - 35, 32, "Lucas Cesar da Silva\n");
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
}}



//JOGO
void jogo(float coordenada, float distancia, int esquerda, char player1[], char player2[], int pontuacao[], int pontuacao1, int pontuacao2, int score1, int score2, float posicao_macaco1, float posicao_macaco2) {
    posicao_macaco1, posicao_macaco2, radianos, vel, score1, score2 = layout(coordenada, distancia, esquerda, player1, player2, pontuacao1, pontuacao2, posicao_macaco1, posicao_macaco2, score1, score2);
    float grv = 10;
    radianos = graus * 3.142 / 180;
    float altura = LIMITE_VERT - 4 - (((vel*vel)*(sin(radianos)*sin(radianos)))/(2*grv));
    float alcance = ((vel*vel)*sin(2*radianos))/grv + posicao_macaco1;

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
        esquerda, acertou, score1, score2 = trajetoria(bananas, tam_bananas, posicao_macaco1, posicao_macaco2, altura, esquerda, &score1, &score2);

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

        posicao_macaco1, posicao_macaco2, radianos, vel, score1, score2 = layout(coordenada, distancia, esquerda, player1, player2, pontuacao1, pontuacao2, posicao_macaco1, posicao_macaco2, score1, score2);


        if (esquerda == 1) {
            altura = LIMITE_VERT - 4 - (((vel*vel)*(sin(radianos)*sin(radianos)))/(2*grv));
            alcance = ((vel*vel)*sin(2*radianos))/grv + posicao_macaco1;
        } else {
            altura = LIMITE_VERT - 4 - (((vel*vel)*(sin(radianos)*sin(radianos)))/(2*grv));
            alcance = ((vel*vel)*sin(2*radianos))/grv + posicao_macaco1;
        }

        sleep(0.1);
    }
}



//DIFICULDADE
int dificuldade(){
clear();
imprimir_em((LIMITE / 2) - 15, 2, "ESCOLHA A DIFICULDADE DO JOGO:");
imprimir_em((LIMITE / 2) - 25, 5, "1 - FACIL : distancia entre os macacos é mostrada");
imprimir_em((LIMITE / 2) - 25, 8, "2 - MEDIO : as posiçoes dos macacos é mostrada");
imprimir_em((LIMITE / 2) - 25, 11, "3 - DIFICIL : distancia  e posição não sao mostrados\n");
scanf("%d", &x);
}



//RANKING
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



//ORDENADOR DO RANKING
void ordenador_rank(char Rank[3][10], int pontos[], int pontuacao_final1, int pontuacao_final2, char player1[], char player2[]) {
    int i = 0, j = 0;
    while (i == 0) {
        if (pontuacao_final1 > pontos[0]) {
            char ord_rank[10], ord_pontos[10];
            strcpy(ord_rank, Rank[0]);
            sprintf(ord_pontos, "%d", pontos[0]);
            strcpy(Rank[0], player1);
            sprintf(pontos[0], "%d", pontuacao_final1);
            strcpy(Rank[2], Rank[1]);
            sprintf(pontos[2], "%d", pontos[1]);
            strcpy(Rank[1], ord_rank);
            sprintf(pontos[1], "%s", ord_pontos);
        }
        else if (pontuacao_final1 > pontos[1]) {
            char ord_rank[10], ord_pontos[10];
            strcpy(ord_rank, Rank[1]);
            sprintf(ord_pontos, "%d", pontos[1]);
            strcpy(Rank[1], player1);
            sprintf(pontos[1], "%d", pontuacao_final1);
            strcpy(Rank[2], ord_rank);
            sprintf(pontos[2], "%s", ord_pontos);
        }
        else if (pontuacao_final1 > pontos[2]) {
            strcpy(Rank[2], player1);
            sprintf(pontos[2], "%d", pontuacao_final1);
        }
        i++;
    }
    while (j == 0) {
        if (pontuacao_final2 > pontos[0]) {
            char ord_rank[10], ord_pontos[10];
            strcpy(ord_rank, Rank[0]);
            sprintf(ord_pontos, "%d", pontos[0]);
            strcpy(Rank[0], player2);
            sprintf(pontos[0], "%d", pontuacao_final2);
            strcpy(Rank[2], Rank[1]);
            sprintf(pontos[2], "%d", pontos[1]);
            strcpy(Rank[1], ord_rank);
            sprintf(pontos[1], "%s", ord_pontos);
        }
        else if (pontuacao_final2 > pontos[1]) {
            char ord_rank[10], ord_pontos[10];
            strcpy(ord_rank, Rank[1]);
            sprintf(ord_pontos, "%d", pontos[1]);
            strcpy(Rank[1], player2);
            sprintf(pontos[1], "%d", pontuacao_final2);
            strcpy(Rank[2], ord_rank);
            sprintf(pontos[2], "%s", ord_pontos);
        }
        else if (pontuacao_final2 > pontos[2]) {
            strcpy(Rank[2], player2);
            sprintf(pontos[2], "%d", pontuacao_final2);
        }
        j++;
    }
}



//TURNOS
void turnos(esquerda){
if(esquerda == 1){
   POSICAO = LIMITE/200;
   esquerda = 0;
}
else {
   POSICAO = LIMITE-15;
   esquerda = 1;
}
}



//LAYOUT
double layout(int coordenada, int distancia, int esquerda, char player1[10], char player2[10], int pontuacao1, int pontuacao2, int posicao_macaco1, int posicao_macaco2, int score1, int score2){
posicao_macaco1 = 1 + rand() % 60;
posicao_macaco2 = 140 + rand()% 60;
if(coordenada == 1){
    if(distancia == 1){
        while(score1 > 0 && score2 > 0){
            turnos(esquerda);
            init(LIMITE_VERT);
            reset(1, 2, LIMITE_VERT - 1, LIMITE);
            imprimir_em(1,1, player1);
            imprimir_em((LIMITE / 2) - 10, LIMITE_VERT-2, "VIDA");
            imprimir_em(LIMITE - 17, 1, player2);
            imprimir_em( 1, 2, "Pontuacao: ");
            printf("%d", pontuacao1);
            imprimir_em(LIMITE - 17, 2, "Pontuacao: ");
            printf("%d", pontuacao2);
            imprimir_em(posicao_macaco1, LIMITE_VERT - 5, "O");
            imprimir_em(posicao_macaco2, LIMITE_VERT - 5, "O");
            imprimir_em(POSICAO, LIMITE_VERT - 2, "Angulo: ");
            scanf("%d", &graus);
            imprimir_em(POSICAO, LIMITE_VERT - 1, "Velocidade: ");
            scanf("%f", &vel);
            return posicao_macaco1, posicao_macaco2, radianos, vel, score1, score2;
        }
        if(score1 == 0){
            clear();
            imprimir_em(LIMITE/2 - 7, 15, player2);
            printf(" Venceu!");
            sleep(3);
            pontuacao_final1 = pontuacao1;
            pontuacao_final2 = pontuacao2;
            ordenador_rank( Rank[3][10], pontos, pontuacao_final1, pontuacao_final2, player1, player2);
            menu(player1, player2, pontuacao, pontuacao1, pontuacao2, score1, score2, posicao_macaco1, posicao_macaco2, Rank[3][10], pontos, pontuacao_final1, pontuacao_final2);
        }
        else if(score2 == 0){
            clear();
            imprimir_em(LIMITE/2 - 7, 15, player1);
            printf(" Venceu!");
            sleep(3);
            pontuacao_final1 = pontuacao1;
            pontuacao_final2 = pontuacao2;
            ordenador_rank( Rank[3][10], pontos, pontuacao_final1, pontuacao_final2, player1, player2);
            menu(player1, player2, pontuacao, pontuacao1, pontuacao2, score1, score2, posicao_macaco1, posicao_macaco2, Rank[3][10], pontos, pontuacao_final1, pontuacao_final2);
        }
    }
    else{
        while(score1 > 0 && score2 > 0){
            turnos(esquerda);
            init(LIMITE_VERT);
            reset(1, 2, LIMITE_VERT - 1, LIMITE);
            imprimir_em(1,1, player1);
            imprimir_em((LIMITE / 2) - 10, LIMITE_VERT-2, "VIDA");
            imprimir_em(LIMITE - 17, 1, player2);
            imprimir_em( 1, 2, "Pontuacao: ");
            printf("%d", pontuacao1);
            imprimir_em(LIMITE - 17, 2, "Pontuacao: ");
            printf("%d", pontuacao2);
            imprimir_em( 1, 3, "Posicao: ");
            printf("%d", posicao_macaco1);
            imprimir_em(posicao_macaco1, LIMITE_VERT - 5, "O");
            imprimir_em( LIMITE - 17, 3, "Posicao: ");
            printf("%d", posicao_macaco2);
            imprimir_em(posicao_macaco2, LIMITE_VERT - 5, "O");
            imprimir_em(POSICAO, LIMITE_VERT - 2, "Angulo: ");
            scanf("%d", &graus);
            imprimir_em(POSICAO, LIMITE_VERT - 1, "Velocidade: ");
            scanf("%f", &vel);
            return posicao_macaco1, posicao_macaco2, radianos, vel, score1, score2;
        }
        if(score1 == 0){
            clear();
            imprimir_em(LIMITE/2 - 7, 15, player2);
            printf(" Venceu!");
            sleep(3);
            pontuacao_final1 = pontuacao1;
            pontuacao_final2 = pontuacao2;
            ordenador_rank( Rank[3][10], pontos, pontuacao_final1, pontuacao_final2, player1, player2);
            menu(player1, player2, pontuacao, pontuacao1, pontuacao2, score1, score2, posicao_macaco1, posicao_macaco2, Rank[3][10], pontos, pontuacao_final1, pontuacao_final2);
        }
        else if(score2 == 0){
            clear();
            imprimir_em(LIMITE/2 - 7, 15, player1);
            printf(" Venceu!");
            sleep(3);
            pontuacao_final1 = pontuacao1;
            pontuacao_final2 = pontuacao2;
            ordenador_rank( Rank[3][10], pontos, pontuacao_final1, pontuacao_final2, player1, player2);
            menu(player1, player2, pontuacao, pontuacao1, pontuacao2, score1, score2, posicao_macaco1, posicao_macaco2, Rank[3][10], pontos, pontuacao_final1, pontuacao_final2);
        }
    }
    } else{
        while(score1 > 0 && score2 > 0){
            turnos(esquerda);
            init(LIMITE_VERT);
            reset(1, 2, LIMITE_VERT - 1, LIMITE);
            imprimir_em(1,1, player1);
            imprimir_em((LIMITE / 2) - 10, LIMITE_VERT-2, "VIDA");
            imprimir_em(LIMITE - 17, 1, player2);
            imprimir_em( 1, 2, "Pontuacao: ");
            printf("%d", pontuacao1);
            imprimir_em(LIMITE - 17, 2, "Pontuacao: ");
            printf("%d", pontuacao2);
            imprimir_em(posicao_macaco1, LIMITE_VERT - 5, "O");
            imprimir_em(posicao_macaco2, LIMITE_VERT - 5, "O");
            imprimir_em(POSICAO, LIMITE_VERT - 2, "Angulo: ");
            scanf("%d", &graus);
            imprimir_em(POSICAO, LIMITE_VERT - 1, "Velocidade: ");
            scanf("%f", &vel);
            return posicao_macaco1, posicao_macaco2, radianos, vel, score1, score2;
        }
        if(score1 == 0){
            clear();
            imprimir_em(LIMITE/2 - 7, 15, player2);
            printf(" Venceu!");
            sleep(3);
            pontuacao_final1 = pontuacao1;
            pontuacao_final2 = pontuacao2;
            ordenador_rank( Rank[3][10], pontos, pontuacao_final1, pontuacao_final2, player1, player2);
            menu(player1, player2, pontuacao, pontuacao1, pontuacao2, score1, score2, posicao_macaco1, posicao_macaco2, Rank[3][10], pontos, pontuacao_final1, pontuacao_final2);
        }
        else if(score2 == 0){
            clear();
            imprimir_em(LIMITE/2 - 7, 15, player1);
            printf(" Venceu!");
            sleep(3);
            pontuacao_final1 = pontuacao1;
            pontuacao_final2 = pontuacao2;
            ordenador_rank( Rank[3][10], pontos, pontuacao_final1, pontuacao_final2, player1, player2);
            menu(player1, player2, pontuacao, pontuacao1, pontuacao2, score1, score2, posicao_macaco1, posicao_macaco2, Rank[3][10], pontos, pontuacao_final1, pontuacao_final2);
        }
        }

}



//TRAJETÓRIA
typedef struct {
        int x;
        int y;
        int ativa;
        int traj_A;
        int traj_B;
    } Banana;

void trajetoria(Banana bananas[], int tam_bananas, int posicao_macaco1, int posicao_macaco2, int altura, int esquerda, int *score1, int *score2) {
    int i;

    if (esquerda == 1) {
        for (i = 0; i < tam_bananas; i++) {
            if (bananas[i].ativa == 0) {
                bananas[i].ativa = 1;
                bananas[i].x = posicao_macaco1;
                bananas[i].y = LIMITE_VERT - 6;
                bananas[i].traj_A = 3;
                bananas[i].traj_B = 1;
                break;
            }
        }

        for (i = 0; i < tam_bananas; i++) {
            if (bananas[i].ativa == 1) {
                while (bananas[i].y > altura && bananas[i].y != 0) {
                    bananas[i].x += bananas[i].traj_A;
                    bananas[i].y -= bananas[i].traj_B;
                    imprimir_em(bananas[i].x, bananas[i].y, "L");
                    sleep(1);
                    imprimir_em(bananas[i].x, bananas[i].y, " ");
                }

                while (bananas[i].y != LIMITE_VERT - 4 && bananas[i].y != 0 && bananas[i].x < LIMITE) {
                    bananas[i].x += bananas[i].traj_A;
                    bananas[i].y += bananas[i].traj_B;
                    imprimir_em(bananas[i].x, bananas[i].y, "L");
                    sleep(1);
                    imprimir_em(bananas[i].x, bananas[i].y, " ");
                }

                if (bananas[i].ativa == 1) {
                    if(esquerda == 1){
                        esquerda = 0;
                    } else{
                        esquerda = 1;
                        }
                    break;
                }
            }
        }

        int acertou = 0;
        for (i = 0; i < tam_bananas; i++) {
            if (bananas[i].ativa == 1 && bananas[i].x <= posicao_macaco2 + 3 && bananas[i].y == LIMITE_VERT - 4 && bananas[i].x >= posicao_macaco2 - 3) {
                acertou = 1;
                *score1 += 1;
                break;
            }
        }
    }
    else {
        for (i = 0; i < tam_bananas; i++) {
            if (bananas[i].ativa == 0) {
                bananas[i].ativa = 1;
                bananas[i].x = posicao_macaco2;
                bananas[i].y = LIMITE_VERT - 6;
                bananas[i].traj_A = 3;
            }
            }
        for (i = 0; i < tam_bananas; i++) {
            if (bananas[i].ativa == 1) {
                while (bananas[i].y > altura && bananas[i].y != 0) {
                    bananas[i].x -= bananas[i].traj_A;
                    bananas[i].y -= bananas[i].traj_B;
                    imprimir_em(bananas[i].x, bananas[i].y, "L");
                    sleep(1);
                    imprimir_em(bananas[i].x, bananas[i].y, " ");
                }

                while (bananas[i].y != LIMITE_VERT - 4 && bananas[i].y != 0 && bananas[i].x > 1) {
                    bananas[i].x -= bananas[i].traj_A;
                    bananas[i].y += bananas[i].traj_B;
                    imprimir_em(bananas[i].x, bananas[i].y, "L");
                    sleep(1);
                    imprimir_em(bananas[i].x, bananas[i].y, " ");
                }

                if (bananas[i].ativa == 1) {
                    if(esquerda == 1){
                        esquerda = 0;
                    } else{
                        esquerda = 1;
                        }
                    break;
                }
            }
        }


        acertou = 0;
        for (i = 0; i < tam_bananas; i++) {
            if (bananas[i].ativa == 1 && bananas[i].x <= posicao_macaco2 + 3 && bananas[i].y == LIMITE_VERT - 4 && bananas[i].x >= posicao_macaco2 - 3) {
                acertou = 1;
                *score1 += 1;
                break;
            }
    }}

bananas->ativa = 0;

return esquerda, acertou,score1,score2;

}

int main(int argc, char *argv[])
{
tutorial();
return 0;
}
