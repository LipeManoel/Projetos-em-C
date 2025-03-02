//header.h

///Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <time.h>

///Formatacoes
//cores de texto
#define red "\033[38;2;194;5;5m\033[1m"
#define def "\033[0m"
//blocos coloridos
#define bRed "\033[48;2;155;0;0m\033[38;2;155;0;0m@@\033[0m"
//cores de fundo
#define fRed "\033[48;2;40;0;0m"

///Assinaturas
//funcoes.c
int fatorialIt(int num);
int processoIt(int n, int r);
int fatorialRec(int num);
int processoRec(int n, int r);
//mensagens.c
void menu();
void barraMenu(int b);
void creditos();
void msg_sair();
void msg_opInvalida(int op);
void msg_resultIterado(int n, int r);
void msg_resultRecursivo(int n, int r);
void msg_formula();
int msg_digiteN();
int msg_digiteR(int n);
