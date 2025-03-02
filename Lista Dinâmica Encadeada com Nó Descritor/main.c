#include "header.h"
#include "infos.c"
#include "mensagens.c"
#include "removes.c"
#include "searchs.c"
#include "inserts.c"

int main() {
    setlocale(LC_ALL, "");
    inicializarLista(&lista);

    int opcao, i=0, freq=900, dur=50;
    do {
        Beep(300,34);
        menu();
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                Beep(freq,dur);
                insereFinal(&lista);
                i=1;
                break;
            case 2:
                Beep(freq,dur);
                insereInicio(&lista);
                i=1;
                break;
            case 3:
                Beep(freq,dur);
                removeFinal(&lista);
                i=1;
                break;
            case 4:
                Beep(freq,dur);
                removeInicio(&lista);
                i=1;
                break;
            case 5:
                Beep(freq,dur);
                consultaPorPosicao(&lista);
                i=1;
                break;
            case 6:
                Beep(freq,dur);
                consultaPorMatricula(&lista);
                i=1;
                break;
            case 7:
                Beep(freq,dur);
                exibirLista(&lista);
                i=1;
                break;
            case 8:
                Beep(freq,dur);
                exibirTamanhoLista(&lista);
                i=1;
                break;
            case 9:
                Beep(freq,dur);
                creditos();
                i=1;
                break;
            case 10:
                Beep(freq,dur);
                printf("\n"yellow"Você escolheu sair!"def"\n\n");
                system("pause");
                liberarLista(&lista);
                exit(0);
                break;
            default:
                printf("\a");
                printf("\n"red"Opção inválida!"def"");
                i=1;
                break;
        }

        printf("\n\n");
        system("pause");

    } while(i == 1);
}


