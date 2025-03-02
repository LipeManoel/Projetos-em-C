//Arquivo infos.c
void inicializarLista(ListaDescritor *lista) {/// Fun��o para inicializar a lista.
    lista->primNo = NULL;//o primeiro n� n�o existe.
    lista->tamanho = 0;//por isso, o tamanho da lista tamb�m � zero.
}

void liberarLista(ListaDescritor *lista) {/// Fun��o para liberar a lista da mem�ria.
    Nodo *atual = lista->primNo;
    while (atual != NULL) {//enquanto n�o apagamos o n� final, liberamos a mem�ria do atual.
        Nodo *temp = atual;//pegamos o n� atual.
        atual = atual->proxNo;//pegamos o pr�ximo n�.
        free(temp);//liberamos o n� atual.
    }
    lista->primNo = NULL;//primeiro n� � apagado.
    lista->tamanho = 0;//consequentemente, o tamanho � zero.
}

void exibirLista(ListaDescritor *descritor) {/// Fun��o para exibir a lista.
    if (descritor->primNo == NULL) {
        listaVazia();  // Chama a fun��o listaVazia() se a lista estiver vazia
        return;  // Retorna da fun��o se a lista estiver vazia
    } else {
        Nodo *atual = descritor->primNo;  // Inicia a exibi��o a partir do primeiro n� da lista
        while (atual != NULL) {  // Percorre a lista at� o �ltimo n�
            printf(gray"\n===================================="def);  // Linha de separa��o estilizada
            printf("\nMatr�cula: %d", atual->dados.matricula);  // Exibe a matr�cula do aluno
            printf(yellow"\nNome: %s"def, atual->dados.nome);  // Exibe o nome do aluno
            printf("\nNota 1: %.2f", atual->dados.n1);  // Exibe a nota 1 do aluno
            printf("\nNota 2: %.2f", atual->dados.n2);  // Exibe a nota 2 do aluno
            printf(gray"\n===================================="def);  // Linha de separa��o estilizada
            atual = atual->proxNo;  // Avan�a para o pr�ximo n� da lista
        }
    }
}

void listaVazia(){
    printf(red"\nA lista est� vazia!"def);
}

void exibirTamanhoLista(ListaDescritor *descritor) {/// Fun��o para exibir o tamanho da lista.
    printf(yellow"\nTamanho atual da lista: %d"def, descritor->tamanho);
}
