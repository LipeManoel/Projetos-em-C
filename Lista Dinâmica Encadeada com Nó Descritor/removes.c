//Arquivo removes.c
void removeInicio(ListaDescritor *descritor) {/// Fun��o para remover o primeiro aluno da lista.
    if (descritor->primNo == NULL) {
        listaVazia();  // Chama a fun��o listaVazia para tratar o caso de lista vazia
        return;  // Retorna da fun��o se a lista estiver vazia
    }else{
        Nodo *temp = descritor->primNo;  // Cria um ponteiro tempor�rio para o primeiro n�
        descritor->primNo = descritor->primNo->proxNo;  // Atualiza o primeiro n� para ser o pr�ximo n� da lista
        free(temp);  // Libera a mem�ria do n� removido
        descritor->tamanho--;  // Decrementa o tamanho da lista
        printf(yellow"\nOs dados foram removidos com sucesso!"def);  // Mensagem de sucesso na remo��o
    }
}

void removeFinal(ListaDescritor *descritor) {/// Fun��o para removee o �ltimo aluno da lista.
    if (descritor->primNo == NULL) {
        listaVazia();  // Chama a fun��o listaVazia para tratar o caso de lista vazia
        return;  // Retorna da fun��o se a lista estiver vazia
    }else{
        // se houver apenas um na lista.
        if (descritor->primNo->proxNo == NULL) {
            free(descritor->primNo);  // Libera a mem�ria do �nico n� da lista
            descritor->primNo = NULL;  // Define o primeiro n� como NULL, pois a lista est� vazia
            descritor->tamanho = 0;  // Zera o tamanho da lista
            return;  // Retorna da fun��o ap�s remover o �nico n� da lista
        }
        // encontrar o penultimo aluno.
        Nodo *penultimo = descritor->primNo;  // Inicia a busca pelo pen�ltimo n� a partir do primeiro n� da lista
        while (penultimo->proxNo->proxNo != NULL) {  // Enquanto n�o chegar ao pen�ltimo n�
            penultimo = penultimo->proxNo;  // Avan�a para o pr�ximo n� da lista
        }
        // agora penultimo->proxNo � o �ltimo n�.
        free(penultimo->proxNo);  // Libera a mem�ria do �ltimo n� da lista
        penultimo->proxNo = NULL;  // Define o pr�ximo n� do pen�ltimo como NULL, pois agora � o �ltimo n� da lista
        descritor->tamanho--;  // Decrementa o tamanho da lista

        printf(yellow"\nOs dados foram removidos com sucesso!"def);  // Mensagem de sucesso na remo��o
    }
}
