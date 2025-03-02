#ifndef ESTATÌSTICACOMPLETA_DECLARACOES_H_INCLUDED
#define ESTATÌSTICACOMPLETA_DECLARACOES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

FILE *txt = NULL;

int **matriz;
int i, j, op;
int lin, col;
int moda;
float soma, media, variancia, mediana, cv;

#define red "\033[38;2;230;80;110m"//vermelho
#define blue "\033[38;2;80;110;230m"//azul
#define blue2 "\033[38;2;58;81;178m"//azul escuro
#define yellow "\033[38;2;230;180;80m"//amarelo
#define pad "\033[0m"//branco padrao

#define bc "\033[48;2;180;180;180m\033[38;2;0;0;0m<>\033[0m"

#endif // ESTATÌSTICACOMPLETA_DECLARACOES_H_INCLUDED
