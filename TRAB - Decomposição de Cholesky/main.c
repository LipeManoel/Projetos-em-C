//main.c
#include "header.h"
#include "impressoes.c"
#include "matriz.c"
#include "cholesky.c"

int main(){

    int opcao;
    setlocale(LC_ALL, "");
    do{
        menu();
        printf("\n\nEscolha uma opção: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                alterarMatriz();
                break;
            case 2:
                aleatorizarMatriz();
                break;
            case 3:
                imprimirMatriz();
                break;
            case 4:
                decomposicaoCholesky();
                break;
            case 5:
                imprimirIteracoes();
                break;
            case 6:
                creditos();
                break;
            case 7:
                msg_Saiu();
                liberarMatriz();
                exit(0);
                break;
            default:
                msg_OpcaoInvalida();
                limparBuffer();// caso seja um caracter invalido
                break;
        }
        system("pause");

    }while(opcao != 7);
}
