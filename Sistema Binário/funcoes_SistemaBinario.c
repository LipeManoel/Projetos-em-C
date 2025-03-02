#include "declaracoes_SistemaBinario.h"
void menu(){
    system("cls");

    ASCII = 26;//flecha
    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    printf("\n#                                         #");
    printf("\n#      "cc"Caleb Fortes || Felipe Manoel"cb"      #");
    printf("\n#                                         #");
    printf("\n#         "caz"MENU - Sistema Binário"cb"          #");
    printf("\n#                                         #");
    printf("\n#     "ccl"1 %c Converter decimal em binário"cb"    #",ASCII);
    printf("\n#     "ccl"2 %c Converter binário em decimal"cb"    #",ASCII);
    printf("\n#     "ccl"3 %c Sair do programa"cb"                #",ASCII);
    printf("\n#                                         #");
    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");

    selecionarOpcao();
}

void selecionarOpcao(){
    int opcao;
    ASCII = 16;//triangulo
    printf("\n\n%c Escolha uma opção: ", ASCII);
    scanf("%i", &opcao);

    switch(opcao){
        case 1:
            beep();
            imprimirDecimalParaBinario();
            continuar();
        case 2:
            beep();
            imprimirBinarioParaDecimal();
            continuar();
        case 3:
            Beep(2500,100);
            printf("\n"cv"VOCÊ ESCOLHEU SAIR!"cb"\n\n");
            printf(cc);
            system("pause");
            exit(0);
        default:
            printf("\a");
            printf("\n"cv"OPÇÃO INVÁLIDA!"cb"");
            while ((opcao = getchar()) != '\n' && opcao != EOF) { } //caso opcao = caracter invalido
            continuar();
    }
}

void continuar(){
    printf("\n\n"cc"");
    system("pause");
    printf(cb);
    beep();
    menu();
}

//FUNCOES DOS  TIPOS DE DADOS
void imprimirBinarioParaDecimal() {
    char binario[MAX];
    double decimal = 0.0;
    int i, ponto = 0;

    printf("\nDigite um número binário: ");
    scanf("%s", binario);
    beep();

    // Procurando o ponto decimal
    for (i = 0; binario[i] != '\0'; ++i) {
        if (binario[i] == '.') {
            ponto = 1;
            break;
        }
    }

    // Convertendo a parte inteira
    for (i = 0; binario[i] != '\0' && binario[i] != '.'; ++i) {
        decimal = decimal * 2 + (binario[i] - '0');
    }

    // Convertendo a parte fracionária
    if (ponto) {
        double f = 0.5;
        for (++i; binario[i] != '\0'; ++i) {
            decimal += (binario[i] - '0') * f;
            f /= 2.0;
        }
    }
    printf("\nO número em decimal é: "cci"%.10f"cb"", decimal);
}

void imprimirDecimalParaBinario() {
    int parteInteira, i=0, j, binario[MAX];//Vetor para armazenar até 100 bits
    double numOriginal, parteFracionaria;

    printf("\t\nInforme um número: ");
    scanf("%lf", &numOriginal);
    beep();

    parteInteira = (int)numOriginal;//pega a parte que vem antes da virgula de num
    parteFracionaria = numOriginal;
    parteFracionaria = parteFracionaria - parteInteira;//pega apenas a parte fracionaria

    while (parteInteira > 0) {
        binario[i] = parteInteira % 2;//divide um numero ate que retorne 1 ou 0 como resultado
        parteInteira = parteInteira / 2;
        i++;
    }

    printf("\nO número %.2f em binário é: ", numOriginal);
    printf(cci);
    for (j=i - 1; j>=0; j--) {//de tras para frente
        printf("%d", binario[j]);//imprime a parte inteira em binário
    }

    // Converte a parte fracionária, se houver
    if(parteFracionaria != 0) {
            printf(".");
            i = 0;
            while (parteFracionaria > 0 && i < MAX) {
                parteFracionaria = parteFracionaria * 2;
                int parteInteira = (int)parteFracionaria;
                binario[i] = parteInteira;
                printf("%d", binario[i]); // Imprime cada dígito da parte fracionária convertida
                parteFracionaria = parteFracionaria - parteInteira;
                i++;
            }
    }
    printf(cb);// cor branca
}

void beep(){
    Beep(322,100);
}
