#include "header.h"

int main(){
    system("cls");
    setlocale(LC_ALL,"");

    int i=0, iMAX;
    float A,B,C,D,X,Xant,EPS,resultado;

    printf(gray"\n============================"def);
    printf(yellow"\nf(x) = Ax%c + Bx%c + Cx + D\n",179,178);
    printf("\nf'(x) = 3Ax%c + 2Bx%c + C",178,185);
    printf(gray"\n============================"def);

    printf("\nInforme A: ");
    scanf("%f", &A);
    printf("\nInforme B: ");
    scanf("%f", &B);
    printf("\nInforme C: ");
    scanf("%f", &C);
    printf("\nInforme D: ");
    scanf("%f", &D);
    printf("\nInforme valor inicial de X: ");
    scanf("%f", &X);
    printf("\nInforme o critério de parada (Eps): ");
    scanf("%f", &EPS);
    printf("\nInforme o máximo de iterações: ");
    scanf("%d", &iMAX);

    FILE *txt;
    txt = fopen("iteracoes.txt", "w"); // Abre o arquivo para escrita
    if (txt == NULL) {
        printf(red"\nErro ao abrir o arquivo.\n"def);
        return;
    }else{
        fprintf(txt, "\n============================");
        printf(gray"\n============================"def);
        do{
            i++;//QNTD de iteracoes
            resultado = X-(((A*X*X*X)+(B*X*X)+(C*X)+D)/(3*(A*X*X)+(2*B*X)+C));
            Xant = X;//x anterior = x atual
            X = resultado;//x = resultado

            printf(red"\nIteração: %d"def, i);
            printf("\nX anterior: %f", Xant);//imprime x anterior
            printf("\nX atual: %f", X);//imprime x atual
            printf("\nResultado: %f", resultado);
            printf(gray"\n============================"def);

            ///PRINTAR NO ARQUIVO:
            fprintf(txt,"\nIteração: %d", i);
            fprintf(txt,"\nX anterior: %f", Xant);//imprime x anterior
            fprintf(txt,"\nX atual: %f", X);//imprime x atual
            fprintf(txt,"\nResultado: %f", resultado);
            fprintf(txt,"\n============================");

        }while(fabs(X-Xant)>EPS && i < iMAX);
    fclose(txt); //fechar o arquivo
    }

    printf("\n\n");
    system("pause");
}
