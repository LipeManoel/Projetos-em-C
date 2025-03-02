//Arquivo mensagens.c
void menu(){
    system("cls");
    barraMenu();
    printf("\n"bloco"                                          "bloco"");
    printf("\n"bloco"                   "gray"-MENU-"def"                 "bloco"");
    printf("\n"bloco"                                          "bloco"");
    printf("\n"bloco"            "blue"Lista Encadeada Com"def"           "bloco"");
    printf("\n"bloco"                "blue"Nó Descritor"def"              "bloco"");
    printf("\n"bloco"                                          "bloco"");
    printf("\n"bloco"    1 = Inserir elemento no final         "bloco"");
    printf("\n"bloco"    2 = Inserir elemento no início        "bloco"");
    printf("\n"bloco"    3 = Remover elemento do final         "bloco"");
    printf("\n"bloco"    4 = Remover elemento do início        "bloco"");
    printf("\n"bloco"    5 = Consultar elemento pela posição   "bloco"");
    printf("\n"bloco"    6 = Consultar elemento pela matrícula "bloco"");
    printf("\n"bloco"    7 = Exibir lista                      "bloco"");
    printf("\n"bloco"    8 = Exibir tamanho da lista           "bloco"");
    printf("\n"bloco"    9 = Créditos                          "bloco"");
    printf("\n"bloco"    10 = Sair                             "bloco"");
    printf("\n"bloco"                                          "bloco"");
    barraMenu();
    printf("\n\nEscolha uma opção: ");
}

void barraMenu(){
    int i;
    printf("\n");
    for (i=0; i<23; i++){
       printf(""bloco"");
    }
}

void creditos(){
    system("cls");
    barraMenu();
    printf("\n"bloco"                                          "bloco"");
    printf("\n"bloco"                 "blue"-CRÉDITOS-"def"               "bloco"");
    printf("\n"bloco"                                          "bloco"");
    printf("\n"bloco"   "gray"Integrantes:"def"                           "bloco"");
    printf("\n"bloco"    1 = Caleb de Souza Fortes             "bloco"");
    printf("\n"bloco"    2 = Erick Dos Santos Souza            "bloco"");
    printf("\n"bloco"    3 = Felipe Manoel Rodrigues Pessoa    "bloco"");
    printf("\n"bloco"    4 = Gabriel França Schbatosk          "bloco"");
    printf("\n"bloco"    5 = Lucas Taniguchi Sakamoto          "bloco"");
    printf("\n"bloco"                                          "bloco"");
    barraMenu();
}
