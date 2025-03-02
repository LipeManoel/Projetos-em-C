//inserts.c
Aluno* criaAluno(int matricula, const char *nome, float n1, float n2) {/// Fun��o para alocar um novo aluno.
    Aluno *novoAluno = (Aluno *)malloc(sizeof(Aluno));  // Aloca mem�ria para um novo aluno
    if (novoAluno == NULL) {  // Verifica se a aloca��o de mem�ria foi bem-sucedida
        printf(red "\nErro ao alocar mem�ria para novo aluno." def);  // Mensagem de erro caso a aloca��o falhe
        return NULL;  // Retorna NULL indicando falha na aloca��o
    }else{
        novoAluno->matricula = matricula;  // Atribui a matr�cula ao novo aluno
        strcpy(novoAluno->nome, nome);  // Copia o nome para o novo aluno
        novoAluno->n1 = n1;  // Atribui a nota 1 ao novo aluno
        novoAluno->n2 = n2;  // Atribui a nota 2 ao novo aluno
        return novoAluno;  // Retorna o ponteiro para o novo aluno alocado
    }
}

void insereInicio(ListaDescritor *descritor) {/// Fun��o para inserir um aluno no in�cio da lista.
    int matricula;
    char nome[30];
    float n1, n2;

    printf("\nDigite a matr�cula do aluno: ");
    scanf("%d", &matricula);
    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", nome);
    printf("Digite a nota 1 do aluno: ");
    scanf("%f", &n1);
    printf("Digite a nota 2 do aluno: ");
    scanf("%f", &n2);

    Aluno *novoAluno = criaAluno(matricula, nome, n1, n2);  // Cria um novo aluno com os dados informados
    if (novoAluno == NULL) return; // Verifica se o aluno foi criado com sucesso e retorna se n�o

    Nodo *novoNodo = (Nodo *)malloc(sizeof(Nodo));  // Aloca mem�ria para um novo n�
    if (novoNodo == NULL) {  // Verifica se a aloca��o de mem�ria para o n� foi bem-sucedida
        printf(red "\nErro ao alocar mem�ria para novo n�." def);  // Mensagem de erro caso a aloca��o falhe
        free(novoAluno);  // Libera a mem�ria do novo aluno criado
        return;  // Retorna da fun��o em caso de falha na aloca��o do n�
    }else{
        novoNodo->dados = *novoAluno;  // Copia os dados do novo aluno para o novo n�
        novoNodo->proxNo = descritor->primNo;  // O novo n� aponta para o n� que anteriormente era o primeiro da lista
        descritor->primNo = novoNodo;  // Atualiza o primeiro n� da lista para ser o novo n� criado
        descritor->tamanho++;  // Incrementa o tamanho da lista
        printf(yellow"\nOs dados foram inseridos com sucesso!"def);  // Mensagem de sucesso na inser��o
        free(novoAluno); // Libera a mem�ria do novoAluno pois seus dados j� foram copiados
    }
}

void insereFinal(ListaDescritor *descritor) {/// Fun��o para inserir um aluno no final da lista.
    int matricula;
    char nome[30];
    float n1, n2;

    printf("\nDigite a matr�cula do aluno: ");
    scanf("%d", &matricula);
    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", nome);
    printf("Digite a nota 1 do aluno: ");
    scanf("%f", &n1);
    printf("Digite a nota 2 do aluno: ");
    scanf("%f", &n2);

    Aluno *novoAluno = criaAluno(matricula, nome, n1, n2);  // Cria um novo aluno com os dados informados
    if (novoAluno == NULL) return; // Verifica se o aluno foi criado com sucesso e retorna se n�o

    Nodo *novoNodo = (Nodo *)malloc(sizeof(Nodo));  // Aloca mem�ria para um novo n�
    if (novoNodo == NULL) {  // Verifica se a aloca��o de mem�ria para o n� foi bem-sucedida
        printf(red "\nErro ao alocar mem�ria para novo n�." def);  // Mensagem de erro caso a aloca��o falhe
        free(novoAluno);  // Libera a mem�ria do novo aluno criado
        return;  // Retorna da fun��o em caso de falha na aloca��o do n�
    }else{
        novoNodo->dados = *novoAluno;  // Copia os dados do novo aluno para o novo n�
        novoNodo->proxNo = NULL;  // Define o pr�ximo n� como NULL, pois ser� o �ltimo da lista

        if (descritor->primNo == NULL) {  // Se a lista estiver vazia
            descritor->primNo = novoNodo;  // O primeiro n� da lista passa a ser o novo n� criado
        } else {  // Se a lista n�o estiver vazia
            Nodo *atual = descritor->primNo;  // Inicia a busca pelo �ltimo n� a partir do primeiro
            while (atual->proxNo != NULL) {  // Enquanto n�o chegar ao �ltimo n�
                atual = atual->proxNo;  // Avan�a para o pr�ximo n� da lista
            }
            atual->proxNo = novoNodo;  // Define o pr�ximo n� do �ltimo n� como o novo n� criado
        }
        descritor->tamanho++;  // Incrementa o tamanho da lista
        printf(yellow"\nOs dados foram inseridos com sucesso!"def);  // Mensagem de sucesso na inser��o
        free(novoAluno); // Libera a mem�ria do novoAluno pois seus dados j� foram copiados
    }
}
