#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define COL 6
#define LIN 6

int main(){

    int *mat;
    int i, j;

    system("cls");
    setlocale(LC_ALL, "");

    *mat = malloc(LIN * COL * sizeof(int));/// aloca um vetor com todas as c�lulas da matriz

    for(i=0; i<LIN; i++){
        for(j=0; j<COL; j++){
            mat[(i*COL)+j] = i+j;/// calcula posi��o de cada c�lula
            printf("\e[38;2;223;23;43m|\e[0m%02d ", mat[(i*COL)+j]);
            if((j+1)%COL==0){
                printf("\n");
            }
        }
    }

    printf("\n\e[38;2;223;23;43m");
    system("pause");

    printf("\nMem�ria liberada!\n");
    printf("\e[48;2;75;23;43m");
    free(mat);/// libera o espa�o alocado da matriz

    getch();
}
