//Arquivo infos.c
void inicializarLista(ListaDescritor *lista) {/// Função para inicializar a lista.
    lista->primNo = NULL;//o primeiro nó não existe.
    lista->tamanho = 0;//por isso, o tamanho da lista também é zero.
}

void liberarLista(ListaDescritor *lista) {/// Função para liberar a lista da memória.
    Nodo *atual = lista->primNo;
    while (atual != NULL) {//enquanto não apagamos o nó final, liberamos a memória do atual.
        Nodo *temp = atual;//pegamos o nó atual.
        atual = atual->proxNo;//pegamos o próximo nó.
        free(temp);//liberamos o nó atual.
    }
    lista->primNo = NULL;//primeiro nó é apagado.
    lista->tamanho = 0;//consequentemente, o tamanho é zero.
}

void exibirLista(ListaDescritor *descritor) {/// Função para exibir a lista.
    if (descritor->primNo == NULL) {
        listaVazia();  // Chama a função listaVazia() se a lista estiver vazia
        return;  // Retorna da função se a lista estiver vazia
    } else {
        Nodo *atual = descritor->primNo;  // Inicia a exibição a partir do primeiro nó da lista
        while (atual != NULL) {  // Percorre a lista até o último nó
            printf(gray"\n===================================="def);  // Linha de separação estilizada
            printf("\nMatrícula: %d", atual->dados.matricula);  // Exibe a matrícula do aluno
            printf(yellow"\nNome: %s"def, atual->dados.nome);  // Exibe o nome do aluno
            printf("\nNota 1: %.2f", atual->dados.n1);  // Exibe a nota 1 do aluno
            printf("\nNota 2: %.2f", atual->dados.n2);  // Exibe a nota 2 do aluno
            printf(gray"\n===================================="def);  // Linha de separação estilizada
            atual = atual->proxNo;  // Avança para o próximo nó da lista
        }
    }
}

void listaVazia(){
    printf(red"\nA lista está vazia!"def);
}

void exibirTamanhoLista(ListaDescritor *descritor) {/// Função para exibir o tamanho da lista.
    printf(yellow"\nTamanho atual da lista: %d"def, descritor->tamanho);
}
