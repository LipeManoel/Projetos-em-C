//mensagens.c

int menu(){//mostrar menu principal
    system("cls");
    barraMenu(27);
    printf("\n"bRed"                                                  "bRed"|");
    printf("\n"bRed"            ===========================           "bRed"|");
    printf("\n"bRed"           \033[7m Á R V O R E   B I N Á R I A "def"          "bRed"|");
    printf("\n"bRed"            ===========================           "bRed"|");
    printf("\n"bRed"                                                  "bRed"|");
    printf("\n"bRed"              \033[1mMenu                                "bRed"|");
    printf("\n"bRed"               %c"red"|1|"def"Criar Árvore                   "bRed"|", 108);
    printf("\n"bRed"               %c"red"|2|"def"Inserir elemento               "bRed"|", 108);
    printf("\n"bRed"               %c"red"|3|"def"Remover elemento               "bRed"|", 108);
    printf("\n"bRed"               %c"red"|4|"def"Buscar elemento                "bRed"|", 108);
    printf("\n"bRed"               %c"red"|5|"def"Listar elementos               "bRed"|", 108);
    printf("\n"bRed"               %c"red"|6|"def"Mostrar Altura                 "bRed"|", 108);
    printf("\n"bRed"               %c"red"|7|"def"Mostrar nós e folhas           "bRed"|", 108);
    printf("\n"bRed"               %c"red"|8|"def"Desalocar                      "bRed"|", 108);
    printf("\n"bRed"               %c"red"|9|"def"Créditos                       "bRed"|", 108);
    printf("\n"bRed"               %c"red"|10|"def"Sair                          "bRed"|", 108);
    printf("\n"bRed"                                                  "bRed"|");
    barraMenu(27);
    printf("\n\nEscolha uma opção: ");
    int op;
    scanf("%d", &op);
    return op;
}

void creditos(){//mostrar creditos do programa
    system("cls");
    barraMenu(27);
    printf("\n"bRed"                                                  "bRed"|");
    printf("\n"bRed""red"  @@@@@@@@@@@@@@@"def"         ===============         "bRed"|");
    printf("\n"bRed""red"  @@    @@    @@@"def"        \033[7m C R É D I T O S "def"        "bRed"|");
    printf("\n"bRed""red"  @@  @@@@  @@ @@"def"         ===============         "bRed"|");
    printf("\n"bRed""red"  @@    @@@@   @@"def"                                 "bRed"|");
    printf("\n"bRed""red"  @@    @@@    @@"def"    \033[1mIntegrantes:                 "bRed"|");
    printf("\n"bRed""red"  @@@    @    @@@"def"      %c Caleb de Souza Fortes    "bRed"|", 108);
    printf("\n"bRed""red"  @@@@@@@@@@@@@@@"def"      %c Felipe Manoel R. Pessoa  "bRed"|", 108);
    printf("\n"bRed"                                                  "bRed"|");
    barraMenu(27);
}

void barraMenu(int b){//loop que imprime as barras presentes nos menus
    printf("\n");
    for(int i=0; i<b; i++){
        printf(bRed);
    }
    printf("|");
}

void msg_sair(){//imprime a mensagem de sair
    printf("\n\033[1mVocê escolheu sair!\n\n"def);
    system("pause");
    exit(0);
}

void msg_opInvalida(int op){//imprime mensagem de opcao invalida
    printf(red"\nOpção inválida!"def);
    while ((op = getchar()) != '\n' && op != EOF);//limpar buffer
}

void msg_formula(){//mostrar formula
    printf("\n"bRed""fRed"  \033[1mFórmula:                                          "def);
    printf("\n"bRed""fRed"   %c n: Total de elementos     "def""fRed"Cn,p =\033[4m   n!   "def""fRed"       "def,108);
    printf("\n"bRed""fRed"   %c p: Elementos escolhidos         "def""fRed"p!(n-p)!       "def, 108);
}

void msg_folhas(int num){//imprimir folhas da arvore binaria
    printf("\n"fRed" "def" Quantidade de folhas: %d", num);
}

void msg_nos(int num){//imprimir nos da arvore binaria
    printf("\n"fRed" "def" Quantidade de nós: %d", num);
}

void msg_removerElemento(){//imprimir mensagens de remocao de valores na arvore
    printf("\n\nDigite o número a ser removido: ");
    int elemento;
    scanf("%d", &elemento);

    if(removeTree(&t, elemento)){
        printf("\n"fRed" "def" O número %d foi removido!", elemento);
    }else {
        printf("\n"fRed" "def" O número %d não pertence a arvore!", elemento);
    }
}

void msg_buscarElemento(){//imprimir mensagens de busca de valores na arvore
    printf("\n\nDigite o número a ser buscado: ");
    int elemento;
    scanf("%d", &elemento);

    if(isInTree(t, elemento)) {
        printf("\n"fRed" "def" O numero %d pertence a arvore!", elemento);
    }else{
        printf("\n"fRed" "def" O numero %d não pertence a arvore!", elemento);
    }
}

void msg_desalocarArvore(){//imprimir mensagem ao deslocar arvore
    printf("\n"fRed" "def" Árvore desalocada com sucesso!");
}

void msg_alturaArvore(int num){//imprimir altura da arvore
    printf("\n"fRed" "def" A altura é de %d unidades.", num);
}

void msg_inserirFormula(){//imprimir mensagens de insercao de valores na arvore
    int n, p;

    printf("\n\nDigite n: ");
    scanf("%d", &n);

    printf("\nDigite p: ");
    scanf("%d", &p);

    int elemento = analiseComb(n, p);
    insertTree(&t, elemento);

    printf("\n"fRed" "def" O numero %d foi inserido na arvore!", elemento);
}

void msg_arvoreCriada(){//imprimir mensagem de criacao da arvore
    printf("\n"fRed" "def" Árvore criada com sucesso!");
}

void msg_mostrarArvore(Tree* t) {//imprimir arvore
    if(t == NULL){
        printf("\n"fRed" "def" A árvore está vazia!");
        return;
    }
    msg_mostrarArvore(t->left);
    printf("\n%d ", t->num);
    msg_mostrarArvore(t->right);
}
