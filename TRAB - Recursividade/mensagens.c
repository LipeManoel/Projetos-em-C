//mensagens.c

void menu(){//mostrar menu principal
    system("cls");
    barraMenu(27);
    printf("\n"bRed"                                                  "bRed"|");
    printf("\n"bRed"              =========================           "bRed"|");
    printf("\n"bRed"              \033[7mR E C U R S I V I D A D E"def"           "bRed"|");
    printf("\n"bRed"              =========================           "bRed"|");
    printf("\n"bRed"                                                  "bRed"|");
    printf("\n"bRed"              \033[1mMenu                                "bRed"|");
    printf("\n"bRed"               %c"red"|1|"def"Realizar processos             "bRed"|", 108);
    printf("\n"bRed"               %c"red"|2|"def"Cr�ditos                       "bRed"|", 108);
    printf("\n"bRed"               %c"red"|3|"def"Sair                           "bRed"|", 108);
    printf("\n"bRed"                                                  "bRed"|");
    barraMenu(27);
    printf("\n\nEscolha uma op��o: ");
}

void creditos(){//mostrar creditos do programa
    system("cls");
    barraMenu(27);
    printf("\n"bRed"                                                  "bRed"|");
    printf("\n"bRed""red"  @@@@@@@@@@@@@@@"def"         ===============         "bRed"|");
    printf("\n"bRed""red"  @@    @@    @@@"def"         \033[7mC R � D I T O S"def"         "bRed"|");
    printf("\n"bRed""red"  @@  @@@@  @@ @@"def"         ===============         "bRed"|");
    printf("\n"bRed""red"  @@    @@@@   @@"def"                                 "bRed"|");
    printf("\n"bRed""red"  @@    @@@    @@"def"    \033[1mIntegrantes:                 "bRed"|");
    printf("\n"bRed""red"  @@@    @    @@@"def"      %c Caleb de Souza Fortes    "bRed"|", 108);
    printf("\n"bRed""red"  @@@@@@@@@@@@@@@"def"      %c Felipe Manoel R. Pessoa  "bRed"|", 108);
    printf("\n"bRed"                                                  "bRed"|");
    barraMenu(27);
}

void barraMenu(int b){//loop que imprime as barras presentes nos menus
    printf("\n");
    for(int i=0; i<b; i++){
        printf(bRed);
    }
    printf("|");
}

void msg_sair(){//imprime a mensagem de sair
    printf("\n\033[1mVoc� escolheu sair!\n\n"def);
    system("pause");
    exit(0);
}

void msg_opInvalida(int op){//imprime mensagem de opcao invalida
    printf(red"\nOp��o inv�lida!"def);
    while ((op = getchar()) != '\n' && op != EOF);//limpar buffer
}

void msg_resultIterado(int n, int r){//imprime os resultados das operacoes
    double tempo, tempoI, tempoF;

    tempoI = clock();
	int iterado = processoIt(n, r);
	tempoF = clock();

	tempo = (tempoF - tempoI)/CLOCKS_PER_SEC;//converte a diferen�a de "ticks" para segundos
	tempo = tempo * 1000;

    printf("\n"fRed" "def" \033[1mM�todo Iterado"def" resultou em %d com %lf ms", iterado, tempo);
}

void msg_resultRecursivo(int n, int r){//imprime os resultados das operacoes
    double tempo, tempoI, tempoF;

    tempoI = clock();
	int recursivo = processoRec(n, r);
	tempoF = clock();

	tempo = (tempoF - tempoI)/CLOCKS_PER_SEC;//converte a diferen�a de "ticks" para segundos
	tempo = tempo * 1000;

    printf("\n"fRed" "def" \033[1mM�todo Recursivo"def" resultou em %d com %lf ms", recursivo, tempo);
}

void msg_formula(){//mostrar formula
    printf("\n"bRed""fRed"  \033[1mF�rmula:                                          "def);
    printf("\n"bRed""fRed"   %c n: Total de elementos      "def""fRed"nCr =\033[4m   n!   "def""fRed"       "def,108);
    printf("\n"bRed""fRed"   %c r: Elementos escolhidos         "def""fRed"r!(n-r)!       "def, 108);
}

int msg_digiteN(){//digitar n da formula
    int num;
    printf("\n\nDigite n: ");
    scanf("%d", &num);

    if (num <= 0){
        printf(red"'n' deve ser maior que 0!"def);
        return msg_digiteN();
    }else{
        return num;
    }
}

int msg_digiteR(int n){//digitar r da formula
    int num;
    printf("\nDigite r: ");
    scanf("%d", &num);

    if (num < 0 || num >= n){
        printf(red"'r' deve ser maior ou igual � 0 e menor que n!"def);
        return msg_digiteR(n);
    }else{
        return num;
    }
}
