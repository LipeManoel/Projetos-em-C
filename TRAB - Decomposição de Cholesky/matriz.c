//matriz.c
int **MATRIZ = NULL, LIN, COL;

void alterarMatriz(){/// Alterar elementos da matriz.
    int n;
    printf("\n  > Digite o número de linhas e colunas: ");
    scanf("%d", &n);

    LIN = n;
    COL= n;

    if(MATRIZ != NULL){
        liberarMatriz();
    }

    MATRIZ = malloc(LIN * sizeof(int*));// aloca um vetor de LINHA ponteiros para linhas

    for(int i=0; i<LIN; i++){
        MATRIZ[i] = malloc(COL*sizeof(int));// cada LINHA recebe um vetor com COLUNAS
    }

    for(int i=0; i<LIN; i++){// percorre a matriz e coloca valores para teste.
        for(int j=0; j<COL; j++){
                MATRIZ[i][j] = 0;
        }
    }
    imprimirMatriz();
}

void imprimirMatriz(){/// Mostrar elementos da matriz.
    if(MATRIZ == NULL || LIN == 0 || COL == 0){
        msg_MatrizInexistente();
    }else{
        printf("\n\t> Elementos da matriz %dx%d:\n",LIN,COL);
        for(int i=0; i<LIN; i++){// percorre a matriz.
            for(int j=0; j<COL; j++){
                if(j%COL==0){
                    printf("\n");
                }
                    printf(purp"\t|"def"%dx%d:%02d",i,j,MATRIZ[i][j]);
            }
        }
        printf("\n\n");
    }
}

void liberarMatriz(){/// Liberar matriz da memória.
    if(MATRIZ != NULL){
        for(int i=0; i<LIN; i++){
            free(MATRIZ[i]);
        }
        free(MATRIZ);
    }
}

void aleatorizarMatriz(){/// Gerar um Valor Aleatório nos elementos da matriz.
    if(MATRIZ == NULL || LIN == 0 || COL == 0){
        msg_MatrizInexistente();
    }else{
        for(int i=0; i<LIN; i++){
            for(int j=0; j<COL; j++){
                MATRIZ[i][j] = (rand() % 100)+1;// entre 1 e 100
            }
        }
        printf("\n  >"purp" Os elementos foram aleatorizados.\n"def);
        imprimirMatriz();
    }
}
