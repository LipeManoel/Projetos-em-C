#include "header.h"

void troca(int *vetor, int a, int b){
    int aux = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = aux;
}

int particiona(int *vetor, int inicio, int fim){
    int pivo = vetor[fim];
    int pivo_indice = inicio;

    for(int i = inicio; i < fim; i++){
        if(vetor[i] <= pivo){
            troca(vetor, i, pivo_indice);
            pivo_indice++;
        }
    }

    troca(vetor, pivo_indice, fim);  // Coloca o pivô no lugar correto
    printf("\nVETOR TROCOU O PIVO %d:", vetor[pivo_indice]);
    mostrarVetor(vetor, fim);

    return pivo_indice;
}

int quickSort(int *vetor, int inicio, int fim){
    if(inicio < fim){
        int pivo = particiona(vetor, inicio, fim);

        quickSort(vetor, inicio, pivo - 1); // Ordena o lado esquerdo
        quickSort(vetor, pivo + 1, fim);    // Ordena o lado direito
    }
    return 0;
}

void mostrarVetor(int *vetor, int vetor_tam){
    for(int i = 0; i < vetor_tam; i++){
        printf("\npos %d = %d", i, vetor[i]);
    }
}

int main(){
    int vetor_tam = 20;
    int *vetor = (int*)malloc(vetor_tam * sizeof(int));

    system("cls");
    setlocale(LC_ALL, "");

    // Preenche o vetor com números aleatórios
    for(int i = 0; i < vetor_tam; i++){
        vetor[i] = rand() % 100;
    }

    printf("\nVETOR ORIGINAL:");
    mostrarVetor(vetor, vetor_tam);

    quickSort(vetor, 0, vetor_tam - 1);

    printf("\n\nVETOR FINAL:");
    mostrarVetor(vetor, vetor_tam);

    free(vetor);
    return 0;
}
