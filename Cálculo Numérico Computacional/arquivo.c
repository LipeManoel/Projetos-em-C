void imprimirIteracoes(){
    FILE *txt;
    txt = fopen("iteracoes.txt", "w"); // Abre o arquivo para escrita

    if (txt == NULL) {
        printf(red"\nErro ao abrir o arquivo.\n"def);
        return;
    }else{
        fprintf(txt, "N�mero de itera��es: %d\n", i);
        printf(yellow"\nO n�mero de itera��es foi salvo no arquivo.\n"def);
    }
    fclose(txt); // Fecha o arquivo
}
