//impressoes.c
void menu(){
    system("cls");
    barraMenu(20);
    printf("\n"bloco"                                    "bloco lim"");
    printf("\n"bloco"                "gray"MENU"def"                "bloco lim"");
    printf("\n"bloco"                                    "bloco lim"");
    printf("\n"bloco"           "purp"DECOMPOSIÇÃO DE"def"          "bloco lim"");
    printf("\n"bloco"              "purp"CHOLESKY"def"              "bloco lim"");
    printf("\n"bloco"                                    "bloco lim"");
    printf("\n"bloco"                                    "bloco lim"");
    printf("\n"bloco"    1 %c Alterar Matriz              "bloco lim"",26);
    printf("\n"bloco"    2 %c Aleatorizar Matriz          "bloco lim"",26);
    printf("\n"bloco"    3 %c Exibir Matriz               "bloco lim"",26);
    printf("\n"bloco"    4 %c Decomposição de Cholesky    "bloco lim"",26);
    printf("\n"bloco"    5 %c Imprimir iterações          "bloco lim"",26);
    printf("\n"bloco"    6 %c Créditos                    "bloco lim"",26);
    printf("\n"bloco"    7 %c Sair                        "bloco lim"",26);
    printf("\n"bloco"                                    "bloco lim"");
    barraMenu(20);
}

void creditos(){
    barraMenu(20);
    printf("\n"bloco"                                    "bloco lim"");
    printf("\n"bloco"    > "gray"Integrantes:"def"                  "bloco lim"");
    printf("\n"bloco"                                    "bloco lim"");
    printf("\n"bloco"    Caleb de Souza Fortes           "bloco lim"");
    printf("\n"bloco"    Felipe Manoel Rodrigues Pessoa  "bloco lim"");
    printf("\n"bloco"                                    "bloco lim"");
    barraMenu(20);
    printf("\n\n");
}

void barraMenu(int a){
    int i;
    printf("\n");
    for(i=0; i<a; i++){
        printf(bloco"");
        if(i == a-1){
            printf(lim"");// ultimo quadrado da barra
        }
    }
}

void limparBuffer() {
    int c;//var auxiliar
    while ((c = getchar()) != '\n' && c != EOF);// limpa o ultimo scanf, seja ele qualquer
}

void msg_MatrizInexistente(){
    printf(red"\n\t> Não existe matriz!\n\n"def);
}

void msg_Saiu(){
    printf("\n\t> "red"Você escolheu sair!\n"def);
}

void msg_OpcaoInvalida(){
    printf("\n\t> "red"Escolha uma opção válida!\n\n"def);
}
