//header.h

///Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

///Formatacoes
//cores de texto
#define red "\033[38;2;194;5;5m\033[1m"
#define def "\033[0m"
//blocos coloridos
#define bRed "\033[48;2;155;0;0m\033[38;2;155;0;0m@@\033[0m"
//cores de fundo
#define fRed "\033[48;2;40;0;0m"

///Declarações
typedef struct tree{
	int num;				//informação
  	struct tree* right;		//subárvore a direita
  	struct tree* left;		//subárvore a esquerda
}Tree;

Tree* MaiorRight(Tree **t);
Tree* t;

///Assinaturas
//mensagens.c
int menu();
void creditos();
void barraMenu(int b);
void msg_sair();
void msg_opInvalida(int op);
void msg_formula();
void msg_folhas(int num);
void msg_nos(int num);
void msg_removerElemento();
void msg_buscarElemento();
void msg_desalocarArvore();
void msg_alturaArvore(int num);
void msg_inserirFormula();
void msg_arvoreCriada();
void msg_mostrarArvore(Tree* t);
//funcoes.c
Tree* createTree();
Tree *MaiorRight(Tree **t);
Tree *MenorLeft(Tree **t);
int treeIsEmpty(Tree* t);
int fatorial(int num);
int analiseComb(int n, int p);
int removeTree(Tree** t, int num);
int isInTree(Tree* t, int num);
int maior(int a, int b);
int altura(Tree *t);
int contarFolhas(Tree* t);
int contarNos(Tree *t);
