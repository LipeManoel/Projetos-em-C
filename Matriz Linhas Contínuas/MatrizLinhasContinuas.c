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
    mat[0] = malloc(LIN * COL * sizeof(int));/// aloca um vetor com todas as células da matriz

    for(i=1;i<LIN; i++){/// ajusta os demais ponteiros de linhas
        mat[i] = mat[0] + i* COL;
    }

    for(i=0; i<LIN; i++){/// percorre a matriz
        for(j=0; j<COL; j++){
            mat[i][j] = 0;
            if(j%6==0){
                printf("\n");
            }
            printf("\e[38;2;232;23;43m|\e[0mL%02d C%02d = %02d  ", i, j, mat[i][j]);
        }
    }

    printf("\n\n");
    system("pause");

    free(mat[0]);/// libera a memória da matriz
    free(mat);
    printf("\n\e[38;2;232;23;43mA memória foi liberada!\e[48;2;75;23;43m\n");

    getch();
}
