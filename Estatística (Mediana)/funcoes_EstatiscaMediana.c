#include "declaracoes_EstatiscaMediana.h"

void sistema(){
    int opcao;
    while(1){
        menu();
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                alterarMatriz();
                continuar();
                break;
            case 2:
                puxarDados();
                continuar();
                break;
            case 3:
                salvarDados();
                continuar();
                break;
            case 4:
                mediana();
                continuar();
                break;
            case 5:
                resumoEstatistico();
                continuar();
                break;
            case 6:
                printf("\nVocê escolheu sair!\n");
                continuar();
                liberarMatriz();
                exit(0);
                break;
            default:
                limparBuffer(opcao);
                break;
        }
    }
}
void inicializarMatriz(int linhas, int colunas) {
    matriz = (int **)malloc(linhas * sizeof(int *));//vetor de tamanho linhas
    for (i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));//vetor de tamanho colunas no vetor linhas
    }
    lin = linhas;
    col = colunas;
}
void alterarMatriz(){
    printf("\nTamanho anterior: %dx%d", lin, col);
    printf("\nEscolha o número de linhas: ");
    scanf("%d", &lin);
    printf("Escolha o número de colunas: ");
    scanf("%d", &col);
    ajustarMatriz(lin, col);
    printf("\nAgora você tem uma matriz de tamanho: %dx%d\n", lin, col);
}
///funcao que calcula a mediana da matriz
void mediana(){
    int troca, v=0, aux=0;
    int *vetor = (int*)malloc(lin*col*sizeof(int));//vetor de uma linha com tam da matriz

    for (i=0; i<lin; i++) {
        for (j=0; j<col; j++) {
            vetor[v] = matriz[i][j];
            v++;
        }
     }

     printf("\nSem ordenação: ");
     for (i=0; i<(lin*col); i++) {
        printf("%d,", vetor[i]);
     }

    do{
        troca = 0;
        for (i=0; i<(lin * col)-1; i++) {//Bubble Sort
            if (vetor[i] > vetor[i + 1]) {
                int aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
                troca = 1; //houve uma troca
            }
        }
    } while (troca);

    printf("\n\nROL: ");
    for (i=0; i<(lin*col); i++) {
        printf("%d,", vetor[i]);
     }

     if((lin * col)%2==0){
        md = (vetor[(lin * col)/2]+vetor[((lin * col)/2)-1])/2;
        printf("\n\nMediana com tamanho par: ");
     }else{
        md = vetor[(lin * col-1)/2];
        printf("\n\nMediana com tamanho  ímpar: ");
     }

    printf("%0.2f\n", md);//imprimir mediana
    free(vetor);
}
///funcao que muda o tamanho da matriz
void ajustarMatriz(int novasLinhas, int novasColunas) {
    matriz = (int **)realloc(matriz, novasLinhas * sizeof(int *));//reakicar vetor de tam linhas
    for (i=lin; i<novasLinhas; i++) {//alocar as linhas novas, a partir do numero atual
        matriz[i] = (int *)malloc(novasColunas * sizeof(int));
    }
    for (i=0; i<novasLinhas; i++) {//realocar os vetores de tam colunas
        matriz[i] = (int *)realloc(matriz[i], novasColunas * sizeof(int));
    }
    for (i=0; i<novasLinhas; i++) {//zerar elementos da matriz
        for (j=0; j<novasColunas; j++) {
            matriz[i][j] = 0;
        }
    }
}
///funcao que limpa o espaco reservado
void liberarMatriz(){
    if (matriz != NULL) {
        for (i=0; i<lin; i++) {
            free(matriz[i]);
        }
        free(matriz);
        matriz = NULL;
        lin = 0;
        col = 0;
    }
}
///funcao que limpa a varivavel opcao
void limparBuffer(int opcao){
    while ((opcao = getchar()) != '\n' && opcao != EOF);
}
///funcao que tira os dados do arquivo.txt e coloca na matriz
void puxarDados() {
    // Leitura de um arquivo
    if (col != 0 && lin != 0) {
        FILE *txt = fopen("Arquivo.txt", "rt"); //"rt": abertura para leitura, arquivo texto
        if (txt == NULL) { // se não conseguiu abrir
            printf("\nArquivo não encontrado!\n");
            printf("\nObservação: O arquivo deve ter nome \"Arquivo.txt\",\nestar na pasta do programa.\n");
        } else {
            i = 0;
            while (!feof(txt) && i<lin) { // Lê até o final do arquivo ou até a última linha da matriz
                j = 0;
                while (j<col && fscanf(txt, "%d", &matriz[i][j]) == 1) { // Lê os valores do arquivo para a matriz
                    j++;
                }
                // Preenche com zeros se a linha terminar antes das colunas esperadas
                while (j < col) {
                    matriz[i][j] = 0;
                    j++;
                }
                i++;
            }
            fclose(txt);
            printf("\nOs dados foram inseridos com sucesso.\n");
        }
    }
    mostrarMatriz();
}
///Função para salvar os dados da matriz em um arquivo .txt
void salvarDados() {
    FILE *txt = fopen("Arquivo.txt", "wt"); //"wt": abertura para escrita
    if (txt == NULL) {
        printf("\nErro ao abrir o arquivo para escrita!\n");
    } else {
        for (i=0; i<lin; i++) {
            for (j=0; j<col; j++) {
                fprintf(txt, "%d ", matriz[i][j]);
            }
            fprintf(txt, "\n"); //nova linha após cada linha da matriz
        }
        fclose(txt);
        printf("\nOs dados foram salvos com sucesso.\n");
    }
}
///funcao que mostra a matriz
void mostrarMatriz() {
    if (col==0 || lin==0) {
        printf("\nA matriz não existe!\n");
    } else {
        printf("\nMATRIZ %dx%d\n", lin, col);
        for (i=0; i<lin; i++) {
            for (j=0; j<col; j++) {
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }
    }
}
///funcao que mostra informacoes gerais
void resumoEstatistico(){
    mediana();
    mostrarMatriz();
}

void continuar(){
    printf("\n");
    system("pause");
}

void menu(){
    system("cls");
    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    printf("\n#                                         #");
    printf("\n#              Felipe Manoel              #");
    printf("\n#                                         #");
    printf("\n#        MENU - Sistema Estatístico       #");
    printf("\n#                                         #");
    printf("\n#     1 - Alterar tamanho da matriz       #");
    printf("\n#     2 - Puxar dados de arquivo .txt     #");
    printf("\n#     3 - Salvar dados em arquivo .txt    #");
    printf("\n#     4 - Calcular mediana                #");
    printf("\n#     5 - Resumo estatístico              #");
    printf("\n#     6 - Sair do programa                #");
    printf("\n#                                         #");
    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    printf("\n\nEscolha uma opção: ");
}
