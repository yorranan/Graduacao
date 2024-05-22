#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define N 10

void countingSort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    int *count = (int *)calloc(max + 1, sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}

int main()
{
    clock_t start = clock();
    setlocale(LC_ALL, "Portuguese");

    for (int rodada = 1; rodada <= 100000-1; rodada *= 10)
    {
        int *V = (int *)malloc(rodada * N * sizeof(int));

        srand(time(NULL));
        for (int i = 0; i < rodada * N; i++)
        {
            V[i] = rand() % 1000;
        }

        countingSort(V, rodada * N);

        free(V);

        clock_t finish = clock();
        double time_spent = (double)(finish - start) / CLOCKS_PER_SEC;
        printf("N = %i Tempo total de execução: %.8lf segundos\n", N * rodada, time_spent);
    }

    return 0;
}
