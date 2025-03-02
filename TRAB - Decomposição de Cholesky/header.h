//header.h
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <math.h>

///Formatacao:
#define def "\033[0m"// cor padrao
#define red "\033[38;2;230;60;80m"// cor vermelha
#define purp "\033[38;2;123;69;255m"// cor azul
#define gray "\033[38;2;140;140;140m"// cor cinza

//layout do menu:
#define bloco "\033[38;2;0;0;0m\033[48;2;210;210;210m  \033[0m"
#define lim "\033[0m|"// limite da formatacao dos blocos do menu(para nao ultrapassar)

///Assinaturas:
//matriz.c:
void alterarMatriz();
void imprimirMatriz();
void liberarMatriz();
void aleatorizarMatriz();
//impressoes.c:
void menu();
void creditos();
void barraMenu(int a);
void limparBuffer();
void msg_MatrizInexistente();
void msg_Saiu();
void msg_OpcaoInvalida();
//cholesky.c:
void decomposicaoCholesky();
void imprimirIteracoes();
