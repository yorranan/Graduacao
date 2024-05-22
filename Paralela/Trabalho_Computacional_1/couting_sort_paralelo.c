#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define N 10

void countingSort(int arr[], int n, int max) {
    int i;

    // Criar e inicializar o array de contagem
    int *count = (int*)calloc(max + 1, sizeof(int));
    int *output = (int*)malloc(n * sizeof(int));

    // Contar a frequência de cada elemento na lista original
    #pragma omp parallel for
    for (i = 0; i < n; i++) {
        #pragma omp atomic
        count[arr[i]]++;
    }

    // Calcular as posições corretas dos elementos na lista ordenada
    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Ordenar os elementos na lista de saída
    #pragma omp parallel for
    for (i = n - 1; i >= 0; i--) {
        int idx = __sync_sub_and_fetch(&count[arr[i]], 1);
        output[idx] = arr[i];
    }

    // Copiar os elementos ordenados de output[] de volta para a lista original
    #pragma omp parallel for
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Liberar memória
    free(count);
    free(output);
}

int main() {
    clock_t start = clock();
    setlocale(LC_ALL, "Portuguese");
    for (int rodada = 1; rodada <= 100000-1; rodada *= 10) {
        int array[N * rodada];
        int max = 0;
        
        // Preencher o vetor com números aleatórios e encontrar o máximo
        srand(time(NULL));
        for (int i = 0; i < N * rodada; i++) {
            array[i] = rand() % N;
            if (array[i] > max) {
                max = array[i];
            }
        }

        countingSort(array, N * rodada, max);

        clock_t finish = clock();
        double time_spent = (double)(finish - start) / CLOCKS_PER_SEC;
        printf("Rodada %i N = %i Tempo de execução: %.8lf\n", rodada, rodada * N, time_spent);
    }
    return 0;
}