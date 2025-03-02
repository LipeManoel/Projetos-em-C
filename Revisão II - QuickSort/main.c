#include "header.h"

void aleatorizarVetor(int *vet, int vetTAM){
    for(int i = 0; i < vetTAM; i++){
        vet[i] = rand() % 100; // Gera n�meros aleat�rios entre 0 e 99
    }
    imprimirVetor(vet, vetTAM); // Chama a fun��o sem return
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
    int pivo = vet[fim]; // Define o piv� como o �ltimo elemento
    int pivo_indice = inicio; // �ndice para os elementos menores que o piv�

    for (int i = inicio; i < fim; i++) {
        if (vet[i] <= pivo) { // Se o elemento atual for menor ou igual ao piv�
            troca(vet, i, pivo_indice); // Troca o elemento com o pivo_indice
            pivo_indice++;
        }
    }
    troca(vet, pivo_indice, fim); // Coloca o piv� na posi��o correta
    return pivo_indice; // Retorna o �ndice final do piv�
}

int escolherPivo(int *vet, int vetTAM, int inicio, int fim){
    int pivo_indice = (inicio + fim) / 2; // Escolhe o piv� como o elemento do meio
    troca(vet, pivo_indice, fim); // Coloca o piv� no fim
    printf("\nPiv� escolhido: %d", vet[fim]); // Imprime o piv� escolhido
    return particionar(vet, inicio, fim); // Particiona e retorna o novo �ndice do piv�
}

void quickSort(int *vet, int vetTAM, int inicio, int fim){
    if (inicio < fim) {
        int pivo_indice = escolherPivo(vet, vetTAM, inicio, fim); // Escolhe e particiona o piv�
        quickSort(vet, vetTAM, inicio, pivo_indice - 1); // Ordena a parte esquerda
        quickSort(vet, vetTAM, pivo_indice + 1, fim); // Ordena a parte direita
    }
}

int main(){
    int vetTAM = 10; // Tamanho do vetor
    int *vet = (int*)malloc(vetTAM * sizeof(int)); // Aloca mem�ria para o vetor

    aleatorizarVetor(vet, vetTAM); // Preenche o vetor com valores aleat�rios

    printf("\nVetor antes do QuickSort:\n");
    imprimirVetor(vet, vetTAM); // Imprime o vetor antes da ordena��o

    quickSort(vet, vetTAM, 0, vetTAM - 1); // Chama o QuickSort

    printf("\nVetor ap�s o QuickSort:\n");
    imprimirVetor(vet, vetTAM); // Imprime o vetor ordenado

    free(vet); // Libera a mem�ria alocada
    system("pause");
    return 0;
}
