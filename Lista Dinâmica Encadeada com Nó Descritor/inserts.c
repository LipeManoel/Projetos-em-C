//inserts.c
Aluno* criaAluno(int matricula, const char *nome, float n1, float n2) {/// Função para alocar um novo aluno.
    Aluno *novoAluno = (Aluno *)malloc(sizeof(Aluno));  // Aloca memória para um novo aluno
    if (novoAluno == NULL) {  // Verifica se a alocação de memória foi bem-sucedida
        printf(red "\nErro ao alocar memória para novo aluno." def);  // Mensagem de erro caso a alocação falhe
        return NULL;  // Retorna NULL indicando falha na alocação
    }else{
        novoAluno->matricula = matricula;  // Atribui a matrícula ao novo aluno
        strcpy(novoAluno->nome, nome);  // Copia o nome para o novo aluno
        novoAluno->n1 = n1;  // Atribui a nota 1 ao novo aluno
        novoAluno->n2 = n2;  // Atribui a nota 2 ao novo aluno
        return novoAluno;  // Retorna o ponteiro para o novo aluno alocado
    }
}

void insereInicio(ListaDescritor *descritor) {/// Função para inserir um aluno no início da lista.
    int matricula;
    char nome[30];
    float n1, n2;

    printf("\nDigite a matrícula do aluno: ");
    scanf("%d", &matricula);
    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", nome);
    printf("Digite a nota 1 do aluno: ");
    scanf("%f", &n1);
    printf("Digite a nota 2 do aluno: ");
    scanf("%f", &n2);

    Aluno *novoAluno = criaAluno(matricula, nome, n1, n2);  // Cria um novo aluno com os dados informados
    if (novoAluno == NULL) return; // Verifica se o aluno foi criado com sucesso e retorna se não

    Nodo *novoNodo = (Nodo *)malloc(sizeof(Nodo));  // Aloca memória para um novo nó
    if (novoNodo == NULL) {  // Verifica se a alocação de memória para o nó foi bem-sucedida
        printf(red "\nErro ao alocar memória para novo nó." def);  // Mensagem de erro caso a alocação falhe
        free(novoAluno);  // Libera a memória do novo aluno criado
        return;  // Retorna da função em caso de falha na alocação do nó
    }else{
        novoNodo->dados = *novoAluno;  // Copia os dados do novo aluno para o novo nó
        novoNodo->proxNo = descritor->primNo;  // O novo nó aponta para o nó que anteriormente era o primeiro da lista
        descritor->primNo = novoNodo;  // Atualiza o primeiro nó da lista para ser o novo nó criado
        descritor->tamanho++;  // Incrementa o tamanho da lista
        printf(yellow"\nOs dados foram inseridos com sucesso!"def);  // Mensagem de sucesso na inserção
        free(novoAluno); // Libera a memória do novoAluno pois seus dados já foram copiados
    }
}

void insereFinal(ListaDescritor *descritor) {/// Função para inserir um aluno no final da lista.
    int matricula;
    char nome[30];
    float n1, n2;

    printf("\nDigite a matrícula do aluno: ");
    scanf("%d", &matricula);
    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", nome);
    printf("Digite a nota 1 do aluno: ");
    scanf("%f", &n1);
    printf("Digite a nota 2 do aluno: ");
    scanf("%f", &n2);

    Aluno *novoAluno = criaAluno(matricula, nome, n1, n2);  // Cria um novo aluno com os dados informados
    if (novoAluno == NULL) return; // Verifica se o aluno foi criado com sucesso e retorna se não

    Nodo *novoNodo = (Nodo *)malloc(sizeof(Nodo));  // Aloca memória para um novo nó
    if (novoNodo == NULL) {  // Verifica se a alocação de memória para o nó foi bem-sucedida
        printf(red "\nErro ao alocar memória para novo nó." def);  // Mensagem de erro caso a alocação falhe
        free(novoAluno);  // Libera a memória do novo aluno criado
        return;  // Retorna da função em caso de falha na alocação do nó
    }else{
        novoNodo->dados = *novoAluno;  // Copia os dados do novo aluno para o novo nó
        novoNodo->proxNo = NULL;  // Define o próximo nó como NULL, pois será o último da lista

        if (descritor->primNo == NULL) {  // Se a lista estiver vazia
            descritor->primNo = novoNodo;  // O primeiro nó da lista passa a ser o novo nó criado
        } else {  // Se a lista não estiver vazia
            Nodo *atual = descritor->primNo;  // Inicia a busca pelo último nó a partir do primeiro
            while (atual->proxNo != NULL) {  // Enquanto não chegar ao último nó
                atual = atual->proxNo;  // Avança para o próximo nó da lista
            }
            atual->proxNo = novoNodo;  // Define o próximo nó do último nó como o novo nó criado
        }
        descritor->tamanho++;  // Incrementa o tamanho da lista
        printf(yellow"\nOs dados foram inseridos com sucesso!"def);  // Mensagem de sucesso na inserção
        free(novoAluno); // Libera a memória do novoAluno pois seus dados já foram copiados
    }
}
