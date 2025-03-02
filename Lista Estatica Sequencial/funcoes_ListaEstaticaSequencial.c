#include "declaracoes_ListaEstaticaSequencial.h"//arquivo header com as declaracoes

void menu(){//menu e suas opcoes
    system("cls");//apagar textos anteriores

    printf("\nACADÊMICOS:\n");
    ASCII = 26; //simbolo de flecha
    printf("\n %c Caleb Fortes", ASCII);
    printf("\n %c Felipe Manoel\n", ASCII);

    ASCII = 4;//simbolo de ouros
    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    printf("\n#                                              #");
    printf("\n#                    -MENU-                    #");
    printf("\n#        "ca"%cLista Estatística Sequencial%c"cb"        #", ASCII, ASCII);
    printf("\n#                                              #");
    printf("\n#        Digite a opção desejada:              #");
    printf("\n#                                              #");
    printf("\n#        1 = Inserir elemento no final         #");
    printf("\n#"cc"        2 = Inserir elemento no início        "cb"#");
    printf("\n#"cc"        3 = Inserir elemento ordenado         "cb"#");
    printf("\n#        4 = Remover elemento do final         #");
    printf("\n#"cc"        5 = Remover elemento do início        "cb"#");
    printf("\n#"cc"        6 = Remover elemento                  "cb"#");
    printf("\n#        7 = Consultar elemento pela posição   #");
    printf("\n#        8 = Consultar elemento pela matrícula #");
    printf("\n#        9 = Exibir lista                      #");
    printf("\n#        10 = Exibir tamanho da lista          #");
    printf("\n#        11 = Sair                             #");
    printf("\n#                                              #");
    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");

    selecionarOpcao();
}

void selecionarOpcao(){//checa a opcao selecionada
    int opcao, freq=300, temp=150;
    printf("\n\nEscolha uma opção para continuar: ");
    scanf("%i", &opcao);

    switch(opcao){
        case 1:
            Beep(freq, temp);//som de beep
            adicionarElementoFinal(alunos);
            continuar();
            break;
        case 2:
            indisponivel();
            break;
        case 3:
            indisponivel();
            break;
        case 4:
            Beep(freq, temp);//som de beep
            removerElementoFinal(alunos);
            continuar();
            break;
        case 5:
            indisponivel();
            break;
        case 6:
            indisponivel();
            break;
        case 7:
            Beep(freq, temp);//som de beep
            elementoPelaPosicao(alunos);
            continuar();
            break;
        case 8:
            elementoPelaMatricula(alunos);
            continuar();
            break;
        case 9:
            Beep(freq, temp);//som de beep
            imprimirLista(alunos);
            continuar();
            break;
        case 10:
            Beep(freq, temp);//som de beep
            imprimirTamanho();
            continuar();
            break;
        case 11:
            Beep(freq, temp);//som de beep
            ASCII = 120;//simbolo x
            printf("\n"cv"%c Você escolheu sair!"cb"\n\n", ASCII);
            system("pause");
            exit(0);
            break;
        default:
            printf("\a");//som de erro
            printf("\nEsta opção é "cv"inválida!"cb"\n\n");
            while((opcao = getchar()) != '\n' && opcao != EOF) { }//apagar caso o valor contido em 'opcao' seja um caracter inválido
            continuar();
            break;
    }
}

void indisponivel(){//quando uma opcao esta indisponivel
    printf("\a");//som de erro
    printf("\nEsta opção está "cv"indisponível!"cb"\n\n");
    continuar();
}

void continuar(){//voltar para o menu, apos pressionar uma tecla
    system("pause");
    Beep(600,300);
    menu();
}

//FUNCOES DA LISTA ESTATISTICA SEQUENCIAL
void adicionarElementoFinal(Array alunos){//01 - Inserir elemento no final
    if(tamAtual<MAX){
        tamAtual++;
        printf("\nDigite a matricula do aluno: ");
        scanf("%i", &alunos[tamAtual].matricula);
        getchar();  // Consome o caractere de nova linha deixado por scanf

        printf("Digite o nome do aluno: ");
        scanf(" %[^\n]", alunos[tamAtual].nome);  // Lê uma linha inteira, incluindo espaços

        printf("Digite a nota 1 do aluno: ");
        scanf("%f", &alunos[tamAtual].nota1);

        printf("Digite a nota 2 do aluno: ");
        scanf("%f", &alunos[tamAtual].nota2);
        printf("\n");

    }else{
        printf("\n"cv"A lista está cheia!"cb"\n");
    }
}

void removerElementoFinal(Array alunos){//04 - Remover elemento no final
    if(tamAtual > 0){
        alunos[tamAtual].matricula=0;
        alunos[tamAtual].nome[0]='\0';
        alunos[tamAtual].nota1=0.0;
        alunos[tamAtual].nota2=0.0;
        tamAtual--;
        printf("\n"ca"Último elemento removido com sucesso!"cb"\n\n");
    } else{
        listaVazia();
    }
}

void elementoPelaPosicao(Array alunos){//07 - Consultar elemento pela posicao
     if(tamAtual > 0){
        int i = 0;
        printf("\nDigite a posição do elemento: ");
        scanf("%i", &i);

        if(i<=tamAtual && i>0){
            imprimirDados(alunos, i);
        }else{
            printf("\nPosição "cv"inexistente!"cb"\n\n");
        }

    } else{
        listaVazia();
    }
}

void elementoPelaMatricula(Array alunos){//08 - Consultar elemento pela matricula
     if(tamAtual > 0){
        int i = 0, m;
        printf("\nDigite a matrícula: ");
        scanf("%i", &m);

        for(i=1; i<=tamAtual && m!=NULL; i++){
            if(alunos[i].matricula == m){
                imprimirDados(alunos, i);
                m = NULL;
            }
        }
        if(m!=NULL){
            printf("\nPosição "cv"inexistente!"cb"\n\n");
        }
    }else{
        listaVazia();
    }
}

void imprimirLista(Array alunos){//09 - Exibir lista
    if(tamAtual > 0){
        for (int i = 1; i <= tamAtual; i++) {
            imprimirDados(alunos, i);
        }
    } else{
        listaVazia();
    }
}

void imprimirTamanho(){//10 - Exibir tamanho da lista
    if(tamAtual > 0){
        printf("\nA lista tem "ca"%i"cb" elemento(s)!\n\n", tamAtual);
    } else{
        listaVazia();
    }
}

void listaVazia(){//mensagem quando a lista esta vazia
    printf("\n"cv"A lista está vazia!"cb"\n\n");
}

void imprimirDados(Array alunos, int i){//para imprimir parte da lista ou a lista interia
    printf(""cc"-------------------------------"cb"");
    printf("\n"ca"Matricula: %d"cb"", alunos[i].matricula);
    printf("\nAluno: %s", alunos[i].nome);
    printf("\nNota1: %.2f", alunos[i].nota1);
    printf("\nNota2: %.2f", alunos[i].nota2);
    printf("\n"cc"-------------------------------"cb"\n");
}
