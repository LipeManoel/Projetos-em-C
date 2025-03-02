//Arquivo header.h

/// Bibliotecas:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <locale.h>

/// Declara��es:
typedef struct aluno {//estrutura com as informa��es dos alunos.
    int matricula;
    char nome[30];
    float n1, n2;
} Aluno;

typedef struct nodo {//n� da lista.
    Aluno dados;//cada n� tem as informa��es de um aluno(da struct).
    struct nodo *proxNo;//pr�ximo n� da lista.
} Nodo;

typedef struct {//cont�m os n�s, que cont�m as informa��es dos alunos.
    Nodo *primNo;//primeiro n� da lista.
    int tamanho;//tamanho atual da lista.
} ListaDescritor;

ListaDescritor lista;//var do tipo ListaDescritor, contendo tudo que a struct tem(os n�s).

/// Formata��o de cor:
#define red "\033[38;2;230;80;110m"//vermelho
#define blue "\033[38;2;80;110;230m"//azul
#define blue2 "\033[38;2;58;81;178m"//azul escuro
#define yellow "\033[38;2;230;180;80m"//amarelo
#define def "\033[0m"//cor branca padrao
#define gray "\033[38;2;140;140;140m"//cor branca padrao

// Layout do menu:
#define bloco "\033[48;2;180;180;180m\033[38;2;0;0;0m<>\033[0m"
