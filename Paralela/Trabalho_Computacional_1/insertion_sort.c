#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

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
    setlocale(LC_ALL, "Portuguese");

    for (int n = 0; n <= 100000; n += 10000)
    {

        clock_t start = clock();
        int vetor[n];
        for (int i = 0; i < n; i++)
        {
            vetor[i] = rand() % n;
        }

        //insertionSort(vetor, n);
        parallelInsertionSort(vetor, n);

        clock_t finish = clock();
        double time_spent = (double)(finish - start) / CLOCKS_PER_SEC;
        printf("N = %i Tempo de execução: %.8lf\n", n, time_spent);
    }

    return 0;
}
