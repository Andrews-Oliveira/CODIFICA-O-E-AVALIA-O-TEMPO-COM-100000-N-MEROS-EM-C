#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define o tamanho do vetor
#define TAMANHO 100000

// Função que realiza a ordenação utilizando o algoritmo Selection Sort
void selectionSort(int vetor[], int tamanho) {
    // Laço para iterar sobre cada elemento do vetor
    for (int i = 0; i < tamanho - 1; i++) {
        int minIndex = i;  // Define o índice do menor elemento encontrado
        // Laço interno para encontrar o menor elemento a partir da posição atual
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[minIndex]) {  // Verifica se encontrou um valor menor
                minIndex = j;  // Atualiza o índice do menor elemento
            }
        }
        // Realiza a troca de elementos
        int temp = vetor[i];
        vetor[i] = vetor[minIndex];
        vetor[minIndex] = temp;
    }
}

// Função para calcular e imprimir o tempo de execução do algoritmo
void imprimirTempo(const char* descricao, clock_t inicio, clock_t fim) {
    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;  // Converte o tempo para segundos
    printf("%s levou %.6f segundos.\n", descricao, tempo);  // Exibe o tempo na tela
}

int main() {
    int vetor[TAMANHO];  // Declara o vetor com o tamanho definido
    clock_t inicio, fim;  // Variáveis para armazenar o tempo inicial e final de execução

    // 1. Caso: Vetor totalmente ordenado em ordem decrescente
    for (int i = 0; i < TAMANHO; i++) vetor[i] = TAMANHO - i;  // Preenche o vetor de forma decrescente
    inicio = clock();  // Início da medição de tempo
    selectionSort(vetor, TAMANHO);  // Ordena o vetor usando Selection Sort
    fim = clock();  // Fim da medição de tempo
    imprimirTempo("Vetor decrescente", inicio, fim);  // Exibe o tempo de execução

    // 2. Caso: Vetor totalmente ordenado em ordem crescente
    for (int i = 0; i < TAMANHO; i++) vetor[i] = i;  // Preenche o vetor de forma crescente
    inicio = clock();
    selectionSort(vetor, TAMANHO);
    fim = clock();
    imprimirTempo("Vetor crescente", inicio, fim);

    // 3. Caso: Primeira metade crescente e segunda metade decrescente
    for (int i = 0; i < TAMANHO / 2; i++) vetor[i] = i;  // Primeira metade crescente
    for (int i = TAMANHO / 2; i < TAMANHO; i++) vetor[i] = TAMANHO - i;  // Segunda metade decrescente
    inicio = clock();
    selectionSort(vetor, TAMANHO);
    fim = clock();
    imprimirTempo("Primeira metade crescente, segunda metade decrescente", inicio, fim);

    // 4. Caso: Primeira metade decrescente e segunda metade crescente
    for (int i = 0; i < TAMANHO / 2; i++) vetor[i] = TAMANHO / 2 - i;  // Primeira metade decrescente
    for (int i = TAMANHO / 2; i < TAMANHO; i++) vetor[i] = i - TAMANHO / 2;  // Segunda metade crescente
    inicio = clock();
    selectionSort(vetor, TAMANHO);
    fim = clock();
    imprimirTempo("Primeira metade decrescente, segunda metade crescente", inicio, fim);

    // 5. Caso: Vetor com elementos totalmente desordenados
    for (int i = 0; i < TAMANHO; i++) vetor[i] = rand() % TAMANHO;  // Preenche o vetor com valores aleatórios
    inicio = clock();
    selectionSort(vetor, TAMANHO);
    fim = clock();
    imprimirTempo("Elementos desordenados", inicio, fim);

    return 0;  // Fim do programa
}
