//Arquivo searchs.c
void consultaPorPosicao(ListaDescritor *descritor) {/// Fun��o para consultar aluno pela posi��o na lista.
    int posicao;
    printf("\nInforme a posi��o do aluno a ser consultado: ");
    scanf("%d", &posicao);

    if (posicao < 0 || posicao >= descritor->tamanho) {  // Verifica se a posi��o � v�lida
        printf(red"\nPosi��o inv�lida!"def);  // Mensagem de erro se a posi��o for inv�lida
        return;  // Retorna da fun��o se a posi��o for inv�lida
    }

    Nodo *atual = descritor->primNo;  // Inicia a busca pelo aluno a partir do primeiro n� da lista
    int i = 0;
    while (atual != NULL && i < posicao) {  // Percorre a lista at� encontrar a posi��o desejada
        atual = atual->proxNo;  // Avan�a para o pr�ximo n� da lista
        i++;  // Incrementa o contador de posi��o
    }

    if (atual != NULL) {  // Se encontrou o aluno na posi��o desejada
        printf(gray"\n=== "yellow"Aluno na posi��o %d"gray" ======"def, posicao);  // Mensagem indicando a posi��o do aluno
        printf("\nMatr�cula: %d", atual->dados.matricula);  // Exibe a matr�cula do aluno
        printf("\nNome: %s", atual->dados.nome);  // Exibe o nome do aluno
        printf("\nNota 1: %.2f", atual->dados.n1);  // Exibe a nota 1 do aluno
        printf("\nNota 2: %.2f", atual->dados.n2);  // Exibe a nota 2 do aluno
        printf(gray"\n=============================="def);  // Linha de separa��o estilizada
    } else {  // Se n�o encontrou o aluno na posi��o desejada
        printf(red"\nAluno n�o encontrado na posi��o espec�ficada!\n"def);  // Mensagem indicando que o aluno n�o foi encontrado
    }
}

void consultaPorMatricula(ListaDescritor *descritor) {/// Fun��o para consultar aluno pela matr�cula na lista.
    int matricula;
    printf("\nInforme a matr�cula do aluno a ser consultado: ");
    scanf("%d", &matricula);

    Nodo *atual = descritor->primNo;  // Inicia a busca pelo aluno a partir do primeiro n� da lista
    while (atual != NULL) {  // Percorre a lista at� encontrar o aluno com a matr�cula desejada
        if (atual->dados.matricula == matricula) {  // Verifica se encontrou o aluno com a matr�cula desejada
            printf(gray"\n=== "yellow"Aluno com matr�cula"gray" %d ==="def, matricula);  // Mensagem indicando a matr�cula do aluno encontrado
            printf("\nNome: %s", atual->dados.nome);  // Exibe o nome do aluno
            printf("\nNota 1: %.2f", atual->dados.n1);  // Exibe a nota 1 do aluno
            printf("\nNota 2: %.2f", atual->dados.n2);  // Exibe a nota 2 do aluno
            printf(gray"\n=============================="def);  // Linha de separa��o estilizada
            return;  // Retorna da fun��o ap�s encontrar o aluno com a matr�cula desejada
        }
        atual = atual->proxNo;  // Avan�a para o pr�ximo n� da lista
    }
    // Se chegou aqui, significa que o aluno n�o foi encontrado.
    printf(red"\nAluno com matr�cula %d n�o encontrado!\n"def, matricula);  // Mensagem indicando que o aluno n�o foi encontrado
}
