//cholesky.c
double **L = NULL;
char iteracoes[10000]; // Para armazenar as iterações

void decomposicaoCholesky() {
    if (MATRIZ == NULL || LIN == 0 || COL == 0){
        msg_MatrizInexistente();
        return;
    }

    L = malloc(LIN * sizeof(double*));
    for (int i = 0; i < LIN; i++) {
        L[i] = malloc(LIN * sizeof(double));
    }

    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < LIN; j++) {
            L[i][j] = 0;
        }
    }

    strcpy(iteracoes, "\nIterações da decomposição de Cholesky:\n");

    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j <= i; j++) {
            double sum = 0.0;
            for (int k = 0; k < j; k++) {
                sum += L[i][k] * L[j][k];
            }

            if (i == j) {
                L[i][j] = sqrt(MATRIZ[i][i] - sum);
            } else {
                L[i][j] = (MATRIZ[i][j] - sum) / L[j][j];
            }

            char buffer[100];
            sprintf(buffer, "L[%d][%d] = %.5f\n", i, j, L[i][j]);
            strcat(iteracoes, buffer);
        }
    }

    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < LIN; j++) {
            if(j%COL==0){
                printf("\n");
            }
            printf(purp"\t|"def"%dx%d:%02d",i,j,L[i][j]);
        }
    }

    printf("\n\n\t> "purp"Decomposição de Cholesky concluída!\n\n"def);
}

void imprimirIteracoes() {
    if (MATRIZ == NULL || LIN == 0 || COL == 0){
        msg_MatrizInexistente();
        return;
    }

    FILE *file = fopen("iteracoes.txt", "w");
    if (file == NULL) {
        printf("\n\t> "red"Erro ao abrir o arquivo!\n\n"def);
        return;
    }

    fprintf(file, "%s", iteracoes);
    fclose(file);
    printf("\n\t> "purp"Iterações salvas como 'iteracoes.txt'.\n\n"def);
}
