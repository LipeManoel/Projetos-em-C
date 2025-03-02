#include "EstatisticaCompleta_funcoes.c"
int main(){

	setlocale(LC_ALL, "");
	system("cls");
    barraMenu();
    printf("\n"bc"                                         "bc"");
    printf("\n"bc"         "blue"ESTÁTISTICA DESCRITIVA"pad"          "bc"");
    printf("\n"bc"                                         "bc"");
    printf("\n"bc"            Originalmente por            "bc"");
    printf("\n"bc"          Marcelo Goulart Souza          "bc"");
    printf("\n"bc"                                         "bc"");
    barraMenu();

	printf("\n\nInforme o número de linhas da matriz:\n");
	scanf("%d", &lin);
	Beep(500,80);
	printf("Informe o número de colunas da matriz:\n");
	scanf("%d", &col);
	Beep(500,80);

	matriz = (int **)malloc(lin * sizeof(int));
	for(j=0; j<col; j++){
		matriz[j] = (int *)malloc(col * sizeof(int));
	}

	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			matriz[i][j] = rand() % 10;
		}
	}

	imprimir_matriz(matriz, lin, col);
	continuar();
}
