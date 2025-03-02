//main.c

#include "header.h"
#include "funcoes.c"
#include "mensagens.c"

int main(){

    setlocale(LC_ALL, "");
    int op, n, r;

    do{
        menu();
        scanf("%d", &op);
        switch(op){
            case 1:
                msg_formula();
                n = msg_digiteN();
                r = msg_digiteR(n);
                msg_resultIterado(n,r);
                msg_resultRecursivo(n,r);
                break;
            case 2:
                creditos();
                break;
            case 3:
                msg_sair();
                break;
            default:
                msg_opInvalida(op);
                break;
        }
        printf("\n\n");
        system("pause");

    }while(op != 3);
}
