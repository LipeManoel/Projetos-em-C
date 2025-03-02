#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define COL 6
#define LIN 6

int main(){

    int **mat;
    int i, j;

    setlocale(LC_ALL, "");
    system("cls");

    mat = malloc(LIN * sizeof(int*));/// aloca um vetor de LINHA ponteiros para linhas

    for(i=0; i<LIN; i++){
        mat[i] = malloc(COL*sizeof(int));/// cada LINHA recebe um vetor com COLUNAS
    }

    for(i=0; i<LIN; i++){/// percorre a matriz
        for(j=0; j<COL; j++){
            mat[i][j] = 0;
            if(j%COL==0){
                printf("\n");
            }
            printf("\e[38;2;232;23;43m|\e[0m%02d  ", mat[i][j]);
        }
    }

    printf("\n\n");
    system("pause");

    for(i=0; i<LIN; i++){/// liberar memoria aonde malloc foi usado
        free(mat[i]);
    }
    free(mat);

    printf("\n\e[38;2;232;23;43mMemória liberada!\e[48;2;75;23;43m");
    printf("\n");

    getch();
}
