//Arquivo searchs.c
void consultaPorPosicao(ListaDescritor *descritor) {/// Função para consultar aluno pela posição na lista.
    int posicao;
    printf("\nInforme a posição do aluno a ser consultado: ");
    scanf("%d", &posicao);

    if (posicao < 0 || posicao >= descritor->tamanho) {  // Verifica se a posição é válida
        printf(red"\nPosição inválida!"def);  // Mensagem de erro se a posição for inválida
        return;  // Retorna da função se a posição for inválida
    }

    Nodo *atual = descritor->primNo;  // Inicia a busca pelo aluno a partir do primeiro nó da lista
    int i = 0;
    while (atual != NULL && i < posicao) {  // Percorre a lista até encontrar a posição desejada
        atual = atual->proxNo;  // Avança para o próximo nó da lista
        i++;  // Incrementa o contador de posição
    }

    if (atual != NULL) {  // Se encontrou o aluno na posição desejada
        printf(gray"\n=== "yellow"Aluno na posição %d"gray" ======"def, posicao);  // Mensagem indicando a posição do aluno
        printf("\nMatrícula: %d", atual->dados.matricula);  // Exibe a matrícula do aluno
        printf("\nNome: %s", atual->dados.nome);  // Exibe o nome do aluno
        printf("\nNota 1: %.2f", atual->dados.n1);  // Exibe a nota 1 do aluno
        printf("\nNota 2: %.2f", atual->dados.n2);  // Exibe a nota 2 do aluno
        printf(gray"\n=============================="def);  // Linha de separação estilizada
    } else {  // Se não encontrou o aluno na posição desejada
        printf(red"\nAluno não encontrado na posição específicada!\n"def);  // Mensagem indicando que o aluno não foi encontrado
    }
}

void consultaPorMatricula(ListaDescritor *descritor) {/// Função para consultar aluno pela matrícula na lista.
    int matricula;
    printf("\nInforme a matrícula do aluno a ser consultado: ");
    scanf("%d", &matricula);

    Nodo *atual = descritor->primNo;  // Inicia a busca pelo aluno a partir do primeiro nó da lista
    while (atual != NULL) {  // Percorre a lista até encontrar o aluno com a matrícula desejada
        if (atual->dados.matricula == matricula) {  // Verifica se encontrou o aluno com a matrícula desejada
            printf(gray"\n=== "yellow"Aluno com matrícula"gray" %d ==="def, matricula);  // Mensagem indicando a matrícula do aluno encontrado
            printf("\nNome: %s", atual->dados.nome);  // Exibe o nome do aluno
            printf("\nNota 1: %.2f", atual->dados.n1);  // Exibe a nota 1 do aluno
            printf("\nNota 2: %.2f", atual->dados.n2);  // Exibe a nota 2 do aluno
            printf(gray"\n=============================="def);  // Linha de separação estilizada
            return;  // Retorna da função após encontrar o aluno com a matrícula desejada
        }
        atual = atual->proxNo;  // Avança para o próximo nó da lista
    }
    // Se chegou aqui, significa que o aluno não foi encontrado.
    printf(red"\nAluno com matrícula %d não encontrado!\n"def, matricula);  // Mensagem indicando que o aluno não foi encontrado
}
