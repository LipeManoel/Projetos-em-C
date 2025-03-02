#include "EstatisticaCompleta_declaracoes.h"

float calculaMedia(int **matriz, int lin, int col){

	int i, j, soma = 0;
	float media;
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			soma += matriz[i][j];
		}
	}

	media = soma/(lin*col);
	return media;
}

float calculaMediana(int **matriz, int lin, int col){

	int i, j, aux, cont=0;
	int n = lin*col;
	int vetor[n];

	for(i=0; i<lin; i++){
	    for(j=0; j<col; j++){
	        vetor[cont] = matriz[i][j];
	        cont++;
	    }
	}

	/*printf("vetor: ");
	for(i=0; i<n; i++){
		if(i != (n-1)){
			printf("%d, ", vetor[i]);
		}else{
			printf("%d.", vetor[i]);
		}
	}
	printf("\n");
	*/
    for (i = 0; i < n; i++) {
        for (j = 0; j < (n - 1); j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }

	cont = 0;
	for(i=0; i<lin; i++){
	    for(j=0; j<col; j++){
	        matriz[i][j] = vetor[cont];
	        cont++;
	    }
	}

	int ponto_medio;
	float soma = 0;
	float mediana;
	if(n % 2 == 0){
		ponto_medio = n/2;
		soma = vetor[ponto_medio] + vetor[ponto_medio+1];
		mediana = soma/2;
	}else{
		ponto_medio = n/2;
		mediana = vetor[ponto_medio];
	}

	return mediana;
}

float calculaVariancia(int **matriz, int lin, int col){

	float diferenca = 0;
	soma = 0;
	media = 0;
	variancia = 0;

	media = calculaMedia(matriz, lin, col);
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			diferenca = pow((media - matriz[i][j]), 2);
			soma += diferenca;
		}
	}
	variancia = soma/(lin*col);
	return variancia;
}

int calculaModa(int **matriz, int lin, int col) {
    int n = lin * col;
    int vetor[n], contador[n], cont;
    moda = 0;
    cont = 0;

    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            vetor[cont] = matriz[i][j];
            cont++;
        }
    }

    for (i = 0; i < n; i++) {
        contador[i] = 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (vetor[i] == vetor[j]) {
                contador[i]++;
            }
        }
    }
    moda = vetor[0];
    cont = contador[0];
    for (i = 1; i < n; i++) {
        if (contador[i] > cont) {
            cont = contador[i];
            moda = vetor[i];
        }
    }

    return moda;
}

void imprimir_matriz(int **matriz, int m, int n){
	printf("\nMatriz %dx%d: \n", lin, col);
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("[%d][%d] = "blue2"%d"pad"\n", i, j, matriz[i][j]);
		}
	}
	printf("\nOutra representação:\n");
    printf(""blue2"");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("%2d ", matriz[i][j]);
		}
		printf("\n");
	}
    printf(""pad"");
}

void continuar(){
    printf("\n");
    system("pause");
    Beep(500,120);
    menu();
}

void arquivo(FILE *txt, float media, float mediana, int moda, float variancia, float desvpad, float cv){
        txt = fopen("Arquivo.txt", "wt"); // "wt": abertura para escrita
        if (txt == NULL) { // se não conseguiu abrir
            printf("\nArquivo não pode ser criado!\n");
        } else {
            fprintf(txt, "Média = %.2f\n", media);
            fprintf(txt, "Mediana = %.2f\n", media);
            fprintf(txt, "Moda = %d\n", moda);
            fprintf(txt, "Variância = %.2f\n", variancia);
            fprintf(txt, "Desvio padrão = %.2f\n", desvpad);
            fprintf(txt, "Coeficiente de variação = %.2f %%\n", cv);
            fclose(txt);
            printf("\n"yellow"Os dados foram inseridos com sucesso."pad"\n");
        }
}

void barraMenu(){
    char ASCII = 135;
    printf("\n\033[38;2;180;180;180m");
    for(i=0; i<45; i++){
            printf("%c",ASCII);
    }
    printf(""pad"");
}

void menu(){
    system("cls");
    barraMenu();
    printf("\n"bc"                                         "bc"");
    printf("\n"bc"           Modificado pelo aluno         "bc"");
    printf("\n"bc"              Felipe Manoel              "bc"");
    printf("\n"bc"                                         "bc"");
    printf("\n"bc"        "blue"MENU - SISTEMA ESTÁTISTICO"pad"       "bc"");
    printf("\n"bc"                                         "bc"");
    printf("\n"bc"     1 - Média                           "bc"");
    printf("\n"bc"     2 - Mediana                         "bc"");
    printf("\n"bc"     3 - Moda                            "bc"");
    printf("\n"bc"     4 - Variância                       "bc"");
    printf("\n"bc"     5 - Desvio padrão                   "bc"");
    printf("\n"bc"     6 - Coefiente de variação           "bc"");
    printf("\n"bc"     7 - Resumo estatístico              "bc"");
    printf("\n"bc"     8 - Mostrar matriz                  "bc"");
    printf("\n"bc"     9 - Sair                            "bc"");
    printf("\n"bc"                                         "bc"");
    barraMenu();
    printf("\n\nEscolha uma opção: ");

    scanf("%d", &op);
    switch (op){
        case 1:
            Beep(500,80);
            media = calculaMedia(matriz, lin, col);
            printf("\n"blue2"Média = "pad"%.2f\n", media);
            continuar();
            break;
        case 2:
            Beep(500,80);
            mediana = calculaMediana(matriz, lin, col);
            printf("\n"blue2"Mediana = "pad"%.2f\n", mediana);
            continuar();
            break;
        case 3:
            Beep(500,80);
            moda = calculaModa(matriz, lin, col);
            printf("\n"blue2"Moda = "pad"%d\n", moda);
            continuar();
            break;
        case 4:
            Beep(500,80);
            variancia = calculaVariancia(matriz, lin, col);
            printf("\n"blue2"Variância = "pad"%.2f\n", variancia);
            continuar();
            break;
        case 5:
            Beep(500,80);
            variancia = calculaVariancia(matriz, lin, col);
            float desvpad = sqrt(variancia);
            printf(""blue2"\nDesvio padrão = "pad"%.2f\n", desvpad);
            continuar();
            break;
        case 6:
            Beep(500,80);
            variancia = calculaVariancia(matriz, lin, col);
            desvpad = sqrt(variancia);
            media = calculaMedia(matriz, lin, col);
            cv = (desvpad/media)*100;
            printf("\n"blue2"Coeficiente de variação = "pad"%.2f %\n", cv);
            continuar();
            break;
        case 7:
            Beep(500,80);
            imprimir_matriz(matriz, lin, col);
            mediana = calculaMediana(matriz, lin, col);
            moda = calculaModa(matriz, lin, col);
            variancia = calculaVariancia(matriz, lin, col);
            desvpad = sqrt(variancia);
            media = calculaMedia(matriz, lin, col);
            cv = (desvpad/media)*100;
            printf("\n"blue2"Média = "pad"%.2f\n", media);
            printf(""blue2"Mediana = "pad"%.2f\n", mediana);
            printf(""blue2"Moda = "pad"%d\n", moda);
            printf(""blue2"Variância = "pad"%.2f\n", variancia);
            printf(""blue2"Desvio padrão = "pad"%.2f\n", desvpad);
            printf(""blue2"Coeficiente de variação = "pad"%.2f %\n", cv);
            arquivo(txt,media, mediana, moda, variancia, desvpad, cv);
            continuar();
            break;
        case 8:
            Beep(500,80);
            imprimir_matriz(matriz, lin, col);
            continuar();
            break;
        case 9:
            Beep(500,80);
            printf("\n"yellow"Você escolheu sair!"pad"\n\n");
            system("pause");
            exit(0);
        default:
            printf("\a");
            printf("\n"red"Opção inválida!"pad"\n");
            continuar();
            break;
    }
}
