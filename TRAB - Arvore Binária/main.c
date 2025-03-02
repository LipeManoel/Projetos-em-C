//main.c

#include "header.h"
#include "funcoes.c"
#include "mensagens.c"

int main(){
	setlocale(LC_ALL, "");

	while(1){
        int op = menu();
		switch(op){
			case 1:
				t = createTree();
				msg_arvoreCriada();
				break;
			case 2:
			    msg_formula();
			    msg_inserirFormula();
				break;
			case 3:
                msg_removerElemento();
				break;
			case 4:
                msg_buscarElemento();
				break;
			case 5:
				msg_mostrarArvore(t);
				break;
			case 6:
				msg_alturaArvore(altura(t));
				break;
			case 7:
			    msg_folhas(contarNos(t));
			    msg_nos(contarFolhas(t));
				break;
            case 8:
                free(t);
				msg_desalocarArvore();
				break;
            case 9:
				creditos();
				break;
			case 10:
				msg_sair();
				break;
			default:
				msg_opInvalida(op);
				break;
		}
    printf("\n\n");
    system("pause");
	}
}
