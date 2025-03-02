#include <stdlib.h>
#include <stdio.h>

#define COL 10
#define LIN 10

int main(){

    int matriz[LIN][COL] = {0};
    int i, j;

    system("cls");

    for(i=0; i<LIN; i++){
        for(j=0; j<COL; j++){
            matriz[i][j] = i+j;

            if(j%5==0){
                printf("\n");
            }
            printf("\e[38;2;232;23;43m|\e[0mL%02d C%02d\e[0m = %02d  ", i, j,matriz[i][j]);

        }
    }

    printf("\n\n");
    printf("\e[38;2;232;23;43m");
    system("pause");
    printf("\e[48;2;75;23;43m");
    return(0);
}
