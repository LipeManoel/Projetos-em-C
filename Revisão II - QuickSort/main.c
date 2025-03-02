#include "header.h"

void aleatorizarVetor(int *vet, int vetTAM){
    for(int i = 0; i < vetTAM; i++){
        vet[i] = rand() % 100; // Gera números aleatórios entre 0 e 99
    }
    imprimirVetor(vet, vetTAM); // Chama a função sem return
}

void imprimirVetor(int *vet, int vetTAM){
    for (int i = 0; i < vetTAM; i++){
        printf("\n%d", vet[i]);
    }
    printf("\n"); // Quebra de linha para facilitar a leitura
}

void troca(int *vet, int A, int B){
    printf("\nTroca entre vet[%d](%d) e vet[%d](%d)", A, vet[A], B, vet[B]);
    int aux = vet[A];
    vet[A] = vet[B];
    vet[B] = aux; // Troca corretamente os valores entre vet[A] e vet[B]
}

int particionar(int *vet, int inicio, int fim){
    int pivo = vet[fim]; // Define o pivô como o último elemento
    int pivo_indice = inicio; // Índice para os elementos menores que o pivô

    for (int i = inicio; i < fim; i++) {
        if (vet[i] <= pivo) { // Se o elemento atual for menor ou igual ao pivô
            troca(vet, i, pivo_indice); // Troca o elemento com o pivo_indice
            pivo_indice++;
        }
    }
    troca(vet, pivo_indice, fim); // Coloca o pivô na posição correta
    return pivo_indice; // Retorna o índice final do pivô
}

int escolherPivo(int *vet, int vetTAM, int inicio, int fim){
    int pivo_indice = (inicio + fim) / 2; // Escolhe o pivô como o elemento do meio
    troca(vet, pivo_indice, fim); // Coloca o pivô no fim
    printf("\nPivô escolhido: %d", vet[fim]); // Imprime o pivô escolhido
    return particionar(vet, inicio, fim); // Particiona e retorna o novo índice do pivô
}

void quickSort(int *vet, int vetTAM, int inicio, int fim){
    if (inicio < fim) {
        int pivo_indice = escolherPivo(vet, vetTAM, inicio, fim); // Escolhe e particiona o pivô
        quickSort(vet, vetTAM, inicio, pivo_indice - 1); // Ordena a parte esquerda
        quickSort(vet, vetTAM, pivo_indice + 1, fim); // Ordena a parte direita
    }
}

int main(){
    int vetTAM = 10; // Tamanho do vetor
    int *vet = (int*)malloc(vetTAM * sizeof(int)); // Aloca memória para o vetor

    aleatorizarVetor(vet, vetTAM); // Preenche o vetor com valores aleatórios

    printf("\nVetor antes do QuickSort:\n");
    imprimirVetor(vet, vetTAM); // Imprime o vetor antes da ordenação

    quickSort(vet, vetTAM, 0, vetTAM - 1); // Chama o QuickSort

    printf("\nVetor após o QuickSort:\n");
    imprimirVetor(vet, vetTAM); // Imprime o vetor ordenado

    free(vet); // Libera a memória alocada
    system("pause");
    return 0;
}
