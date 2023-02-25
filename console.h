#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED

void clear(); // limpar a tela

void imprimir_em(int x, int y, char *texto);

void reset(int x, int y, int lines, int columns);

//Variáveis globais
#define LIMITE 156
#define LIMITE_VERT 40
#define PONTOS_ACERTO 100
#define PONTOS_ERRO 1

#endif // CONSOLE_H_INCLUDED
