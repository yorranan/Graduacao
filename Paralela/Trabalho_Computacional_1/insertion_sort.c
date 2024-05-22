#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define N 10

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void parallelInsertionSort(int arr[], int n)
{
    int i, key, j;

    #pragma omp parallel for private(i, key, j)
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    clock_t start = clock();
    setlocale(LC_ALL, "Portuguese");

    for (int rodada = 1; rodada <= 100000-1; rodada *= 10)
    {
        int vetor[N * rodada];
        for (int i = 0; i < N * rodada; i++)
        {
            vetor[i] = rand() % N;
        }

        // insertionSort(vetor, N * rodada);
        parallelInsertionSort(vetor, N * rodada);

        clock_t finish = clock();
        double time_spent = (double)(finish - start) / CLOCKS_PER_SEC;
        printf("N = %i Tempo de execução: %.8lf\n", rodada * N, time_spent);
    }

    return 0;
}
