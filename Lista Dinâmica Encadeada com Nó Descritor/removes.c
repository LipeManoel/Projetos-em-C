//Arquivo removes.c
void removeInicio(ListaDescritor *descritor) {/// Função para remover o primeiro aluno da lista.
    if (descritor->primNo == NULL) {
        listaVazia();  // Chama a função listaVazia para tratar o caso de lista vazia
        return;  // Retorna da função se a lista estiver vazia
    }else{
        Nodo *temp = descritor->primNo;  // Cria um ponteiro temporário para o primeiro nó
        descritor->primNo = descritor->primNo->proxNo;  // Atualiza o primeiro nó para ser o próximo nó da lista
        free(temp);  // Libera a memória do nó removido
        descritor->tamanho--;  // Decrementa o tamanho da lista
        printf(yellow"\nOs dados foram removidos com sucesso!"def);  // Mensagem de sucesso na remoção
    }
}

void removeFinal(ListaDescritor *descritor) {/// Função para removee o último aluno da lista.
    if (descritor->primNo == NULL) {
        listaVazia();  // Chama a função listaVazia para tratar o caso de lista vazia
        return;  // Retorna da função se a lista estiver vazia
    }else{
        // se houver apenas um na lista.
        if (descritor->primNo->proxNo == NULL) {
            free(descritor->primNo);  // Libera a memória do único nó da lista
            descritor->primNo = NULL;  // Define o primeiro nó como NULL, pois a lista está vazia
            descritor->tamanho = 0;  // Zera o tamanho da lista
            return;  // Retorna da função após remover o único nó da lista
        }
        // encontrar o penultimo aluno.
        Nodo *penultimo = descritor->primNo;  // Inicia a busca pelo penúltimo nó a partir do primeiro nó da lista
        while (penultimo->proxNo->proxNo != NULL) {  // Enquanto não chegar ao penúltimo nó
            penultimo = penultimo->proxNo;  // Avança para o próximo nó da lista
        }
        // agora penultimo->proxNo é o último nó.
        free(penultimo->proxNo);  // Libera a memória do último nó da lista
        penultimo->proxNo = NULL;  // Define o próximo nó do penúltimo como NULL, pois agora é o último nó da lista
        descritor->tamanho--;  // Decrementa o tamanho da lista

        printf(yellow"\nOs dados foram removidos com sucesso!"def);  // Mensagem de sucesso na remoção
    }
}
