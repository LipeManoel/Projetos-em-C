//funcoes.c

int fatorialIt(num){//calcular fatorial do numero dado
    int result = 1;
    for (int i = num; i > 1; i--) {
        result = result * i;
    }
    return result;
}

int processoIt(int n, int r){
    int fatN, fatR, fatNR;

    fatN = fatorialIt(n);      // fatorial de n
    fatR = fatorialIt(r);      // fatorial de r
    fatNR = fatorialIt(n - r); // fatorial de n-r

    return fatN/(fatR*fatNR);
}

int fatorialRec(int num) {//calcular fatorial do numero dado
    if (num == 0 || num == 1) {
        return  num;
    }
    return num * fatorialRec(num - 1);
}

int processoRec(int n, int r) {
    int fatN, fatR, fatNR;

    fatN = fatorialRec(n);      // fatorial de n
    fatR = fatorialRec(r);      // fatorial de r
    fatNR = fatorialRec(n - r); // fatorial de n-r

    return fatN / (fatR * fatNR);
}
