/// Bibliotecas:
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>//para usar acentuacao
#include <windows.h>//para usar o beep(e sons de erro do Windows)

/// Cores de texto:
#define cv "\033[1;31m" //cor vermelha
#define cc "\033[1;30m" //cor cinza
#define cb "\033[0m" //cor branca(padrao)
#define ca "\033[1;33m" //cor amarela

/// Variaveis e afins:
#define MAX 100//tamanho maximo da lista

typedef struct {
    int matricula;
    float nota1, nota2;
    char nome[30];
} infoAlunos;

typedef infoAlunos Array[MAX];//cria um tipo de variavel chamada array com a struct, para armazenar as info. de até 30 alunos
Array alunos;//variavel do tipo array(um vetor de tam MAX, onde cada index contem a estrutura do struct)

int tamAtual = 0;//tamanho atual da lista
int ASCII;//usada para converter num em simbolos com "%c"
