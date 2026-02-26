#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comparacoes;
long long movimentacoes;


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparacoes++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                movimentacoes += 3; 
            }
        }
    }
}


void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            movimentacoes += 3; 
        }
    }
}


void criarVetorDecrescente(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}


void testarAlgoritmo(void (*sort)(int[], int), int tamanho, char nome[]) {
    int *vetor = (int*) malloc(tamanho * sizeof(int));

    criarVetorDecrescente(vetor, tamanho);

    comparacoes = 0;
    movimentacoes = 0;

    clock_t inicio = clock();
    sort(vetor, tamanho);
    clock_t fim = clock();

    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\nAlgoritmo: %s | Tamanho: %d\n", nome, tamanho);
    printf("Tempo: %.6f segundos\n", tempo);
    printf("Comparacoes: %lld\n", comparacoes);
    printf("Movimentacoes: %lld\n", movimentacoes);

    free(vetor);
}


int main() {

    int tamanhos[] = {1000, 5000, 10000};

    for (int i = 0; i < 3; i++) {
        testarAlgoritmo(bubbleSort, tamanhos[i], "Bubble Sort");
        testarAlgoritmo(selectionSort, tamanhos[i], "Selection Sort");
    }

    return 0;
}
